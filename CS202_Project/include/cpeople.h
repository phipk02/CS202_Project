#ifndef CPEOPLE_H_
#define CPEOPLE_H_

//

class CPEOPLE {

    public:
    CPEOPLE();
    void render(sf::RenderWindow*);
    void resetState();
    void moveLeft();
    void moveRight();
    void moveUp();
    void moveDown();
    bool isImpact(CVEHICLE*);
    bool isImpact(CANIMAL*);
    bool isVictory();

    private:
    sf::Texture pTexture;
    sf::Sprite pSprite;
    float velocity;
};


#endif

// #pragma once

// // Player

// #include "cvehicle.h"
// #include "canimal.h"
// #include "CommandQueue.hpp"

// #include "ResourceIdentifiers.hpp"

// class CPEOPLE : public Object
// {
// public:
// 		enum Action
// 		{
// 			MoveLeft,
// 			MoveRight,
// 			MoveUp,
// 			MoveDown,
// 			ActionCount
// 		};


// 	public:
// 								CPEOPLE();

// 		void					handleEvent(const sf::Event& event, CommandQueue& commands);
// 		void					handleRealtimeInput(CommandQueue& commands);

// 		void					assignKey(Action action, sf::Keyboard::Key key);
// 		sf::Keyboard::Key		getAssignedKey(Action action) const;


// 	private:
// 		void					initializeActions();
// 		static bool				isRealtimeAction(Action action);


// 	private:
// 		std::map<sf::Keyboard::Key, Action>		mKeyBinding;
// 		std::map<Action, Command>				mActionBinding;
// };