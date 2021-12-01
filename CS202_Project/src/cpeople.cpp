#include "../include/CPEOPLE.h"

CPEOPLE::CPEOPLE() {
    // init Texture
    pTexture.loadFromFile("path");
    // init Sprite
    pSprite.setTexture(pTexture);
    //pSprite.scale(0,0);

    // init other variables
    moveSpeed = 0.2f;
    mState = true;

    // set initial position (start point in the game)
    //pSprite.setPosition(/*x, y*/);
}

void CPEOPLE::moveUp() {
    pSprite.move(0, -moveSpeed*1.0f);
}

void CPEOPLE::moveLeft() {
    pSprite.move(-moveSpeed*1.0f, 0);
}

void CPEOPLE::moveRight() {
    pSprite.move(+moveSpeed*1.0f, 0);
}

void CPEOPLE::moveDown() {
    pSprite.move(0, +moveSpeed*1.0f);
}

bool CPEOPLE::isImpact(const CVEHICLE*&) {

}

bool CPEOPLE::isImpact(const CANIMAL*&) {

}

bool CPEOPLE::isFinish() {

}

bool CPEOPLE::isDead() {
    return mState;
}

void CPEOPLE::render(sf::RenderTarget* window) {
    window->draw(pSprite);
}