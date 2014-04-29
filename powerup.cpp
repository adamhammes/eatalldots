#include "powerup.hpp"

#define DANGER_ZONE 2

void Powerup::make_graph( GraphMap* map ) {
	graph_width  = map->getWidth();
	graph_height = map->getHeight();

	graph = vector< vector< Vertex > >( graph_width, vector< Vertex >( graph_height ) );

	for ( int i = 0; i < graph_width; i++ ) {
		for ( int j = 0; j < graph_height; j++ ) {
			graph[i][j] = Vertex( i, j );
		}
	}
}

bool Powerup::sort_function( Vertex* a, Vertex* b ) {
	if( hero_close( b ) ) {
		return a;
	}
	if( hero_close( a ) ) {
		return b;
	}
	return a;
}

Vertex* Powerup::get_vertex( int x, int y ) {
	return &graph[x][y];
}

Powerup::Powerup( int type ): Actor( type ) {}

Powerup* Powerup::duplicate() {
	return new Powerup( getType() );
}

const char*  Powerup::getActorId() { 	
	return "smartPowerup"; 
}

const char* Powerup::getNetId() {
	return "hammesa"; 
}

int Powerup::vertex_type( Vertex& v ) {
	int num_neighbors = map->getNumActors();
	for ( int i = 0; i < num_neighbors; i++ ) {
		int a, b;
		map->getActorPosition( i, a, b );
		Vertex temp( a, b );
		if( temp == v ) {
			return map->getActorType( i );
		}
	}
	return 0;
}

bool Powerup::hero_close( Vertex* v ) {
	if( check_type( v, ACTOR_ENEMY ) ) {
		return true;
	}
	for ( int i = 0; i < map->getNumNeighbors( v->x, v->y ); i++ ) {
		int a, b;
		map->getNeighbor( v->x, v->y, i, a, b );
		Vertex* temp = get_vertex( a, b );
		if( check_type( temp, ACTOR_ENEMY ) ) {
			return true;
		}
	}
	return false;
}

bool Powerup::check_type( Vertex* v, int type ) {
	return (vertex_type( *v ) & type) && !(vertex_type( *v ) & ACTOR_DEAD);
}


int Powerup::selectNeighbor( GraphMap* map, int cur_x, int cur_y ) {
	this->map = map;

	Vertex* start = get_vertex( cur_x, cur_y );

	// if we are on an enemy
	if( check_type( start, ACTOR_ENEMY ) || map->getNumNeighbors( cur_x, cur_y ) <= 1 ) {
		return 0;
	}

	queue< Vertex* > q;
	Vertex* temp;
	// find adjacent enemies, avoid paths close to enemy heros
	for( int i = 0; i < map->getNumNeighbors( cur_x, cur_y ); i++ ) {
		int a, b;
		map->getNeighbor( start->x, start->y, i, a, b );
		temp = get_vertex( a, b );
		if( check_type( temp, ACTOR_ENEMY ) ) {
			return i;
		}
		if( !hero_close( temp ) ) {
			q.push( temp );
		}
	}

	if( q.size() == 0 ) {
		return 0;
	}

	bool stop = false;
	while( !q.empty() && !stop ) {
		Vertex* popped = q.front();
		q.pop();

		if( popped->visited ) {
			continue;
		}

		popped->visited = true;

		int num_neighbors = map->getNumNeighbors( popped->x, popped->y );
		for ( int i = 0; i < num_neighbors && !stop; i++ ) {
			int a, b;
			map->getNeighbor( popped->x, popped->y, i, a, b );
			temp = get_vertex( a, b );

			if( !temp->visited || !check_type( temp, ACTOR_HERO ) ) {
				temp->prev = popped;
				if(check_type( temp, ACTOR_EATABLE ) ) {
					stop = true;
				}
				q.push( temp );
			}
		
		}
	}
	return 0;
}