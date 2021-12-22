#pragma once

#ifndef SAVESTATE_H
#define SAVESTATE_H

#include "State.h"
#include "Game.h"
#include "Application.h"

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>

#include <string>
#include <filesystem>


class SaveState : public State
{
	public:
								SaveState(StateStack& stack, Context context);

		virtual void			draw();
		virtual bool			update(sf::Time dt);
		virtual bool			handleEvent(const sf::Event& event);

		void					playSound();

		void					updateOptionText();
        void                    save(const std::string& filename);


	private:
		enum OptionNames
		{
			Slot1,
            Slot2,
            Slot3,
            Return,
		};

		enum OptionNext {
			Continue,
			ReturnMainMenu,
		};

	private:
		sf::Sprite				mBackgroundSprite;
        sf::Text                finishText;
		sf::Text				mStateName;

		std::vector<sf::Text>	mOptions;
		std::size_t				mOptionIndex;

		std::vector<sf::Text>	mNextOptions;
		std::size_t				mNextOptionsIndex;

        bool                    isFinished;
};

#endif // SAVESTATE_H