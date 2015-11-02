/**
*	@file Computer.h
*	@class User
*
*	@brief A human player
*	
*	@section Description
*	A class that defines a human player
*	
*	@section License
*	Copyright belongs to Merissa Joubert and Juan du Preez
*	
*/
#ifndef USER_H
#define USER_H
#include "Player.h"
#include "Mediator.h"
#include <iostream>
using namespace std;

class User:  public Player
{
	public:	
		void createUnit(UnitFactory*);//!< createUnit uses a unitFactory to create a new unit and add it to the player's army
		/*!
			@param u is a UnitFactory used to create the new unit;
		*/
		void makeMove();//!< makeMove encapsulates the algorithm used to move units across the map and add them to the map
		void moveUnit(Unit*,int,int);//!< @todo update
		void moveUp(Unit *);//!< moveUp moves the current unit one block up on the map
		void moveDown(Unit *);//!< moveDown moves the current unit one block down on the map
		void moveLeft(Unit *);//!< moveLeft moves the current unit one block left on the map
		void moveRight(Unit *);//!< moveRight moves the current unit one block to the right on the map	
};
#endif