#pragma once

#ifndef LOADINGSTATE_H
#define LOADINGSTATE_H

#include "State.h"
#include "ParallelTask.h"
#include "Application.h"


#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>


class LoadingState : public State
{
public:
	LoadingState(StateStack& stack, Context context);

	virtual void			draw();
	virtual bool			update(sf::Time dt);
	virtual bool			handleEvent(const sf::Event& event);

	void					playSound();

	void					setCompletion(float percent);

private:
	sf::Sprite				mBackgroundSprite;

	sf::Text				mLoadingText;
    sf::Text                mFinishText;
	sf::RectangleShape		mProgressBarBackground;
	sf::RectangleShape		mProgressBar;

	ParallelTask			mLoadingTask;
};

#endif // BOOK_LOADINGSTATE_HPP