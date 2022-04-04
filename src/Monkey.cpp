#pragma once
#include "Monkey.h"

Monkey::Monkey(const string& name, const Location& loc):Animal(name, loc, "Monkey")
{
	resetStep();
}

Monkey::~Monkey()
{
}

void Monkey::step()
{
	m_stepCounter++;

	if (m_stepCounter >= 5)
	{
		resetStep();
	}
	
	Location newLocation = m_location + (m_direction * m_stepSize);
	if (outOfBounds(newLocation))
	{
		resetStep();
	}
	else
	{
		setLocation(newLocation);
	}
	
}

void Monkey::resetStep()
{
	m_stepCounter = 0;
	m_direction = MyRandom::RandomDirectionWDLR_location();
	m_stepSize = MyRandom::RandomNumBetweenBorders(1, 2);
}

void Monkey::move()
{
	if (!isMoving())
	{
		m_move = true;
		resetStep();
	}
}
