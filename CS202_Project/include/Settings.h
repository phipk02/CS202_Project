#pragma once

#pragma once

#ifndef SETTINGS_H
#define SETTINGS_H

#include "State.h"
#include "Game.h"
#include "Application.h"

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>


class SettingsState : public State
{
	public:
								SettingsState(StateStack& stack, Context context);

		virtual void			draw();
		virtual bool			update(sf::Time dt);
		virtual bool			handleEvent(const sf::Event& event);

		void					playSound();

		void					updateOptionText();


	private:
		enum OptionNames
		{
			Level,
            Sound,
			Return,
		};


	private:
		sf::Sprite				mBackgroundSprite;
        sf::Text                mStateName;
        sf::Text                mInstructionText;
        sf::Text                mLevel;
        sf::Text                mSound;

		std::vector<sf::Text>	mOptions;
		std::size_t				mOptionIndex;
};

#endif // SETTINGS_H