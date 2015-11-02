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

#ifndef PIERCINGFACTORY_H
#define	PIERCINGFACTORY_H
#include "UnitFactory.h" //because of inheritance
#include "Thief.h"   	 //Classes to instatiate
#include "Goblin.h"

class PiercingFactory : public UnitFactory
{
	public:
	Unit* createPlayer()//!< returns a unit that human players of the game can create
	{
		return new Thief();
	};
	Unit* createMonster()//!< returns a unit that computer players of the game can create
	{
		return new Goblin();
	};
};



#endif	/* PIERCINGFACTORY_H */

