#pragma once

#ifndef ENEMY_H
#define ENEMY_H

#include "ResourceHolder.h"
#include "ResourceIdentifiers.h"
//#include "Game.h"

// #include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

class Enemy {
    public:
        enum Type {
            Bird,
            Car,
            Dinosaur,
            Truck,
            TypeCount
        };

    public:
                                Enemy(Type type, const TextureHolder& textures, bool direction, float x, float y);
                                ~Enemy() {};
        void                    move(sf::Time dt, int level);
        // void                    reset(sf::RenderWindow& windows);
        // void                    spawn(sf::Vector2f mLanePosition);
        void                    draw(sf::RenderWindow& windows);
        sf::Vector2f            getPosition();
        const Type              getType();

        void                    setPosition(float x, float y);


        const sf::FloatRect     getBound();
    
    private:
        Type                    mType;
        sf::Sprite              mSprite;
        float                   mSpeed;
        bool                    mDirection;
};

#endif