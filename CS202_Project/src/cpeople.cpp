
#include "cpeople.h"

CPEOPLE::CPEOPLE() {
    pTexture.loadFromFile("asset\\people.png", sf::IntRect(6, 4, 12, 20));
    pSprite.setTexture(pTexture);
    pSprite.setPosition(470, 500);
    pSprite.setScale(1.5, 1.5);
    velocity = 0.2f;
}

void CPEOPLE::render(sf::RenderWindow* window) {
    window->draw(pSprite);
}

void CPEOPLE::resetState() {
    pSprite.setPosition(470, 500);
}

void CPEOPLE::moveLeft() {
    if (pSprite.getGlobalBounds().left <= 1) return;
    pSprite.move(-velocity, 0);
}

void CPEOPLE::moveRight() {
    if (pSprite.getGlobalBounds().left + pSprite.getGlobalBounds().width >= 960) return;
    pSprite.move(+velocity, 0); 
}

void CPEOPLE::moveUp() {
    if (pSprite.getGlobalBounds().top <= 0) return;
    pSprite.move(0, -velocity);
}

void CPEOPLE::moveDown() {
    if (pSprite.getGlobalBounds().top + pSprite.getGlobalBounds().height >= 540) return;
    pSprite.move(0, +velocity);
}

bool CPEOPLE::isImpact(CVEHICLE* enemy) {
    if (pSprite.getGlobalBounds().intersects(enemy->getBound())) {
        return true;
    }
    return false;
}

bool CPEOPLE::isImpact(CANIMAL* enemy) {
    if (pSprite.getGlobalBounds().intersects(enemy->getBound())) {
        return true;
    }
    return false;
}

bool CPEOPLE::isVictory() {
    if (pSprite.getGlobalBounds().top <= 35) return true;
    return false;
}

// #include "../include/cpeople.h"
// #include "../include/CommandQueue.hpp"
// #include "../include/canimal.h"
// #include "../include/cvehicle.h"
// #include "../include/Foreach.hpp"

// #include <map>
// #include <string>
// #include <algorithm>

// struct ObjectMover
// {
// 	ObjectMover(float vx, float vy)
// 	: velocity(vx, vy)
// 	{
// 	}

// 	void operator() (Object& object, sf::Time) const
// 	{
// 		Object.accelerate(velocity);
// 	}

// 	sf::Vector2f velocity;
// };

// CPEOPLE::CPEOPLE()
// {
// 	// Set initial key bindings
// 	mKeyBinding[sf::Keyboard::Left] = MoveLeft;
// 	mKeyBinding[sf::Keyboard::Right] = MoveRight;
// 	mKeyBinding[sf::Keyboard::Up] = MoveUp;
// 	mKeyBinding[sf::Keyboard::Down] = MoveDown;

// 	// Set initial action bindings
// 	initializeActions();	

// 	// Assign all categories to CPEOPLE's Object
// 	FOREACH(auto& pair, mActionBinding)
// 		pair.second.category = Category::Player;
// }

// void CPEOPLE::handleEvent(const sf::Event& event, CommandQueue& commands)
// {
// 	if (event.type == sf::Event::KeyPressed)
// 	{
// 		// Check if pressed key appears in key binding, trigger command if so
// 		auto found = mKeyBinding.find(event.key.code);
// 		if (found != mKeyBinding.end() && !isRealtimeAction(found->second))
// 			commands.push(mActionBinding[found->second]);
// 	}
// }

// void CPEOPLE::handleRealtimeInput(CommandQueue& commands)
// {
// 	// Traverse all assigned keys and check if they are pressed
// 	FOREACH(auto pair, mKeyBinding)
// 	{
// 		// If key is pressed, lookup action and trigger corresponding command
// 		if (sf::Keyboard::isKeyPressed(pair.first) && isRealtimeAction(pair.second))
// 			commands.push(mActionBinding[pair.second]);
// 	}
// }

// void CPEOPLE::assignKey(Action action, sf::Keyboard::Key key)
// {
// 	// Remove all keys that already map to action
// 	for (auto itr = mKeyBinding.begin(); itr != mKeyBinding.end(); )
// 	{
// 		if (itr->second == action)
// 			mKeyBinding.erase(itr++);
// 		else
// 			++itr;
// 	}

// 	// Insert new binding
// 	mKeyBinding[key] = action;
// }

// sf::Keyboard::Key CPEOPLE::getAssignedKey(Action action) const
// {
// 	FOREACH(auto pair, mKeyBinding)
// 	{
// 		if (pair.second == action)
// 			return pair.first;
// 	}

// 	return sf::Keyboard::Unknown;
// }

// void CPEOPLE::initializeActions()
// {
// 	const float CPEOPLESpeed = 200.f;

// 	mActionBinding[MoveLeft].action	 = derivedAction<Object>(ObjectMover(-CPEOPLESpeed, 0.f));
// 	mActionBinding[MoveRight].action = derivedAction<Object>(ObjectMover(+CPEOPLESpeed, 0.f));
// 	mActionBinding[MoveUp].action    = derivedAction<Object>(ObjectMover(0.f, -CPEOPLESpeed));
// 	mActionBinding[MoveDown].action  = derivedAction<Object>(ObjectMover(0.f, +CPEOPLESpeed));
// }

// bool CPEOPLE::isRealtimeAction(Action action)
// {
// 	switch (action)
// 	{
// 		case MoveLeft:
// 		case MoveRight:
// 		case MoveDown:
// 		case MoveUp:
// 			return true;

// 		default:
// 			return false;
// 	}
// }