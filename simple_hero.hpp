#ifndef SIMPLE_HERO_HPP_
#define SIMPLE_HERO_HPP_

#include "GraphMap.hpp"
#include "vertex.hpp"
#include "Actor.hpp"

#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

class Simple_Hero : public Actor {
	public:
		int graph_width;
		int graph_height;
		vector< vector< Vertex > > graph;


		inline Simple_Hero( int type ) : Actor( type ) {}
		inline Simple_Hero* duplicate() {
			return new Simple_Hero( this->getType() );
		}
		
		inline virtual const char* getActorId() { 	
			return "simplehero"; 
		}
		
		inline virtual const char* getNetId() {
			return "hammesa"; 
		}

		Vertex* get_vertex( int x, int y );	
		void make_graph( GraphMap* map );		
		int get_type( GraphMap* map, Vertex* v );

		virtual int selectNeighbor( GraphMap* map, int x, int y );
		int where_go( GraphMap* map, Vertex& source, Vertex& target );
		Vertex rank_actors( GraphMap* map, Vertex* first );
		void set_weight( GraphMap* map, Vertex* v, int num_eatables );
};
#endif