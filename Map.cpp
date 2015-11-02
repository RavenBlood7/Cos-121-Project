#include "Map.h"
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>

using namespace std;

Map::Map(const char* fileName)
{
    FileLocation = fileName;
    mapSizeX = 20;
    mapSizeY = 21;
    setMap();
}

Map::~Map()
{
	for (int i = 0; i < mapSizeX; i++)
	{
		delete [] MapContents[i];
	}
	delete [] MapContents;
}

void Map::setMap()
{
    MapContents = new char*[mapSizeX];
    for(int i=0;i<mapSizeX;i++)
    {
        MapContents[i] = new char[mapSizeY];
    }
    ifstream myReadFile;
    myReadFile.open(FileLocation);
    string output;
    int count = 0;
    if (myReadFile.is_open()) 
    {
        while (getline(myReadFile, output)) 
        {
            strcpy(MapContents[count], output.c_str());
            count++;
        }
    }
    myReadFile.close();
}
void Map::printMap()
{
    for(int i = 0; i < mapSizeX;i++)
    {
	    for (int j = 0; j < mapSizeY; j++)
	    {
		    if (MapContents[i][j] == 'M'		//user units
			|| MapContents[i][j] == 'S'
			|| MapContents[i][j] == 'T')
		    {
			cout << "\33[32m" << MapContents[i][j] << "\033[0m"; ////////just check for \n ??
		    }
		    else if(MapContents[i][j] == 'E'		//user units
			|| MapContents[i][j] == 'G'
			|| MapContents[i][j] == 'O')
		    {
			 cout << "\33[31m" << MapContents[i][j] << "\033[0m"; ////////just check for \n ??   
		    }
		    else if (MapContents[i][j] == 'B')
		    {
			cout << "\33[34m" << MapContents[i][j] << "\033[0m"; ////////just check for \n ??
		    }
		    else
		    {
			    cout << MapContents[i][j];
		    }
	    }
        cout << endl;
    }
}

moveState Map::Move(int fromX,int fromY,int toX,int toY, char toPlace)
{
	//checking out of range destination
	if (toX >= mapSizeX || toX < 0
		|| toY >= mapSizeY || toY < 0 		//out of range
		|| MapContents[toX][toY] == '#'
		|| MapContents[toX][toY] == ']'
		|| MapContents[toX][toY] == '['		//an obstacle
		|| MapContents[toX][toY] == 'M'
		|| MapContents[toX][toY] == 'S'
		|| MapContents[toX][toY] == 'T')		//own unit
	{
		return OBSTRUCTION;
	}
	else if (MapContents[toX][toY] == ' ')
	{
		if ((fromX == 1 && fromY == 1) ||
		(fromX == 3 && fromY == 3))		//i.e. comes from base						////////////////change enemy base here and in computer.cpp line 14
		{
			MapContents[toX][toY] = toPlace;								/**/
		}
		else							//anywhere else on map
		{
			MapContents[toX][toY] = MapContents[fromX][fromY];
			MapContents[fromX][fromY] = ' ';								/**/
		}
		return NOTHING;		
	}
	else if (MapContents[toX][toY] == 'E'		//other unit
		|| MapContents[toX][toY] == 'G'
		|| MapContents[toX][toY] == 'O')
	{
		return OTHER_UNIT;
	}
	else if (MapContents[toX][toY] == 'B') 		//entering a base
	{
		if (toX == 1 and toY == 1) 			//entering own base
		{
			MapContents[fromX][fromY] = ' ';								/**/
			return OWN_BASE;
		}
		else							//entering other base
		{
			return OTHER_BASE;
		}
	}
	return OBSTRUCTION;
}


