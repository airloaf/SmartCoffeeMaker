#pragma once

#include "Model.h"

class Controller{
    public:
        void setModel(Model *modelReference);

    protected:
        Model *model;
};