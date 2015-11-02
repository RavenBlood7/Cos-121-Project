/**
*	@file BludgeoningFactpry.h
*	@class BludgeoningFactory
*
*	@brief A class that extends UnitFactory and can create specialized units
*
*	@section License
*	Copyright belongs to Merissa Joubert and Juan du Preez
*	
*/

#ifndef BLUDGEONINGFACTORY_H
#define	BLUDGEONINGFACTORY_H
#include "UnitFactory.h"
#include "Soldier.h"   	 
#include "Ogre.h"

class BludgeoningFactory : public UnitFactory
{
	public:
    Unit* createPlayer()//!< createPlayer returns a new unit that human players of the game can create
    {
   	 return new Soldier();
    };
    Unit* createMonster()//!< createMonster returns a new unit that AI players of the game can create
    {
   	 return new Ogre();
    };
};



#endif	/* BLUDGEONINGFACTORY_H */

