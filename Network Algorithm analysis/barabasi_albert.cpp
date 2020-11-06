#include "graph.h"
#include "project3.h"

Graph create_barabasi_albert_graph(int n, int d){
	int M[2*n*d];
	vector<int> start;
	vector<int> end;
	int r;
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	mt19937 generator = mt19937(seed);
	Graph graph = Graph(n);

	for(int v = 0; v< n; v++){
		for(int i =0; i< d; i++){
			M[2*(v*d+i)] = v;
			uniform_int_distribution<int> dist(0,2*(v*d+i));
			r = dist(generator);
			M[2*(v*d+i) + 1] = M[r];
		}
	}
	int n1; int n2;
	for(int i =0; i <= n*d-1;i++){
		n1 = M[2*i]+1;
		n2 = M[2*i+1]+1;
		if(n1 != n2){
			graph.add_edges(n1,n2);
		}
	}
	return graph;
}