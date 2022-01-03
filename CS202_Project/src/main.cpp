#include "../include/Application.h"
//#include "Application.cpp"
#include "../include/Utility.h"
// #include "Utility.cpp"

#include <stdexcept>
#include <iostream>

#include <SFML/Graphics.hpp>

int main()
{
	try
	{
		Application app;
		app.run();
	}
	catch (std::exception& e)
	{
		std::cout << "\nEXCEPTION: " << e.what() << std::endl;
	}
	// sf::Texture test;
	// if (!test.loadFromFile("../asset/Road.png")) {
	// 	std::cout << "aaa\n";
	// }

	// std::cout << "?\n";

	// sf::Sprite a(test);
	// // a.setTextureRect(sf::IntRect(0, 265, 1280, 430));
	// a.setPosition(0, 0);
	// a.setScale(1.f, 0.3f);
	// sf::Texture a;
	// a.loadFromFile("../asset/Road.png");
	// sf::Sprite Background(a);
	// sf::RenderWindow window(sf::VideoMode(900, 600), "AAA");
	// while (true) {
	// 	window.clear(sf::Color::Green);
	// 	window.draw(Background);
	// 	window.display();
	// }
	// sf::Texture Dino_1;
	// Dino_1.loadFromFile("../asset/Dinosaur_1.png");
	// sf::Sprite Dinosaur_1(Dino_1, sf::IntRect(339, 4, 14, 16));
	// centerOrigin(Dinosaur_1);
	// Dinosaur_1.setPosition(67, 110);
	// Dinosaur_1.setScale(2.5f, 2.5f);

	// sf::Texture Dino_2;
	// Dino_2.loadFromFile("../asset/Dinosaur_2.png");
	// sf::Sprite Dinosaur_2(Dino_2, sf::IntRect(222, 4, 14, 16));
	// centerOrigin(Dinosaur_2);
	// Dinosaur_2.setPosition(107, 110);
	// Dinosaur_2.setScale(2.5f, 2.5f);

	// sf::Texture b_1;
	// b_1.loadFromFile("../asset/Bird_1.png");
	// sf::Sprite Bird_1(b_1, sf::IntRect(64, 6, 31, 19));
	// centerOrigin(Bird_1);
	// Bird_1.setPosition(151, 110);
	// Bird_1.setScale(1.34f, 2.f);

	// // Traffic light 0.17f, 0.2f

	// // sf::Texture b_2;
	// // Dino_2.loadFromFile("../asset/Bird_2.png");
	// // sf::Sprite Bird_2(b_2, sf::IntRect(192, 6, 31, 19));
	// // centerOrigin(Bird_2);
	// // Bird_2.setPosition(166, 110);
	// // Bird_2.setScale(1.33f, 2.f);

	// sf::Texture c1;
	// c1.loadFromFile("../asset/Car_1.png");
	// sf::Sprite Car_1(c1);
	// centerOrigin(Car_1);
	// Car_1.setPosition(231, 110);
	// Car_1.setScale(0.07f, 0.1f);

	// sf::Texture c2;
	// c2.loadFromFile("../asset/Car_2.png");
	// sf::Sprite Car_2(c2);
	// centerOrigin(Car_2);
	// Car_2.setPosition(316, 110);
	// Car_2.setScale(0.07f, 0.1f);

	// sf::Texture t1;
	// t1.loadFromFile("../asset/Truck_1.png");
	// sf::Sprite Truck_1(t1);
	// centerOrigin(Truck_1);
	// Truck_1.setPosition(410, 110);
	// Truck_1.setScale(0.33f, 0.27f);

	// sf::Texture t2;
	// t2.loadFromFile("../asset/Truck_2.png");
	// sf::Sprite Truck_2(t2);
	// centerOrigin(Truck_2);
	// Truck_2.setPosition(515, 110);
	// Truck_2.setScale(0.33f, 0.27f);

	// sf::Texture Player;
	// if (!Player.loadFromFile("../asset/Meow.png")) {
	// 	std::cout << "?\n";
	// }
	// sf::Sprite b(Player, sf::IntRect(0, 0, 16, 16));
	// centerOrigin(b);
	// b.setPosition(25, 110);
	// b.setScale(2.5f, 2.5f);
	// sf::RenderWindow window(sf::VideoMode(1280, 1000), "AAA");
	// while (true) {
	// 	window.clear(sf::Color::Green);
	// 	window.draw(a);
	// 	window.draw(b);
	// 	window.draw(Dinosaur_1);
	// 	window.draw(Dinosaur_2);
	// 	window.draw(Bird_1);
	// 	// window.draw(Bird_2);
	// 	window.draw(Car_1);
	// 	window.draw(Car_2);
	// 	window.draw(Truck_1);
	// 	window.draw(Truck_2);
	// 	window.display();
	// }
	return 0;
}