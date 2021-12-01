#pragma once

#include "cvehicle.h"
#include "canimal.h"

class CPEOPLE : public COBJECT
{
    bool mState;
    sf::Texture pTexture;
    sf::Sprite pSprite;
    float moveSpeed;
public:
    CPEOPLE();
    void moveUp();
    void moveLeft();
    void moveRight();
    void moveDown();
    bool isImpact(const CVEHICLE*&);
    bool isImpact(const CANIMAL*&);
    bool isFinish();
    bool isDead();
    void render(sf::RenderTarget*);
};