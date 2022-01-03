#pragma once

#ifndef RESOURCEIDENTIFIERS_H
#define RESOURCEIDENTIFIERS_H


// Forward declaration of SFML classes
namespace sf
{
	class Texture;
	class Font;
	class Level;
}

namespace Textures
{
	enum ID
	{
		Bird1,
		Bird2,
		Car1,
		Car2,
		Dinosaur1,
		Dinosaur2,
		Player,
		Truck1,
		Truck2,
		Background,
		GreenLight,
		RedLight,
		Road,
	};
}

namespace Fonts
{
	enum ID
	{
		Main,
	};
}

// Forward declaration and a few type definitions
template <typename Resource, typename Identifier>
class ResourceHolder;

typedef ResourceHolder<sf::Texture, Textures::ID>	TextureHolder;
typedef ResourceHolder<sf::Font, Fonts::ID>			FontHolder;

#endif // RESOURCEIDENTIFIERS_H