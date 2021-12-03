
#ifndef TRAFFICLIGHT_H_
#define TRAFFICLIGHT_H_

class TrafficLight {
private:
    sf::Texture lightRed;
    sf::Texture lightGreen;
    sf::Sprite tlSprite;
    bool green;
public:
    TrafficLight();
    void setPos(float posX, float posY);
    bool isGreen();
    void switchLight();
    const sf::FloatRect getBounds() const;
    void render(sf::RenderTarget*);
};

#endif