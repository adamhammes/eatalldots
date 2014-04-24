#include "powerup.hpp"

#define SEARCH_RADIUS 5

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

Powerup::Powerup( int type ): Actor( type ) {}

Powerup* Powerup::duplicate() {
	return new Powerup( getType() );
}

const char*  Powerup::getActorId() { 	
	return "simplehero"; 
}

const char* Powerup::getNetId() {
	return "hammesa"; 
}

bool Powerup::visited( const Vertex& v ) const {
	return v_set.find( v ) != v_set.end();
}

int Powerup::selectNeighbor( GraphMap* map, int cur_x, int cur_y ) {
	this->map = map;
	v_set.clear();
	rank_nodes( cur_x, cur_y );

	return 0;
}

void Powerup::rank_nodes( int x, int y ) {
	queue< Vertex > q;
	Vertex temp( x, y );
	dist[temp] = 0;

	q.push( Vertex( x, y ) );

	vector< Vertex > enemies;
	vector< Vertex > eatables;

	bool stop = false;
	while( !q.empty() && enemies.size() < SEARCH_RADIUS && !stop ) {
		Vertex popped = q.front();
		q.pop();

		v_set.insert( popped );
		if( vertex_type( popped ) & ACTOR_ENEMY ) {
			enemies.push_back( popped );
		}

		if( vertex_type( popped ) & ACTOR_EATABLE ) {
			eatables.push_back( popped );
		}

		int num_neighbors = map->getNumNeighbors( popped.x, popped. y )
		for ( int i = 0; i < num_neighbors; i++ ) {
			int a, b;
			map->getNeighbor( popped.x, popped.y, i, a, b );
			Vertex temp( a, b );

			if( !visited( temp ) ) {
				dist[temp] = dist[popped] + 1;
				if( dist[temp] > SEARCH_RADIUS ) {
					stop = true;
					break;
				}
				
				q.push( temp );
			}
		}
	}

}


