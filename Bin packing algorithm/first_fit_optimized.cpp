#include "AVLTree.h"
#include "project2.h"
using namespace forest;

struct mypair {
	int index;
	double items;
};

bool compare_index_op(const mypair & a, const mypair & b)
{
	return a.items > b.items;
}


void first_fit_optimized(const std::vector<double>& items, std::vector<int>& assignment, std::vector<double>& free_space)
{
	int size = items.size();
	if(!size)
	{
		return;
	}
	
	FFNode new_bin = FFNode(0,1.0,1.0);
	free_space.push_back(1.0);
	//There is at least one item insert new bin to the tree
	AVLTree<FFNode> tree;
	tree.insert(new_bin);
	for(int i =0; i < size; i++)
	{
		double bestrc  = tree.Largestrc();
		//check if there is a bin in the tree that fit the item 
		if(items[i] > bestrc)
		{
			int new_Bin_rc = free_space.size();
			FFNode new_node = FFNode(new_Bin_rc,1.0,1.0);
			tree.insert(new_node);
			free_space.push_back(1.0);
		}
		//traverse the tree to put the item in the right place
		int key = tree.FFtraverse(items[i]);
		free_space[key] -= key;
		assignment[i] = key;
	}
	
}

void first_fit_optimized_decreasing(const std::vector<double>& items, std::vector<int>& assignment, std::vector<double>& free_space)
{
	int size = items.size();
	if(!size)
	{
		return;
	}
	
	vector<mypair> sorted_items;
	for(int i = 0; i < size;i++)
	{
		mypair p = {i,items[i]};
		sorted_items.push_back(p);
	}

	std::sort(sorted_items.begin(),sorted_items.end(),compare_index_op);

	FFNode new_bin = FFNode(0,1.0,1.0);
	free_space.push_back(1.0);
	//There is at least one item insert new bin to the tree
	AVLTree<FFNode> tree;
	tree.insert(new_bin);
	for(int i =0; i < size; i++)
	{
		double bestrc  = tree.Largestrc();
		//check if there is a bin in the tree that fit the item 
		if(sorted_items[i].items > bestrc)
		{
			int new_Bin_rc = free_space.size();
			FFNode new_node = FFNode(new_Bin_rc,1.0,1.0);
			tree.insert(new_node);
			free_space.push_back(1.0);
		}
		//traverse the tree to put the item in the right place
		int key = tree.FFtraverse(sorted_items[i].items);
		free_space[key] -= key;
		assignment[sorted_items[i].index] = key;
	}
	
}
