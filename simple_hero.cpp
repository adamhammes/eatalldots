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
		printf("Called get_vertex without initializing graph\n");
		exit(0);
	}

	return graph[x][y];

}

int Simple_Hero::select_neighbor( GraphMap* map, int x, int y ) {





	return 0;
}


int Simple_Hero::where_go( GraphMap* map, int x1, int y1, int x2, int y2 ) {
	queue<Vertex> v_q;

	Vertex source ( x1, y1 );
	Vertex target ( x2, y2 );
	Vertex popped, temp;


	v_q.push( source );

	while( !v_q.empty() ) {
		popped = v_q.front();

		if( popped == target ) break;

		if( popped.visited ) {
			v_q.pop();
			continue;
		}

		for( int i = 0; i < map->getNumNeighbors( popped.x, popped.y ); i++ ) {
			int a, b;
			map->getNeighbor( popped.x, popped.y, i, a, b );
			temp = get_vertex( a, b );
			temp.prev = &popped;
			temp.visited = true;
			v_q.push( temp );
		}
		
	}

	return 0;
}






Simple_Hero::~Simple_Hero() {}


#endif
