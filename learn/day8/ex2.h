#ifndef SYSTEM_H
#define SYSTEM_H

#include <memory>
#include "Sensor.h"

class System{
    public:
        System();
        void update();

    private:
        std::unique_ptr<Sensor> sensor;
};

#endif