#ifndef SENSOR_H
#define SENSOR_H

class Sensor {
public:
    Sensor();
    int read() const;

private:
    int value;      

};

#endif