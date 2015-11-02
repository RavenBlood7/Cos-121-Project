#include "Computer.h"

Unit* Computer:: createUnit(string type)
{
	Unit* monster;
	
	if ( type == "Magic")
	monster = this->baracks.at(0)->createMonster();	
	else if(type == "Bludgeoning")
	monster = this->baracks.at(1)->createMonster();
	else if(type == "Piercing")
	monster = this->baracks.at(2)->createMonster();
	
	monster->move(3, 3);  						//Change enemy base here and in Map.cpp line 95
	
	return monster;
}
void Computer:: makeMove()
{
	for (unsigned int k = 0; k < 3; k++)
	{
		srand((unsigned)time(0));
		int randChoice = (rand()%3) +1;
		
		if ((army.empty() || randChoice == 1) && army.size() < 6)
		{
			int randMonster = (rand()%3)+1;
			switch (randMonster)
			{
				case 1:  
				{
					addToArmy(createUnit("Magic"));
				} break;
				case 2: 
				{
					addToArmy(createUnit("Bludgeoning"));
				} break;
				case 3:
				{
					addToArmy(createUnit("Piercing"));
				}
			}
			cout << "AI has made a unit" << endl;
		}
		else
		{
			srand((unsigned)time(0));			
			int randUnit = (rand()%army.size()-1 - 0 + 1)+0;
			cout << (this->army.at(randUnit))->getType() << endl;
			moveUnit(this->army.at(randUnit));
		}
		mediator->printMap();	
	}
}

void Computer:: moveUnit(Unit* myUnit)
{
	char toPlace;
	if (myUnit->getType() == "Magic")
	toPlace = 'E';
	else if(myUnit->getType() == "Bludgeoning")
	toPlace = 'O';
	else if(myUnit->getType() == "Piercing")
	toPlace = 'G';	

	srand((unsigned)time(0));
	int randChoice = (rand()%2) +1;	
	switch (randChoice)
	{
	case 1:
		if (!moveLeft(myUnit, toPlace))
		{
			if (!moveUp(myUnit, toPlace))
			{
				if (!moveRight(myUnit, toPlace))
				{
					moveDown(myUnit, toPlace);
				}
			}
		}break;
	case 2:
		if (!moveUp(myUnit, toPlace))
		{
			if (!moveLeft(myUnit, toPlace))
			{
				if (!moveDown(myUnit, toPlace))
				{
					moveRight(myUnit, toPlace);
				}
			}
		}break;
	}		
		

}

bool Computer::moveUp(Unit * unit, char toPlace)
{
	return mediator->update(unit, unit->getXpos() - 1, unit->getYpos(), toPlace);
	cout << "Computer moved up" << endl;
}

bool Computer::moveDown(Unit *unit , char toPlace)
{
	return mediator->update(unit, unit->getXpos() + 1, unit->getYpos(), toPlace);
	cout << "Computer moved down" << endl;
}

bool Computer::moveLeft(Unit * unit, char toPlace)
{
	return mediator->update(unit, unit->getXpos(), unit->getYpos() - 1, toPlace);
	cout << "Computer moved left" << endl;
}

bool Computer::moveRight(Unit *unit, char toPlace)
{
	return mediator->update(unit, unit->getXpos(), unit->getYpos() + 1, toPlace);
	cout << "Computer moved right" << endl;
}

void Computer::createUnit(UnitFactory*)
{
	
}

