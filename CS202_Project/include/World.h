#pragma once

#ifndef WORLD_H
#define WORLD_H

#include "ResourceHolder.h"
#include "ResourceIdentifiers.h"
#include "Save.h"
#include "Load.h"

// #include "SceneNode.hpp"
// #include "SpriteNode.hpp"
// #include "Aircraft.hpp"
// #include "CommandQueue.hpp"
// #include "Command.hpp"

#include <SFML/System/Time.hpp>
#include <SFML/System/NonCopyable.hpp>
#include <SFML/Graphics/View.hpp>
#include <SFML/Graphics/Texture.hpp>

#include <array>
#include <queue>


// Forward declaration
namespace sf
{
	class RenderWindow;
}

class World : private sf::NonCopyable
{
	public:
		explicit							World(sf::RenderWindow& window);
		// void								update(sf::Time dt);
		// void								draw();
		
		// CommandQueue&						getCommandQueue();

	friend class SaveState;
	friend class LoadState;

	private:
		void								loadTextures();
		// void								buildScene();
		// void								adaptPlayerPosition();
		// void								adaptPlayerVelocity();

	private:
		sf::RenderWindow&					mWindow;
		sf::View							mWorldView;
		TextureHolder						mTextures;

		// SceneNode							mSceneGraph;
		// std::array<SceneNode*, LayerCount>	mSceneLayers;
		// CommandQueue						mCommandQueue;
		int 								a;

		sf::FloatRect						mWorldBounds;
		sf::Vector2f						mSpawnPosition;
		float								mScrollSpeed;
		// Aircraft*							mPlayerAircraft;
};

#endif // WORLD_H