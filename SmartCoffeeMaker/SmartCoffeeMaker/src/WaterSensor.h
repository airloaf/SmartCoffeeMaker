#pragma once

#define NUM_READINGS 10000

#include "Model.h"

class WaterSensor{

    public:
        WaterSensor();

        void updateSensor();
        void setModel(Model *model);

    private:
        long numReadings;
        long sumReadings;

        Model *model;

};