#ifndef VERTEX_CPP_
#define VERTEX_CPP_
#include "vertex.hpp"

Vertex::Vertex() {}

Vertex::Vertex( int x, int y ) {
	this-> x = x;
	this-> y = y;
	this->visited = false;
	this->weight = this->dist = 0;
}

bool operator== ( Vertex& a, Vertex& b ) {
	return a.x == b.x && a.y == b.y;
}

bool operator!= ( Vertex& a, Vertex& b ) {
	return !( a == b );
}

bool sort_function ( Vertex* a, Vertex* b ) {
	if( a->weight > b->weight ) {
		return true;
	}

	if( a->weight == b->weight ) {
		return a->dist < b->dist;
	}
	return false;
}
#endif