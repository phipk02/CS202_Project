// #include "SFML/Graphics.hpp"
// #ifndef MENU_H
// #define MENU_H
// #define MAX_NUMBER_OF_ITEM 3
// class Menu {
// public:
//     virtual void draw(sf::RenderWindow& window) = 0;
//     virtual void MoveUp() = 0;
//     virtual void MoveDown() = 0;
//     virtual int getPressedItem() = 0;
// protected:
//     int selectedItemIndex = 0;
//     sf::Texture title;
//     sf::Font font;
//     sf::Text menu[MAX_NUMBER_OF_ITEM];
// };

// class MainMenu : public Menu {
// public:
//     MainMenu(float width, float height);

//     void draw(sf::RenderWindow& window);
//     void MoveUp();
//     void MoveDown();
//     int getPressedItem();
// };

// class SaveMenu : public Menu {
// public:
//     SaveMenu(float width, float height);

//     void draw(sf::RenderWindow& window);
//     void MoveUp();
//     void MoveDown();
//     int getPressedItem();
// };

// class PauseMenu : public Menu {
// public:
//     PauseMenu(float width, float height);

//     void draw(sf::RenderWindow& window);
//     void MoveUp();
//     void MoveDown();
//     int getPressedItem();
// };

// class NextLevelScreen : public Menu {
// public:
//     NextLevelScreen(float width, float heigh);
//     void draw(sf::RenderWindow& window);
//     void MoveUp();
//     void MoveDown();
//     int getPressedItem();
// private:
//     int NUMBER_OF_ITEMS = 2;
// };
// #endif

// /*
// * HAM MAIN MAU
// * int main()
// {
//     sf::RenderWindow window(sf::VideoMode(800, 600), "menu");

//     MainMenu mainMenu(window.getSize().x, window.getSize().y);
//     SaveMenu saveMenu(window.getSize().x, window.getSize().y);
//     PauseMenu pauseMenu(window.getSize().x, window.getSize().y);
//     NextLevelScreen nextMenu(window.getSize().x, window.getSize().y);

//     while (window.isOpen())
//     {
//         sf::Event event;
//         while (window.pollEvent(event))
//         {
//             switch (event.type) {
//             case sf::Event::KeyReleased:
//                 switch (event.key.code) {
//                 case sf::Keyboard::Up:
//                     mainMenu.MoveUp();
//                     break;

//                 case sf::Keyboard::Down:
//                     mainMenu.MoveDown();
//                     break;

//                 case sf::Keyboard::Return:
//                     switch (mainMenu.getPressedItem()) {
//                     case 0:
//                         // lam gi khi chon lua chon thu nhat
//                         break;
//                     case 1:
//                         // lam gi khi chon lua chon thu hai
//                         break;
//                     case 2:
//                         // lam gi khi chon lua chon thu ba
//                         break;
//                     }
//                     break;
//                 }
//                 break;

//             case sf::Event::Closed:
//                 window.close();
//                 break;
//             }
//         }

//         window.clear(sf::Color(32, 33, 36, 255));

//         mainMenu.draw(window);

//         window.display();
//     }
//     return 0;
// }
// */
