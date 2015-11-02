/**
*	@file Unit.h
*	@class Unit
*
*	@brief An abstract class that describes all units of the game
*	@section Description
*	The unit class is an abstract Product class that provides an interface for other abstract products to interact with. 
*	@section License
*	Copyright belongs to Merissa Joubert and Juan du Preez
*	
*/
#ifndef UNIT_H
#define	UNIT_H
#include <string>
#include <ostream>
using namespace std;
class Unit
{
    private:
        
        int health;//!< Stores the health of the current unit
        int damage;//!< Stores the damage that the current unit can deal
        string type;//!< Stores the type of the current unit eg Magic, Piercing or Bludgeoning
	int xpos;//!<Stores the x coordinate of the unit
	int ypos;//!<Stores the y coodinate of the unit
	double cost;
    public:
        Unit(int h, int d, string t)
          {
	      health =h;
              damage =d;
              type = t;
	      xpos =1;
	      ypos=1;
          };//!<The Constructor 
	 /*! The constructor simpy sets all the member variables to the input parameters provided.
	  *@param h is an integer that is used to initialize the unit's max health.
	  *@param d is an integer that is used to initialize the unit's starting damage.
	  *@param t is a string that is used to initialize the unit's type eg. Magic/Piercing/Bludgeoning.
	  */
	friend ostream& operator<<(ostream &os, Unit & myUnit)
	{
		myUnit.printUnit(os);
		return os;
	}
	virtual ostream& printUnit(ostream &os)
	{
		os<<type<<" at block ["<<xpos<<","<<ypos<<"]";
		return os;
	}
        virtual ~Unit(){};//!<The destructor
        virtual int attack(Unit* a){ return damage;}//!<The attack function
		/*!The attack function is overridden in all subclasses in order to be specific to each unit*/
        virtual void takeDamage(int d)=0;//!< The takeDamage function 
		/*!The take damage function simply subtracts damage dealt to the unit from its health*/
        virtual bool isAlive()=0;//!<The is Alive function returns true if the unit is alive and false otherwise
        virtual Unit* clone()=0;//!<The clone function
		/*!The clone function is pure virtual in the unit class making it abstract. This is because each clone needs to be of one of the subclasses*/
        virtual int getHealth(){return health;};//!< getHealth returns the unit's health
        virtual int getDamage(){return damage;};//!<getDamage returns the unit's damage
        virtual void setHealth(int h){health = h;};//!<setHealth sets the unit's damage
        virtual void setDamage(int m){damage = m;};//!<setDamage sets the unit's damage
        virtual void setType(string t){type =t;};//!<setType can change the unit's type
        virtual string getType(){return type;};//!<getType returns the unit's type
	virtual void setCost(double c){ cost =c;};//!< setCost sets the cost of the unit depending on its type
	virtual double getCost(){return cost;};//!< getCost returns the cost of the unit
        virtual int getXpos(){return xpos;};//!< returns the current xpos of the unit
	virtual int getYpos(){return ypos;};//!< returns the current ypos of the unit
	virtual void move(int x, int y){xpos = x; ypos = y;};//!<moves the unit according to its new x position and y position
};
#endif	/* UNIT_H */

