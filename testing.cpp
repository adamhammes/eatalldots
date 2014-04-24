#include "vertex.hpp"
#include "GameManager.hpp"
#include "simple_hero.hpp"
#include "Actor.hpp"
#include "stdio.h"

int main( void ) {
	FILE* f = fopen( "maps/basic.txt", "r" );
	GraphMap map( f );

	Simple_Hero hero( ACTOR_HERO );

	hero.make_graph( &map );

	fclose( f );
	return 0;
}
