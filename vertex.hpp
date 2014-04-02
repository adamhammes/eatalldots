#ifndef VERTEX_HPP_
#define VERTEX_HPP_



class Vertex {

	public:
		Vertex();
		Vertex( int x, int y, Vertex* nprev = 0 );

		char* character;

		int x;
		int y;
		
		int weight;
		int dist;

		Vertex* prev;
		bool visited;
};

		bool operator!= ( Vertex& a, Vertex& b );;
		bool operator== ( Vertex& a, Vertex& b );
#endif
