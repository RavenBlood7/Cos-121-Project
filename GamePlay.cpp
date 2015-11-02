
#include "GamePlay.h"
#include <iostream>

GamePlay::GamePlay()
{
	string myMap = "Map.txt";
	map = new Map(myMap.c_str());
	med = new Mediator(map);
}
GamePlay::~GamePlay()
{
	delete map;
	delete med;
}
		
void GamePlay:: addPlayer(string name)
{
	Player *p;
	if(name == "AI")
		p = new Computer();
	else	p= new User();
	p->setName(name);
	players.push_back(p);
	players.at(players.size() - 1)->setMediator(med);
}
void GamePlay:: play()
{
	string name;
	cout<<"\033[1;31mWELCOME TO THE MONSTER GAME\033[0m\n"<<endl;

	unsigned int count =0;
	Player * winner;
	//unsigned int numPlayers=0;
	//cout<<"\033[31mEnter the number of players for this round : \033[0m\n"<<endl;
	//cin>>numPlayers;
	//for (unsigned int loop =0; loop< numPlayers; loop++)
	//{
		cout<<"Enter the name of the player"<<endl;
		cin>> name;
		addPlayer(name);
		addPlayer("AI");
	
	cout<<"\033[1;32m***********************************GAME START***********************************\033[0m\n";
	while (!GameOver())
	{
		//cout<<"it enters the while! wohooo!"<<endl;
		if(count<players.size())
		{
			//cout<<"enters the if"<<endl;
			players.at(count)->makeMove();
			//players.at(count)->checkUnits();
			count++;
		}
		else
		{
			count =0;
		}
	}
	if (GameOver())
	{
		winner = getWinner();
		cout<<"\033[1;32mThe winner is : "<<winner->getName()<<"\033[0m\n"<<endl;
		cout<<"\033[1;32m*************************************GAME OVER***********************************\033[0m\n";
	}
/////////////////////////////////////////////*/
	//addPlayer("Me");
//	
//	while (!GameOver())
//	{
//		players.at(1)->makeMove();		
//		players.at(0)->makeMove();
//	}
	
	
}
bool GamePlay::GameOver()
{
	if (players.size()==1)
		return true;
	else
		return false;
	//game is over when all players but one is out... that player wins
}
void GamePlay:: removePlayer(Player*p)
{
	int count =0;
	bool found = false;
	for (unsigned int loop =0; loop<players.size();loop++)
	{
		if (players.at(loop)==p)
		{
			found = true;
		}
		else
			count++;
	}
	if (found)
	{ 
		players.erase(players.begin(),players.begin()+3);
	}
	else
		cout<<"That player has already died!"<<endl;
}
Player* GamePlay:: getWinner()
{
	return players.at(0);
}
	