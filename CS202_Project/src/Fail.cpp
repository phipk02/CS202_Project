#include "../include/Fail.h"
#include "../include/Utility.h"
#include "../include/Foreach.h"
#include "../include/ResourceHolder.h"

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/View.hpp>


FailState::FailState(StateStack& stack, Context context)
	: State(stack, context)
	, mOptions()
	, mOptionIndex(0)
{

	sf::Texture& texture = context.textures->get(Textures::Background);
	sf::Font& font = context.fonts->get(Fonts::Main);

	mBackgroundSprite.setTexture(texture);

	mFailText.setFont(font);
	mFailText.setString("HAHA! YOU LOSER! WANT TO BE BEAT ONE MORE TIME?");
	mFailText.setCharacterSize(20u);
	centerOrigin(mFailText);
	mFailText.setStyle(sf::Text::Bold);
	mFailText.setFillColor(sf::Color::Red);
	mFailText.setPosition(context.window->getView().getSize().x / 2.f, 200.f);

	// A simple menu demonstration
	sf::Text tryAgainOption;
	tryAgainOption.setFont(font);
	tryAgainOption.setString("Try again");
	centerOrigin(tryAgainOption);
	tryAgainOption.setPosition(context.window->getView().getSize() / 2.f + sf::Vector2f(0.f, -45.f));
	mOptions.push_back(tryAgainOption);

	sf::Text loadOption;
	loadOption.setFont(font);
	loadOption.setString("Load game");
	centerOrigin(loadOption);
	loadOption.setPosition(context.window->getView().getSize() / 2.f + sf::Vector2f(0.f, -15.f));
	mOptions.push_back(loadOption);

	sf::Text mainMenuOption;
	mainMenuOption.setFont(font);
	mainMenuOption.setString("Return to main menu");
	centerOrigin(mainMenuOption);
	mainMenuOption.setPosition(context.window->getView().getSize() / 2.f + sf::Vector2f(0.f, 15.f));
	mOptions.push_back(mainMenuOption);

	sf::Text exitOption;
	exitOption.setFont(font);
	exitOption.setString("Exit");
	centerOrigin(exitOption);
	exitOption.setPosition(context.window->getView().getSize() / 2.f + sf::Vector2f(0.f, 45.f));
	mOptions.push_back(exitOption);

	updateOptionText();
}

void FailState::draw()
{
	sf::RenderWindow& window = *getContext().window;

	window.setView(window.getDefaultView());
	window.draw(mBackgroundSprite);
	window.draw(mFailText);

	FOREACH(const sf::Text & text, mOptions)
		window.draw(text);
}

bool FailState::update(sf::Time)
{
	playSound();
	return false;
}

bool FailState::handleEvent(const sf::Event& event)
{
	// The demonstration menu logic
	if (event.type != sf::Event::KeyPressed)
		return false;

	if (event.key.code == sf::Keyboard::Return)
	{
		if (mOptionIndex == TryAgain)
		{
			std::cout << "End -> Game clear push game\n";
			requestStateClear();
			requestStackPush(States::Game);
		}
		else if (mOptionIndex == LoadGame) {
			std::cout << "End -> Load clear, push game load\n";
			requestStackPush(States::Load);
		}
		else if (mOptionIndex == ReturnMainMenu) {
			std::cout << "End -> Menu clear push\n";
			requestStateClear();
			requestStackPush(States::Menu);
		}
		else if (mOptionIndex == Exit)
		{
			// The exit option was chosen, by removing itself, the stack will be empty, and the game will know it is time to close.
			requestStateClear();
		}
	}

	else if (event.key.code == sf::Keyboard::Up)
	{
		// Decrement and wrap-around
		if (mOptionIndex > 0)
			mOptionIndex--;
		else
			mOptionIndex = mOptions.size() - 1;

		updateOptionText();
	}

	else if (event.key.code == sf::Keyboard::Down)
	{
		// Increment and wrap-around
		if (mOptionIndex < mOptions.size() - 1)
			mOptionIndex++;
		else
			mOptionIndex = 0;

		updateOptionText();
	}

	return false;
}

void FailState::updateOptionText()
{
	if (mOptions.empty())
		return;

	// White all texts
	FOREACH(sf::Text & text, mOptions)
		text.setFillColor(sf::Color::White);

	// Red the selected text
	mOptions[mOptionIndex].setFillColor(sf::Color::Red);
}

void FailState::playSound() {
	if (Application::sound) {
		if (Application::mSound[0].getStatus() == sf::Sound::Stopped) Application::mSound[0].play();
		Application::mSound[1].stop();
	}
	else {
		Application::mSound[0].stop();
		Application::mSound[1].stop();
	}
}