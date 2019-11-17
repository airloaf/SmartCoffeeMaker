#pragma once

#include <ClickEncoder.h>
#include <Wire.h>
#include <TimerOne.h>

#include "Model.h"

class UserInput {
    private:
        int16_t last, value;

        Model *model;

        void handleCWTurn();
        void handleCCWTurn();
        void handleClick();
        void handleDoubleClick();

    public:
        UserInput();

        // Loop the user input
        void loop();

        // Set the model reference
        void setModel(Model *modelReference);

};