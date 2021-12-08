#pragma once

#pragma once

#ifndef LOADSTATE_H
#define LOADSTATE_H

#include "State.h"
#include "Game.h"

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>

#include <string>
#include <filesystem>


class LoadState : public State
{
	public:
								LoadState(StateStack& stack, Context context);

		virtual void			draw();
		virtual bool			update(sf::Time dt);
		virtual bool			handleEvent(const sf::Event& event);

		void					updateOptionText();
        void                    load(const std::string& filename);


	private:
		enum OptionNames
		{
			Slot1,
            Slot2,
            Slot3,
            Return,
		};


	private:
		sf::Sprite				mBackgroundSprite;
        sf::Text                finishText;
		sf::Text				mStateName;

		std::vector<sf::Text>	mOptions;
		std::size_t				mOptionIndex;

        bool                    existFile[3];
        bool                    isFinished;
};

#endif // LOADSTATE_H