#ifndef OBJECT_HPP
#define OBJECT_HPP

#include <../include/SceneNode.hpp>


class Object : public SceneNode
{
	public:
		void				setVelocity(sf::Vector2f velocity);
		void				setVelocity(float vx, float vy);
		void				accelerate(sf::Vector2f velocity);
		void				accelerate(float vx, float vy);
		sf::Vector2f		getVelocity() const;


	private:
		virtual void		updateCurrent(sf::Time dt);


	private:
		sf::Vector2f		mVelocity;
};

#endif // OBJECT_HPP