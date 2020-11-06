#include "graph.h"
Graph::Graph(int num_nodes):num_nodes(num_nodes){
	for(int i = 0; i < num_nodes; i++){
		Node n(i + 1);
		nodes.push_back(n);
		maps.insert({i+1,n});
	}
}


Graph::Graph(int num_nodes, vector<int> u, vector<int> v): num_nodes(num_nodes),u(u),v(v){
	for(int i = 0; i < num_nodes; i++){
		Node n(i + 1);
		nodes.push_back(n);
		maps.insert({i+1,n});
	}
	for(int i = 0 ; i < u.size(); i++)
	{
		if(u[i] > num_nodes || u[i] <1){
			throw "Given Edges contain unkonwn Node.";
		}
		if(v[i] > num_nodes || v[i] <1){
			throw "Given Edges contain unkonwn Node.";
		}
		if(find(nodes[u[i]-1].edges.begin(),nodes[u[i]-1].edges.end(),v[i]) == nodes[u[i]-1].edges.end()){
			nodes[u[i]-1].edges.push_back(v[i]);
			nodes[v[i]-1].edges.push_back(u[i]);
			maps[u[i]].edges.push_back(v[i]);
			maps[v[i]].edges.push_back(u[i]);
			num_edges += 1;
			}
	}
}
int Graph::get_num_nodes(){
	return num_nodes;
}
int Graph::get_num_edges() {
	return num_edges;
}
vector<Node> Graph::get_neighbors(Node u){
	int id = u.id;
	vector<Node> v;
	for(int i:maps[id].edges){
		v.push_back(maps[i]);
	}
	return v;
}

map<int, Node> Graph::get_id_to_node_map(){
	return maps;
}

void Graph::add_edges(int u, int v){
	if(!is_neighbor(maps[u],maps[v]))
	{
		maps[u].edges.push_back(v);
		maps[v].edges.push_back(u);
		num_edges += 1;
	}
}


bool Graph::is_neighbor(Node u, Node v){
	vector<int>::iterator it= find(u.edges.begin(),u.edges.end(),v.id);
	if(it == u.edges.end())
		return false;
	return true;
}


Graph make_graph(int num_nodes, std::vector<int> u, std::vector<int> v){
	Graph g = Graph(num_nodes,u,v);
	return g;
}




vector<int> Graph::Breathfirst(int start){
	bool visited[num_nodes+1];
	int distance[num_nodes+1];
	int current;
	vector<int> path{start};
	for(int num = 0; num < num_nodes+1; num++)
	{
		visited[num] = false;
		distance[num] = 0;
	}
	visited[start] = true;
	while(path.size() != 0)
	{	
		current = path[0];
		path.erase(path.begin());
		for(int i: maps[current].edges)
		{
			if(!visited[i])
			{
				visited[i] =true;
				distance[i]= distance[current] + 1; 
				path.push_back(i);
			}
		}
	}
	vector<int> id_distance{current,distance[current]};
	return id_distance;
}

int Graph::triangle_count(){
	vector<int> L;

	int count =0;
	int dv[num_nodes+1];
	map<int,bool> HL;
	vector<vector<int>> D(num_nodes+1);
	vector<vector<int>> Nv(num_nodes+1);
	for(int i=1; i<= num_nodes;i++){
		dv[i] = maps[i].edges.size();
		HL.insert({i,false});
	}
	 for(int i=1; i<= num_nodes;i++){
	 	D[dv[i]].push_back(i);
	 }
	for(int count =1; count <= num_nodes; count++){
		int smallest_index= -1;
		int select_vertex = -1;
		for(int i = 0; i< D.size(); i++){
			if(D[i].size() != 0){
				smallest_index = i;
				select_vertex = D[i][0];
				L.insert(L.begin(),select_vertex);
				D[i].erase(D[i].begin());
				HL[select_vertex] = true;
				break;
			}
		}
		if(select_vertex != -1)
		{
			for(int w: maps[select_vertex].edges){
				if(HL[w] == false){
					vector<int>::iterator it = find(D[dv[w]].begin(),D[dv[w]].end(),w);
					if(it != D[dv[w]].end()){
						D[dv[w]].erase(it);
					}
					dv[w] -= 1;
					D[dv[w]].push_back(w);
					Nv[select_vertex].push_back(w);
				}
			}
		}
	}
	int node_number = 0;
	for(int v: L){
		node_number += 1;
		//cout<<"number: "<<node_number<<endl;
		int size = Nv[v].size();
		for(int i =0;i<size;i++){
			for(int j=i+1; j< size;j++){
				if(is_neighbor(maps[Nv[v][i]],maps[Nv[v][j]]))
					count++;
			}
		}
	}
	return count;	
}

int Graph::two_edge_path_count(){
	int count = 0;
	for(int i=1; i<= num_nodes; i++)
	{
		int degree = maps[i].edges.size();
		count += degree * (degree -1)/2;
	}
	return count;
}











