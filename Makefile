


all : ssbros


ssbros : ssbros.cpp 
	g++ -g -Wall -o ssbros ssbros.cpp Actor.o GraphMap.o GameManager.o OtherActors.o -lncurses


clean:
	rm *.o ssbros


tarball:
	tar czf project2.tar.gz Makefile *.hpp ssbros.cpp *.o maps/*.txt
