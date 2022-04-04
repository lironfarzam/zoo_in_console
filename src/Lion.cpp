#pragma once 

#include "Lion.h"

Lion::Lion(const string& name, const Location& loc):Animal(name,loc,"Lion")
{
	//set random the first direction 
	resetStep();
}

Lion::~Lion()
{
}
void Lion::step()
{
	Location newLocation = (m_location + (m_direction * m_stepSize));

	if (outOfBounds(newLocation))
	{
		turnHorizontally();
	}
	else
	{
		setLocation(newLocation);
	}
}

void Lion::resetStep()
{
	m_direction = MyRandom::leftOrRight_location();
}

void Lion::move()
{
	if (!isMoving())
	{
		m_move = true;
		resetStep();
	}
}

