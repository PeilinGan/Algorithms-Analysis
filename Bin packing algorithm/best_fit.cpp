#include "project2.h"

struct mypair {
	int index;
	double items;
};

bool compare_index(const mypair & a, const mypair & b)
{
	return a.items > b.items;
}


void best_fit(const std::vector<double>& items, std::vector<int>& assignment, std::vector<double>& free_space)
{
	int size = items.size();
	if(size == 0)
	{
		return;
	}
	for(int i = 0; i < size; i++)
	{
		int best_bin = -1;
		double best_remaining = 100.0;
		for(int j = 0; j < free_space.size(); j++ )
		{
			if(items[i] <= free_space[j])
			{
				if(free_space[j] < best_remaining)
				{
					best_remaining = free_space[j];
					best_bin = j;
				}
			}
		}
		if(best_bin == -1)
		{
			assignment[i] = free_space.size();
			free_space.push_back(1.0 - items[i]);
		}
		else
		{
			assignment[i] = best_bin;
			free_space[best_bin] -= items[i];
		}
	}
}
void best_fit_decreasing(const std::vector<double>& items, std::vector<int>& assignment, std::vector<double>& free_space)
{
	int size = items.size();
	if(size == 0)
	{
		return;
	}
	
	vector<mypair> sorted_items;
	for(int i = 0; i < size;i++)
	{
		mypair p = {i,items[i]};
		sorted_items.push_back(p);
	}

	std::sort(sorted_items.begin(),sorted_items.end(),compare_index);

	for(int i = 0; i < size; i++)
	{
		int best_bin = -1;
		double best_remaining = 100.0;
		for(int j = 0; j < free_space.size(); j++ )
		{
			if(sorted_items[i].items <= free_space[j])
			{
				if(free_space[j] < best_remaining)
				{
					best_remaining = free_space[j];
					best_bin = j;
				}
			}
		}
		if(best_bin == -1)
		{
			assignment[sorted_items[i].index] = free_space.size();
			free_space.push_back(1.0 - sorted_items[i].items);
		}
		else
		{
			assignment[sorted_items[i].index] = best_bin;
			free_space[best_bin] -= sorted_items[i].items;
		}
	}
}

