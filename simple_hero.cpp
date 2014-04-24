#include "simple_hero.hpp"

int Simple_Hero::get_type( GraphMap* map, Vertex* v ) {
	int num_neighbors = map->getNumActors();
	for ( int i = 0; i < num_neighbors; i++ ) {
		int a, b;
		map->getActorPosition( i, a, b );
		Vertex temp( a, b );
		if( temp == *v ) {
			return map->getActorType( i );
		}
	}
	return 0;
}

void Simple_Hero::make_graph( GraphMap* map ) {
	graph_width  = map->getWidth();
	graph_height = map->getHeight();

	graph = vector< vector< Vertex > >( graph_width, vector< Vertex >( graph_height ) );

	for ( int i = 0; i < graph_width; i++ ) {
		for ( int j = 0; j < graph_height; j++ ) {
			graph[i][j] = Vertex( i, j );
		}
	}
}

Vertex* Simple_Hero::get_vertex( int x, int y ) {
	return &graph[x][y];
}

int Simple_Hero::selectNeighbor( GraphMap* map, int x, int y ) {
	make_graph( map );
	Vertex start( x, y );
	Vertex to_go = rank_actors( map, &start );
	return where_go( map, start, to_go );
}

int Simple_Hero::where_go( GraphMap* map, Vertex& source, Vertex& target ) {
	for( int i = 0; i < graph_width; i++ ) {
		for( int j = 0; j < graph_height; j++ ) {
			get_vertex( i, j )->visited = false;
		}
	}
	
	Vertex* start = get_vertex( source.x, source.y );

	queue< Vertex* > q;
	q.push( start );
	Vertex* temp;
	bool stop = false;
	while( !q.empty() && !stop ) {
		Vertex* popped = q.front();
		q.pop();

		if ( popped->visited ) {
			continue;
		}

		popped->visited = true;

		int num_neighbors = map->getNumNeighbors( popped->x, popped->y );
		for ( int i = 0; i < num_neighbors && !stop; i++ ) {
			int a, b;
			map->getNeighbor( popped->x, popped->y, i, a, b );
			temp = get_vertex( a, b );

			if( !temp->visited ) {
				temp->prev = popped;
				if( *temp == target ) {
					stop = true;
				}
				q.push( temp );
			}
		}
	}

	while( temp->prev != start ) {
		temp = temp->prev;
	}

	int num_neighbors = map->getNumNeighbors( temp->prev->x, temp->prev->y );
	for( int i = 0; i < num_neighbors; i++ ) {
		int a, b;
		map->getNeighbor( temp->prev->x, temp->prev->y, i, a, b );
		Vertex check( a, b );
		
		if( check == *temp ) {
			return i;
		}
	}	
	return 0;
}

Vertex Simple_Hero::rank_actors( GraphMap* map, Vertex* first ) {
	make_graph( map );

	if( map->getNumNeighbors( first->x, first-> y ) == 1 ) {
		int a, b;
		map->getNeighbor( first->x, first->y, 0, a, b );
		Vertex temp( a, b );
		return temp;
	}

	vector< Vertex* > ordered;
	int num_actors = map->getNumActors();
	for ( int i = 0; i < num_actors; i++ ) {
		if(  (map->getActorType( i ) & ACTOR_EATABLE) != 0 )  {
			int a, b;
			map->getActorPosition( i, a, b );
			Vertex* temp = get_vertex( a, b );
			if( temp->x != -1 && temp->y != -1 ) {
				ordered.push_back( temp );
			}
		}
	}

	if( ordered.size() == 1 ) {
		return *ordered[0];
	}

	queue< Vertex* > q;
	q.push( first );

	while( !q.empty() ) {
		Vertex* popped = q.front();
		q.pop();

		if ( popped->visited ) {
			continue;
		}

		popped->visited = true;

		int num_neighbors = map->getNumNeighbors( popped->x, popped->y );
		for ( int i = 0; i < num_neighbors; i++ ) {
			int a, b;
			map->getNeighbor( popped->x, popped->y, i, a, b );
			Vertex* temp = get_vertex( a, b );

			if( !temp->visited ) {
				temp->dist = popped->dist + 1;
				q.push( temp );
			}
		}
	}

	sort( ordered.begin(), ordered.end(), sort_function );

	int num_eatables = ordered.size();
	for ( int i = 0; i < num_eatables; i++ ) {
		set_weight( map, ordered[i], num_eatables );
		if( ordered[i]->weight >= num_eatables ) 	
			return *ordered[i];
	}

	sort( ordered.begin(), ordered.end(), sort_function );
	return *ordered[0];
}

void Simple_Hero::set_weight( GraphMap* map, Vertex* v, int num_eatables ) {
	for ( int i = 0; i < graph_width; i++ ) {
		for ( int j = 0; j < graph_height; j++ ) {
			get_vertex( i, j )->visited = false;
		}
	}

	queue< Vertex* > q;
	q.push( v );

	while( !q.empty() ) {
		Vertex* popped = q.front();
		q.pop();

		if( popped->visited ) 	continue;

		popped->visited = true;

		if( get_type( map, popped ) & ACTOR_EATABLE ) {
			v->weight++;
			if( v->weight == num_eatables ) return;
		}

		int num_neighbors = map->getNumNeighbors( popped->x, popped->y );
		for ( int i = 0; i < num_neighbors; i++ ) {
			int a, b;
			map->getNeighbor( popped->x, popped->y, i, a, b );
			Vertex* temp = get_vertex( a, b );

			if( !temp->visited ) {
				q.push( temp );
			}
		}
	}
}