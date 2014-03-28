all : ssbros simple_hero.o


testing : testing.cpp
	g++ -g -Wall -o testing testing.cpp Vector.o Simple_Hero.o GraphMap.o 

ssbros : ssbros.cpp 
	g++ -g -Wall -o ssbros ssbros.cpp Actor.o GraphMap.o GameManager.o OtherActors.o -lncurses


simple_hero.o : simple_hero.hpp simple_hero.cpp
	g++ -g -Wall -c simple_hero.cpp

tarball:
	tar czf project2.tar.gz Makefile *.hpp ssbros.cpp *.o maps/*.txt
