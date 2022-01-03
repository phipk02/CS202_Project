#pragma once

#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "State.h"
#include "Player.h"
#include "Enemy.h"
#include "Utility.h"

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>

#include <vector>
#include <map>

//class Enemy;

class GameState : public State
{
	public:
							GameState(StateStack& stack, Context context);
							~GameState();

		virtual void		draw();
		virtual bool		update(sf::Time dt);
		virtual bool		handleEvent(const sf::Event& event);

		void				buildScene();
		void				adaptPlayerPosition();
		void				checkCollisions();
		void				reachFinishLine();

		void 				spawnEnemies(int index);
		void 				destroyEnemiesOutsideView();

		static void			changeLevel(int _level);
		static int 			getLevel();

		static void 		save(const std::string& filename);
		static void 		load(const std::string& filename);

	private:
		static int 				level;

		static Player*					mPlayer;
		static std::vector<Enemy*>		mEnemies;

		static bool				mTrafficLight; // 1 red 0 green
		float					mLanes[6];
		static bool				mExisted[6];

		sf::Sprite				mBackground;
		sf::Text				mStaticLevel;
		sf::Text				mFinish;
		sf::Sprite				mLight;
		sf::Time				mLightCountdown;
};

#endif // BOOK_GAMESTATE_HPP