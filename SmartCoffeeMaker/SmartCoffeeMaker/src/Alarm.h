#pragma once

#define BUZZER 3

#include "Model.h"

class Alarm {

    private:

        Model *model;

        long periodTime;
        long startTime;

        bool alarmToggled;
        bool periodOn;

    public:

        Alarm();

        void update();
        void setModel(Model *model);

};