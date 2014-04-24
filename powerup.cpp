#include "powerup.hpp"



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

int& Powerup::dist( const Vertex& v) {
	return distances[v];
}

int Powerup::selectNeighbor( GraphMap* map, int cur_x, int cur_y ) {
	this->map = map;
	v_set.clear();
	rank_nodes( cur_x, cur_y );

	return 0;
}

void Powerup::rank_nodes( int x, int y ) {
	queue< Vertex > q;
	q.push( Vertex( x, y ) );

	vector< Vertex > enemies;
	vector< Vertex > eatables;

	while( !q.empty() && enemies.size() < 5 ) {
		Vertex popped = q.front();
		q.pop();

		v_set.insert( popped );



	}

}


