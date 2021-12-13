#include "canimal.h"

void CANIMAL::move() {
    aSprite.move(velocity, 0);
}

void CANIMAL::render(sf::RenderWindow* window) {
    window->draw(aSprite);
}

const sf::FloatRect CANIMAL::getBound() const {
    return aSprite.getGlobalBounds();
}

CDINOSAUR::CDINOSAUR(int level, float offsetY) {
    aTexture.loadFromFile("asset\\dino.png", sf::IntRect(5, 5, 15, 15));
    aSprite.setTexture(aTexture);
    aSprite.setScale(2.5, 2.5);
    velocity = 0.09 * level;
    aSprite.setPosition(-50, offsetY);
}

CBIRD::CBIRD(int level, float offsetY) {
    aTexture.loadFromFile("asset\\people.png", sf::IntRect(168, 128, 16, 16));
    aSprite.setTexture(aTexture);
    aSprite.setScale(1.3, 1.3);
    velocity = - 0.12 * level;
    aSprite.setPosition(970, offsetY);
}





// #include "../include/canimal.h"
// #include "../include/ResourceHolder.hpp"

// #include <SFML/Graphics/RenderTarget.hpp>
// #include <SFML/Graphics/RenderStates.hpp>


// Textures::ID toTextureID(CANIMAL::Type type)
// {
// 	switch (type)
// 	{
// 		case CANIMAL::Bird:
// 			return Textures::Bird;

// 		case CANIMAL::Dinosaur:
// 			return Textures::Dinosaur;
// 	}
// 	return Textures::Bird;
// }

// CANIMAL::CANIMAL(Type type, const TextureHolder& textures)
// : mType(type)
// , mSprite(textures.get(toTextureID(type)))
// {
// 	sf::FloatRect bounds = mSprite.getLocalBounds();
// 	mSprite.setOrigin(bounds.width / 2.f, bounds.height / 2.f);
// }

// void CANIMAL::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const
// {
// 	target.draw(mSprite, states);
// }

// unsigned int CANIMAL::getCategory() const
// {
// 	return Category::Enemy;
// }