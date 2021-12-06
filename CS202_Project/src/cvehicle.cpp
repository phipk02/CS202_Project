#include <../include/CVEHICLE.h>
#include <../include/ResourceHolder.hpp>

#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderStates.hpp>


Textures::ID toTextureID(CVEHICLE::Type type)
{
	switch (type)
	{
		case CVEHICLE::Car:
			return Textures::Car;

		case CVEHICLE::Truck:
			return Textures::Truck;
	}
	return Textures::Bird;
}

CVEHICLE::CVEHICLE(Type type, const TextureHolder& textures)
: mType(type)
, mSprite(textures.get(toTextureID(type)))
{
	sf::FloatRect bounds = mSprite.getLocalBounds();
	mSprite.setOrigin(bounds.width / 2.f, bounds.height / 2.f);
}

void CVEHICLE::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(mSprite, states);
}

unsigned int CVEHICLE::getCategory() const
{
	return Category::Enemy;
}

// #include "../include/cvehicle.h"

// // CCAR

// CCAR::CCAR() {
//     vTexture.loadFromFile("path");
//     vSprite.setTexture(vTexture);
//     //vSprite.setScale();
//     //vSprite.setPosition(x, y);
//     //moveSpeed = ;
//     //canMove = ;
// }

// void CCAR::move() { 
//     if (canMove)
//      vSprite.move(moveSpeed*1.0, 0);
// }


// void CCAR::render(sf::RenderTarget* window) {
//     window->draw(vSprite);
// }

// const sf::FloatRect CCAR::getBounds() const {
//     return vSprite.getGlobalBounds();
// }

// void CCAR::checkCollision(CVEHICLE* other, TrafficLight* tl) { 
//     // stop when red light in front of or the previous car stop
//     if (vSprite.getGlobalBounds().intersects(tl->getBounds()) && !tl->isGreen()) {
//         canMove = false;
//         return;
//     }
    
//     if (other == nullptr) return;
//     if (moveSpeed > 0 &&
//         vSprite.getGlobalBounds().left + vSprite.getGlobalBounds().width + 10 >= other->getBounds().left) { 
//         canMove = false;
//         return;
//     }
//     if (moveSpeed < 0 &&
//         vSprite.getGlobalBounds().left <= other->getBounds().left + getBounds().width + 10) {
//             canMove = false;
//             return;
//         }
//     canMove = true;
// }

// // CTRUCK

// CTRUCK::CTRUCK() {
//     vTexture.loadFromFile("path");
//     vSprite.setTexture(vTexture);
//     //vSprite.setScale();
//     //vSprite.setPosition(x, y);
//     //moveSpeed = ;
//     //canMove = ;
   
// }

// void CTRUCK::move() {  
//     if (canMove)
//         vSprite.move(moveSpeed*1.0, 0);
// }

// void CTRUCK::render(sf::RenderTarget* window) {
//     window->draw(vSprite);
// }

// const sf::FloatRect CTRUCK::getBounds() const {
//     return vSprite.getGlobalBounds();
// }

// void CTRUCK::checkCollision(CVEHICLE* other, TrafficLight* tl) { 
//     // stop when red light in front of or the previous car stop
//     if (vSprite.getGlobalBounds().intersects(tl->getBounds()) && !tl->isGreen()) {
//         canMove = false;
//         return;
//     }
    
//     if (other == nullptr) return;
//     if (moveSpeed > 0 &&
//         vSprite.getGlobalBounds().left + vSprite.getGlobalBounds().width + 10 >= other->getBounds().left) { 
//         canMove = false;
//         return;
//     }
//     if (moveSpeed < 0 &&
//         vSprite.getGlobalBounds().left <= other->getBounds().left + getBounds().width + 10) {
//             canMove = false;
//             return;
//         }
//     canMove = true;
// }