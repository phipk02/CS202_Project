#include "../include/Pause.h"
#include "../include/Utility.h"
#include "../include/ResourceHolder.h"
#include "../include/Foreach.h"

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/View.hpp>


PauseState::PauseState(StateStack& stack, Context context)
: State(stack, context)
, mBackgroundSprite()
, mOptions()
, mOptionIndex(0)
{
	sf::Font& font = context.fonts->get(Fonts::Main);
	sf::Vector2f viewSize = context.window->getView().getSize();

	context.window -> clear();

	sf::Text continueOption;
	continueOption.setFont(font);
	continueOption.setString("Continue");
	centerOrigin(continueOption);
	continueOption.setPosition(context.window->getView().getSize() / 2.f + sf::Vector2f(0.f, -60.f));
	mOptions.push_back(continueOption);

	sf::Text saveOption;
	saveOption.setFont(font);
	saveOption.setString("Save game");
	centerOrigin(saveOption);
	saveOption.setPosition(context.window->getView().getSize() / 2.f + sf::Vector2f(0.f, -30.f));
	mOptions.push_back(saveOption);

	sf::Text loadOption;
	loadOption.setFont(font);
	loadOption.setString("Load game");
	centerOrigin(loadOption);
	loadOption.setPosition(context.window->getView().getSize() / 2.f + sf::Vector2f(0.f, 0.f));
	mOptions.push_back(loadOption);

	sf::Text settingsOption;
	settingsOption.setFont(font);
	settingsOption.setString("Settings");
	centerOrigin(settingsOption);
	settingsOption.setPosition(context.window->getView().getSize() / 2.f + sf::Vector2f(0.f, 30.f));
	mOptions.push_back(settingsOption);

	sf::Text mainMenuOption;
	mainMenuOption.setFont(font);
	mainMenuOption.setString("Return to main menu");
	centerOrigin(mainMenuOption);
	mainMenuOption.setPosition(context.window->getView().getSize() / 2.f + sf::Vector2f(0.f, 60.f));
	mOptions.push_back(mainMenuOption);
}

void PauseState::draw()
{
	sf::RenderWindow& window = *getContext().window;
	window.setView(window.getDefaultView());

	sf::RectangleShape backgroundShape;
	backgroundShape.setFillColor(sf::Color(32, 33, 36, 255));
	backgroundShape.setSize(window.getView().getSize());

	window.draw(backgroundShape);
	FOREACH(const sf::Text& text, mOptions)
		window.draw(text);
}

bool PauseState::update(sf::Time)
{
	return false;
}

bool PauseState::handleEvent(const sf::Event& event)
{
	if (event.type != sf::Event::KeyPressed)
		return false;

	if (event.key.code == sf::Keyboard::Escape)
	{
		// Escape pressed, remove itself to return to the game
		requestStackPop();
	}

	if (event.key.code == sf::Keyboard::Return)
	{
		if (mOptionIndex == Continue)
		{
			std::cout << "Pause pop\n";
			requestStackPop();
			// requestStackPush(States::Game);
		}
        else if (mOptionIndex == Save) {
            // requestStackPop();
			std::cout << "Pause -> Save no pop\n";
            requestStackPush(States::Save);
        }
        else if (mOptionIndex == Load) {
			std::cout << "Pause -> Load no pop\n";
            requestStackPush(States::Load);
        }
		else if (mOptionIndex == Settings) {
			std::cout << "Pause -> Settings no pop\n";
			requestStackPush(States::Settings);
		}
		else if (mOptionIndex == MainMenu)
		{
			// The exit option was chosen, by removing itself, the stack will be empty, and the game will know it is time to close.
			std::cout << "Pause -> Menu clear\n";
		
			requestStateClear();
			requestStackPush(States::Menu);
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

	if (event.key.code == sf::Keyboard::BackSpace)
	{
		// Escape pressed, remove itself to return to the game
		requestStateClear();
		requestStackPush(States::Menu);
	}

	return false;
}

void PauseState::updateOptionText()
{
	if (mOptions.empty())
		return;

	// White all texts
	FOREACH(sf::Text& text, mOptions)
		text.setFillColor(sf::Color::White);

	// Red the selected text
	mOptions[mOptionIndex].setFillColor(sf::Color::Red);
}