#pragma once

#include <vector>
#include <conio.h>
#include <map>

#include "Const.h"
#include "Factory.h"
#include "Animal.h"
#include "Io.h"

class Zoo
{
public:
	Zoo();
	~Zoo();
	
	void run();
	void clear();
	

private:

	void resetMenu();

	int enumMenuToInt(string) const ;
	bool withinLimits(int row, int col);


	void moveAllAnimals();

	void print();
	void printBackGround();
	void printAnimalOnMap();
	void printAtLocation(Location, char);
	void printList();
	void printGetCommend();

	void Menu_stop();
	void Menu_move();
	void Menu_create();
	void create(string, string);
	void Menu_del();
	void deleteAnimalByIndex(int);
	void Menu_delAll();
	void Menu_help();
	void Menu_exit();

	std::vector < std::unique_ptr<Animal>> m_Animals;
	std::map<std::string, int> m_menu;
	int m_animalCounter = 0;
};

