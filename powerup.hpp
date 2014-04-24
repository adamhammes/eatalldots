#ifndef POWERUP_HPP_
#define POWERUP_HPP_

#include "GraphMap.hpp"
#include "vertex.hpp"
#include "Actor.hpp"
#include <unordered_set>
#include <unordered_map>
#include <functional>

using namespace std;

class Powerup : public Actor {
	private:
		unordered_set< Vertex, hash_vertex > v_set;
		unordered_map< Vertex, int, hash_vertex > distances;

		bool visited( const Vertex& v ) const;
		int& dist( const Vertex& v );
	public:
		Powerup( int type );
		Powerup* duplicate();

		const char* getActorId();
		const char* getNetId();
		int selectNeighbor( GraphMap* map, int x, int y );
};


#endif