#pragma once

#include "Model.h"
#include "Observer.h"

#include <LiquidCrystal_I2C.h>

class View: public Observer{
  private:
    // LCD Display
    LiquidCrystal_I2C *lcd;

    Model *model;

    char *previousTopDisplayText;

  public:
    View();

    // Set the model for the view
    void setModel(Model *model);

    // The observer notify
    void onNotify();
};
