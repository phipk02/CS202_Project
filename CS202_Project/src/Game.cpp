#include "../include/Game.h"

//#include "Player.cpp"
//#include "Enemy.cpp"

#include <fstream>
using namespace std;

int GameState::level = 1;
Player* GameState::mPlayer = nullptr;
bool GameState::mTrafficLight = false;
vector<Enemy*> GameState::mEnemies(6, nullptr);
bool GameState::mExisted[6];

GameState::~GameState() {
	delete mPlayer;
	mPlayer = nullptr;
	for (int i = 0; i < 6; i++) {
		mExisted[i] = false;
		delete mEnemies[i];
		mEnemies[i] = nullptr;
	}
}

GameState::GameState(StateStack& stack, Context context)
: State(stack, context)
// , mPlayer(nullptr)
// , mTrafficLight(false)
// , mEnemies(6, nullptr)
, mLanes()
{
	mPlayer = new Player(*context.textures);

	mLanes[0] = 488.f, mLanes[1] = 411.f, mLanes[2] = 341.f, mLanes[3] = 271.f, mLanes[4] = 201.f, mLanes[5] = 131.f;

	for (int i = 0; i < 6; i++) {
		mExisted[i] = true;
		bool direction = std::rand() % 2;
		Enemy::Type type = static_cast<Enemy::Type>(rand() % Enemy::Type::TypeCount);
		mEnemies[i] = new Enemy(type, *context.textures, direction, direction ? 900.f : 0.f, mLanes[i]);
	}

	mBackground.setTexture(context.textures -> get(Textures::Road));

	mStaticLevel.setFont(context.fonts -> get(Fonts::Main));
	mStaticLevel.setString("Level " + std::to_string(level));
	mStaticLevel.setPosition(5.f, 30.f);
	mStaticLevel.setCharacterSize(20u);
	mStaticLevel.setFillColor(sf::Color::Red);

	mFinish.setFont(context.fonts -> get(Fonts::Main));
	mFinish.setString((level < 3) ? ("LEVEL " + std::to_string(level + 1)) : ("FINISH"));
	mFinish.setPosition(400.f, 35.f);
	mFinish.setCharacterSize(40.f);
	mFinish.setFillColor(sf::Color::Red);

	mLight.setTexture(context.textures -> get(Textures::GreenLight));
	mLight.setScale(0.4f, 0.2f);
	centerOrigin(mLight);
	mLight.setPosition(21.f, 80.f);
	
	mLightCountdown = sf::seconds(3);

}

void GameState::draw()
{
	// std::cout << "Draw\n";
	sf::RenderWindow* window = getContext().window;
	window -> draw(mBackground);

	window -> draw(mStaticLevel);

	window -> draw(mFinish);

	window -> draw(mLight);

	for (int i = 0; i < 6; i++) mEnemies[i] -> draw(*window);
	mPlayer -> draw(*window);
}

bool GameState::update(sf::Time dt)
{
	// std::cout << "Game update\n";

	destroyEnemiesOutsideView();
	for (int i = 0; i < 6; i++) {
		if (!mExisted[i]) spawnEnemies(i);
	}

	if (mLightCountdown <= sf::Time::Zero) {
		mTrafficLight = !mTrafficLight;
		mLightCountdown = sf::seconds(3);
	}
	else mLightCountdown -= dt;

	mLight.setTexture(getContext().textures -> get(mTrafficLight ? Textures::RedLight : Textures::GreenLight));

	mFinish.setString((level < 3) ? ("LEVEL " + std::to_string(level + 1)) : ("FINISH"));
	mStaticLevel.setString("Level " + std::to_string(level));

	checkCollisions();
	reachFinishLine();

	if (mPlayer -> getStatus() == Player::Status::Success) {
		if (level < 3) {
			level++;
			buildScene();
		}
		else {
			std::cout << "game Pop\n";
			requestStackPop();
			// requestStackPush(States::End);
		}
	}
	else if (mPlayer -> getStatus() == Player::Status::Failure) {
		std::cout << "game Pop\n";
		requestStackPop();
		// requestStackPush(States::Fail);
	}
	else {
		for (int i = 0; i < mEnemies.size(); i++) {
			if (mTrafficLight && (mEnemies[i]->getType() == Enemy::Type::Car || mEnemies[i]->getType() == Enemy::Type::Truck)) {

			} 
			else mEnemies[i] -> move(dt, level);
		}
		mPlayer -> update(dt);

		adaptPlayerPosition();

		mPlayer -> setVelocity(0.f, 0.f);
	}
	
	return true;
}

bool GameState::handleEvent(const sf::Event& event)
{
	// std::cout << "Game handle event\n";
	if (event.type == sf::Event::KeyPressed) {
		std::cout << "Key pressed\n";
		if (event.key.code == sf::Keyboard::Escape) {
			std::cout << "Game -> Pause no pop\n";
			requestStackPush(States::Pause);
		}
		if (event.key.code == sf::Keyboard::T) {
			std::cout << "Game -> Load no pop\n";
			requestStackPush(States::Load);
		}
		if (event.key.code == sf::Keyboard::L) {
			std::cout << "Game -> Save no pop\n";
			requestStackPush(States::Save);
		}
		if (event.key.code == sf::Keyboard::Up || event.key.code == sf::Keyboard::W) {
			std::cout << "Move up\n";
			mPlayer->accelerate(0, -1);
		}
		if (event.key.code == sf::Keyboard::Down || event.key.code == sf::Keyboard::S) {
			std::cout << "Move down\n";
			mPlayer->accelerate(0, +1);
		}
		if (event.key.code == sf::Keyboard::Left || event.key.code == sf::Keyboard::A) {
			std::cout << "Move left\n";
			mPlayer->accelerate(-1, 0);
		}
		if (event.key.code == sf::Keyboard::Right || event.key.code == sf::Keyboard::D) {
			std::cout << "Move right\n";
			mPlayer->accelerate(+1, 0);
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
	ofstream fout(filename, ios::out | ios::binary | ios::trunc);
	if (!fout) {
		cout << "Can't open file\n";
		fout.close();
		return;
	}

	int lv = level;
	sf::Vector2f pos = mPlayer -> getPosition();

	fout.write((char*) &lv, sizeof(int));
	fout.write((char*) &(pos.x), sizeof(float));
	fout.write((char*) &(pos.y), sizeof(float));

	for (int i = 0; i < 6; i++) {
		sf::Vector2f pos = mEnemies[i] -> getPosition();
		fout.write((char*) &(pos.x), sizeof(float));
		fout.write((char*) &(pos.y), sizeof(float));
	}
	
	fout.write((char*) &(mTrafficLight), sizeof(bool));
	
	for (int i = 0; i < 6; i++) {
		fout.write((char*) &(mExisted[i]), sizeof(bool));
	}
	fout.close();
}

void GameState::load(const std::string& filename) {
	std::cout << "GameState::load\n";
	ifstream fin(filename, ios::in | ios::binary);
	if (!fin) {
		cout << "Can't open file\n";
		fin.close();
		return;
	}

	float x, y;
	fin.read((char*) &x, sizeof(float));
	fin.read((char*) &y, sizeof(float));

	mPlayer -> setPosition(x, y);
	for (int i = 0; i < 6; i++) {
		fin.read((char*) &x, sizeof(float));
		fin.read((char*) &y, sizeof(float));
		mEnemies[i] -> setPosition(x, y);
	}

	fin.read((char*) &mTrafficLight, sizeof(bool));
	for (int i = 0; i < 6; i++) {
		fin.read((char*) &(mExisted[i]), sizeof(bool));
	}
	fin.close();
}

void GameState::buildScene() {
	mPlayer->setStatus(Player::Status::Running);

	mPlayer -> setPosition(450.f, 560.f);

	mPlayer -> setVelocity(0.f, 0.f);

	mFinish.setString((level < 3) ? ("LEVEL " + std::to_string(level + 1)) : ("FINISH"));

	mStaticLevel.setString("Level " + std::to_string(level));

	for (int i = 0; i < 6; i++) {
		mExisted[i] = true;
		bool direction = std::rand() % 2;
		Enemy::Type type = static_cast<Enemy::Type>(rand() % Enemy::Type::TypeCount);
		mEnemies[i] = new Enemy(type, *getContext().textures, direction, direction ? 900.f : 0.f, mLanes[i]);
	}
};

void GameState::adaptPlayerPosition() {
	sf::FloatRect viewBounds = sf::FloatRect(0, 0, getContext().window -> getView().getSize().x, getContext().window -> getView().getSize().y);
	const float borderDistance = 40.f;

	sf::Vector2f position = mPlayer->getPosition();
	position.x = std::max(position.x, viewBounds.left + borderDistance);
	position.x = std::min(position.x, viewBounds.left + viewBounds.width - borderDistance);
	position.y = std::max(position.y, viewBounds.top + borderDistance);
	position.y = std::min(position.y, viewBounds.top + viewBounds.height - borderDistance);
	mPlayer->setPosition(position);
};

void GameState::checkCollisions() {
	for (int i = 0; i < 6; i++) {
		if (mPlayer -> getBound().intersects(mEnemies[i] -> getBound())) {
			mPlayer -> setStatus(Player::Status::Failure);
			std::cout << "Player dies\n";
			return;
		};
	}
};

void GameState::reachFinishLine() {
	if (!sf::FloatRect(0.f, 100.f, 900.f, 500.f).contains(mPlayer->getPosition())) mPlayer -> setStatus(Player::Status::Success);
};

void GameState::spawnEnemies(int index) {
	mExisted[index] = true;
	bool direction = std::rand() % 2;
	Enemy::Type type = static_cast<Enemy::Type>(rand() % Enemy::Type::TypeCount);
	mEnemies[index] = new Enemy(type, *getContext().textures, direction, direction ? 900.f : 0.f, mLanes[index]);
};

void GameState::destroyEnemiesOutsideView() {
	sf::FloatRect mWorldBounds = sf::FloatRect(0.f, 0.f, 900.f, 600.f);
	for (int i = 0; i < 6; i++) {
		if (!mWorldBounds.contains(mEnemies[i] -> getPosition())) {
			delete mEnemies[i];
			mExisted[i] = false;
		}
	}
};