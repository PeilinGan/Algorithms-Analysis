#include "project3.h"

/*
Node must 
    have a default constructor
    have a public member int 'id' which uniquely identifies a node (no two nodes have the same id).
           id must be set in the constructor and thereafter not modified 
    have the following method: 
        bool operator==(const Node& other) const {return id == other.id;} 

You may add whatever other members you like to Node
*/

class Node {
public:
	int id;
	vector<int> edges;
public: 
	Node(){ id = 0;}
	Node(int id): id(id) {}
	Node(const Node & other){
		id = other.id;
		edges = vector<int>(other.edges);
	}
	
	bool operator==(const Node& other) const {
		return id == other.id;
	} 
};