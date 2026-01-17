#ifndef IACTUATOR_H 
#define IACTUATOR_H

class IActuator {
public:
    virtual ~IActuator() = default;
    virtual void command(int value) = 0;
};  

#endif