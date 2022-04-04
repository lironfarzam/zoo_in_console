#pragma once
#include "Location.h"
#include "Const.h"
#include <string>

class Animal
{
public:
	Animal(const string& name, const Location& loc, const string& type);
	~Animal();

	virtual void step() = 0;
	virtual void move() = 0;

	virtual void stop();
	virtual void printDetails() const;
	virtual char getInitial() const;
	virtual void setLocation(Location);
	virtual Location getLocation() const;
	virtual bool isMoving() const;
	virtual bool outOfBounds(Location) const;
	virtual void turnHorizontally();
	virtual void turnVertially();
	virtual string getType()const;

protected:
	
	Location m_location = {0,0};
	Location m_direction = {0,0}; 
	string m_name = "";
	string m_type = "";
	bool m_move = true;

private:
	
};
