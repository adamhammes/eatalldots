#ifndef POWERUP_HPP_
#define POWERUP_HPP_

#include "GraphMap.hpp"
#include "vertex.hpp"
#include "Actor.hpp"
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <vector>


using namespace std;

class Powerup : public Actor {
	private: 
		GraphMap* map;
		unordered_set< Vertex, hash_vertex > v_set;
		unordered_map< Vertex, int, hash_vertex > dist;

		bool visited( const Vertex& v ) const;
		int& dist( const Vertex& v );

	public:
		Powerup( int type );
		int selectNeighbor( GraphMap* map, int x, int y );
		Powerup* duplicate();

		const char* getActorId();
		const char* getNetId();

		void rank_nodes( int x, int y );
};
#endif