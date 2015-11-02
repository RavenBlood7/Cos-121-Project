/**
*	@file Mediator.h
*	@class Mediator
*
*	@brief Defines an interface for communication between the players and computers
*	
*	@section Description
*	The mediator updates the map whenever players move their units around or add new units to the game
*	
*	@section License
*	Copyright belongs to Merissa Joubert and Juan du Preez
*
*/
#ifndef MEDIATOR_H
#define MEDIATOR_H

#include "Map.h"
#include "Unit.h"

#include <vector>
class Player;

class Mediator
{
	private:
		vector<Player*> players;//!< players is a vector of player pointers. The mediator uses this to keep track of the changes in the game
		Map *map;//!< map is a Map pointer
	public:
		Mediator(Map *);//!< The constructor recieves a Map pointer and attaches itself to the map
		void addPlayer(Player*);//!< addPlayer adds a new player to the map.
		bool update(Unit*, int, int, char);//!< update updates the current Unit's position on the map
		void printMap();//!< printMap prints the map with all the units on it
		
};
#endif