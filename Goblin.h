/**
*	@file Goblin.h
*	@class Goblin
*
*	@brief A Piercing unit
*
*	@section License
*	Copyright belongs to Merissa Joubert and Juan du Preez
*	
*/

#ifndef GOBLIN_H
#define	GOBLIN_H
#include "Piercing.h"
#include<string>
using namespace std;
class Goblin: public Piercing
{
	public:
    Goblin();//!< the constructor calls the Piercing constructor
};
#endif	/* GOBLIN_H */

