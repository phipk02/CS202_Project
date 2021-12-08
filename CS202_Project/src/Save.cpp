#include "../include/Save.h"
#include "../include/Utility.h"
#include "../include/Foreach.h"
#include "../include/ResourceHolder.h"

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/View.hpp>


SaveState::SaveState(StateStack& stack, Context context)
: State(stack, context)
, mOptions()
, mOptionIndex(0)
, isFinished(false)
{
	sf::Texture& texture = context.textures->get(Textures::Background);
	sf::Font& font = context.fonts->get(Fonts::Main);

	context.window -> clear();

	mBackgroundSprite.setTexture(texture);

    mStateName.setFont(font);
    mStateName.setString("SAVE GAME");
    centerOrigin(mStateName);
    mStateName.setCharacterSize(50);
    mStateName.setStyle(sf::Text::Bold);
    mStateName.setPosition(context.window->getView().getSize().x / 2.f, 55.f);
	
	// A simple menu demonstration
    sf::Text saveOption1;
	saveOption1.setFont(font);
	saveOption1.setString("Slot 1");
	centerOrigin(saveOption1);
	saveOption1.setPosition(context.window->getView().getSize() / 2.f + sf::Vector2f(0.f, -45.f));
	mOptions.push_back(saveOption1);

    sf::Text saveOption2;
	saveOption2.setFont(font);
	saveOption2.setString("Slot 2");
	centerOrigin(saveOption2);
	saveOption2.setPosition(context.window->getView().getSize() / 2.f + sf::Vector2f(0.f, -15.f));
	mOptions.push_back(saveOption2);

    sf::Text saveOption3;
	saveOption3.setFont(font);
	saveOption3.setString("Slot 3");
	centerOrigin(saveOption3);
	saveOption3.setPosition(context.window->getView().getSize() / 2.f + sf::Vector2f(0.f, 15.f));
	mOptions.push_back(saveOption3);

	sf::Text returnOption;
	returnOption.setFont(font);
	returnOption.setString("Return");
	centerOrigin(returnOption);
	returnOption.setPosition(context.window->getView().getSize() / 2.f + sf::Vector2f(0.f, 45.f));
	mOptions.push_back(returnOption);

    finishText.setFont(font);
    finishText.setString("Save successfully. Press any key to return!");
    centerOrigin(finishText);
    finishText.setPosition(context.window->getView().getSize() / 2.f);

	updateOptionText();
}

void SaveState::draw()
{
    sf::RenderWindow& window = *getContext().window;
    window.setView(window.getDefaultView());
    window.draw(mBackgroundSprite);

    if (isFinished) {
        window.draw(finishText);
    }
    else {
        window.draw(mStateName);

        FOREACH(const sf::Text& text, mOptions)
            window.draw(text);
    }
}

bool SaveState::update(sf::Time)
{
	return false;
}

bool SaveState::handleEvent(const sf::Event& event)
{
	// The demonstration menu logic
	if (event.type != sf::Event::KeyPressed)
		return false;

    if (isFinished)
        requestStackPop();

	if (event.key.code == sf::Keyboard::Return)
	{
		if (mOptionIndex == Slot1)
		{
			GameState::save("../saveFile/1.bin");
            isFinished = true;
		}
        else if (mOptionIndex == Slot2) {
			GameState::save("../saveFile/2.bin");
            isFinished = true;
        }
        else if (mOptionIndex == Slot3) {
			GameState::save("../saveFile/3.bin");
            isFinished = true;
        }
		else if (mOptionIndex == Return)
		{
			std::cout << "Save pop\n";
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

	return false;
}

void SaveState::updateOptionText()
{
	if (mOptions.empty())
		return;

	// White all texts
	FOREACH(sf::Text& text, mOptions)
		text.setFillColor(sf::Color::White);

	// Red the selected text
	mOptions[mOptionIndex].setFillColor(sf::Color::Red);
}

void SaveState::save(const std::string& filename) {
    GameState::save(filename);
    isFinished = true;
}