Game.out: GamePlay.o Player.o User.o Map.o Mediator.o Computer.o Magic.o Bludgeoning.o Piercing.o Mage.o Elemental.o Soldier.o Goblin.o Thief.o Ogre.o UnitFactory.h MagicFactory.h BludgeoningFactory.h PiercingFactory.h driver.cpp
	g++ GamePlay.o Player.o User.o Map.o mediator.o Computer.o Magic.o Bludgeoning.o Piercing.o Mage.o Elemental.o Soldier.o Goblin.o Thief.o Ogre.o UnitFactory.h MagicFactory.h BludgeoningFactory.h PiercingFactory.h driver.cpp -o Game.out

Driver.o: GamePlay.h driver.cpp
	g++ -Wall  -Werror -c driver.cpp

GamePlay.o: Player.h Unit.h UnitFactory.h MagicFactory.h BludgeoningFactory.h PiercingFactory.h Thief.h Mage.h Elemental.h Goblin.h Ogre.h Soldier.h GamePlay.cpp
	g++ -Wall  -Werror -c GamePlay.cpp

Player.o: Player.h Player.cpp
	g++ -Wall -Werror -c Player.cpp

User.o: User.h User.cpp
	g++ -Wall -Werror -c User.cpp

Map.o: Map.h Map.cpp
	g++ -Wall -Werror -c Map.cpp
	
Mediator.o: Mediator.h mediator.cpp
	g++ -Wall -Werror -c mediator.cpp

Computer.o: Computer.h Computer.cpp
	g++ -Wall -Werror -c Computer.cpp

Magic.o: Unit.h Magic.h Magic.cpp
	g++ -c -Wall -Werror Magic.cpp
    
Bludgeoning.o: Unit.h Bludgeoning.h Bludgeoning.cpp 
	g++ -c -Wall -Werror Bludgeoning.cpp 
    
Piercing.o: Unit.h Piercing.h Piercing.cpp 
	g++ -c -Wall -Werror Piercing.cpp
    
Mage.o: Unit.h Magic.h Mage.h Mage.cpp    
	g++ -c -Wall -Werror Mage.cpp    
    
Elemental.o: Unit.h Magic.h Elemental.h Elemental.cpp
	g++ -c -Wall -Werror  Elemental.cpp
    
Soldier.o: Unit.h Bludgeoning.h Soldier.h Soldier.cpp
	g++ -c -Wall -Werror  Soldier.cpp
    
Goblin.o: Unit.h Piercing.h Goblin.h Goblin.cpp
	g++ -c -Wall -Werror Goblin.cpp
    
Thief.o: Unit.h Piercing.h Thief.h Thief.cpp
	g++ -c -Wall -Werror Thief.cpp
    
Ogre.o: Unit.h Bludgeoning.h Ogre.h Ogre.cpp    
	g++ -c -Wall -Werror  Ogre.cpp 

run: 
	./Game.out


clean:
	rm *.o Game.out
	


