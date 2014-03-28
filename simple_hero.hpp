#ifndef SIMPLE_HERO_HPP_
#define SIMPLE_HERO_HPP_


#include "GraphMap.hpp"
#include "vertex.hpp"
#include "Actor.hpp"

#include <vector>



using namespace std;

class Simple_Hero : public Actor {

	protected: 
		void make_graph( GraphMap* map );

	public:
		int graph_width;
		int graph_height;
		bool made_graph;


		Simple_Hero( int type );
		virtual ~Simple_Hero();
		virtual int select_neighbor( GraphMap* map, int x, int y );
		virtual Simple_Hero* duplicate();
		virtual const char* getActorId();
		virtual const char* getNetId();


		void update_vertices( GraphMap* map );
		Vertex& get_vertex( int x, int y );

		vector< Vertex > actor_list;
		vector< vector< Vertex > > graph;


		int find_path( Vertex v );
		int where_go( GraphMap* map, int x1, int y1, int x2, int y2 );
};

#endif
