#pragma once

#include <ClickEncoder.h>
#include <Wire.h>
#include <TimerOne.h>

#include "Model.h"
#include "MenuController.h"

class UserInput {
    private:
        int16_t last, value;

        Model *model;
        MenuController *menuController;

    public:
        UserInput();

        // Loop the user input
        void loop();

        // Set the model reference
        void setModel(Model *modelReference);

        void setMenuController(MenuController *controller);

};