#pragma once

#include <iostream>
#include "cpeople.h"
#include "canimal.h"
#include "cvehicle.h"
#include "menu.h"

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

using namespace std;

enum class GAME_STATE{MENU, LEVEL_1, LEVEL_2, LEVEL_3, GAMEOVER};

typedef void* HANDLE;

class CGAME {
    CTRUCK* axt;
    CCAR* axh;
    CDINOSAUR* akl;
    CBIRD* ac;
    CPEOPLE cn;
    vector<CANIMAL*> animals;
    const int rowCount = 7;
    const int maxVehicle = 5;
    vector<vector<CVEHICLE*>> vehicles;
    vector<sf::Sprite> sprites;


    GAME_STATE gameState = GAME_STATE::MENU;
    Menu *menu = nullptr;

    void initVariables();
    void initWindow();
    void initVehicle();

    sf::RenderWindow* window;
    sf::Event event;
    sf::VideoMode videoMode;

    sf::RectangleShape enemy;
    sf::Texture texture;
    sf::Sprite background;

public:
    CGAME(); 
    void drawGame(); 
    ~CGAME(); 
    CPEOPLE getPeople();
    CVEHICLE* getVehicle();
    CANIMAL* getAnimal(); 
    void resetGame(); 
    void exitGame(HANDLE); 
    void startGame(); 
    void loadGame(istream&); 
    void saveGame(istream&); 
    void pauseGame(HANDLE); 
    void resumeGame(HANDLE); 
    void updatePosPeople(char);
    void updatePosVehicle(); 
    void updatePosAnimal();
    void drawBackground(const string &backgroundIMG);
    void resizeImage(sf::Sprite& sprite);

    void update();
    void render();
    void pollEvents();
    void GetDesktopResolution();
    const bool running() const;
};