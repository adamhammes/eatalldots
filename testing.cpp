#include "vertex.hpp"
#include "GameManager.hpp"
#include "simple_hero.hpp"
#include "stdio.h"

int main( void ) {
	FILE* f = fopen( "maps/basic.txt", "r" );
	GraphMap* map = new GraphMap( f );

	Simple_Hero* hero = new Simple_Hero( ACTOR_HERO );


	fclose( f );

	delete( hero );
	delete( map );
	return 0;
}
