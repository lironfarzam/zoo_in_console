#pragma once

#include "Animal.h"
#include "Io.h"

class Lion : public Animal{

public:
	Lion(const string& name, const Location& loc);
	~Lion();

	virtual void step() override;
	void resetStep();
	virtual void move() override;

private:
	int m_stepSize = 2;
	
};
