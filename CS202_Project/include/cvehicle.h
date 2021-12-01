#pragma once

#ifndef CVEHICLE_H_
#define CVEHICLE_H_

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include<SFML/Network.hpp>

class CVEHICLE {
    // bool state; // 0: moving, 1: stopped
protected:
    sf::Texture vTexture;
    sf::Sprite vSprite;
    float moveSpeed;
    friend class CGAME;
public:
    //virtual void move(int, int) = 0;
    virtual void move() = 0;
    virtual void render(sf::RenderTarget*) = 0;
    virtual const sf::FloatRect getBounds() const = 0;
};

class CCAR : public CVEHICLE {
public:
    CCAR();
    //void move(int, int);
    void move();
    void render(sf::RenderTarget*);
    const sf::FloatRect getBounds() const;
};

class CTRUCK : public CVEHICLE {
public:
    CTRUCK();
    //void move(int, int);
    void move();
    void render(sf::RenderTarget*);
    const sf::FloatRect getBounds() const;
};

#endif // !CVEHICLE_H_