#pragma once

#include "cobject.h"

class CVEHICLE : public COBJECT {
    // bool state; // 0: moving, 1: stopped
protected:
    int mX, mY;
    friend class CGAME;
public:
    virtual void move(int, int) = 0;
};

class CCAR : public CVEHICLE {
public:
    void move(int, int);
};

class CTRUCK : public CVEHICLE {
public:
    void move(int, int);
};