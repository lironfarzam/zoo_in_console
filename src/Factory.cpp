#pragma once

#include "Factory.h"

#include <iostream>

/*
*  A SINGLETON factory to create game objects
*/

Factory::~Factory()
{
}

Factory& Factory::instance()
{
    static Factory inst;
    return inst;
}


Factory::Factory()
{
}

std::unique_ptr<Animal> Factory::createAnimal(char type , std::string name)
{
    //Random location within the zoo
    int startRow = (rand() % MAX_ROW - MIN_ROW) + MIN_ROW;
    int startCol = (rand() % MAX_COL - MIN_COL) + MIN_COL;

    switch (type)
    {
    case (LION):
        return std::make_unique<Lion>(name, Location{ startRow,startCol });
        break;
    
    case (MONKEY):
        return std::make_unique<Monkey>(name, Location{ startRow,startCol });
        break;
    
    case (OWL):
        return std::make_unique<Owl>(name, Location{ startRow,startCol });
        break;
    }

    return nullptr;
}

