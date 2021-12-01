#pragma once

#include "cvehicle.h"
#include "canimal.h"

class CPEOPLE : public COBJECT
{
    bool mState; //false - die
    sf::Texture pTexture;
    sf::Sprite pSprite;
    float moveSpeed;
public:
    CPEOPLE();
    void moveUp(sf::RenderWindow&);
    void moveLeft(sf::RenderWindow&);
    void moveRight(sf::RenderWindow&);
    void moveDown(sf::RenderWindow&);
    bool isImpact(const CVEHICLE*&);
    bool isImpact(const CANIMAL*&);
    bool isFinish();
    bool isDead();
    void render(sf::RenderTarget*);
};