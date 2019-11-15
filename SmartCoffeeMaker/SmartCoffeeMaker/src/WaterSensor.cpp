#include "WaterSensor.h"
#include "Arduino.h"

#define WATER_SENSOR_PIN A3

#define READING_THRESHOLD 1020

WaterSensor::WaterSensor(){
    numReadings = 0;
    model = nullptr;
}

void WaterSensor::updateSensor(){

    sensorReadings[numReadings] = analogRead(WATER_SENSOR_PIN);
    numReadings++;

    // Check if the number of readings exceeds the
    // maximum number of readings
    if(numReadings == NUM_READINGS){
        numReadings = 0;

        bool waterLevelLow = true;

        for(int readingIndex = 0; readingIndex < NUM_READINGS; readingIndex++){
            if(sensorReadings[readingIndex] < READING_THRESHOLD){
                waterLevelLow = false;
            }
        }


        if(model != nullptr){
            model->setWaterLevelLow(waterLevelLow);
        }
    }

}

void WaterSensor::setModel(Model *modelReference){
    model = modelReference;
}