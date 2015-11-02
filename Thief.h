/**
*	@file Thief.h
*	@class Thief
*
*	@brief A Piercing unit
*
*	@section License
*	Copyright belongs to Merissa Joubert and Juan du Preez
*	
*/

#ifndef THIEF_H
#define	THIEF_H
#include "Piercing.h"
#include<string>
using namespace std;
class Thief: public Piercing
{
	public:
  Thief();  //!< calls the Piercing constructor
};
#endif	/* THIEF_H */

