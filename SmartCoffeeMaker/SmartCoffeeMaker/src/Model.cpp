#include "Model.h"
#include "Arduino.h"

Model::Model(){
  // Brewing is initially off
  isBrewing = false;
  brewRequested = false;

  waterLevelLow = true;
  potPresent = false;

  // Select the default selection
  menuOptionSelection = 0;

  // Number of observers added
  numObservers = 0;
  
  // initial input state
  inputState = InputState::NONE;

  // Set initial text to empty
  displayText = nullptr;

  interfaceState = InterfaceState::MENU;
  menuState = MenuState::MENU_BREW;
  brewState = BrewState::BREWING;
  settingsState = SettingsState::SETTINGS_ALARM_NOISE;
  schedulingState = SchedulingState::SCHEDULING;

  setInterfaceState(InterfaceState::MENU);
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

void Model::updateDisplayText(){
  if(interfaceState == InterfaceState::MENU){
    displayText = MENU_STRINGS[menuState];
  }else if(interfaceState == InterfaceState::BREW){
    displayText = BREWING_STRINGS[brewState];
  }else if(interfaceState == InterfaceState::SETTING){
    displayText = SETTINGS_STRINGS[settingsState];
  }else if(interfaceState == InterfaceState::BREW){
    displayText = SCHEDULING_STRINGS[schedulingState];
  }
}

InterfaceState Model::getInterfaceState(){
  return interfaceState;
}

MenuState Model::getMenuState(){
  return menuState;
}
BrewState Model::getBrewState(){
  return brewState;
}

SettingsState Model::getSettingsState(){
  return settingsState;
}

SchedulingState Model::getSchedulingState(){
  return schedulingState;
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

bool Model::isPotPresent(){
  return potPresent;
}

bool Model::isBrewRequested(){
  return brewRequested;
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

void Model::setPotPresent(bool present){
  potPresent = present;
  notifyObservers();
}

void Model::setBrewRequested(bool request){
  brewRequested = request;
  //notifyObservers();
}

void Model::setView(Observer *viewReference){
  view = viewReference;
}

void Model::setRelay(Observer *relayReference){
  relay = relayReference;
}

void Model::setInterfaceState(InterfaceState interfaceState){
  this->interfaceState = interfaceState;
  updateDisplayText();
  notifyObservers();
}

void Model::setMenuState(MenuState menuState){
  this->menuState = menuState;
  updateDisplayText();
  notifyObservers();
}

void Model::setBrewState(BrewState brewState){
  this->brewState = brewState;
  updateDisplayText();
  notifyObservers();
}

void Model::setSettingsState(SettingsState settingsState){
  this->settingsState = settingsState;
  updateDisplayText();
  notifyObservers();
}

void Model::setSchedulingState(SchedulingState schedulingState){
  this->schedulingState = schedulingState;
  updateDisplayText();
  notifyObservers();
}