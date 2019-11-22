#include "WaterSensor.h"
#include "Arduino.h"

#define WATER_SENSOR_PIN A3

#define READING_THRESHOLD 1020

WaterSensor::WaterSensor(){
    numReadings = 0;
    model = nullptr;
    sumReadings = 0;
}

void WaterSensor::updateSensor(){

    sumReadings += analogRead(WATER_SENSOR_PIN);
    numReadings++;

    // Check if the number of readings exceeds the
    // maximum number of readings
    if(numReadings == NUM_READINGS){
        numReadings = 0;

        Serial.println(sumReadings);
        long expected = ((long) NUM_READINGS) * (long) 1023;
        Serial.println(expected);
        Serial.println(analogRead(WATER_SENSOR_PIN));

        bool waterLevelLow = (sumReadings >= (expected-NUM_READINGS*2));

        if(model != nullptr){
            model->setWaterLevelLow(waterLevelLow);
        }

        sumReadings = 0;
    }

}

void WaterSensor::setModel(Model *modelReference){
    model = modelReference;
}