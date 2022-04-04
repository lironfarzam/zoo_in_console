#pragma once


#include "Zoo.h"

Zoo::Zoo()
{
	m_Animals.clear();
	resetMenu();
	clear();
	//An initial boot that the zoo will not be empty
	create("Lion", "Simba");
	create("Lion", "Nala");
	create("Lion", "Mufasa");
	create("Monkey", "Rapiky");
	create("Lion", "Sarabi");
	create("Owl", "Owl");
	create("Lion", "Scar");
}

Zoo::~Zoo()
{}

void Zoo::run()
//The main function runs in a loop until you want to close the program
{
	
	string userCommend = "";
	bool stillRunning = true;
	
	while (stillRunning)
	{
		print();
		std::cin >> userCommend;
		int userCommendInInt = enumMenuToInt(userCommend);
		//A menu of options for action
		switch (userCommendInInt)
		{
		case (MENU_STOP):
			Menu_stop();
			break;

		case (MENU_MOVE):
			Menu_move();
			break;

		case (MENU_CREATE):
			Menu_create();
			break;

		case (MENU_DELETE):
			Menu_del();
			break;

		case (MENU_DELETE_ALL):
			Menu_delAll();
			break;

		case (MENU_HELP):
			Menu_help();
			break;

		case (MENU_EXIT):
			Menu_exit();
			stillRunning = false;
			break;

		case (MENU_CONTINU):
			moveAllAnimals();
			break;

		}
	}
}

inline void Zoo::clear()
{
	Screen::clearScreen();
}

void Zoo::resetMenu()
{
	m_menu.insert({"stop", MENU_STOP});
	m_menu.insert({"move", MENU_MOVE});
	m_menu.insert({"create" , MENU_CREATE});
	m_menu.insert({"del", MENU_DELETE});
	m_menu.insert({"delAll", MENU_DELETE_ALL});
	m_menu.insert({"help", MENU_HELP});
	m_menu.insert({"exit",MENU_EXIT});
	m_menu.insert({".", MENU_CONTINU});
}

int Zoo::enumMenuToInt(const string s) const
//Convert a command to an int value to use the menu
{
	if (auto it{ m_menu.find(s) }; it != std::end(m_menu))
	{
		return it->second;
	}
	else
	{
		// Key was not found..
		return 0;
	}
}

void Zoo::Menu_create()
{
	string type; string name;
	Screen::clearScreen();
	std::cout << "Plese enter animal type:" << std::endl;
	std::cin>>type;
	std::cout << "And what would you like to call her?" << std::endl;
	std::cin >> name;
	create(type, name);
}

void Zoo::create(string type, string name)
{
	std::unique_ptr<Animal>temp = Factory::instance().createAnimal(type[0], name);
	if (temp)
	{
		m_animalCounter++;
		temp->printDetails();
		m_Animals.push_back(std::move(temp));
	}
	else
	{
		std::cout << "Oops we do not keep such animals ... probably their place in nature" << endl;
	}
}

void Zoo::Menu_del()
{
	int index;
	Screen::clearScreen();
	std::cout << "Plese enter index of animal to DELETE:" << std::endl;
	std::cin >> index;
	if (0 <= index && index < m_animalCounter)
	{
		deleteAnimalByIndex(index);
	}
	else
	{
		std::cout << "Not in our zoo ..." << std::endl;
	}
}

void Zoo::deleteAnimalByIndex(int index)
{
	m_Animals.erase(m_Animals.begin() + index);
	m_animalCounter--;
}

void Zoo::Menu_delAll()
{
	Screen::clearScreen();
	string animalType;
	char yesOrNo;
	std::cout << "What type of animal do you want to delete? " << std::endl;
	std::cin >> animalType;
	std::cout << "You're going to release all the "<< animalType<<" so there are no left in the zoo... Are you sure? [N \ Y]" << std::endl;
	std::cin >> yesOrNo;
	if (yesOrNo == 'Y' || yesOrNo == 'y')
	{
		for (int i= m_animalCounter -1; i >= 0; i--)
		{
			if (m_Animals[i]->getType() == animalType)
			{
				deleteAnimalByIndex(i);
			}
		}
		std::cout << "All"<< animalType <<"were released back into the wild" << std::endl;
	}
	else
	{
		std::cout << "A wise decision, all the animals continue to roam the zoo area" << std::endl;
	}
}

void Zoo::Menu_help()
{
	clear();
	std::cout << std::endl;
	std::cout << "  Welcome to Liron Zoo's help system:" << std::endl<< std::endl;
	std::cout << "  stop   -> Select an animal in the zoo according to the index and stop the movement until the [move] command" << std::endl;
	std::cout << "  move   -> Select an animal in the zoo according to the index of continued movement until the [stop] command" << std::endl;
	std::cout << "  craetr -> Create a new animal and add it to the zoo area." << std::endl;
	std::cout << "  del    -> Erase an animal according to an index and release it into the wild." << std::endl;
	std::cout << "  delAll -> Deletion of all animals of a certain type and their release into the wild." << std::endl;
	std::cout << "  help   -> Open the help directory." << std::endl;
	std::cout << "  exit   -> Close the program." << std::endl<< std::endl;
	std::cout << "  Click each button to return to the zoo." << std::endl;
	//int c = getchar();
	_getch();
}

void Zoo::Menu_exit()
{
	clear();
	std::cout<<std::endl;
	std::cout <<"Thank you for visiting our zoo :) Come again." <<std::endl;

}

void Zoo::moveAllAnimals()
{
	for (auto& animal : m_Animals)
	{
		if (animal->isMoving())
		{
			animal->step();
		}
	}
}

void Zoo::print()
{
	clear();
	printBackGround();
	printList();
	printAnimalOnMap();
	printGetCommend();
	
}

void Zoo::printBackGround()
{
	std::cout << std::string((2 + MAX_COL), '#') << std::endl;
	for (int i = 0; i < MAX_ROW; i++)
	{
		std::cout << '#' << std::string(MAX_COL, ' ') << '#' << std::endl;
		//std::cout << i << std::string(MAX_COL, ' ') << '#' << std::endl;
	}
	std::cout << std::string((2 + MAX_COL), '#') << std::endl;
}

void Zoo::printAnimalOnMap()
{
	for (auto& animal : m_Animals)
	{
		Location l = animal->getLocation();
		char c = animal->getInitial();
		printAtLocation(l, c);
	}
}

void Zoo::printAtLocation(Location l, char c)
{
	Screen::setLocation(l);
	cout << c;
}

void Zoo::printList()
{
	//empty rows saved for comend
	std::cout << endl<< endl << endl;
	int i = 0;
	for (auto& animal : m_Animals)
	{
		std::cout << i << ". ";
		animal->printDetails();
		i++;
	}
}

void Zoo::printGetCommend()
{
	Screen::setLocation({MAX_ROW + 1,0});
	cout <<"Enter a commend:" << endl;
}

void Zoo::Menu_stop()
{
	Screen::clearScreen();
	int index = 0;
	std::cout << "Plese enter animal index to stop:" << std::endl;
	std::cin >> index;
	if (0<= index && index < m_animalCounter)
	{
		m_Animals[index]->stop();
	}
	else
	{
		std::cout << "Not in our zoo ..." << std::endl;
	}
}

void Zoo::Menu_move()
{
	Screen::clearScreen();
	int index = 0;
	std::cout << "Plese enter animal index to move:" << std::endl;
	std::cin >> index;
	if (0 <= index && index < m_animalCounter)
	{
		m_Animals[index]->move();
	}
	else
	{
		std::cout << "Not in our zoo ..." << std::endl;
	}
}

bool Zoo::withinLimits(int row, int col)
{
	return (MIN_COL <= col && col <= MAX_COL) && (MIN_ROW <= row && row <= MAX_ROW);
}
