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

enum InterfaceState {
  MENU = 0,
  BREW = 1,
  SETTING = 2,
  SCHEDULE = 3,
  ERRORS = 4,
  INTERFACE_SELECTIONS = 5
};

enum MenuState {
  MENU_BREW = 0,
  MENU_SETTINGS = 1,
  MENU_SCHEDULE = 2,
  MENU_SELECTIONS = 3
};

enum BrewState {
  BREWING = 0,
  BREWING_SELECTIONS = 1
};

enum SettingsState {
  SETTINGS_ALARM_NOISE = 0,
  SETTINGS_SELECTIONS = 1
};

enum SchedulingState{
  SCHEDULING = 0,
  SCHEDULING_SELECTIONS = 1
};

enum ErrorState {
  LOW_WATER = 0,
  NO_COFFEE_POT = 1,
  FINISHED_BREWING = 2,
  ERROR_SELECTIONS = 3
};

class Model{
  private:

    InterfaceState interfaceState;
    MenuState menuState;
    BrewState brewState;
    SettingsState settingsState;
    SchedulingState schedulingState;
    ErrorState errorState;
    
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
    bool potPresent;
    bool brewRequested;
    bool alarmToggle;

    // Notify the observers of the changes to the model
    void notifyObservers();

    // Update the display text
    void updateDisplayText();

    char *MENU_BREW_STRING = "Brew Coffee";
    char *MENU_SETTINGS_STRING = "Settings";
    char *MENU_SCHEDULE_STRING = "Schedule";

    char *MENU_STRINGS[MenuState::MENU_SELECTIONS] = {MENU_BREW_STRING, MENU_SETTINGS_STRING, MENU_SCHEDULE_STRING};
    
    char *BREW_BREWING_STRING = "Brewing Coffee";

    char *BREWING_STRINGS[BrewState::BREWING_SELECTIONS] = {BREW_BREWING_STRING};
    
    char *SETTINGS_ALARM_NOISE_STRING = "Adjust Alarm";

    char *SETTINGS_STRINGS[SettingsState::SETTINGS_SELECTIONS] = {SETTINGS_ALARM_NOISE_STRING};

    char *SCHEDULING_SCHEDULE_STRING = "Schedule Brew";

    char *SCHEDULING_STRINGS[SchedulingState::SCHEDULING_SELECTIONS] = {SCHEDULING_SCHEDULE_STRING};

    char *ERROR_LOW_WATER = "LOW ON WATER";
    char *ERROR_NO_COFFEE_POT = "NO COFFEE POT";
    char *ERROR_FINISHED_BREWING = "FINISHED BREW";

    char *ERROR_STRINGS[ErrorState::ERROR_SELECTIONS] = {ERROR_LOW_WATER, ERROR_NO_COFFEE_POT, ERROR_FINISHED_BREWING};

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
    bool isPotPresent();
    bool isBrewRequested();
    bool getAlarmToggle();

    InterfaceState getInterfaceState();
    MenuState getMenuState();
    BrewState getBrewState();
    SettingsState getSettingsState();
    SchedulingState getSchedulingState();
    ErrorState getErrorState();

    // Setters
    void setIsBrewing(bool brewing);
    void setMenuOptionSelection(int selection);
    void setDisplayText(char *text);
    void setWaterLevelLow(bool level);
    void setPotPresent(bool present);
    void setBrewRequested(bool request);
    void setAlarmToggle(bool alarm);

    void setInterfaceState(InterfaceState interfaceState);
    void setMenuState(MenuState menuState);
    void setBrewState(BrewState brewState);
    void setSettingsState(SettingsState settingsState);
    void setSchedulingState(SchedulingState schedulingState);
    void setErrorState(ErrorState errorState);

    void setView(Observer *viewReference);
    void setRelay(Observer *relayReference);
  
};
