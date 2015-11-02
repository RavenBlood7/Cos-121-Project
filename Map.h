#ifndef MAP_H
#define MAP_H

#include <iostream>
using namespace std;

enum moveState {NOTHING, OBSTRUCTION, OTHER_UNIT, OTHER_BASE, OWN_BASE};
class Map
{
private:
    char** MapContents;
    const char* FileLocation;
    void SetMap();
    int mapSizeX;
    int mapSizeY;
public:
    ~Map();
    Map(const char*);
    void printMap();
    /**
     * @TODO Complete the move to allow an update to the map
     */
    moveState Move(int,int,int,int, char);
    void setMap();
    
    
};
#endif