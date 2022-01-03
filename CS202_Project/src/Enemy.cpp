#include "../include/Enemy.h"
#include "../include/Utility.h"

Enemy::Enemy(Enemy::Type type, const TextureHolder& textures, bool direction, float x, float y):
mType(type)
, mDirection(direction)
{
    if (type == Type::Bird) {
        mSprite.setTexture(textures.get(direction ? Textures::Bird1 : Textures::Bird2));
        mSprite.setTextureRect(direction ? sf::IntRect(64, 6, 31, 19) : sf::IntRect(192, 6, 31, 19));
        mSprite.setScale(1.34f, 2.f);
        mSpeed = 150.f;
    }
    else if (type == Type::Car) {
        mSprite.setTexture(textures.get(direction ? Textures::Car1 : Textures::Car2));
        mSprite.setScale(0.07f, 0.1f);
        mSpeed = 300.f;
    }
    else if (type == Type::Dinosaur) {
        mSprite.setTexture(textures.get(direction ? Textures::Dinosaur1 : Textures::Dinosaur2));
        mSprite.setScale(2.5f, 2.5f);
        mSprite.setTextureRect(direction ? sf::IntRect(339, 4, 14, 16) : sf::IntRect(222, 4, 14, 16));
        mSpeed = 350.f;
    }
    else {
        mSprite.setTexture(textures.get(direction ? Textures::Truck1 : Textures::Truck2));
        mSprite.setScale(0.33f, 0.27f);
        mSpeed = 140.f;
    }

    centerOrigin(mSprite);
    mSprite.setPosition(x, y);
};

void Enemy::setPosition(float x, float y) {
    mSprite.setPosition(x, y);
};
// Enemy::~Enemy();

void Enemy::draw(sf::RenderWindow& windows) {
    windows.draw(mSprite);
};

sf::Vector2f Enemy::getPosition() {
    return mSprite.getPosition();
};

void Enemy::move(sf::Time dt, int level) {
    mSprite.move(mDirection ? (-mSpeed * dt.asSeconds() * level) : (mSpeed * dt.asSeconds() * level), 0);
};

// void Enemy::reset(sf::RenderWindow& windows) {
//     mSprite.setPosition(mDirection * (windows.getView().getSize().x), mSprite.getPosition().y);
// };

const Enemy::Type Enemy::getType() {
    return mType;
}

const sf::FloatRect Enemy::getBound() {
    return mSprite.getGlobalBounds();
};