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
    // Set to brew
    if(model->getIsBrewing() && !model->getWaterLevelLow()){
        digitalWrite(RELAY_PIN, HIGH);
    }else{
        digitalWrite(RELAY_PIN, LOW);
    }
}