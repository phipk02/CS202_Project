#pragma once

#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "State.h"
// #include "Save.h"
// #include "Load.h"
// #include "World.h"
// #include "Player.h"

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>

// class SaveState;
// class LoadState;
// class SettingsState;

class GameState : public State
{
	public:
							GameState(StateStack& stack, Context context);

		virtual void		draw();
		virtual bool		update(sf::Time dt);
		virtual bool		handleEvent(const sf::Event& event);

		static void			changeLevel(int _level);
		static int 			getLevel();

		static void 		save(const std::string& filename);
		static void 		load(const std::string& filename);


	private:
		static int 			level;
		// static World*		mWorld;
		// Player&				mPlayer;
};

#endif // GAMESTATE_H