#pragma once

#include <cobject.h>

class CPEOPLE : public COBJECT
{
    bool mState;
public:
    CPEOPLE();

    void up(int);
    void down(int);
    void left(int);
    void right(int);

    bool isImpact(const COBJECT *&);

    bool isFinish();
    bool isDead();
};