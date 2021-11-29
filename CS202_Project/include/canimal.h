#pragma once

#ifndef CANIMAL_H_
#define CANIMAL_H_
class CANIMAL {
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

#endif // !CANIMAL_H_