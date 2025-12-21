#ifndef SENSOR_H
#define SENSOR_H

class Sensor
{
public:
    Sensor();
    int readValue() const;

private:
    int value;
};  

#endif 