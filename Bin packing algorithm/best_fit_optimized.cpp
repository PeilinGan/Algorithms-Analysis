#include "AVLTree.h"
#include "project2.h"
using namespace forest;

struct my_pair {
	int index;
	double items;
};

bool compare_index_opbf(const my_pair & a, const my_pair & b)
{
	return a.items > b.items;
}


void best_fit_optimized(const std::vector<double>& items, std::vector<int>& assignment, std::vector<double>& free_space)
{
	int size = items.size();
	if(!size)
	{
		return;
	}
	//there is at least one item. insert new bin the the tree
	BFNode new_bin = BFNode(0,1.0,1.0);
	free_space.push_back(1.0);
	AVLTree <BFNode> tree;
	tree.insert(new_bin);

	for(int i =0; i < size; i++)
	{
		//check if there is a bin in the tree that fit the item
		double bestrc  = tree.Largestrc(); 
		if(items[i] > bestrc)
		{
			int new_Bin_rc = free_space.size();
			BFNode new_node = BFNode(new_Bin_rc,1.0,1.0);
			tree.insert(new_node);
			free_space.push_back(1.0);
		}
		//traverse the tree to put the item in the right place
		int key = tree.BFpack(items[i]);
		free_space[key] -= key;
		assignment[i] = key;
	}	
}

void best_fit_optimized_decreasing(const std::vector<double>& items, std::vector<int>& assignment, std::vector<double>& free_space)
{
	int size = items.size();
	if(!size)
	{
		return;
	}
	vector<my_pair> sorted_items;
	for(int i = 0; i < size;i++)
	{
		my_pair p = {i,items[i]};
		sorted_items.push_back(p);
	}

	std::sort(sorted_items.begin(),sorted_items.end(),compare_index_opbf);

	//there is at least one item. insert new bin the the tree
	BFNode new_bin = BFNode(0,1.0,1.0);
	free_space.push_back(1.0);
	AVLTree <BFNode> tree;
	tree.insert(new_bin);

	for(int i =0; i < size; i++)
	{
		//check if there is a bin in the tree that fit the item
		double bestrc  = tree.Largestrc(); 
		if(sorted_items[i].items > bestrc)
		{
			int new_Bin_rc = free_space.size();
			BFNode new_node = BFNode(new_Bin_rc,1.0,1.0);
			tree.insert(new_node);
			free_space.push_back(1.0);
		}
		//traverse the tree to put the item in the right place
		int key = tree.BFpack(sorted_items[i].items);
		free_space[key] -= key;
		assignment[sorted_items[i].index] = key;
	}	
}