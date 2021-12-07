#include "../include/cpeople.h"
#include "../include/CommandQueue.hpp"
#include "../include/canimal.h"
#include "../include/cvehicle.h"
#include "../include/Foreach.hpp"

#include <map>
#include <string>
#include <algorithm>

struct ObjectMover
{
	ObjectMover(float vx, float vy)
	: velocity(vx, vy)
	{
	}

	void operator() (Object& object, sf::Time) const
	{
		Object.accelerate(velocity);
	}

	sf::Vector2f velocity;
};

CPEOPLE::CPEOPLE()
{
	// Set initial key bindings
	mKeyBinding[sf::Keyboard::Left] = MoveLeft;
	mKeyBinding[sf::Keyboard::Right] = MoveRight;
	mKeyBinding[sf::Keyboard::Up] = MoveUp;
	mKeyBinding[sf::Keyboard::Down] = MoveDown;

	// Set initial action bindings
	initializeActions();	

	// Assign all categories to CPEOPLE's Object
	FOREACH(auto& pair, mActionBinding)
		pair.second.category = Category::Player;
}

void CPEOPLE::handleEvent(const sf::Event& event, CommandQueue& commands)
{
	if (event.type == sf::Event::KeyPressed)
	{
		// Check if pressed key appears in key binding, trigger command if so
		auto found = mKeyBinding.find(event.key.code);
		if (found != mKeyBinding.end() && !isRealtimeAction(found->second))
			commands.push(mActionBinding[found->second]);
	}
}

void CPEOPLE::handleRealtimeInput(CommandQueue& commands)
{
	// Traverse all assigned keys and check if they are pressed
	FOREACH(auto pair, mKeyBinding)
	{
		// If key is pressed, lookup action and trigger corresponding command
		if (sf::Keyboard::isKeyPressed(pair.first) && isRealtimeAction(pair.second))
			commands.push(mActionBinding[pair.second]);
	}
}

void CPEOPLE::assignKey(Action action, sf::Keyboard::Key key)
{
	// Remove all keys that already map to action
	for (auto itr = mKeyBinding.begin(); itr != mKeyBinding.end(); )
	{
		if (itr->second == action)
			mKeyBinding.erase(itr++);
		else
			++itr;
	}

	// Insert new binding
	mKeyBinding[key] = action;
}

sf::Keyboard::Key CPEOPLE::getAssignedKey(Action action) const
{
	FOREACH(auto pair, mKeyBinding)
	{
		if (pair.second == action)
			return pair.first;
	}

	return sf::Keyboard::Unknown;
}

void CPEOPLE::initializeActions()
{
	const float CPEOPLESpeed = 200.f;

	mActionBinding[MoveLeft].action	 = derivedAction<Object>(ObjectMover(-CPEOPLESpeed, 0.f));
	mActionBinding[MoveRight].action = derivedAction<Object>(ObjectMover(+CPEOPLESpeed, 0.f));
	mActionBinding[MoveUp].action    = derivedAction<Object>(ObjectMover(0.f, -CPEOPLESpeed));
	mActionBinding[MoveDown].action  = derivedAction<Object>(ObjectMover(0.f, +CPEOPLESpeed));
}

bool CPEOPLE::isRealtimeAction(Action action)
{
	switch (action)
	{
		case MoveLeft:
		case MoveRight:
		case MoveDown:
		case MoveUp:
			return true;

		default:
			return false;
	}
}