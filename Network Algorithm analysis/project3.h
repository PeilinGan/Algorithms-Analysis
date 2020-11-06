#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
#include <string>
#include <cmath>
#include <cfloat>
#include <random>
#include <chrono>
#include <numeric>
#include <fstream>


using namespace std;
#ifndef PROJECT3_H
#define PROJECT3_H

/******* NODE CLASS ********/
class Node;  // define/implement in node.h

/*
Node must 
    have a default constructor
    have a public member int 'id' which uniquely identifies a node (no two nodes have the same id).
           id must be set in the constructor and thereafter not modified 
    have the following method: 
        bool operator==(const Node& other) const {return id == other.id;} 

You may add whatever other members you like to Node
*/

class Graph;


/******* ALGORITHMS TO IMPLEMENT ********/
// implement all 3 in graph_algorithms.cpp
// should include graph.h
int get_diameter(Graph graph); 
float get_clustering_coefficient(Graph graph);
std::map<int, int> get_degree_distribution(Graph graph);

/******* GRAPH GENERATION FUNCTIONS ********/
Graph create_erdos_renyi_graph(int n, float p); // implement in erdos_renyi.cpp
                                                // only if your student ID is ODD
Graph create_barabasi_albert_graph(int n, int d); // implement in barabasi_albert.cpp
                                                  // only if your student ID is EVEN
// whichever file you have should #include "graph.h"

/******* FILE SUMMARY (SORTED BY DEPENDENCIES) 
    project3.h
    node.h
    graph.h
    graph.cpp
    graph_algorithms.cpp
    erdos_renyi.cpp OR barabasi_albert.cpp (see GRAPH GENERATION FUNCTIONS section)
    run.sh 
*/
#endif