#ifndef SENSOR_H
#define SENSOR_H

#include "ISensor.h"

class Sensor : public ISensor {
public:
    Sensor();
    int read() const;

private:
    int value;      

};

#endif