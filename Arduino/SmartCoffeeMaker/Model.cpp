#include "Model.h"

Model::Model(){
  // Brewing is initially off
  isBrewing = false;

  // Select the default selection
  menuOptionSelection = 0;

  // Number of observers added
  numObservers = 0;
}

void Model::addObserver(Observer *observer){
  observers[numObservers] = observer;
  numObservers++;
}

void Model::notifyObservers(){
  for(int observerIndex =0; observerIndex < numObservers; observerIndex++){
    observers[observerIndex]->onNotify();
  }
}

bool Model::getIsBrewing(){
  return isBrewing;
}

int Model::getMenuOptionSelection(){
  return menuOptionSelection;
}

void Model::setIsBrewing(bool brewing){
  isBrewing = brewing;
  notifyObservers();
}

void Model::setMenuOptionSelection(int selection){
  menuOptionSelection = selection;
  notifyObservers();
}
