#include <../include/Object.hpp>


void Object::setVelocity(sf::Vector2f velocity)
{
	mVelocity = velocity;
}

void Object::setVelocity(float vx, float vy)
{
	mVelocity.x = vx;
	mVelocity.y = vy;
}

sf::Vector2f Object::getVelocity() const
{
	return mVelocity;
}

void Object::accelerate(sf::Vector2f velocity)
{
	mVelocity += velocity;
}

void Object::accelerate(float vx, float vy)
{
	mVelocity.x += vx;
	mVelocity.y += vy;
}

void Object::updateCurrent(sf::Time dt)
{	
	move(mVelocity * dt.asSeconds());
}