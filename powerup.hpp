#ifndef POWERUP_HPP_
#define POWERUP_HPP_

#include "GraphMap.hpp"
#include "vertex.hpp"
#include "Actor.hpp"

using namespace std;

class Powerup : public Actor {
	public:
		Powerup( int type );
		int selectNeighbor( GraphMap* map, int x, int y );
		Powerup* duplicate();

		const char* getActorId();
		const char* getNetId();
}


#endif