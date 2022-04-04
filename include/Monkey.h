#pragma once

#include "Animal.h"
#include "Io.h"

class Monkey : public Animal {

public:
	Monkey(const string& name, const Location& loc);
	~Monkey();

	virtual void step() override;
	void resetStep();
	virtual void move() override;


private:
	int m_stepCounter = 5;
	int m_stepSize = 1;
};
