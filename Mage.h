/**
*	@file Mage.h
*	@class Mage
*
*	@brief A Magic unit
*
*	@section License
*	Copyright belongs to Merissa Joubert and Juan du Preez
*	
*/

#ifndef MAGE_H
#define	MAGE_H
#include "Magic.h"
#include<string>
using namespace std;
class Mage: public Magic
{
	public:
    Mage();//!< The constructor calls the Magic constructor
};
#endif	/* MAGE_H */

