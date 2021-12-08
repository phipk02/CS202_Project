#include "../include/Menu.h"
#include "../include/Utility.h"
#include "../include/Foreach.h"
#include "../include/ResourceHolder.h"

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/View.hpp>


MenuState::MenuState(StateStack& stack, Context context)
: State(stack, context)
, mOptions()
, mOptionIndex(0)
{
	sf::Texture& texture = context.textures->get(Textures::Background);
	sf::Font& font = context.fonts->get(Fonts::Main);

	mBackgroundSprite.setTexture(texture);

	mStateName.setFont(font);
    mStateName.setString("MENU");
    centerOrigin(mStateName);
    mStateName.setCharacterSize(50);
    mStateName.setStyle(sf::Text::Bold);
    mStateName.setPosition(context.window->getView().getSize().x / 2.f, 55.f);
	
	// A simple menu demonstration
    sf::Text newOption;
	newOption.setFont(font);
	newOption.setString("New game");
	centerOrigin(newOption);
	newOption.setPosition(context.window->getView().getSize() / 2.f + sf::Vector2f(0.f, -45.f));
	mOptions.push_back(newOption);

    sf::Text loadOption;
	loadOption.setFont(font);
	loadOption.setString("Load game");
	centerOrigin(loadOption);
	loadOption.setPosition(context.window->getView().getSize() / 2.f + sf::Vector2f(0.f, -15.f));
	mOptions.push_back(loadOption);

    sf::Text settingsOption;
	settingsOption.setFont(font);
	settingsOption.setString("Settings");
	centerOrigin(settingsOption);
	settingsOption.setPosition(context.window->getView().getSize() / 2.f + sf::Vector2f(0.f, 15.f));
	mOptions.push_back(settingsOption);

	sf::Text exitOption;
	exitOption.setFont(font);
	exitOption.setString("Exit");
	centerOrigin(exitOption);
	exitOption.setPosition(context.window->getView().getSize() / 2.f + sf::Vector2f(0.f, 45.f));
	mOptions.push_back(exitOption);

	updateOptionText();
}

void MenuState::draw()
{
	sf::RenderWindow& window = *getContext().window;

	window.setView(window.getDefaultView());
	window.draw(mBackgroundSprite);

    window.draw(mStateName);

	FOREACH(const sf::Text& text, mOptions)
		window.draw(text);
}

bool MenuState::update(sf::Time)
{
	return true;
}

bool MenuState::handleEvent(const sf::Event& event)
{
	// The demonstration menu logic
	if (event.type != sf::Event::KeyPressed)
		return false;

	if (event.key.code == sf::Keyboard::Return)
	{
		if (mOptionIndex == NewGame)
		{
			std::cout << "Menu -> Game pop\n";
			requestStackPop();
			requestStackPush(States::Game);
		}
        else if (mOptionIndex == LoadGame) {
			std::cout << "Menu -> Load no pop\n";
            requestStackPush(States::Load);
        }
        else if (mOptionIndex == Settings) {
			std::cout << "Menu -> Settings no pop\n";
            requestStackPush(States::Settings);
        }
		else if (mOptionIndex == Exit)
		{
			// The exit option was chosen, by removing itself, the stack will be empty, and the game will know it is time to close.
			requestStackPop();
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

	return true;
}

void MenuState::updateOptionText()
{
	if (mOptions.empty())
		return;

	// White all texts
	FOREACH(sf::Text& text, mOptions)
		text.setFillColor(sf::Color::White);

	// Red the selected text
	mOptions[mOptionIndex].setFillColor(sf::Color::Red);
}