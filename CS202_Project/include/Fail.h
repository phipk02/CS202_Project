#pragma once

#ifndef FAIL_H
#define FAIL_H

#include "State.h"
#include "Application.h"

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>


class FailState : public State
{
public:
	FailState(StateStack& stack, Context context);

	virtual void			draw();
	virtual bool			update(sf::Time dt);
	virtual bool			handleEvent(const sf::Event& event);

	void					playSound();

	void					updateOptionText();


private:
	enum OptionNames
	{
		TryAgain,
		LoadGame,
		ReturnMainMenu,
		Exit,
	};


private:
	sf::Sprite				mBackgroundSprite;

	std::vector<sf::Text>	mOptions;
	std::size_t				mOptionIndex;

	sf::Text				mFailText;
};

#endif // FAIL_H