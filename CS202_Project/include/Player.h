#pragma once

#ifndef PLAYER_H
#define PLAYER_H

#include "ResourceHolder.h"
#include "ResourceIdentifiers.h"

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include <map>

class Player {
    public:
        enum Status {
            Running,
            Success,
            Failure,
        };

    public:
                                                Player(const TextureHolder& textures);

        void                                    load(float x, float y);
        
        void                                    setStatus(const Status& status);
        Status                                  getStatus();

        void                                    setPosition(sf::Vector2f& other);
        void                                    setPosition(float x, float y);
        sf::Vector2f                            getPosition();

        void                                    draw(sf::RenderWindow& window);

        void                                    setVelocity(float x, float y);
        void                                    setVelocity(sf::Vector2f& other);

        void                                    accelerate(float x, float y);
        void                                    accelerate(sf::Vector2f& other);

        void                                    update(sf::Time dt);
        const sf::FloatRect                     getBound();

    private:
        sf::Sprite                              mSprite;
        sf::Vector2f                            mVelocity;

        float                                   mSpeed;
        Status                                  mStatus;
};

#endif // !PLAYER_H
