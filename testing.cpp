#include "vertex.hpp"
#include "GameManager.hpp"
#include "simple_hero.hpp"
#include "stdio.h"

int main( void ) {
	GraphMap* map = new GraphMap( fopen( "maps/basic.txt", "r" ) );

	Simple_Hero hero( 1 );

	hero.make_graph( map );




	delete( map );
	return 0;
}
