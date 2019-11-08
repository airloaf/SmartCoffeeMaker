#define WITH_LCD 0

#include "ClickEncoder.h"
#include <TimerOne.h>
#include <LiquidCrystal_I2C.h>

#define COFFEE_PIN 8

// Create LCD display
LiquidCrystal_I2C lcd(0x3F, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

int counter = 0;

bool coffeeOn = false;

// Create encoder
ClickEncoder *encoder;
int16_t last, value;

enum DisplayState {
  BREW,
  SET_TIMER
} displayState;

void timerIsr() {
  encoder->service();
}

// Initialize the display
void setupDisplay(){
  lcd.begin(0, 0);
  displayState = BREW;
  lcd.print("Brew Coffee");
  //updateDisplay();
}


// Update the display
void updateDisplay(){
  lcd.setCursor(0,0);

  switch(displayState){
    case BREW:
      lcd.print("Brew Coffee");
    break;
    default:
      lcd.print("Set Timer");
    break;
  }
}

void setup() {
  Serial.begin(9600);

  // Create the rotary encoder
  encoder = new ClickEncoder(A1, A0, A2);
  Timer1.initialize(1000);
  Timer1.attachInterrupt(timerIsr); 

  pinMode(COFFEE_PIN, OUTPUT);
  digitalWrite(COFFEE_PIN, LOW);
  
  last = -1;

  // Setup the LCD Display
  setupDisplay();
  
}

void loop() {
  //updateDisplay();

  // Get the encoder value
  value += encoder->getValue();
  if (value != last) {
    last = value;
    Serial.print("Encoder Value: ");
    Serial.println(value);
  }
  
  ClickEncoder::Button b = encoder->getButton();
  if (b != ClickEncoder::Open) {
    Serial.print("Button: ");
    #define VERBOSECASE(label) case label: Serial.println(#label); break;
    switch (b) {
      VERBOSECASE(ClickEncoder::Pressed);
      VERBOSECASE(ClickEncoder::Held)
      VERBOSECASE(ClickEncoder::Released)
      case ClickEncoder::Clicked:
          coffeeOn = !coffeeOn;
          Serial.print("Coffee: ");
          Serial.println(coffeeOn);
          digitalWrite(COFFEE_PIN, coffeeOn? HIGH: LOW);
      break;
      case ClickEncoder::DoubleClicked:
          Serial.println("ClickEncoder::DoubleClicked");
          encoder->setAccelerationEnabled(!encoder->getAccelerationEnabled());
          Serial.print("  Acceleration is ");
          Serial.println((encoder->getAccelerationEnabled()) ? "enabled" : "disabled");
        break;
    }
  }
}
