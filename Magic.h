/**
*	@file Magic.h
*	@class Magic
*
*	@brief A class that extends Unit and has specialized abilities
*
*	@section License
*	Copyright belongs to Merissa Joubert and Juan du Preez
*	
*/

#ifndef MAGIC_H
#define	MAGIC_H
#include "Unit.h"
#include <string>
using namespace std;

class Magic: public Unit
{
public:
    Magic(int,int,string);//!<Constructor calls Unit's constructor
    Magic(Magic*);//!Copy constructor used in the prototype pattern
    int attack(Unit*);//!<Overridden attack function
    /*!
     * @param target 
     * target is used to check if the current unit does more or less damage to it due to its type
     */
    void takeDamage(int d);//!Overridden takeDamage function
    bool isAlive();//!< isAlive Checks if the unit is still alive
    Magic* clone();//!<clone Clones the current unit using the copy constructor
    int getHealth();//!< returns the units health
    int getDamage();//!< returns the units damage
    string getType();//!< returns the units Type
    void setHealth(int);//!< sets the units health
    void setDamage(int);//!< sets the units damage
    void setType(string);//!< sets the units Type
    ~Magic();//!< The Destructor
    
};
#endif	/* MAGIC_H */

