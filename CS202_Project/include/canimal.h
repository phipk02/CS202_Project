#ifndef CANIMAL_H_
#define CANIMAL_H_

#include "Object.hpp"
#include "ResourceIdentifiers.hpp"

#include <SFML/Graphics/Sprite.hpp>

class CANIMAL : public Object {
public:
    enum Type { 
        Dinosaur,
        Bird, 
    };
public:
    CANIMAL(Type type, const TextureHolder& textures);
    virtual unsigned int	getCategory() const;

    // Action functions

private:
    virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;

private:
    Type mType;
    sf::Sprite mSprite;
};

#endif // !CANIMAL_H_