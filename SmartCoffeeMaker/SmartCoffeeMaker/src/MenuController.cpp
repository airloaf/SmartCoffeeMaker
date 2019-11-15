#include "MenuController.h"

MenuController::MenuController(){
    // Set the menu to the main menu
    menuState = MenuState::MAIN_MENU;
    mainMenuSelection = MainMenuSelection::BREW_COFFEE;
}

void MenuController::doubleClickPress(){
    displayText();
}

void MenuController::singleClickPress(){
    if(menuState == MenuState::MAIN_MENU){
        if(mainMenuSelection == MainMenuSelection::BREW_COFFEE){
            menuState = MenuState::BREWING;
            model->setIsBrewing(true);
        }
    }else if(menuState == MenuState::BREWING){
        menuState = MenuState::MAIN_MENU;
        model->setIsBrewing(false);
    }
    displayText();
}

void MenuController::cwTurn(){
    displayText();
}

void MenuController::ccwTurn(){
    displayText();
}

void MenuController::displayText(){
    if(menuState == MenuState::MAIN_MENU){
        model->setDisplayText(MainMenuStrings[ mainMenuSelection]);
    }else if(menuState == MenuState::BREWING){
        model->setDisplayText(BREWING_TEXT);
    }
}

void MenuController::setModel(Model *modelReference){
    model = modelReference;
}