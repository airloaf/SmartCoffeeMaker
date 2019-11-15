#pragma once

#include "Observer.h"

#define NUM_OBSERVERS 2

enum InputState {
  CLOCK_WISE_TURN,
  COUNTER_CLOCK_WISE_TURN,
  SINGLE_CLICK,
  DOUBLE_CLICK,
  NONE
};

class Model{
  private:
    // The observers for the model
    Observer *observers[NUM_OBSERVERS];

    Observer *view;
    Observer *relay;

    InputState inputState;

    bool isBrewing;
    int menuOptionSelection;
    int numObservers;

    char *displayText;

    bool waterLevelLow;

    // Notify the observers of the changes to the model
    void notifyObservers();

  public:
    Model();

    // Add observer to the model
    void addObserver(Observer *observer);

    // Set the input
    void setInputState(InputState nextInputState);
    void resetInputState();

    // Getters
    bool getIsBrewing();
    int getMenuOptionSelection();
    InputState getInputState();
    char *getDisplayText();
    bool getWaterLevelLow();

    // Setters
    void setIsBrewing(bool brewing);
    void setMenuOptionSelection(int selection);
    void setDisplayText(char *text);
    void setWaterLevelLow(bool level);

    void setView(Observer *viewReference);
    void setRelay(Observer *relayReference);
  
};
