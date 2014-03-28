#include "Vertex.hpp"
#include "GameManager.hpp"
#include "simple_hero.hpp"


int main( void ) {
	GraphMap* map = new GraphMap( "maps/basic.txt" );

	map.make_graph( map );




	delete( map );
	return 0;
}
