#pragma once

#define NUM_READINGS 5

#include "Model.h"
#include <SPI.h>
#include <MFRC522.h>

class PotSensor{

    public:
        PotSensor();

        void updateSensor();
        void setModel(Model *model);

    private:
        int sensorReadings[NUM_READINGS];
        int numReadings;
        long previousSensorTime;

        Model *model;
        MFRC522 *sensor;

};