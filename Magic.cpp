/*!
 * File:   Magic.cpp
 * Author: merissa
 * Created on 06 October 2015, 4:32 PM
 */
#include "Magic.h"
#include "Unit.h"

Magic::Magic(int h, int d , string t):Unit(h,d,t)
{
    
}
int Magic::attack(Unit* target)
{
    if(target->getType()=="Magic")
    {
        return(this->getDamage());
    }
    else if(target->getType()=="Bludgeoning")
    {
        return (this->getDamage()+50);//magic deals more damage to bludgeoning
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
void Magic:: takeDamage(int d)
{
    int tempHealth = getHealth();
    
    if (d>tempHealth)
        setHealth(0);
    else
        setHealth(tempHealth-d);
}
bool Magic:: isAlive()
{
    if(getHealth()>0)
        return true;
    else
        return false;
}
Magic::~Magic()
{
    
}
int Magic:: getHealth()
{
    return Unit::getHealth();
}
int Magic:: getDamage()
{
    return Unit::getDamage();
}
void Magic:: setHealth(int h)
{
    Unit::setHealth(h);
}
void Magic:: setDamage(int m)
{
    Unit::setDamage(m);
}
void Magic::setType(string t)
{
    Unit::setType(t);
}
string Magic::getType()
{
    return Unit::getType();
}
Magic* Magic:: clone()
{
    return new Magic(this);
}
Magic::Magic(Magic* m):Unit(m->getHealth(),m->getDamage(),m->getType())
{
    
}
