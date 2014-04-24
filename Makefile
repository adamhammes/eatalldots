all : ssbros

clean :
	rm  -f ssbros testing simple_hero.o vertex.o OtherActors.o powerup.o

testing : testing.cpp simple_hero.o
	g++ -g -Wall -o testing testing.cpp vertex.o simple_hero.o GraphMap.o Actor.o

ssbros : ssbros.cpp simple_hero.o OtherActors.o powerup.o
	g++ -g -Wall -o ssbros ssbros.cpp Actor.o GraphMap.o GameManager.o OtherActors.o simple_hero.o vertex.o Pursuer.o -lncurses

vertex.o : vertex.hpp vertex.cpp
	g++ -g -Wall -c vertex.cpp

simple_hero.o : simple_hero.cpp vertex.o
	g++ -g -Wall -c simple_hero.cpp

OtherActors.o : OtherActors.hpp OtherActors.cpp
	g++ -g -Wall -c OtherActors.cpp

powerup.o : powerup.cpp vertex.o
	g++ -g -Wall -std=c++11 powerup.cpp