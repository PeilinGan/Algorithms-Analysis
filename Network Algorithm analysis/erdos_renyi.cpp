#include "graph.h"

Graph create_erdos_renyi_graph(int n, float p){
	vector<int> start;
	vector<int> end;
	int v = 1; 
	int w = -1;
	double r;
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	mt19937 generator = mt19937(seed);
	uniform_real_distribution<double> dist(0.0,1.0);
	while(v < n)
	{
		r = dist(generator);
		while(r == 1.0)
			{ r = dist(generator);}
		w = w + 1+ floor(log(1-r)/log(1-p));
		while(w >= v && v <n){
			w = w-v;
			v += 1;
		}
		if(v < n )
		{
			start.push_back(v+1);
			end.push_back(w+1);
		}
	}
	return Graph(n,start,end);
}



