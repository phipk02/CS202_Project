#ifndef CATEGORY_H
#define CATEGORY_H


// Entity/scene node category, used to dispatch commands
namespace Category
{
	enum Type
	{
		None				= 0,
		SceneAirLayer		= 1 << 0,
		Player		        = 1 << 1,
		Enemy       		= 1 << 2,
	};
}

#endif // CATEGORY_H