#pragma once

#include <cobject.h>

class CVEHICLE : public COBJECT {
    // bool state; // 0: moving, 1: stopped
protected:
    int mX, mY;
    friend class CGAME;
public:
    virtual void move(int, int);
    virtual void stop(bool);

    virtual void sound();
};

class CCAR : public CVEHICLE {
    public:
};

class CTRUCK : public CVEHICLE {
    public:
};