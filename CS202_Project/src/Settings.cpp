#include "../include/Settings.h"
#include "../include/Utility.h"
#include "../include/Foreach.h"
#include "../include/ResourceHolder.h"

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/View.hpp>


SettingsState::SettingsState(StateStack& stack, Context context)
: State(stack, context)
, mOptions()
, mOptionIndex(0)
{

	sf::Texture& texture = context.textures->get(Textures::Background);
	sf::Font& font = context.fonts->get(Fonts::Main);

	context.window -> clear();

	mBackgroundSprite.setTexture(texture);

    // State name
	mStateName.setFont(font);
    mStateName.setString("SETTINGS");
    mStateName.setCharacterSize(50);
    mStateName.setStyle(sf::Text::Bold);
    centerOrigin(mStateName);
    mStateName.setPosition(context.window->getView().getSize().x / 2.f, 55.f);

    // Instruction
    mInstructionText.setFont(font);
    mInstructionText.setString("(Press Enter to change value!)");
    centerOrigin(mInstructionText);
    mInstructionText.setPosition(mStateName.getPosition() + sf::Vector2f(0.f, 10.f));

    mLevel.setFont(font);
    mLevel.setString(std::to_string(GameState::getLevel()));
    centerOrigin(mLevel);
    mLevel.setPosition(context.window->getView().getSize() / 2.f + sf::Vector2f(80.f, -30.f));

    mSound.setFont(font);
    mSound.setString(Application::sound ? "On" : "Off");
    centerOrigin(mSound);
    mSound.setPosition(context.window->getView().getSize() / 2.f + sf::Vector2f(80.f, 0.f));
	
	// A simple menu demonstration
    sf::Text changeLevelOption;
	changeLevelOption.setFont(font);
	changeLevelOption.setString("Level");
	centerOrigin(changeLevelOption);
	changeLevelOption.setPosition(context.window->getView().getSize() / 2.f + sf::Vector2f(0.f, -30.f));
	mOptions.push_back(changeLevelOption);

    sf::Text soundOption;
	soundOption.setFont(font);
	soundOption.setString("Sound");
	centerOrigin(soundOption);
	soundOption.setPosition(context.window->getView().getSize() / 2.f + sf::Vector2f(0.f, 0.f));
	mOptions.push_back(soundOption);

    sf::Text returnOption;
	returnOption.setFont(font);
	returnOption.setString("Return");
	centerOrigin(returnOption);
	returnOption.setPosition(context.window->getView().getSize() / 2.f + sf::Vector2f(0.f, 30.f));
	mOptions.push_back(returnOption);

	updateOptionText();
}

void SettingsState::draw()
{
	sf::RenderWindow& window = *getContext().window;

	window.setView(window.getDefaultView());
	window.draw(mBackgroundSprite);

    window.draw(mStateName);

    mLevel.setString(std::to_string(GameState::getLevel()));
    mSound.setString(Application::sound ? "On" : "Off");

	FOREACH(const sf::Text& text, mOptions)
		window.draw(text);
    
    window.draw(mLevel);
    window.draw(mSound);
}

bool SettingsState::update(sf::Time)
{
	playSound();
	return false;
}

bool SettingsState::handleEvent(const sf::Event& event)
{
    int level = GameState::getLevel();
	// The demonstration menu logic
	if (event.type != sf::Event::KeyPressed)
		return false;

	if (event.key.code == sf::Keyboard::Return)
	{
		if (mOptionIndex == Level)
		{
			if (level == 3) level = 1;
            else level++;
            GameState::changeLevel(level);
		}
        else if (mOptionIndex == Sound) {
            Application::sound = !Application::sound;
        }
		else if (mOptionIndex == Return)
		{
			std::cout << "pop Settings\n";
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

void SettingsState::updateOptionText()
{
	if (mOptions.empty())
		return;

	// White all texts
	FOREACH(sf::Text& text, mOptions)
		text.setFillColor(sf::Color::White);

	// Red the selected text
	mOptions[mOptionIndex].setFillColor(sf::Color::Red);
}

void SettingsState::playSound() {
	if (Application::sound) {
		if (Application::mSound[0].getStatus() == sf::Sound::Stopped) Application::mSound[0].play();
		Application::mSound[1].stop();
	}
	else {
		Application::mSound[0].stop();
		Application::mSound[1].stop();
	}
}