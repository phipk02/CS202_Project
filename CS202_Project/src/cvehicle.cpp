#include "cvehicle.h"

TrafficLight::TrafficLight() {
    RedLight.loadFromFile("asset\\traffic light.png", sf::IntRect(121, 0, 120, 191));
    GreenLight.loadFromFile("asset\\traffic light.png", sf::IntRect(0, 0, 120, 191));
    state = true;
    tlSprite.setTexture(GreenLight);
    tlSprite.setScale(0.15, 0.15);
}

void TrafficLight::setPosition(float x, float y) {
    tlSprite.setPosition(x, y);
}

void TrafficLight::render(sf::RenderWindow* window) {
    window->draw(tlSprite);
}

void TrafficLight::switchLight() {
    state = !state;
    if (state) 
        tlSprite.setTexture(GreenLight);
    else
        tlSprite.setTexture(RedLight);
}

bool TrafficLight::isGreen() {
    return state;
}

const sf::FloatRect TrafficLight::getBound() const {
    return tlSprite.getGlobalBounds();
}


void CVEHICLE::move() {
    if (canMove)
    vSprite.move(velocity, 0);
}

void CVEHICLE::render(sf::RenderWindow* window) {
    window->draw(vSprite);
}

void CVEHICLE::checkCollision(CVEHICLE* previous, TrafficLight* trl) {
    /*
    if (vSprite.getGlobalBounds().intersects(previous->getBound())
        || (!trl->isGreen() && vSprite.getGlobalBounds().intersects(trl->getBound()))) {
                canMove = false;
    }
    canMove = true;
    */
}

const sf::FloatRect CVEHICLE::getBound() const {
    return vSprite.getGlobalBounds();
}

CCAR::CCAR(int level, float offsetY) {
    vTexture.loadFromFile("asset\\car.png");
    vSprite.setTexture(vTexture);
    vSprite.setScale(0.07f, 0.07f);

    velocity = -0.1 * level;
    canMove = true;
    vSprite.setPosition(970, offsetY);
} 

void CCAR::checkCollision(CVEHICLE* previous, TrafficLight* trl) {
    if (!trl->isGreen() && vSprite.getGlobalBounds().intersects(trl->getBound())) {
        canMove = false;
    }
    else if (previous != nullptr && vSprite.getGlobalBounds().left  - 10 <= previous->getBound().left + previous->getBound().width) {
        canMove = false;
    }
    else
        canMove = true;
}

CTRUCK::CTRUCK(int level, float offsetY) {
    vTexture.loadFromFile("asset\\truck.png");
    vSprite.setTexture(vTexture);
    vSprite.setScale(0.2f, 0.2f);

    velocity = 0.088 * level;
    canMove = 1;
    vSprite.setPosition(-50, offsetY);
}

void CTRUCK::checkCollision(CVEHICLE* previous, TrafficLight* trl) {
    if (!trl->isGreen() && vSprite.getGlobalBounds().intersects(trl->getBound())) {
        canMove = false;
    }
    else if (previous != nullptr && vSprite.getGlobalBounds().left + vSprite.getGlobalBounds().width +10 >= previous->getBound().left) {
        canMove = false;
    }
    else
        canMove = true;
}

// #include "../include/CVEHICLE.h"
// #include "../include/ResourceHolder.hpp"

// #include <SFML/Graphics/RenderTarget.hpp>
// #include <SFML/Graphics/RenderStates.hpp>


// Textures::ID toTextureID(CVEHICLE::Type type)
// {
// 	switch (type)
// 	{
// 		case CVEHICLE::Car:
// 			return Textures::Car;

// 		case CVEHICLE::Truck:
// 			return Textures::Truck;
// 	}
// 	return Textures::Bird;
// }

// CVEHICLE::CVEHICLE(Type type, const TextureHolder& textures)
// : mType(type)
// , mSprite(textures.get(toTextureID(type)))
// {
// 	sf::FloatRect bounds = mSprite.getLocalBounds();
// 	mSprite.setOrigin(bounds.width / 2.f, bounds.height / 2.f);
// }

// void CVEHICLE::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const
// {
// 	target.draw(mSprite, states);
// }

// unsigned int CVEHICLE::getCategory() const
// {
// 	return Category::Enemy;
// }

// // #include "../include/cvehicle.h"

// // // CCAR

// // CCAR::CCAR() {
// //     vTexture.loadFromFile("path");
// //     vSprite.setTexture(vTexture);
// //     //vSprite.setScale();
// //     //vSprite.setPosition(x, y);
// //     //moveSpeed = ;
// //     //canMove = ;
// // }

// // void CCAR::move() { 
// //     if (canMove)
// //      vSprite.move(moveSpeed*1.0, 0);
// // }


// // void CCAR::render(sf::RenderTarget* window) {
// //     window->draw(vSprite);
// // }

// // const sf::FloatRect CCAR::getBounds() const {
// //     return vSprite.getGlobalBounds();
// // }

// // void CCAR::checkCollision(CVEHICLE* other, TrafficLight* tl) { 
// //     // stop when red light in front of or the previous car stop
// //     if (vSprite.getGlobalBounds().intersects(tl->getBounds()) && !tl->isGreen()) {
// //         canMove = false;
// //         return;
// //     }
    
// //     if (other == nullptr) return;
// //     if (moveSpeed > 0 &&
// //         vSprite.getGlobalBounds().left + vSprite.getGlobalBounds().width + 10 >= other->getBounds().left) { 
// //         canMove = false;
// //         return;
// //     }
// //     if (moveSpeed < 0 &&
// //         vSprite.getGlobalBounds().left <= other->getBounds().left + getBounds().width + 10) {
// //             canMove = false;
// //             return;
// //         }
// //     canMove = true;
// // }

// // // CTRUCK

// // CTRUCK::CTRUCK() {
// //     vTexture.loadFromFile("path");
// //     vSprite.setTexture(vTexture);
// //     //vSprite.setScale();
// //     //vSprite.setPosition(x, y);
// //     //moveSpeed = ;
// //     //canMove = ;
   
// // }

// // void CTRUCK::move() {  
// //     if (canMove)
// //         vSprite.move(moveSpeed*1.0, 0);
// // }

// // void CTRUCK::render(sf::RenderTarget* window) {
// //     window->draw(vSprite);
// // }

// // const sf::FloatRect CTRUCK::getBounds() const {
// //     return vSprite.getGlobalBounds();
// // }

// // void CTRUCK::checkCollision(CVEHICLE* other, TrafficLight* tl) { 
// //     // stop when red light in front of or the previous car stop
// //     if (vSprite.getGlobalBounds().intersects(tl->getBounds()) && !tl->isGreen()) {
// //         canMove = false;
// //         return;
// //     }
    
// //     if (other == nullptr) return;
// //     if (moveSpeed > 0 &&
// //         vSprite.getGlobalBounds().left + vSprite.getGlobalBounds().width + 10 >= other->getBounds().left) { 
// //         canMove = false;
// //         return;
// //     }
// //     if (moveSpeed < 0 &&
// //         vSprite.getGlobalBounds().left <= other->getBounds().left + getBounds().width + 10) {
// //             canMove = false;
// //             return;
// //         }
// //     canMove = true;
// // }