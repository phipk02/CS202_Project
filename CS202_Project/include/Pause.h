#pragma once

#ifndef PAUSESTATE_H
#define PAUSESTATE_H

#include "State.h"

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>


class PauseState : public State
{
	public:
								PauseState(StateStack& stack, Context context);

		virtual void			draw();
		virtual bool			update(sf::Time dt);
		virtual bool			handleEvent(const sf::Event& event);

		void					updateOptionText();

	private:
		enum {
			Continue,
			Save,
			Load,
			Settings,
			MainMenu,
		};

	private:
		sf::Sprite				mBackgroundSprite;

		std::vector<sf::Text> 	mOptions;
		std::size_t				mOptionIndex;
};

#endif // PAUSESTATE_H

////////