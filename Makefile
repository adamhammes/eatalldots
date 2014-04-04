all : ssbros simple_hero.o


testing : testing.cpp simple_hero.o
	g++ -g -Wall -o testing testing.cpp vertex.o simple_hero.o GraphMap.o Actor.o


ssbros : ssbros.cpp 
	g++ -g -Wall -o ssbros ssbros.cpp Actor.o GraphMap.o GameManager.o OtherActors.o -lncurses


vertex.o : vertex.hpp vertex.cpp
	g++ -g -Wall -c vertex.cpp


simple_hero.o : simple_hero.cpp
	g++ -g -Wall -c simple_hero.cpp

tarball:
	tar czf project2.tar.gz Makefile *.hpp ssbros.cpp *.o maps/*.txt
