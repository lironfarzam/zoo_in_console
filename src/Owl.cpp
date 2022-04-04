#pragma once

#include "Owl.h"

Owl::Owl(const string& name, const Location& loc):Animal(name, loc, "Owl")
{
	resetStep();
}

Owl::~Owl()
{
}

void Owl::step()
{

	Location newLocation = m_location + (m_direction * m_stepSize);
	if (outOfBounds(newLocation))
	{
		m_direction *= {-1, -1};
	}
	else
	{
		setLocation(newLocation);
	}
}

void Owl::resetStep()
{
	m_direction = MyRandom::slant_location();
}

void Owl::move()
{
	if (!isMoving())
	{
		m_move = true;
		resetStep();
	}
}
