// #ifndef BOOK_COMMAND_HPP
// #define BOOK_COMMAND_HPP

// /*Commands denote messages that are sent to various game objects.
// /*A command is able to alter the object and to issue orders such as moving an entity, making sounds, ...


// /** The following example shows std::function in action. First, we assign a function
//  *  pointer to it, then we assign a lambda expression:
//  *      int add(int a, int b) { return a + b };
//  *      std::function<int(int, int)> adder1 = &add;
//  *      std::function<int(int, int)> adder2 = [] (int a, int b) { return a + b; };
//  *  The std::function object can be called using its overloaded operator():
//  *      int sum = adder1(3, 5); // same as add(3, 5)
//  *  The Command structure's member variable action contains the function that implements the order issued to an object.
//  *  The first parameter is a reference to a scene node, which is affected by the command.
//  *  The second parameter denotes the delta time of the current frame. For example, we can instantiate a command as follows:
//  *          void moveLeft(SceneNode& node, sf::Time dt)
//  *              {
//  *                  node.move(-30.f * dt.asSeconds(), 0.f);
//  *              }
//  *          Command c;
//  *          c.action = &moveLeft;
//  *  Using the lambda expressions, the equivalent functionality can be written as follows:
//  *          c.action = [] (SceneNode& node, sf::Time dt)
//  *              {
//  *                  node.move(-30.f * dt.asSeconds(), 0.f);
//  *              };
//  *  In short, we can now define any operation on a scene node inside a Command object.
//  *  The advantage of a command over a direct function call is abstraction: We do not
//  *  need to know on which scene node to invoke the function; we only specify the action
//  *  that is performed on it. The message passing system is responsible to deliver the
//  *  commands to the correct recipients
// */

// #include "Category.hpp"

// #include <SFML/System/Time.hpp>

// #include <functional>
// #include <cassert>


// class SceneNode;

// struct Command
// {
// 												Command();

// 	std::function<void(SceneNode&, sf::Time)>	action;
// 	unsigned int								category;
// };

// template <typename GameObject, typename Function>
// std::function<void(SceneNode&, sf::Time)> derivedAction(Function fn)
// {
// 	return [=] (SceneNode& node, sf::Time dt)
// 	{
// 		// Check if cast is safe
// 		assert(dynamic_cast<GameObject*>(&node) != nullptr);

// 		// Downcast node and invoke function on it
// 		fn(static_cast<GameObject&>(node), dt);
// 	};
// }

// #endif // BOOK_COMMAND_HPP