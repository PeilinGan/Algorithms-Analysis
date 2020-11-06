#include "project3.h"
#include "node.h"

class AbstractGraph 
{
    public: // all methods must be overriden
        virtual int get_num_nodes() = 0; // number of nodes
        virtual int get_num_edges() = 0; // number of edges
        virtual bool is_neighbor(Node u, Node v) = 0 ;
        virtual std::vector<Node> get_neighbors(Node u) = 0; 

        // allows lookup of nodes from ids
        virtual std::map<int, Node> get_id_to_node_map() = 0;
};


class Graph : public AbstractGraph
{
private:
	map<int,Node> maps;
	int num_nodes = 0;
	int num_edges = 0;
	vector<Node> nodes;
	vector<int> u;
	vector<int> v;
public:
    Graph(){}
    Graph(int num_nodes);
    Graph(int num_nodes, vector<int> u, vector<int> v);
public: // all methods must be overriden
    int get_num_nodes(); // number of nodes
    int get_num_edges() ; // number of edges
    bool is_neighbor(Node u, Node v);
    std::vector<Node> get_neighbors(Node u); 
    void add_edges(int u, int v);

    // allows lookup of nodes from ids
    std::map<int, Node> get_id_to_node_map() ;
    vector<int> Breathfirst(int start);
    int triangle_count();
    int two_edge_path_count();


};


// construct a graph using num_nodes nodes and edges (ui, vi) for all i
// u and v will be the same length
// (ui, vi) are pairs of integers which can be mapped uniquely to (ui', vi'), pairs of Nodes
Graph make_graph(int num_nodes, std::vector<int> u, std::vector<int> v);







