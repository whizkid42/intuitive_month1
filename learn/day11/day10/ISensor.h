#ifndef ISENSOR_H
#define ISENSOR_H

class ISensor {
public:
    virtual ~ISensor() = default;
    virtual int read() const = 0;
};      
#endif