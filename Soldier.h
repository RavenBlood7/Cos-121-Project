/**
*	@file Soldier.h
*	@class Soldier
*
*	@brief A Bludgeoning unit
*
*	@section License
*	Copyright belongs to Merissa Joubert and Juan du Preez
*	
*/
#ifndef SOLDIER_H
#define	SOLDIER_H
#include "Bludgeoning.h"
#include<string>
using namespace std;
class Soldier : public Bludgeoning
{
	public:
    Soldier();//!< Calls the Bludgeoning constructor
};
#endif	/* SOLDIER_H */

