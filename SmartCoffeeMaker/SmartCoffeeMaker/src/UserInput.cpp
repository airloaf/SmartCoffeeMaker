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

void UserInput::setMenuController(MenuController *controller){
  menuController = controller;
}

void UserInput::loop(){

  // Get the encoder value
  value += encoder->getValue();
  if (value != last) {
    last = value;
    if (value >= 4){
      value = 0;
      model->setInputState(InputState::CLOCK_WISE_TURN);
      menuController->cwTurn();
      Serial.println("Clock Wise");
    }else if(value <= -4){
      value = 0;
      model->setInputState(InputState::COUNTER_CLOCK_WISE_TURN);
      menuController->ccwTurn();
      Serial.println("Counter Clock Wise");
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
          menuController->singleClickPress();
          Serial.println("Click");
      break;
      case ClickEncoder::DoubleClicked:
          model->setInputState(InputState::DOUBLE_CLICK);
          menuController->doubleClickPress();
          Serial.println("Double Click");
        break;
    }
  }
}