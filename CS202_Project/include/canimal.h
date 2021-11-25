#pragma once

#include "cobject.h"

class CANIMAL : public COBJECT {
public:
    virtual void move(int, int) = 0;

    virtual void tell() = 0;
};

class CDINOSAUR: public CANIMAL {
public:
    void move(int, int);

    void tell();
};

class CBIRD: public CANIMAL {
public:
    void move(int, int);

    void tell();    
};