#ifndef APPLICATION_H
#define APPLICATION_H

#include "ResourceHolder.h"
#include "ResourceIdentifiers.h"
#include "StateStack.h"
#include "Utility.h"
#include "State.h"
#include "StateStack.h"
#include "StateIdentifiers.h"
#include "Game.h"
#include "Menu.h"
#include "Pause.h"
#include "Loading.h"
#include "Save.h"
#include "Load.h"
#include "Settings.h"

#include <SFML/System/Time.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>


class Application
{
	public:
								Application();
		void					run();

		static bool				sound;
		
	private:
		void					processInput();
		void					update(sf::Time dt);
		void					render();

		void					updateStatistics(sf::Time dt);
		void					registerStates();


	private:
		static const sf::Time	TimePerFrame;

		sf::RenderWindow		mWindow;
		TextureHolder			mTextures;
	  	FontHolder				mFonts;

		StateStack*				mStateStack;

		sf::Text				mStatisticsText;
		sf::Time				mStatisticsUpdateTime;
		std::size_t				mStatisticsNumFrames;
};

#endif // APPLICATION_H