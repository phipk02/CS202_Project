#pragma once

#include "cvehicle.h"
#include "canimal.h"

class CPEOPLE : public COBJECT
{
    bool mState;
public:
    CPEOPLE();
    void moveUp(int);
    void moveLeft(int);
    void moveRight(int);
    void moveDown(int);
    bool isImpact(const CVEHICLE*&);
    bool isImpact(const CANIMAL*&);
    bool isFinish();
    bool isDead();
};