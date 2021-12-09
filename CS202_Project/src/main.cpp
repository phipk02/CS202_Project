#include "../include/Application.h"
#include "Application.cpp"

#include <stdexcept>
#include <iostream>

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
}