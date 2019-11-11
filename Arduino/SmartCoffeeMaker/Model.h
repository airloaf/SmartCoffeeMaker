#pragma once

#include "Observer.h"

#define NUM_OBSERVERS 1

class Model{
  private:
    // The observers for the model
    Observer *observers[NUM_OBSERVERS];
    
    bool isBrewing;
    int menuOptionSelection;
    int numObservers;

    // Notify the observers of the changes to the model
    void notifyObservers();

  public:
    Model();

    // Add observer to the model
    void addObserver(Observer *observer);

    // Getters
    bool getIsBrewing();
    int getMenuOptionSelection();

    // Setters
    void setIsBrewing(bool brewing);
    void setMenuOptionSelection(int selection);
  
};
