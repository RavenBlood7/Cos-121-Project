/**
*	@file GamePlay.h
*	@class GamePlay
*
*	@brief A Facade that encapsulates all game functionality.
*	
*	@section Description
*	GamePlay uses all the other defined classes and patterns to execute the game.	
*	
*	@section License
*	Copyright belongs to Merissa Joubert and Juan du Preez
*	
*/
#ifndef GAMEPLAY_H
#define GAMEPLAY_H
#include "Player.h"
#include "User.h"
#include "Computer.h"
#include "Unit.h"
#include "UnitFactory.h"
#include "UnitFactory.h"
#include "MagicFactory.h" 
#include "BludgeoningFactory.h" 
#include "PiercingFactory.h" 
#include "Thief.h" 
#include "Mage.h" 
#include "Elemental.h" 
#include "Goblin.h" 
#include "Ogre.h" 
#include "Soldier.h"
#include <vector>

#include "Map.h"
#include "Mediator.h"

using namespace std;
class GamePlay
{
	private:
		vector<Player*> players;//!< stores all the players of the game
	public:
		GamePlay();//!<The constructor
		~GamePlay();//!<The destructor
		void play();//!<play encapsulates all game functionality
		void addPlayer(string name);//!< adds a player to the game
		/**
		@param name holds the name of the player to be added to the game
		*/
		bool GameOver();//!< GameOver checks if there is more than one player left in the game and returns true if there is only one player left in the game
		void removePlayer(Player*p);//!< removePlayer removes a player from the game if they have no more units left
		/**
		@param p a pointer to a player in the players vector
		*/
		Player* getWinner(); //!< getWinner returns a pointer to the winner of the game
		Map * map;//!< map is a map pointer
		Mediator * med;//! med is a mediator pointer
		
};
#endif