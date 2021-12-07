// #ifndef CATEGORY_HPP
// #define CATEGORY_HPP


// // Entity/scene node category, used to dispatch commands
// namespace Category
// {
// 	enum Type
// 	{
// 		None				= 0,
// 		Scene				= 1 << 0,
// 		Player		= 1 << 1,
// 		Enemy		= 1 << 2,
// 	};
// }

// /** This makes it possible to combine different categories with the bitwise OR operator.
//     When we want to send a command to all available airplanes, we can create a
//     combined category as follows:
//     unsigned int anyAircraft = Category::PlayerAircraft
//                              | Category::AlliedAircraft
//                              | Category::EnemyAircraft;
//  */

// #endif // CATEGORY_HPP