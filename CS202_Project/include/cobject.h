#ifndef _COBJECT_H_
#define _COBJECT_H_

#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <Windows.h>

using namespace std;

class COBJECT {
protected:
	// float mX, mY;
public:
	COBJECT(float x, float y);

	virtual void drawObject(sf::RenderWindow& window);
};

#endif