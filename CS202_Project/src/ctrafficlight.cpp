// #include "../include/ctrafficlight.h"

// TrafficLight::TrafficLight() {
//     //lightRed.loadFromFile("asset\\traffic light.png", sf::IntRect(121, 0, 120, 191));
//     //lightGreen.loadFromFile("asset\\traffic light.png", sf::IntRect(0, 0, 120, 191));
//     green = true;
//     tlSprite.setTexture(lightGreen);
//     //tlSprite.setScale(0.15, 0.15);
//     //tlSprite.setPosition(, );
// }

// void TrafficLight::switchLight() {
//     green = !green;
//     if (green) {
//         tlSprite.setTexture(lightGreen);
//         tlSprite.setScale(0.2, 0.2);
//     }
//     else {
//         tlSprite.setTexture(lightRed);
//         tlSprite.setScale(0.2, 0.2);
//     }
// }

// bool TrafficLight::isGreen() {
//     return green;
// }

// const sf::FloatRect TrafficLight::getBounds() const {
//     return tlSprite.getGlobalBounds();
// }

// void TrafficLight::render(sf::RenderTarget* window) {
//     window->draw(tlSprite);
// }

// void TrafficLight::setPos(float posX, float posY) {
//     tlSprite.setPosition(posX, posY);
// }