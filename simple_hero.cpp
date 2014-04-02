#ifndef SIMPLE_HERO_CPP_
#define SIMPLE_HERO_CPP_

#include "simple_hero.hpp"
#include <stdlib.h>
#include <queue>


Simple_Hero::Simple_Hero( int type ) : Actor( type ) {
	actor_list = vector<Vertex>();
	made_graph = false;
	
}

const char* Simple_Hero::getActorId() {
	return "simplehero";
}

const char* Simple_Hero::getNetId() {
	return "hammesa";
}

void Simple_Hero::update_vertices( GraphMap* map ) {	
	int x, y;
	actor_list.resize( map->getNumActors() );

	for( int i = 0; i < map->getNumActors(); i++ ) {
		map->getActorPosition( i, x, y );
		actor_list[i] = Vertex( x, y );
	}

	if( !made_graph ) make_graph( map );
}

void Simple_Hero::make_graph( GraphMap* map ) {
	graph_width  = map->getWidth();
	graph_height = map->getHeight();

	graph.reserve( graph_width );


	for(int i = 0; i < graph_width; i++ ) {
		graph[i].reserve( graph_height );
	}

	update_vertices( map );
	made_graph = true;
}

Vertex& Simple_Hero::get_vertex( int x, int y ) {
	if( !made_graph ) {
		printf( "Called get_vertex without initializing graph\n" );
		exit(0);
	}

	return graph[x][y];

}

int Simple_Hero::select_neighbor( GraphMap* map, int x, int y ) {





	return 0;
}


int Simple_Hero::where_go( GraphMap* map, int x1, int y1, int x2, int y2 ) {
	queue<Vertex> v_q;

	if( x1 < 0 || y1 < 0 ) {
		printf( "Invalid coordinates for source vertex in where_go - (%d, %d)\n", x1, y1 );
		exit(0);
	}

	if( x2 < 0 || y2 < 0 ) {
		printf( "Invalid coordinates for dest vertex in where_go - (%d, %d)\n", x2, y2 );
		exit(0);
	}


	Vertex source ( x1, y1 );
	Vertex target ( x2, y2 );
	Vertex popped, temp;


	v_q.push( source );

	while( !v_q.empty() ) {
		popped = v_q.front();


		if( popped.visited ) {
			v_q.pop();
			continue;
		}

		for( int i = 0; i < map->getNumNeighbors( popped.x, popped.y ); i++ ) {
			int a, b;
			map->getNeighbor( popped.x, popped.y, i, a, b );
			temp = get_vertex( a, b );
			temp.prev = &popped;

			if( temp == target ) {
				break;
			}

			if( !temp.visited ) {
				temp.visited = true;
				v_q.push( temp );
			}
		}

		v_q.pop();
		
	}

	while( !(*temp.prev == source ) ) {
		temp = *temp.prev;
	}

	for( int i = 0; i < map->getNumNeighbors( temp.prev->x, temp.prev->y ); i++ ) {
		int a, b;
		map->getNeighbor( temp.prev->x, temp.prev->y, i, a, b );
		Vertex check( a, b );
		
		if( check == source ) {
			return i;
		}
	}	


	return -1;
}






Simple_Hero::~Simple_Hero() {}


#endif
