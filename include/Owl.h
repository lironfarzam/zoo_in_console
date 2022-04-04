#pragma once

#include "Animal.h"
#include "Io.h"

class Owl : public Animal {

public:
	Owl(const string& name, const Location& loc);
	~Owl();

	virtual void step() override;
	void resetStep();
	virtual void move() override;


private:
	int m_stepSize = 3;
};
