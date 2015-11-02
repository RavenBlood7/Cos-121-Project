/**
*	@file Elemental.h
*	@class Elemental
*
*	@brief A Magic unit
*
*	@section License
*	Copyright belongs to Merissa Joubert and Juan du Preez
*	
*/

#ifndef ELEMENTAL_H
#define	ELEMENTAL_H
#include "Magic.h"
#include<string>
using namespace std;
class Elemental: public Magic
{
	public:
    Elemental();//!< The constructor calls the Magic constructor
};
#endif	/* ELEMENTAL_H */

