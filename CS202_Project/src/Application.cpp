#include "../include/Application.h"

//#include "State.cpp"
//#include "StateStack.cpp"

bool Application::sound = true;
const sf::Time Application::TimePerFrame = sf::seconds(1.f/60.f);

Application::Application()
: mWindow(sf::VideoMode(900, 600), "Game", sf::Style::Close)
, mTextures()
, mFonts()
, mStateStack(nullptr)
, mStatisticsText()
, mStatisticsUpdateTime()
, mStatisticsNumFrames(0)
{
	mStateStack = new StateStack(State::Context(mWindow, mTextures, mFonts));

	mWindow.setKeyRepeatEnabled(false);

	mFonts.load(Fonts::Main, "E:/CS202/Project1/Project1/asset/myfont.ttf");
	// mTextures.load(Textures::TitleScreen, "Media/Textures/TitleScreen.png");

	mTextures.load(Textures::Background, "E:/CS202/Project1/Project1/asset/Background.png");
	mTextures.load(Textures::Bird1, "E:/CS202/Project1/Project1/asset/Bird_1.png");
	mTextures.load(Textures::Bird2, "E:/CS202/Project1/Project1/asset/Bird_2.png");
	mTextures.load(Textures::Car1, "E:/CS202/Project1/Project1/asset/Car_1.png");
	mTextures.load(Textures::Car2, "E:/CS202/Project1/Project1/asset/Car_2.png");
	mTextures.load(Textures::Dinosaur1, "E:/CS202/Project1/Project1/asset/Dinosaur_1.png");
	mTextures.load(Textures::Dinosaur2, "E:/CS202/Project1/Project1/asset/Dinosaur_2.png");
	mTextures.load(Textures::Player, "E:/CS202/Project1/Project1/asset/Meow.png");
	mTextures.load(Textures::Truck1, "E:/CS202/Project1/Project1/asset/Truck_1.png");
	mTextures.load(Textures::Truck2, "E:/CS202/Project1/Project1/asset/Truck_2.png");
	mTextures.load(Textures::Road, "E:/CS202/Project1/Project1/asset/Road.png");
	mTextures.load(Textures::GreenLight, "E:/CS202/Project1/Project1/asset/GreenLight.png");
	mTextures.load(Textures::RedLight, "E:/CS202/Project1/Project1/asset/RedLight.png");

	mStatisticsText.setFont(mFonts.get(Fonts::Main));
	mStatisticsText.setPosition(5.f, 5.f);
	mStatisticsText.setCharacterSize(20u);
	mStatisticsText.setFillColor(sf::Color::Red);

	registerStates();
	mStateStack -> pushState(States::Menu);

	mWindow.setKeyRepeatEnabled(true);
}

void Application::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;

	while (mWindow.isOpen())
	{
		mWindow.clear();
		sf::Time dt = clock.restart();

		// std::cout << "Time: " << dt.asSeconds() << "\n";

		timeSinceLastUpdate += dt;
		while (timeSinceLastUpdate > TimePerFrame)
		{
			timeSinceLastUpdate -= TimePerFrame;

			processInput();
			update(TimePerFrame);

			// Check inside this loop, because stack might be empty before update() call
			if (mStateStack -> isEmpty())
				mWindow.close();
		}

		updateStatistics(dt);
		render();
	}
}

void Application::processInput()
{
	sf::Event event;
	while (mWindow.pollEvent(event))
	{
		mStateStack -> handleEvent(event);

		if (event.type == sf::Event::Closed)
			mWindow.close();
	}
}

void Application::update(sf::Time dt)
{
	mStateStack -> update(dt);
}

void Application::render()
{
	mWindow.clear();

	mStateStack -> draw();

	mWindow.setView(mWindow.getDefaultView());
	mWindow.draw(mStatisticsText);

	mWindow.display();
}

void Application::updateStatistics(sf::Time dt)
{
	mStatisticsUpdateTime += dt;
	mStatisticsNumFrames += 1;
	if (mStatisticsUpdateTime >= sf::seconds(1.0f))
	{
		mStatisticsText.setString("FPS: " + toString(mStatisticsNumFrames));

		mStatisticsUpdateTime -= sf::seconds(1.0f);
		mStatisticsNumFrames = 0;
	}
}

void Application::registerStates()
{
	mStateStack -> registerState<LoadingState>(States::Loading);
	mStateStack -> registerState<MenuState>(States::Menu);
	mStateStack -> registerState<GameState>(States::Game);
	mStateStack -> registerState<PauseState>(States::Pause);
	mStateStack -> registerState<SaveState>(States::Save);
	mStateStack -> registerState<LoadState>(States::Load);
	mStateStack -> registerState<SettingsState>(States::Settings);
}