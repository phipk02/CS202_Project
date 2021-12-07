#include "../include/menu.h"
#include <iostream>

//main menu ------------------------------------------------------------------

MainMenu::MainMenu(float width, float height)
{
	if (!font.loadFromFile("../External/Poppins-SemiBold.ttf"))
	{
		std::cout << "Error loading font";
	}
	menu[0].setFont(font);
	menu[0].setFillColor(sf::Color(220, 20, 60));
	menu[0].setString("New game");
	menu[0].setOrigin(menu[0].getLocalBounds().width / 2, menu[0].getLocalBounds().height / 2);
	menu[0].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEM + 1) * 1.25));

	menu[1].setFont(font);
	menu[1].setFillColor(sf::Color::White);
	menu[1].setString("Load game");
	menu[1].setOrigin(menu[1].getLocalBounds().width / 2, menu[1].getLocalBounds().height / 2);
	menu[1].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEM + 1) * 2.25));

	menu[2].setFont(font);
	menu[2].setFillColor(sf::Color::White);
	menu[2].setString("Settings");
	menu[2].setOrigin(menu[2].getLocalBounds().width / 2, menu[2].getLocalBounds().height / 2);
	menu[2].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEM + 1) * 3.25));

	selectedItemIndex = 0;
}

void MainMenu::draw(sf::RenderWindow& window)
{

	if (!title.loadFromFile("../External/logo2.png")) {
		return;
	}
	sf::Sprite logo(title);

	logo.setScale(sf::Vector2f(1, 1));
	auto bounds = logo.getLocalBounds();
	logo.setOrigin(bounds.width / 2.f, bounds.height / 2.f);
	logo.setPosition(window.getSize().x / 2, window.getSize().y / (MAX_NUMBER_OF_ITEM + 4.5));
	window.draw(logo);
	for (int i = 0; i < MAX_NUMBER_OF_ITEM; i++) {
		window.draw(menu[i]);
	}
}

void MainMenu::MoveUp()
{
	if (selectedItemIndex - 1 >= 0) {
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex--;
		menu[selectedItemIndex].setFillColor(sf::Color(220, 20, 60));
	}
}

void MainMenu::MoveDown()
{
	if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEM) {
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex++;
		menu[selectedItemIndex].setFillColor(sf::Color(220, 20, 60));
	}
}

int MainMenu::getPressedItem()
{
	return selectedItemIndex;
}

//save menu ------------------------------------------------------------------

SaveMenu::SaveMenu(float width, float height)
{
	if (!font.loadFromFile("../External/Poppins-SemiBold.ttf"))
	{
		std::cout << "Error loading font";
	}
	menu[0].setFont(font);
	menu[0].setFillColor(sf::Color(220, 20, 60));
	menu[0].setString("Save slot 1");
	menu[0].setOrigin(menu[0].getLocalBounds().width / 2, menu[0].getLocalBounds().height / 2);
	menu[0].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEM + 1) * 1.25));

	menu[1].setFont(font);
	menu[1].setFillColor(sf::Color::White);
	menu[1].setString("Save slot 2");
	menu[1].setOrigin(menu[1].getLocalBounds().width / 2, menu[1].getLocalBounds().height / 2);
	menu[1].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEM + 1) * 2.25));

	menu[2].setFont(font);
	menu[2].setFillColor(sf::Color::White);
	menu[2].setString("Save slot 3");
	menu[2].setOrigin(menu[2].getLocalBounds().width / 2, menu[2].getLocalBounds().height / 2);
	menu[2].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEM + 1) * 3.25));

	selectedItemIndex = 0;
}

void SaveMenu::draw(sf::RenderWindow& window)
{

	if (!title.loadFromFile("../External/save2.png")) {
		return;
	}
	sf::Sprite logo(title);

	logo.setScale(sf::Vector2f(1, 1));
	auto bounds = logo.getLocalBounds();
	logo.setOrigin(bounds.width / 2.f, bounds.height / 2.f);
	logo.setPosition(window.getSize().x / 2, window.getSize().y / (MAX_NUMBER_OF_ITEM + 4.5));
	window.draw(logo);
	for (int i = 0; i < MAX_NUMBER_OF_ITEM; i++) {
		window.draw(menu[i]);
	}
}

void SaveMenu::MoveUp()
{
	if (selectedItemIndex - 1 >= 0) {
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex--;
		menu[selectedItemIndex].setFillColor(sf::Color(220, 20, 60));
	}
}

void SaveMenu::MoveDown()
{
	if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEM) {
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex++;
		menu[selectedItemIndex].setFillColor(sf::Color(220, 20, 60));
	}
}

int SaveMenu::getPressedItem()
{
	return selectedItemIndex;
}

// pause ------------------------------------------------------------------

PauseMenu::PauseMenu(float width, float height)
{
	if (!font.loadFromFile("../External/Poppins-SemiBold.ttf"))
	{
		std::cout << "Error loading font";
	}
	menu[0].setFont(font);
	menu[0].setFillColor(sf::Color(220, 20, 60));
	menu[0].setString("Continue");
	menu[0].setOrigin(menu[0].getLocalBounds().width / 2, menu[0].getLocalBounds().height / 2);
	menu[0].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEM + 1) * 1.25));

	menu[1].setFont(font);
	menu[1].setFillColor(sf::Color::White);
	menu[1].setString("Retry");
	menu[1].setOrigin(menu[1].getLocalBounds().width / 2, menu[1].getLocalBounds().height / 2);
	menu[1].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEM + 1) * 2.25));

	menu[2].setFont(font);
	menu[2].setFillColor(sf::Color::White);
	menu[2].setString("Quit to main menu");
	menu[2].setOrigin(menu[2].getLocalBounds().width / 2, menu[2].getLocalBounds().height / 2);
	menu[2].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEM + 1) * 3.25));

	selectedItemIndex = 0;
}

void PauseMenu::draw(sf::RenderWindow& window)
{

	if (!title.loadFromFile("../External/pause2.png")) {
		return;
	}
	sf::Sprite logo(title);

	logo.setScale(sf::Vector2f(1, 1));
	auto bounds = logo.getLocalBounds();
	logo.setOrigin(bounds.width / 2.f, bounds.height / 2.f);
	logo.setPosition(window.getSize().x / 2, window.getSize().y / (MAX_NUMBER_OF_ITEM + 4.5));
	window.draw(logo);
	for (int i = 0; i < MAX_NUMBER_OF_ITEM; i++) {
		window.draw(menu[i]);
	}
}

void PauseMenu::MoveUp()
{
	if (selectedItemIndex - 1 >= 0) {
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex--;
		menu[selectedItemIndex].setFillColor(sf::Color(220, 20, 60));
	}
}

void PauseMenu::MoveDown()
{
	if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEM) {
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex++;
		menu[selectedItemIndex].setFillColor(sf::Color(220, 20, 60));
	}
}

int PauseMenu::getPressedItem()
{
	return selectedItemIndex;
}

// next level ------------------------------------------------------------------

NextLevelScreen::NextLevelScreen(float width, float height)
{
	if (!font.loadFromFile("../External/Poppins-SemiBold.ttf"))
	{
		std::cout << "Error loading font";
	}
	menu[0].setFont(font);
	menu[0].setFillColor(sf::Color(220, 20, 60));
	menu[0].setString("Continue to the next level");
	menu[0].setOrigin(menu[0].getLocalBounds().width / 2, menu[0].getLocalBounds().height / 2);
	menu[0].setPosition(sf::Vector2f(width / 2, height / (NUMBER_OF_ITEMS + 1) * 1.25));

	menu[1].setFont(font);
	menu[1].setFillColor(sf::Color::White);
	menu[1].setString("Quit");
	menu[1].setOrigin(menu[1].getLocalBounds().width / 2, menu[1].getLocalBounds().height / 2);
	menu[1].setPosition(sf::Vector2f(width / 2, height / (NUMBER_OF_ITEMS + 1) * 2.25));

	selectedItemIndex = 0;
}

void NextLevelScreen::draw(sf::RenderWindow& window)
{
	if (!title.loadFromFile("../External/nextlevel2.png")) {
		return;
	}
	sf::Sprite logo(title);
	logo.setScale(sf::Vector2f(1, 1));
	auto bounds = logo.getLocalBounds();
	logo.setOrigin(bounds.width / 2.f, bounds.height / 2.f);
	logo.setPosition(window.getSize().x / 2, window.getSize().y / (MAX_NUMBER_OF_ITEM + 4.5));
	window.draw(logo);
	for (int i = 0; i < NUMBER_OF_ITEMS; i++) {
		window.draw(menu[i]);
	}
}

void NextLevelScreen::MoveUp()
{
	if (selectedItemIndex - 1 >= 0) {
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex--;
		menu[selectedItemIndex].setFillColor(sf::Color(220, 20, 60));
	}
}

void NextLevelScreen::MoveDown()
{
	if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEM) {
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex++;
		menu[selectedItemIndex].setFillColor(sf::Color(220, 20, 60));
	}
}

int NextLevelScreen::getPressedItem()
{
	return selectedItemIndex;
}