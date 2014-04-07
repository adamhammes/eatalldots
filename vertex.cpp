#ifndef VERTEX_CPP_
#define VERTEX_CPP_
#include "vertex.hpp"
#include <limits>

Vertex::Vertex() {
	this->visited = false;
	this->prev = 0;
}

Vertex::Vertex( int x, int y, Vertex* nprev ) {
	this-> x = x;
	this-> y = y;
	this->visited = false;
	this->weight = 0;
	this->prev = nprev;
}


bool operator== ( Vertex& a, Vertex& b ) {
	return a.x == b.x && a.y == b.y;
}

bool operator!= ( Vertex& a, Vertex& b ) {
	return !( a == b );

}

#endif
