#include "../include/Load.h"
#include "../include/Utility.h"
#include "../include/Foreach.h"
#include "../include/ResourceHolder.h"

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/View.hpp>


LoadState::LoadState(StateStack& stack, Context context)
: State(stack, context)
, mOptions()
, mOptionIndex(0)
, isFinished(false)
{
	sf::Texture& texture = context.textures->get(Textures::Background);
	sf::Font& font = context.fonts->get(Fonts::Main);

	context.window -> clear();

	mBackgroundSprite.setTexture(texture);

    for (int i = 0; i < 3; i++) {
        std::string file = "../saveFile/" + std::to_string(i + 1) + ".bin";
        existFile[i] = std::filesystem::exists(file);
    }

    mStateName.setFont(font);
    mStateName.setString("LOAD GAME");
    centerOrigin(mStateName);
    mStateName.setCharacterSize(50);
    mStateName.setStyle(sf::Text::Bold);
    mStateName.setPosition(context.window->getView().getSize().x / 2.f, 55.f);
	
	// A simple menu demonstration
    sf::Text loadOption1;
	loadOption1.setFont(font);
	loadOption1.setString(existFile[0] ? "Slot 1" : "Empty");
	centerOrigin(loadOption1);
	loadOption1.setPosition(context.window->getView().getSize() / 2.f + sf::Vector2f(0.f, -45.f));
	mOptions.push_back(loadOption1);

    sf::Text loadOption2;
	loadOption2.setFont(font);
	loadOption2.setString(existFile[1] ? "Slot 2" : "Empty");
	centerOrigin(loadOption2);
	loadOption2.setPosition(context.window->getView().getSize() / 2.f + sf::Vector2f(0.f, -15.f));
	mOptions.push_back(loadOption2);

    sf::Text loadOption3;
	loadOption3.setFont(font);
	loadOption3.setString(existFile[2] ? "Slot 3" : "Empty");
	centerOrigin(loadOption3);
	loadOption3.setPosition(context.window->getView().getSize() / 2.f + sf::Vector2f(0.f, 15.f));
	mOptions.push_back(loadOption3);

	sf::Text returnOption;
	returnOption.setFont(font);
	returnOption.setString("Return");
	centerOrigin(returnOption);
	returnOption.setPosition(context.window->getView().getSize() / 2.f + sf::Vector2f(0.f, 45.f));
	mOptions.push_back(returnOption);

    finishText.setFont(font);
    finishText.setString("Load successfully. Press any key to return!");
    centerOrigin(finishText);
    finishText.setPosition(context.window->getView().getSize() / 2.f);

	updateOptionText();
}

void LoadState::draw()
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

bool LoadState::update(sf::Time)
{
	playSound();
	return false;
}

bool LoadState::handleEvent(const sf::Event& event)
{
	// The demonstration menu logic
	if (event.type != sf::Event::KeyPressed)
		return false;

    if (isFinished) {
        std::cout << "Pause -> Game clear\n";
        requestStateClear();
        requestStackPush(States::Game);
    }

	if (event.key.code == sf::Keyboard::Return)
	{
		if (mOptionIndex == Slot1)
		{
            GameState::load("E:/CS202/Project1/Project1/saveFile/1.bin");
            isFinished = true;
		}
        else if (mOptionIndex == Slot2) {
            GameState::load("E:/CS202/Project1/Project1/saveFile/2.bin");
            isFinished = true;
        }
        else if (mOptionIndex == Slot3) {
            GameState::load("E:/CS202/Project1/Project1/saveFile/3.bin");
            isFinished = true;
        }
		else if (mOptionIndex == Return)
		{
			std::cout << "pop Load\n";
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

void LoadState::updateOptionText()
{
	if (mOptions.empty())
		return;

	// White all texts
	FOREACH(sf::Text& text, mOptions)
		text.setFillColor(sf::Color::White);

	// Red the selected text
	mOptions[mOptionIndex].setFillColor(sf::Color::Red);
}

void LoadState::load(const std::string& filename) {
    GameState::load(filename);
    isFinished = true;
	requestStateClear();
	requestStackPush(States::Game);
}

void LoadState::playSound() {
	if (Application::sound) {
		if (Application::mSound[0].getStatus() == sf::Sound::Stopped) Application::mSound[0].play();
		Application::mSound[1].stop();
	}
	else {
		Application::mSound[0].stop();
		Application::mSound[1].stop();
	}
}