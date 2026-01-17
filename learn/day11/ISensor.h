#ifndef ISENSOR_H
#define ISENSOR_H

#include "SensorStatus.h"

class ISensor {
public:
    virtual ~ISensor() = default;
    virtual int read() const = 0;
    virtual SensorStatus status() const = 0;
};      
#endif