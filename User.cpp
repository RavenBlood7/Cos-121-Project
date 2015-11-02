#include "User.h"

void User:: createUnit(UnitFactory*u)
{
	addToArmy(u->createPlayer());
}

void User:: makeMove()
{
		int choice;
		int type;
		int unit;
		char move;
		cout<< "\033[1;33m"<<"Player "<<getName()<<" your turn starts now\033[0m\n";
		while(!outOfMoves())
		{
			cout<<"\033[1;32mChoose your move\033[0m\n"<<endl;
			cout<<"\033[1;32m To create a new unit press 1\033[0m\n"<<endl;
			cout<<"\033[1;32m To move units press 2\033[0m\n"<<endl;
			cin>>choice;
		
		
			if(choice== 1)
			{	
				cout<<"\033[1;32mEnter the type of unit you want to make\033[0m\n"<<endl;
				cout<<"\033[32mTo create a Mage enter 1\033[0m\n"<<endl;
				cout<<"\033[32mTo create a Soldier enter 2\033[0m\n"<<endl;
				cout<<"\033[32mTo create a Thief enter 3\033[0m\n"<<endl;
				cin>>type;
				
				switch (type)
				{
					case 1:
						{
							createUnit(baracks.at(0));
						}; break;
					case 2:
						{
							createUnit(baracks.at(1));
						};break;
					case 3:
						{
							createUnit(baracks.at(2));
						}break;
				}
			}
			else if(choice== 2)
			{
				cout<<" \033[1;33mChoose a unit to move\033[0m\n "<<endl;
				printArmy();
				cin>>unit;
				cout<<"\033[1;33m Enter W to move up, A to move left, S to move down or D to move right\033[0m\n";
				cin>>move;
				switch (move)
				{
					case 'W': moveUp(army.at(unit)); break;
					case 'S': moveDown(army.at(unit)); break;
					case 'A': moveLeft(army.at(unit)); break;
					case 'D': moveRight(army.at(unit)); break;
				};

			}
			
		mediator->printMap();
		decreaseMoves();
		}
		cout<<"\033[33m Turn Over \033[0m\n"<<endl;
}
void User:: moveUnit(Unit* myUnit, int x, int y)
{
	myUnit->move((myUnit->getXpos()+x),myUnit->getYpos()+y);//!<this moves the unit on the map according to what the user enters
}

void User::moveUp(Unit * unit)
{
	char toPlace;
	if (unit->getType() == "Magic")
	toPlace = 'M';
	else if(unit->getType() == "Bludgeoning")
	toPlace = 'S';
	else if(unit->getType() == "Piercing")
	toPlace = 'T';
	if (!mediator->update(unit, unit->getXpos() - 1, unit->getYpos(), toPlace))
	{
		cout << "Invalid move" << endl;
	}
}

void User::moveDown(Unit * unit)
{
	char toPlace;
	if (unit->getType() == "Magic")
	toPlace = 'M';
	else if(unit->getType() == "Bludgeoning")
	toPlace = 'S';
	else if(unit->getType() == "Piercing")
	toPlace = 'T';
	if (!mediator->update(unit, unit->getXpos() + 1, unit->getYpos(), toPlace))
	{
		cout << "Invalid move" << endl;
	}
}

void User::moveLeft(Unit * unit)
{
	char toPlace;
	if (unit->getType() == "Magic")
	toPlace = 'M';
	else if(unit->getType() == "Bludgeoning")
	toPlace = 'S';
	else if(unit->getType() == "Piercing")
	toPlace = 'T';
	if (!mediator->update(unit, unit->getXpos(), unit->getYpos() - 1, toPlace))
	{
		cout << "Invalid move" << endl;
	}
}

void User::moveRight(Unit *unit)
{
	char toPlace;
	if (unit->getType() == "Magic")
	toPlace = 'M';
	else if(unit->getType() == "Bludgeoning")
	toPlace = 'S';
	else if(unit->getType() == "Piercing")
	toPlace = 'T';
	if (!mediator->update(unit, unit->getXpos(), unit->getYpos() + 1, toPlace))
	{
		cout << "Invalid move" << endl;
	}	
}