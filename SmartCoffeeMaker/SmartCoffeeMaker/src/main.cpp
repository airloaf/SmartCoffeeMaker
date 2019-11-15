#include "Arduino.h"

#include "View.h"
#include "Model.h"
#include "UserInput.h"
#include "MenuController.h"
#include "Relay.h"
#include "WaterSensor.h"

#include <ClickEncoder.h>
#include <TimerOne.h>
#include <Wire.h>

// Model to hold the current state
Model *model;

// View for the smart coffee maker
View *view;

// Menu controller
MenuController *menuController;

// User Input
UserInput *userInput;

// Relay
Relay *relay;

// Water Water
WaterSensor *waterSensor;

void setup(){
  Serial.begin(9600);
  
  model = new Model();
  view = new View();
  userInput = new UserInput();
  waterSensor = new WaterSensor();

  menuController->setModel(model);
  model->addObserver(view);

  view->setModel(model);
  userInput->setModel(model);

  menuController = new MenuController();
  menuController->setModel(model);
  userInput->setMenuController(menuController);
  menuController->displayText();

  relay = new Relay();
  relay->setModel(model);

  waterSensor->setModel(model);

  model->addObserver(relay);

  //model->setView(view);
  //model->setRelay(relay);

  view->onNotify();
  
}

void loop(){
  userInput->loop();
  waterSensor->updateSensor();

  int reading = analogRead(A3);
  Serial.println(reading);

}