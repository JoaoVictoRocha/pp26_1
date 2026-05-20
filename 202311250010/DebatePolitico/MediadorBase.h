#ifndef MEDIADORBASE_H
#define MEDIADORBASE_H

#include "ConfiguraTempo.h"

class MediadorBase {
public:
    
    virtual void debate(ConfiguraTempo& config) = 0; 
    virtual ~MediadorBase() = default;
};

#endif