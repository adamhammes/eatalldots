#include "powerup.hpp"
using namespace std;

Powerup::Powerup( int type ): Actor( type ) {}

Powerup* Powerup::duplicate() {
	return new Powerup( this->getType() );
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


