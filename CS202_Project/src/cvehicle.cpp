#include "../include/cvehicle.h"

// CCAR

CCAR::CCAR() {
    vTexture.loadFromFile("path");
    vSprite.setTexture(vTexture);
    //vSprite.setScale();

    //moveSpeed = ;

    //vSprite.setPosition(x, y);
}

void CCAR::move() { //from left to right
     vSprite.move(moveSpeed*1.0, 0);
}


void CCAR::render(sf::RenderTarget* window) {
    window->draw(vSprite);
}

const sf::FloatRect CCAR::getBounds() const {
    return vSprite.getGlobalBounds();
}

// CTRUCK

CTRUCK::CTRUCK() {
    vTexture.loadFromFile("path");
    vSprite.setTexture(vTexture);
    //vSprite.setScale();

    //moveSpeed = ;

    //vSprite.setPosition(x, y);
}

void CTRUCK::move() {  // from left to right
    vSprite.move(moveSpeed*1.0, 0);
}

void CTRUCK::render(sf::RenderTarget* window) {
    window->draw(vSprite);
}

const sf::FloatRect CTRUCK::getBounds() const {
    return vSprite.getGlobalBounds();
}