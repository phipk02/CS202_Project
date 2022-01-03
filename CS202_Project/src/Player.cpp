#include "../include/Player.h"
#include "../include/Utility.h"

#include <math.h>

Player::Player(const TextureHolder& textures) {
    mSprite.setTexture(textures.get(Textures::Player));
    mSprite.setTextureRect(sf::IntRect(0, 0, 16, 16));
    centerOrigin(mSprite);
    mSprite.setScale(2.5f, 2.5f);
    mSprite.setPosition(450.f, 580.f);
    mSpeed = 500.f;
    mStatus = Status::Running;
    setVelocity(0.f, 0.f);
};

void Player::setStatus(const Player::Status& status) {
    mStatus = status;
};

Player::Status Player::getStatus() {
    return mStatus;
};

sf::Vector2f Player::getPosition() {
    return mSprite.getPosition();
};

void Player::draw(sf::RenderWindow& window) {
    window.draw(mSprite);
};

void Player::load(float x, float y) {
    mSprite.setPosition(x, y);
};

void Player::setVelocity(float x, float y) {
    mVelocity.x = x;
    mVelocity.y = y;
};

void Player::setVelocity(sf::Vector2f& other) {
    mVelocity.x = other.x;
    mVelocity.y = other.y;
}

void Player::accelerate(float x, float y) {
    mVelocity.x += x;
    mVelocity.y += y;
};

void Player::accelerate(sf::Vector2f& other) {
    mVelocity.x += other.x;
    mVelocity.y += other.y;
};

void Player::update(sf::Time dt) {
    // std::cout << "Player update " << dt.asSeconds() << "\n";
    if (mVelocity.x != 0.f && mVelocity.y != 0.f) {
        mVelocity.x /= std::sqrt(2.f);
        mVelocity.y /= std::sqrt(2.f);
    }
    mSprite.move(mVelocity.x * mSpeed * dt.asSeconds(), mVelocity.y * mSpeed * dt.asSeconds());
}

void Player::setPosition(sf::Vector2f& other) {
    mSprite.setPosition(other);
};

void Player::setPosition(float x, float y) {
    mSprite.setPosition(x, y);
};

const sf::FloatRect Player::getBound() {
    return mSprite.getGlobalBounds();
};
