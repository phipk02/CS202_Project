#pragma once

#ifndef MENUSTATE_H
#define MENUSTATE_H

#include "State.h"
#include "Application.h"

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>


class MenuState : public State
{
	public:
								MenuState(StateStack& stack, Context context);

		virtual void			draw();
		virtual bool			update(sf::Time dt);
		virtual bool			handleEvent(const sf::Event& event);

		void					playSound();

		void					updateOptionText();


	private:
		enum OptionNames
		{
			NewGame,
            LoadGame,
            Settings,
			Exit,
		};


	private:
		sf::Sprite				mBackgroundSprite;
		sf::Text				mStateName;

		std::vector<sf::Text>	mOptions;
		std::size_t				mOptionIndex;
};

#endif // BOOK_MENUSTATE_HPP