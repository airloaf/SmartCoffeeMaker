#include "PotSensor.h"
#include "Arduino.h"

#define SS_PIN 10
#define RST_PIN 9

PotSensor::PotSensor(){
    numReadings = 0;
    model = nullptr;
    sensor = new MFRC522(SS_PIN, RST_PIN);
    SPI.begin();
    sensor->PCD_Init();
    sensor->PCD_DumpVersionToSerial();

    previousSensorTime = millis();
}

// Delay for the sensor in millis
#define TIME_DELAY 300

void PotSensor::updateSensor(){

    long deltaTime = millis() - previousSensorTime;
    if(deltaTime < TIME_DELAY){
        return ;
    }

    previousSensorTime = millis();

    int cardPresent = 0;
    sensor->PICC_ReadCardSerial();
    sensor->PICC_IsNewCardPresent();
    if(! sensor->PICC_ReadCardSerial()){
    cardPresent = 0;
    }else{
    cardPresent = 1;
    }

    sensorReadings[numReadings] = cardPresent;
    numReadings++;

    // Check if the number of readings exceeds the
    // maximum number of readings
    if(numReadings == NUM_READINGS){
        numReadings = 0;

        bool potPresent = true;

        for(int readingIndex = 0; readingIndex < NUM_READINGS; readingIndex++){
            if(sensorReadings[readingIndex] == 0){
                potPresent = false;
            }
        }

        Serial.println(potPresent);

        if(model != nullptr){
            model->setPotPresent(potPresent);
        }
    }

}

void PotSensor::setModel(Model *modelReference){
    model = modelReference;
}