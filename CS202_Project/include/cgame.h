#pragma once

#include <iostream>
#include "cpeople.h"
#include "canimal.h"
#include "cvehicle.h"
#include "menu.h"

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
// #include <wtypes.h>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>
#include <vector>

using namespace std;

typedef void* HANDLE;

enum class GAMESTATE {LEVEL1, LEVEL2, LEVEL3, PAUSE, MENU, SETTINGS, LOADGAME_MENU, SAVEGAME, GAMEOVER, LOADGAME_PAUSE};

class CGAME {
private:
    // Objects
    vector<CANIMAL*> animals;
    vector<CVEHICLE*> vehicles;
    CPEOPLE player;

    //
    GAMESTATE state = GAMESTATE::MENU;
    GAMESTATE level = GAMESTATE::LEVEL1;
    Menu menu;
    sf::Event event;


    sf::RenderWindow* window;
    sf::VideoMode videoMode;

private:
    void pollEvents();
    void update();
    void render();

public:
    CGAME();
    ~CGAME();

    void run();
};