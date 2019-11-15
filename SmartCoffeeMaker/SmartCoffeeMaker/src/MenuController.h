#pragma once

#include "Model.h"
#include "Controller.h"

class MenuController{

    enum MenuState {
        MAIN_MENU = 0,
        BREWING = 1,
        NUM_MENU_STATES = 2
    };

    enum MainMenuSelection {
        BREW_COFFEE = 0,
        SETTINGS = 1,
        NUM_SELECTIONS = 2
    };

    const char *BREW_TEXT = "Brew Coffee";
    const char *SETTINGS_TEXT = "Settings";
    const char *BREWING_TEXT = "Brewing Coffee";

    const char *MainMenuStrings[2] = {BREW_TEXT, SETTINGS_TEXT};

    public:
        MenuController();

        void doubleClickPress();
        void singleClickPress();
        void cwTurn();
        void ccwTurn();

        void setModel(Model *modelReference);
        void displayText();

    private:
        Model *model;

        MenuState menuState;
        MainMenuSelection mainMenuSelection;

};