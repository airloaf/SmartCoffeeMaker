#pragma once

#define NUM_READINGS 5

#include "Model.h"

class WaterSensor{

    public:
        WaterSensor();

        void updateSensor();
        void setModel(Model *model);

    private:
        int sensorReadings[NUM_READINGS];
        int numReadings;

        Model *model;

};