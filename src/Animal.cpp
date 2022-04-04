#pragma once

#include "Animal.h"

Animal::Animal(const string& name, const Location& loc, const string& type):m_name(name),m_location(loc), m_type(type)
{}

Animal::~Animal()
{}

void Animal::printDetails() const
{
	std::cout << m_name << " - " << m_type << " : " << m_location << std::endl;
}

char Animal::getInitial() const
{
	return m_type[0];
}

string Animal::getType() const
{
	return m_type;
}

void Animal::setLocation(Location loc)
{
	if (!outOfBounds(loc))
		m_location = loc;
}

Location Animal::getLocation() const
{
	return m_location;
}

void Animal::stop()
{
	m_move = false;
}
bool Animal::isMoving() const
{
	return m_move;
}

bool Animal::outOfBounds(Location loc) const
{
	return (loc.m_row < MIN_ROW || loc.m_row >= MAX_ROW || loc.m_col < MIN_COL || loc.m_col >= MAX_COL);
}

void Animal::turnVertially()
{
	m_direction *= {-1, 1};
}

void Animal::turnHorizontally()
{
	m_direction *= {1, -1};
}

