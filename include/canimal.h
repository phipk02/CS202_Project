#pragma once

#include "cobject.h"

class CANIMAL : public COBJECT {
public:
    virtual void move();

    virtual void sound();
};

class CDINOSAUR: public CANIMAL {
public:
    void move();

    void sound();
};

class CBIRD: public CANIMAL {
public:
    void move();

    void sound();    
};