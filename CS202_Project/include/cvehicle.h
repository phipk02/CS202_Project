#pragma once

#ifndef CVEHICLE_H_
#define CVEHICLE_H_
class CVEHICLE {
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

#endif // !CVEHICLE_H_