#include "Player.h"
#include <iostream>

	void Player:: printArmy()
	{
		for (unsigned int loop =0; loop<army.size();loop++)
		{
			cout<<"Unit "<<loop<<": "<< *army.at(loop)<<endl;
		}
	}
	Player :: Player()
	{
		MagicFactory* MF = new MagicFactory();
		BludgeoningFactory* BF = new BludgeoningFactory();
		PiercingFactory* PF= new PiercingFactory();
		baracks.push_back(MF);
		baracks.push_back(BF);
		baracks.push_back(PF);
		maxUnits = 5;
		moves = 3;
		//mediator = new Mediator();
	}
	Player :: ~Player()
	{
		
	}
	void Player:: addToArmy(Unit* u)
	{
		try
		{
			if(army.size()<=maxUnits)
				army.push_back(u);//!<adds the desired unit to the player's army
			else
				throw 1;
		}
		catch (int e)
		{
			cout<<"You have reached your population limit!"<<endl;
			cout<<"Try moving some units around"<<endl;
			moves+=1;
		}
	}
	bool Player::  IsOut()
	{
		if (army.empty())
			return true;
		else 
			return false;
	}
	void Player:: setMaxUnits(int m)
	{ 
			maxUnits = m;
	}
	void Player::  setName(string n)
	{
		name = n;
	}
	string Player::  getName()
	{
		return name;	
	}
	void Player:: setNumMoves(int n)
	{
		moves =n;
	}
	bool Player:: outOfMoves()
	{
		if (moves ==0)
		{
			moves = 3;
			return true;
		}
		else
			return false;
	}
	//void Player:: checkUnits()
	//{
	
	//}
	void Player:: decreaseMoves()
	{
		try
		{
			if (moves >0)
				moves--;
			else 
				throw 1;
		}
		catch (int e)
		{
			cout<<"You are out of moves!"<<endl;
		}
	}
	
void Player::setMediator(Mediator *med)
{
	mediator = med;
	mediator->addPlayer(this);
}	