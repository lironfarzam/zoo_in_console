#pragma once

#include "Const.h"
#include "Animal.h"
#include "Lion.h"
#include "Monkey.h"
#include "Owl.h"

// a singleton factory to create game objects

class Factory {
public:
	~Factory();
	static Factory& instance();

	std::unique_ptr<Animal> createAnimal(char,std::string);
	
private:
	Factory();
	Factory(const Factory&) = default;
	Factory& operator=(const Factory&) = default;

};