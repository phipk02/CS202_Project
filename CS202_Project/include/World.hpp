#ifndef WORLD_HPP
#define WORLD_HPP

#include <../include/ResourceHolder.hpp>
#include <../include/ResourceIdentifiers.hpp>
#include <../include/SceneNode.hpp>
#include <../include/SpriteNode.hpp>
#include <../include/canimal.h>
#include <../include/cvehicle.h>
#include <../include/cpeople.h>
#include <../include/CommandQueue.hpp>
#include <../include/Command.hpp>

#include <SFML/System/NonCopyable.hpp>
#include <SFML/Graphics/View.hpp>
#include <SFML/Graphics/Texture.hpp>

#include <math.h>
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
		void								update(sf::Time dt);
		void								draw();

        CommandQueue&						getCommandQueue();

	private:
		void								loadTextures();
		void								buildScene();
        void								adaptPlayerPosition();
		void								adaptPlayerVelocity();


	private:
		enum Layer
		{
			Background,
			Lane,
			LayerCount
		};


	private:
		sf::RenderWindow&					mWindow;
		sf::View							mWorldView;
		TextureHolder						mTextures;

		SceneNode							mSceneGraph;
		std::array<SceneNode*, LayerCount>	mSceneLayers;
        CommandQueue						mCommandQueue;

		sf::FloatRect						mWorldBounds;
		sf::Vector2f						mSpawnPosition;
		float								mScrollSpeed;
		CPEOPLE*							mPlayer;
};

#endif // WORLD_HPP