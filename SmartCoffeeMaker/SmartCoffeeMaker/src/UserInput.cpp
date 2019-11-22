#include "UserInput.h"

// Click Encoder
ClickEncoder *encoder;

// Timer interrupt
void timerIsr() {
  encoder->service();
}

UserInput::UserInput(){

  // Initialize the click encoder
  encoder = new ClickEncoder(A1, A0, A2);

  // Initialize timer 1
  Timer1.initialize(1000);
  Timer1.attachInterrupt(timerIsr);
  encoder->setAccelerationEnabled(false);
   
  last = -1;
  value = 0;

}

void UserInput::setModel(Model *modelReference){
  model = modelReference;
}

void UserInput::loop(){

  // Get the encoder value
  value += encoder->getValue();
  if (value != last) {
    last = value;
    if (value >= 4){
      value = 0;
      model->setInputState(InputState::CLOCK_WISE_TURN);
      handleCWTurn();
      Serial.println("Clock Wise");
    }else if(value <= -4){
      value = 0;
      model->setInputState(InputState::COUNTER_CLOCK_WISE_TURN);
      Serial.println("Counter Clock Wise");
      handleCCWTurn();
    }
  }

  ClickEncoder::Button b = encoder->getButton();
  if (b != ClickEncoder::Open) {
    #define VERBOSECASE(label) case label: Serial.println(#label); break;
    switch (b) {
      VERBOSECASE(ClickEncoder::Pressed);
      VERBOSECASE(ClickEncoder::Held)
      VERBOSECASE(ClickEncoder::Released)
      case ClickEncoder::Clicked:
          model->setInputState(InputState::SINGLE_CLICK);
          Serial.println("Click");
          handleClick();

      break;
      case ClickEncoder::DoubleClicked:
          model->setInputState(InputState::DOUBLE_CLICK);
          Serial.println("Double Click");
          handleClick();
        break;
    }
  }
}

void UserInput::handleCWTurn(){
      if(model->getInterfaceState() == InterfaceState::MENU){
        model->setMenuState((model->getMenuState() + 1) % MenuState::MENU_SELECTIONS);
      }else if(model->getInterfaceState() == InterfaceState::ERRORS){
        model->setInterfaceState(InterfaceState::MENU);
      }
}

void UserInput::handleCCWTurn(){
  if(model->getInterfaceState() == InterfaceState::MENU){
    model->setMenuState((model->getMenuState() - 1) % MenuState::MENU_SELECTIONS);
  }else if(model->getInterfaceState() == InterfaceState::ERRORS){
    model->setInterfaceState(InterfaceState::MENU);
  }
}

void UserInput::handleClick(){
  InterfaceState currentInterfaceState = model->getInterfaceState();

  if(currentInterfaceState == InterfaceState::MENU){
    MenuState currentMenuState = model->getMenuState();

    // Turn on the brewing
    if(currentMenuState == MenuState::MENU_BREW){
      //model->setInterfaceState(InterfaceState::BREW);
      model->setBrewRequested(true);
    }
  }else if(currentInterfaceState == InterfaceState::ERRORS){
    model->setInterfaceState(InterfaceState::MENU);
  }

}

void UserInput::handleDoubleClick(){
  InterfaceState currentInterfaceState = model->getInterfaceState();

  if(currentInterfaceState != InterfaceState::MENU){
    model->setInterfaceState(InterfaceState::MENU);
  }else if(currentInterfaceState == InterfaceState::ERRORS){
    model->setInterfaceState(InterfaceState::MENU);
  }
}