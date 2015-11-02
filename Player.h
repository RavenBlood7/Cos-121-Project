/**
*	@file Player.h
*	@class Player
*
*	@brief An abstract class that defines a player.
*	
*	@section Description
*	Encapsulates the basic properties of both computer players and human players
*	
*	@section License
*	Copyright belongs to Merissa Joubert and Juan du Preez
*
*/
#ifndef PLAYER_H
#define PLAYER_H
#include "Unit.h"
#include "UnitFactory.h"
#include "MagicFactory.h"
#include "PiercingFactory.h"
#include "BludgeoningFactory.h"
#include <vector>
#include <string>

#include "Mediator.h"
using namespace std;

class Player
{
	private:
		
		
		double Treasury;//!*<Will store a player's money
		unsigned int maxUnits;//!< Stores the maximum number units
		string name;//!< Stores the Player name
		int moves;//!<The move counter variable
	
	public:
		void checkUnits();
		vector<Unit*> army;//!<Stores all the units that the player owns
		vector<UnitFactory*> baracks;//!< Stores the three unit factories
		Player();//!< The constructor
		~Player();//!< The destructor
		void addToArmy(Unit*u);//!< addToArmy adds a new unit to the army
		/**
		@param u is a unit pointer to a unit object that will be added to the player's army 
		*/
		void printArmy();//!< prints all the units that are currently stored in the player's army
		virtual void createUnit(UnitFactory*)=0;/**<createUnit is a pure virtual method that is overidden 
		by computer and user to add the correct type of unit to the player's army*/
		bool IsOut();//!< isOut returns true if the player has no more units in their army
		virtual void makeMove()=0;//!< makeMove encapsulates the algorithm that lets players make and move units 
		//virtual void moveUnit(Unit*,int,int)=0;
		void setMaxUnits(int m);//! setMaxUnits sets the maximum units in the game 
		/**
		@param m an integer that stores the maximum number of units
		*/
		void setName(string n);//!< setName sets the plaeyer's name
		/**
		@param n the name of the player
		*/
		string getName();//!< getName returns the name of the player
		void setNumMoves(int n);//!< setNumMoves sets the number of moves a player has
		/**
		@param n an integer that stores a player's number of moves
		*/
		void decreaseMoves();//!< decreaseMoves subtracts one from the player's current number of moves
		bool outOfMoves();//!< returns true if the player has no more moves left and false otherwise
	
		void setMediator(Mediator *);//!< setMediator attaches the player to the mediator pointer passed as a parameter
	protected:
		Mediator * mediator;//!< mediator stores a pointer to the mediator that this player belongs to
};
#endif