#include "../include/Loading.h"
#include "../include/Utility.h"
#include "../include/ResourceHolder.h"

//#include "ParallelTask.cpp"
//#include "Utility.cpp"

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/View.hpp>


LoadingState::LoadingState(StateStack& stack, Context context)
: State(stack, context)
{
	sf::RenderWindow& window = *getContext().window;
	sf::Font& font = context.fonts->get(Fonts::Main);
	sf::Vector2f viewSize = window.getView().getSize();

	mLoadingText.setFont(font);
	mLoadingText.setString("Loading Resources");
	centerOrigin(mLoadingText);
	mLoadingText.setPosition(viewSize.x / 2.f, viewSize.y / 2.f + 50.f);

    // mBackgroundSprite.setTexture(context.textures->get(Textures::TitleScreen));

	mFinishText.setFont(context.fonts->get(Fonts::Main));
	mFinishText.setString("Loading successfully. Press any key to start!");
	centerOrigin(mFinishText);
	mFinishText.setPosition(sf::Vector2f(context.window->getSize() / 2u));

	mProgressBarBackground.setFillColor(sf::Color::White);
	mProgressBarBackground.setSize(sf::Vector2f(viewSize.x - 20, 10));
	mProgressBarBackground.setPosition(10, mLoadingText.getPosition().y + 40);

	mProgressBar.setFillColor(sf::Color(100,100,100));
	mProgressBar.setSize(sf::Vector2f(200, 10));
	mProgressBar.setPosition(10, mLoadingText.getPosition().y + 40);

	setCompletion(0.f);

	mLoadingTask.execute();
}

void LoadingState::draw()
{
	sf::RenderWindow& window = *getContext().window;

	window.setView(window.getDefaultView());

    if (mLoadingTask.isFinished()) {
        window.draw(mFinishText);
    }
    else {
        window.draw(mLoadingText);
        window.draw(mProgressBarBackground);
        window.draw(mProgressBar);
    }
}

bool LoadingState::update(sf::Time)
{
	// Update the progress bar from the remote task or finish it
	if (mLoadingTask.isFinished())
	{
	}
	else
	{
		setCompletion(mLoadingTask.getCompletion());
	}
	return true;
}

bool LoadingState::handleEvent(const sf::Event& event)
{
    if (mLoadingTask.isFinished() && event.type == sf::Event::KeyPressed) {
        requestStackPop();
		std::cout << "Menu\n";
        requestStackPush(States::Menu);
    }
	return true;
}

void LoadingState::setCompletion(float percent)
{
	if (percent > 1.f) // clamp
		percent = 1.f;

	mProgressBar.setSize(sf::Vector2f(mProgressBarBackground.getSize().x * percent, mProgressBar.getSize().y));
}