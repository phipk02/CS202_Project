#pragma once

#ifndef CVEHICLE_H_
#define CVEHICLE_H_

#include "ResourceIdentifiers.hpp"
#include "Object.hpp"

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include "ctrafficlight.h"

class CVEHICLE : public Object {
public:
    enum Type {
        Car,
        Truck,
    };
public:
    CVEHICLE(Type type, const TextureHolder& textures);
    virtual unsigned int	getCategory() const;

    // Action functions

private:
    virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;

private:
    Type mType;
    sf::Sprite mSprite;
};

// class CCAR : public CVEHICLE {
// public:
//     CCAR();
//     //void move(int, int);
//     void move();
//     void render(sf::RenderTarget*);
//     const sf::FloatRect getBounds() const;
//     void checkCollision(CVEHICLE* , TrafficLight*);
// };

// class CTRUCK : public CVEHICLE {
// public:
//     CTRUCK();
//     //void move(int, int);
//     void move();
//     void render(sf::RenderTarget*);
//     const sf::FloatRect getBounds() const;
//     void checkCollision(CVEHICLE*, TrafficLight*);
// };

#endif // !CVEHICLE_H_