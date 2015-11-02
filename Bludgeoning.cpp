/*! 
 * File:   Bludgeoning.cpp
 * Author: merissa
 * Created on 06 October 2015, 4:33 PM
 */
#include "Bludgeoning.h"

Bludgeoning::Bludgeoning(int h, int d, string t):Unit(h,d,t)
{
    
}
int Bludgeoning:: attack(Unit* target)
{
     if(target->getType()=="Magic")
    {
        return(this->getDamage());
    }
    else if(target->getType()=="Bludgeoning")
    {
        return (this->getDamage());
    }
    else if(target->getType()=="Piercing")
    {
       return(this->getDamage()+50);//Bludgeoning deals more damage to piercing
    }
    else
    {
        return 0;
    }
}
void Bludgeoning:: takeDamage(int d)
{
    int tempHealth = getHealth();
    
    if (d>tempHealth)
        setHealth(0);
    else
        setHealth(tempHealth-d);
}
bool Bludgeoning:: isAlive()
{
    if(getHealth()>0)
        return true;
    else
        return false;
}
Bludgeoning::~Bludgeoning()
{
}
int Bludgeoning:: getHealth()
{
     return Unit::getHealth();
}
int Bludgeoning:: getDamage()
{
     return Unit::getDamage();
}
void Bludgeoning:: setHealth(int h)
{
    Unit::setHealth(h);
}
void Bludgeoning:: setDamage(int m)
{
    Unit::setDamage(m);
}
void Bludgeoning::setType(string t)
{
    Unit::setType(t);
}
string Bludgeoning::getType()
{
    return Unit::getType();
}
Bludgeoning* Bludgeoning:: clone()
{
    return new Bludgeoning(this);
}
Bludgeoning::Bludgeoning(Bludgeoning* b):Unit(b->getHealth(),b->getDamage(),b->getType())
{
    
}

