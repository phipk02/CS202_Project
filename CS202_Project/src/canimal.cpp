#include <../include/canimal.h>
#include <../include/ResourceHolder.hpp>

#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderStates.hpp>


Textures::ID toTextureID(CANIMAL::Type type)
{
	switch (type)
	{
		case CANIMAL::Bird:
			return Textures::Bird;

		case CANIMAL::Dinosaur:
			return Textures::Dinosaur;
	}
	return Textures::Bird;
}

CANIMAL::CANIMAL(Type type, const TextureHolder& textures)
: mType(type)
, mSprite(textures.get(toTextureID(type)))
{
	sf::FloatRect bounds = mSprite.getLocalBounds();
	mSprite.setOrigin(bounds.width / 2.f, bounds.height / 2.f);
}

void CANIMAL::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(mSprite, states);
}

unsigned int CANIMAL::getCategory() const
{
	return Category::Enemy;
}