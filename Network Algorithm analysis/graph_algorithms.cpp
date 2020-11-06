#include "graph.h"
#include "project3.h"


int get_diameter(Graph graph){
	int max_distance = -1;
	int start = 1;
	bool stop = false;
	while(!stop)
	{
		vector<int> id_distance = graph.Breathfirst(start);
		if(id_distance[1] <= max_distance){
			stop = true;
			return max_distance;
		}
		start = id_distance[0];
		max_distance = id_distance[1];
	}
	return max_distance;
}


float get_clustering_coefficient(Graph graph){
	int denominator = graph.two_edge_path_count();
	int numerator = graph.triangle_count();
	return (float) 3*numerator / denominator;
}


std::map<int, int> get_degree_distribution(Graph graph){
	map<int,int> maps;
	int num_nodes = graph.get_num_nodes();
	int degree;
	map<int,Node> id_to_map = graph.get_id_to_node_map();
	for(int i =0; i <= num_nodes; i++){
		maps.insert({i,0});
	}
	for(int i = 1;i <= num_nodes; i++)
	{
		degree = id_to_map[i].edges.size();
		maps[degree] += 1;
	}
	return maps;
}
