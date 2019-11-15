#include "Model.h"
#include "Arduino.h"

Model::Model(){
  // Brewing is initially off
  isBrewing = false;

  // Select the default selection
  menuOptionSelection = 0;

  // Number of observers added
  numObservers = 0;
  
  // initial input state
  inputState = InputState::NONE;

  // Set initial text to empty
  displayText = "";
}

void Model::addObserver(Observer *observer){
  observers[numObservers] = observer;
  numObservers++;
}

void Model::setInputState(InputState nextInputState){
  inputState = nextInputState;
  notifyObservers();
}

void Model::setDisplayText(char *text){
  displayText = text;
  notifyObservers();
}

void Model::resetInputState(){
  inputState = InputState::NONE;
}

void Model::notifyObservers(){
  for(int observerIndex =0; observerIndex < numObservers; observerIndex++){
    observers[observerIndex]->onNotify();
  }
}

InputState Model::getInputState(){
  return inputState;
}

bool Model::getIsBrewing(){
  return isBrewing;
}

int Model::getMenuOptionSelection(){
  return menuOptionSelection;
}

char *Model::getDisplayText(){
  return displayText;
}

bool Model::getWaterLevelLow(){
  return waterLevelLow;
}

void Model::setIsBrewing(bool brewing){
  isBrewing = brewing;
  notifyObservers();
}

void Model::setMenuOptionSelection(int selection){
  menuOptionSelection = selection;
  notifyObservers();
}

void Model::setWaterLevelLow(bool level){
  waterLevelLow = level;
  notifyObservers();
}

void Model::setView(Observer *viewReference){
  view = viewReference;
}

void Model::setRelay(Observer *relayReference){
  relay = relayReference;
}