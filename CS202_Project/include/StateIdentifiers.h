#pragma once

#ifndef STATEIDENTIFIERS_H
#define STATEIDENTIFIERS_H

namespace States
{
	enum ID
	{
		None,
		Menu, 		// done
		Game, 		// done but level 1, level 2, level 3
        Load, 		// dont but load function
		Loading, 	// done
		Pause, 		// done
        Save, 		// dont but save function
        End,  		//
		Settings,	//
		Fail,
	};
}

#endif