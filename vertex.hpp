#ifndef VERTEX_HPP_
#define VERTEX_HPP_

#include <unordered_set>
using namespace std;

class Vertex {

	public:
		Vertex();
		Vertex( int x, int y );

		char* character;

		int x;
		int y;
		
		int weight;
		int dist;

		Vertex* prev;
		bool visited;
};

bool operator!= ( const Vertex& a, const Vertex& b );
bool operator== ( const Vertex& a, const Vertex& b );
bool sort_function( Vertex* a, Vertex* b );

struct hash_vertex {
	int operator()(const Vertex &v ) const {
		return v.x ^ v.y;
	}
};


#endif
