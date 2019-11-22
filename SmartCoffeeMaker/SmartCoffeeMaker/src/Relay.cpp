#include "Relay.h"
#include <Arduino.h>

#define RELAY_PIN 8

Relay::Relay(){
    pinMode(RELAY_PIN, OUTPUT);
    digitalWrite(RELAY_PIN, HIGH);
}

void Relay::setModel(Model *modelReference){
    model = modelReference;
}

void Relay::onNotify(){

    // Check if the brew was requested
    if(model->isBrewRequested()){

        // turn off the brew request
        model->setBrewRequested(false);

        // Check if the brew can occur
        bool waterLevelLow = model->getWaterLevelLow();
        bool potPresent = model->isPotPresent();

        // Check if there is water and a pot is present
        if(!waterLevelLow && potPresent){
            // Turn on the coffee machine
            digitalWrite(RELAY_PIN, LOW);

            // Set the model to brewing
            model->setInterfaceState(InterfaceState::BREW);
            model->setIsBrewing(true);
            return;
        }else if(waterLevelLow){
            Serial.println("Water Level Is Low");
            model->setErrorState(ErrorState::LOW_WATER);
            model->setInterfaceState(InterfaceState::ERRORS);
        }else if(!potPresent){
            model->setErrorState(ErrorState::NO_COFFEE_POT);
            model->setInterfaceState(InterfaceState::ERRORS);
            Serial.println("Pot is not present");
        }

    }

    // Check if we are brewing
    if(model->getIsBrewing()){
        // Check if the water level is low
        if(model->getWaterLevelLow()){

            // Turn off brewing
            model->setIsBrewing(false);

            // Set the errors
            model->setErrorState(ErrorState::FINISHED_BREWING);

            // Set the interface state to the menu
            model->setInterfaceState(InterfaceState::ERRORS);

            model->setAlarmToggle(true);

            // Turn off the relay
            digitalWrite(RELAY_PIN, HIGH);
        }else if(!model->isPotPresent()){

            // Turn off brewing
            model->setIsBrewing(false);
            
            // Set error text
            model->setErrorState(ErrorState::NO_COFFEE_POT);

            // Set the interface state to the menu
            model->setInterfaceState(InterfaceState::ERRORS);

            // Turn off the relay
            digitalWrite(RELAY_PIN, HIGH);
        }
    }

}