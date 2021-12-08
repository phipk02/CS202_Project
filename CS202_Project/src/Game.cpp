#include "../include/Game.h"

int GameState::level = 1;
// World* GameState::mWorld = nullptr;

GameState::GameState(StateStack& stack, Context context)
: State(stack, context)
// , mWorld(*context.window)
// , mPlayer(*context.player)
{
	// if (!mWorld) mWorld = new World(*context.window);
}

void GameState::draw()
{
	// mWorld.draw();
}

bool GameState::update(sf::Time dt)
{
	// mWorld.update(dt);

	// CommandQueue& commands = mWorld.getCommandQueue();
	// mPlayer.handleRealtimeInput(commands);

	return true;
}

bool GameState::handleEvent(const sf::Event& event)
{
	// Game input handling
	// CommandQueue& commands = mWorld.getCommandQueue();
	// mPlayer.handleEvent(event, commands);

	// Escape pressed, trigger the pause screen
	if (event.type == sf::Event::KeyPressed) {
		if (event.key.code == sf::Keyboard::Escape) {
			std::cout << "Game -> Pause no pop\n";
			requestStackPush(States::Pause);
		}
		else if (event.key.code == sf::Keyboard::T) {
			std::cout << "Game -> Load no pop\n";
			requestStackPush(States::Load);
		}
		else if (event.key.code == sf::Keyboard::L) {
			std::cout << "Game -> Save no pop\n";
			requestStackPush(States::Save);
		}
	}

	return true;
}

void GameState::changeLevel(int _level) {
	level = _level;
	std::cout << "Change successfully!\n";
}

int GameState::getLevel() {
	return level;
}

void GameState::save(const std::string& filename) {
	std::cout << "GameState::save\n";
}

void GameState::load(const std::string& filename) {
	std::cout << "GameState::load\n";
}