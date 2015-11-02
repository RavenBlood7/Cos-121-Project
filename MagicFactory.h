/**
*	@file MagicFactory.h
*	@class MagicFactory
*
*	@brief Extends UnitFactory to create specialized units
*
*	@section License
*	Copyright belongs to Merissa Joubert and Juan du Preez
*	
*/
#ifndef MAGICFACTORY_H
#define	MAGICFACTORY_H

#include "UnitFactory.h" //because of inheritance
#include "Mage.h"   	 //Classes to instatiate
#include "Elemental.h"

class MagicFactory : public UnitFactory
{
	public:
	Unit* createPlayer()//!< returns a unit that human players of the game can create
	{
		return new Mage();
	};
	Unit* createMonster()//!< returns a unit that computer players of the game can create
	{
		return new Elemental();
	};
};


#endif	/* MAGICFACTORY_H */

