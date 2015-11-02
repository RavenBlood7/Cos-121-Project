#include "Mediator.h"
#include "Player.h"

Mediator::Mediator(Map *newMap)
{
	map = newMap;
}
		
void Mediator::addPlayer(Player* playa)
{
	players.push_back(playa);
}

bool Mediator::update(Unit* unit, int toX, int toY, char toPlace)
{
	int worked = map->Move(unit->getXpos(), unit->getYpos(), toX, toY, toPlace);
	int otherPlayer = 0;	
	
	switch (worked)
	{
		case NOTHING: 
		{
			unit->move(toX, toY);
			return true;
		}
		case OBSTRUCTION: return false;
		case OTHER_UNIT: 
		{
			Unit * otherUnit;
			unsigned int i;

		//find other unit by looking in all of mediator's players' armies in toX toY positions
			for (i = 0; i < players.size(); i++)
			{
				for (unsigned int j = 0; j < players.at(i)->army.size(); j++)
				{
					if (players.at(i)->army.at(j)->getXpos() == toX
						&& players.at(i)->army.at(j)->getYpos() == toY)
					{
						otherUnit = players.at(i)->army.at(j);
						if (i == 0)
						{
							otherPlayer = 1;
						}
						else
						{
							otherPlayer = 0;
						}
						break;
					}
				}
			}
			
		//attack unit
			cout << "Player " << players.at(otherPlayer)->getName() << " is attacking!" << endl;
			cout << "Unit with damage " << unit->getDamage() << " is attacking unit with health " << otherUnit->getHealth() << endl;
			otherUnit->takeDamage(unit->attack(otherUnit));
			cout << "Unit 2 now has " << otherUnit->getHealth() << " health left"<< endl;

		//if unit dies. update map and players barraks
			if (!otherUnit->isAlive())
			{
				for (i = 0; i < players.size(); i++)
				{
					for (unsigned int j = 0; j < players.at(i)->army.size(); j++)
					{
						if (players.at(i)->army.at(j) == otherUnit)
						{
							players.at(i)->army.erase(players.at(i)->army.begin() + j);
						}
					}
				}	
				map->Move(otherUnit->getXpos(), otherUnit->getYpos(), 1, 1, ' ');
				delete otherUnit;				
				cout << "unit has died :(" << endl;
			}

			
			return true;
			
		}
		case OTHER_BASE :
		{
			Unit * otherUnit = players.at(otherPlayer)->army.at(0);

			cout << "Player " << players.at(0)->getName() << " is attacking!" << endl;
			cout << "Unit with damage " << unit->getDamage() << " is attacking unit with health " << otherUnit->getHealth() << endl;
			otherUnit->takeDamage(unit->attack(otherUnit));
			cout << "Unit 2 now has " << otherUnit->getHealth() << " health left"<< endl;			
			if (!otherUnit->isAlive())
			{
				map->Move(otherUnit->getXpos(), otherUnit->getYpos(), 1, 1, ' ');
				delete otherUnit;				
				cout << "unit has died :(" << endl;
			}			
		}
		case OWN_BASE :
		{
			unit->move(toX, toY);
			return true;
		}
	}
	map->printMap();
	return false;
	
}

void Mediator::printMap()
{
	map->printMap();
}