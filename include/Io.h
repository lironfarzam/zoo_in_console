#pragma once

#include "Location.h"

namespace Screen
{
	// Reset terminal cursor location to start of the screen (0,0)
	void resetLocation();
	// Set terminal cursor location to the desired location
	void setLocation(const Location location);
	void clearScreen();
}

namespace MyRandom
{
	int leftOrRight_int();
	int RandomNumBetweenBorders(int, int);
	Location leftOrRight_location();
	Location upOrDown_location();
	Location slant_location();
	Location RandomDirectionWDLR_location();
				   
}