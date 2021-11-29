#include "../include/cgame.h"

void CGAME::pollEvents() {
    while (window -> pollEvent(event)) {
        switch (event.type) {
            case sf::Event::Closed: {
                window -> close();
                break;
            }
            case sf::Event::KeyPressed: {
                switch (event.key.code) {
                    case sf::Keyboard::Escape: {
                        if (state == GAMESTATE::PAUSE) {
                            // continue game
                        }
                        else if (state == GAMESTATE::LOADGAME_PAUSE) {
                            // return pause screen
                        }
                        else if (state == GAMESTATE::LOADGAME_MENU || state == GAMESTATE::SETTINGS || state == GAMESTATE::GAMEOVER) {
                            // return menu screen
                        }
                        else if (state == GAMESTATE::MENU) {
                            // exit game
                        }
                        else
                            // pause game
                        break;
                    }

                    case sf::Keyboard::W:
                    case sf::Keyboard::Up: {
                        // Pause screen
                        if (state == GAMESTATE::PAUSE) { // continue, save, load, exit
                            
                        }
                        else if (state == GAMESTATE::MENU) { // Menu screen: start, load, settings

                        }
                        else if (state == GAMESTATE::GAMEOVER) { // GAMEOVER: load, try again, exit

                        }
                        else if (state == GAMESTATE::LEVEL1 || state == GAMESTATE::LEVEL2 || state == GAMESTATE::LEVEL3) { 
                            // player 
                        }
                        break;
                    }

                    case sf::Keyboard::S:
                    case sf::Keyboard::Down: {
                        // Pause screen
                        if (state == GAMESTATE::PAUSE) {
                            
                        }
                        else if (state == GAMESTATE::MENU) { // Menu screen

                        }
                        else if (state == GAMESTATE::GAMEOVER) { // GAMEOVER

                        }
                        else if (state == GAMESTATE::LEVEL1 || state == GAMESTATE::LEVEL2 || state == GAMESTATE::LEVEL3) { 
                            // player 
                        }
                        break;
                    }

                    case sf::Keyboard::A:
                    case sf::Keyboard::Left: {
                        // move player left
                        break;
                    }

                    case sf::Keyboard::D:
                    case sf::Keyboard::Right: {
                        // move player up
                        break;
                    }

                    case sf::Keyboard::Return: {
                        // pause

                        // menu

                        // gameover
                    }
                }
            }
        }
    }
}