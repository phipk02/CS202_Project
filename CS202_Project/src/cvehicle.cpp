#include "../include/cvehicle.h"

// CCAR

CCAR::CCAR() {
    vTexture.loadFromFile("path");
    vSprite.setTexture(vTexture);
    //vSprite.setScale();
    //vSprite.setPosition(x, y);
    //moveSpeed = ;
    //canMove = ;
}

void CCAR::move() { 
    if (canMove)
     vSprite.move(moveSpeed*1.0, 0);
}


void CCAR::render(sf::RenderTarget* window) {
    window->draw(vSprite);
}

const sf::FloatRect CCAR::getBounds() const {
    return vSprite.getGlobalBounds();
}

void CCAR::checkCollision(CVEHICLE* other, TrafficLight* tl) { 
    // stop when red light in front of or the previous car stop
    if (vSprite.getGlobalBounds().intersects(tl->getBounds()) && !tl->isGreen()) {
        canMove = false;
        return;
    }
    
    if (other == nullptr) return;
    if (moveSpeed > 0 &&
        vSprite.getGlobalBounds().left + vSprite.getGlobalBounds().width + 10 >= other->getBounds().left) { 
        canMove = false;
        return;
    }
    if (moveSpeed < 0 &&
        vSprite.getGlobalBounds().left <= other->getBounds().left + getBounds().width + 10) {
            canMove = false;
            return;
        }
    canMove = true;
}

// CTRUCK

CTRUCK::CTRUCK() {
    vTexture.loadFromFile("path");
    vSprite.setTexture(vTexture);
    //vSprite.setScale();
    //vSprite.setPosition(x, y);
    //moveSpeed = ;
    //canMove = ;
   
}

void CTRUCK::move() {  
    if (canMove)
        vSprite.move(moveSpeed*1.0, 0);
}

void CTRUCK::render(sf::RenderTarget* window) {
    window->draw(vSprite);
}

const sf::FloatRect CTRUCK::getBounds() const {
    return vSprite.getGlobalBounds();
}

void CTRUCK::checkCollision(CVEHICLE* other, TrafficLight* tl) { 
    // stop when red light in front of or the previous car stop
    if (vSprite.getGlobalBounds().intersects(tl->getBounds()) && !tl->isGreen()) {
        canMove = false;
        return;
    }
    
    if (other == nullptr) return;
    if (moveSpeed > 0 &&
        vSprite.getGlobalBounds().left + vSprite.getGlobalBounds().width + 10 >= other->getBounds().left) { 
        canMove = false;
        return;
    }
    if (moveSpeed < 0 &&
        vSprite.getGlobalBounds().left <= other->getBounds().left + getBounds().width + 10) {
            canMove = false;
            return;
        }
    canMove = true;
}