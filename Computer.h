/**
*	@file Computer.h
*	@class Computer
*
*	@brief An abstract class that defines a computer player.
*	
*	@section Description
*	Encapsulates the basic properties of computer players.
*	
*	@section License
*	Copyright belongs to Juan du Preez and Merissa Joubert
*	
*/
#ifndef COMPUTER_H
#define COMPUTER_H
#include "Player.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

class Computer: public Player
{
	public:
	void createUnit(UnitFactory*);//!< createUnit creates a unit of a specific type
	/**
	@param type holds the type of unit to be created
	*/
	Unit* createUnit(string type);// What does this do?
	void makeMove();//!< Encapsulates the method that is used to move units across the map and add them to the maps
	void moveUnit(Unit*);//!< moves a unit to a new position on the map
	/**
	@param u is a pointer to the unit that will be moved
	*/

	bool moveUp(Unit * unit, char toPlace);//!< moveUp moves the current unit up one block on the map
	/**
	@param unit is a unit pointer to the current unit being moved
	@param a character W/A/S/D that tells the mediator where the unit will move
	*/
	bool moveDown(Unit * unit, char toPlace);//!< moveDown moves the current unit down one block on the map
	/**
	@param unit is a unit pointer to the current unit being moved
	@param a character W/A/S/D that tells the mediator where the unit will move
	*/
	bool moveLeft(Unit * unit, char toPlace);//!< moveLeft moves the current unit left one block on the map
	/**
	@param unit is a unit pointer to the current unit being moved
	@param a character W/A/S/D that tells the mediator where the unit will move
	*/
	bool moveRight(Unit *unit, char toPlace);//!< moveRight moves the current unit right one block on the map
	/**
	@param unit is a unit pointer to the current unit being moved
	@param a character W/A/S/D that tells the mediator where the unit will move
	*/	
};
#endif