#include "Arduino.h"

#include "View.h"
#include "Model.h"
#include "UserInput.h"
#include "Relay.h"
#include "WaterSensor.h"
#include "PotSensor.h"

#include <ClickEncoder.h>
#include <TimerOne.h>
#include <Wire.h>
#include <Tone.h>


// Model to hold the current state
Model *model;

// View for the smart coffee maker
View *view;

// User Input
UserInput *userInput;

// Relay
Relay *relay;

// Water Water
WaterSensor *waterSensor;

// Pot Sensor
PotSensor *potSensor;

void setup(){
  Serial.begin(9600);

  model = new Model();
  view = new View();
  userInput = new UserInput();
  waterSensor = new WaterSensor();
  relay = new Relay();
  potSensor = new PotSensor();

  view->setModel(model);
  userInput->setModel(model);
  relay->setModel(model);
  waterSensor->setModel(model);
  potSensor->setModel(model);

  model->addObserver(view);
  model->addObserver(relay);

  view->onNotify();
}

void loop(){
  userInput->loop();
  waterSensor->updateSensor();
  potSensor->updateSensor();
  /*
  bool cardPresent = false;
  mfrc522.PICC_ReadCardSerial();
  mfrc522.PICC_IsNewCardPresent();
  if(! mfrc522.PICC_ReadCardSerial()){
    cardPresent = false;
  }else{
    cardPresent = true;
  }

  Serial.print(cardPresent);
  */
}