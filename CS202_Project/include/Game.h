#ifndef GAME_H_
#define GAME_H_

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include<SFML/Network.hpp>


#include "canimal.h"
#include "src\\canimal.cpp"
#include "cvehicle.h"
#include "src\\cvehicle.cpp"
#include "cpeople.h"
#include "src\\cpeople.cpp"

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

class CGAME {
    public:
    CGAME(sf::RenderWindow*);
    
    int run(int);
    void saveGame(int, sf::RenderWindow*);

    private:
    
    std::vector<CTRUCK> truckFlow;
    std::vector<CCAR> carFlow;
    std::vector<CBIRD> birdFlow;
    std::vector<CDINOSAUR> dinoFlow;
    CPEOPLE player;

    sf::Texture scrInstruction, scrSettings, scrPause, scrDeadScene, scrEnd, scrSave;
    sf::Texture scrWc1, scrWc2, scrWc3, scrGame1, scrGame2, scrGame3;
    sf::Sprite sprInstruction, sprSettings, sprPause, sprDeadScene, sprEnd, sprSave;
    sf::Sprite sprWc1, sprWc2, sprWc3, sprGame1, sprGame2, sprGame3;

    sf::Sprite sprGame;
    sf::RenderWindow* win;
};


#endif

// #ifndef GAME_HPP
// #define GAME_HPP

// #include "World.hpp"

// #include <SFML/System/Time.hpp>
// #include <SFML/Window/Keyboard.hpp>
// #include <SFML/Graphics/Text.hpp>
// #include <SFML/Graphics/Font.hpp>
// #include <SFML/Graphics/RenderWindow.hpp>

// using namespace std;

// class Game : private sf::NonCopyable
// {
// 	public:
// 								Game();
// 		void					run();
		

// 	private:
// 		void					processEvents();
// 		void					update(sf::Time elapsedTime);
// 		void					render();

// 		void					updateStatistics(sf::Time elapsedTime);	
// 		void					handlePlayerInput(sf::Keyboard::Key key, bool isPressed);
		

// 	private:
// 		static const sf::Time	TimePerFrame;

// 		sf::RenderWindow		mWindow;
// 		World					mWorld;

// 	  	sf::Font				mFont;
// 		sf::Text				mStatisticsText;
// 		sf::Time				mStatisticsUpdateTime;
// 		std::size_t				mStatisticsNumFrames;
// };

// #endif // GAME_HPP