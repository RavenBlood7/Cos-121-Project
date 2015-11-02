/*! 
 * File:   Piercing.cpp
 * Author: merissa
 * Created on 06 October 2015, 4:33 PM
 */
#include "Piercing.h"


Piercing::Piercing(int h, int d, string t):Unit(h,d,t)
{
}
int Piercing:: attack(Unit* target)
{
    if(target->getType()=="Magic")
    {
        return(this->getDamage()+50);//Piercing does more damage to magic
    }
    else if(target->getType()=="Bludgeoning")
    {
        return (this->getDamage());
    }
    else if(target->getType()=="Piercing")
    {
       return(this->getDamage());
    }
    else
    {
        return 0;
    }
}
void Piercing:: takeDamage(int d)
{
}
bool Piercing:: isAlive()
{
	 if(getHealth()>0)
        return true;
	else
        return false;
}
Piercing::~Piercing()
{
}
int Piercing:: getHealth()
{
	return Unit::getHealth();
}
int Piercing:: getDamage()
{
	return Unit::getDamage();
}
void Piercing:: setHealth(int h)
{
	 Unit::setHealth(h);
}
void Piercing:: setDamage(int m)
{
	Unit::setDamage(m);
}
void Piercing::setType(string t)
{
    Unit::setType(t);
}
string Piercing::getType()
{
    return Unit::getType();
}
Piercing* Piercing:: clone()
{
    return new Piercing(this);
}
Piercing::Piercing(Piercing* p):Unit(p->getHealth(),p->getDamage(),p->getType())
{
    
}

