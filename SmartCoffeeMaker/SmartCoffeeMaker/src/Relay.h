#pragma once

#include "Observer.h"
#include "Model.h"

class Relay: public Observer{

    public:
        Relay();

        void setModel(Model *modelReference);
        void onNotify();

    private:
        Model *model;

};