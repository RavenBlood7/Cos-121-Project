/**
*	@file Bludgeoning.h
*	@class Bludgeoning
*
*	@brief A class that extends Unit and has specialized abilities
*
*	@section License
*	Copyright belongs to Merissa Joubert and Juan du Preez
*	
*/
#ifndef BLUDGEONING_H
#define	BLUDGEONING_H
#include "Unit.h"
#include <string>
using namespace std;

class Bludgeoning: public Unit
{
public:
    Bludgeoning(int, int, string);//!<Constructor calls Unit's constructor
    Bludgeoning(Bludgeoning *);//!Copy constructor used in the prototype pattern
    int attack(Unit*);//!<Overridden attack function
    /*!
     * @param target 
     * target is used to check if the current unit does more or less damage to it due to its type
     */
    void takeDamage(int );//!Overridden takeDamage function
    bool isAlive();//!< isAlive Checks if the unit is still alive
    Bludgeoning* clone();//!<clone Clones the current unit using the copy constructor
    int getHealth();//!< returns the health of the unit
    int getDamage();//!< returns the damage of the unit
    string getType();//!< returns the type of unit
    void setHealth(int);//!< sets the unit's health
    void setDamage(int);//!< sets the units damage. Could be used if an upgrade mechanism is added to the game
    void setType(string);//!< sets the type of unit.
    ~Bludgeoning();//!< the destructor
    
};
#endif	/* BLUDGEONING_H */

