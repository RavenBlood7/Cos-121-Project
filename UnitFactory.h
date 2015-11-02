/**
*	@file UnitFactpry.h
*	@class UnitFactory
*
*	@brief An abstract class that provides an interface for the creation of units in the game
*
*	@section License
*	Copyright belongs to Merissa Joubert and Juan du Preez
*	
*/

#ifndef UNITFACTORY_H
#define	UNITFACTORY_H

#include "Unit.h"
class UnitFactory
{
    
    public:
   		 
   	 /**
   	 *    A constructor for creating a unit factory
   	 */    
	UnitFactory(){};

   	 /**
   	 *    A destructor for deleting a unit factory
   	 */    
   	 virtual ~UnitFactory(){};
    
   	 /**
   	 *    A pure virtual function for creating a player
   	 *    @return Unit pointer that was created
   	 */    
   	 virtual Unit* createPlayer() = 0;
    
   	 /**
   	 *    A pure virtual function for creating a monster
   	 *    @return Unit pointer that was created
   	 */   	 
   	 virtual Unit* createMonster() = 0;
};



#endif	/* UNITFACTORY_H */

