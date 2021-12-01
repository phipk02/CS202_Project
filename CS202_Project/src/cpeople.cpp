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

void CPEOPLE::moveUp(sf::RenderWindow& window) {
    if (pSprite.getGlobalBounds().top <=0 ) {
        pSprite.setPosition(pSprite.getGlobalBounds().left, 0.0f);
    } 
    else
        pSprite.move(0, -moveSpeed*1.0f);
}

void CPEOPLE::moveLeft(sf::RenderWindow& window) {
    if (pSprite.getGlobalBounds().left <=0 ) {
        pSprite.setPosition(0.0f, pSprite.getGlobalBounds().top);
    } 
    else
        pSprite.move(-moveSpeed * 1.0f, 0);
}

void CPEOPLE::moveRight(sf::RenderWindow& window) {
    if (pSprite.getGlobalBounds().left + pSprite.getGlobalBounds().width >= window.getSize().x) 
        pSprite.setPosition(window.getSize().x- pSprite.getGlobalBounds().width, pSprite.getGlobalBounds().top);
    else
        pSprite.move(+moveSpeed*1.0f, 0);
}

void CPEOPLE::moveDown(sf::RenderWindow& window) {
    if (pSprite.getGlobalBounds().top + pSprite.getGlobalBounds().height >= window.getSize().y)
		pSprite.setPosition(pSprite.getGlobalBounds().left, window.getSize().y - pSprite.getGlobalBounds().height);
    else
        pSprite.move(0, +moveSpeed*1.0f);
}

bool CPEOPLE::isImpact(const CVEHICLE*& vehicle) {
    if (pSprite.getGlobalBounds().intersects(vehicle->getBounds())) {
        mState = false;
        return true;
    }
    return false;
}

bool CPEOPLE::isImpact(const CANIMAL*&) {

}

bool CPEOPLE::isFinish() {

}

bool CPEOPLE::isDead() {
    return !mState;
}

void CPEOPLE::render(sf::RenderTarget* window) {
    window->draw(pSprite);
}