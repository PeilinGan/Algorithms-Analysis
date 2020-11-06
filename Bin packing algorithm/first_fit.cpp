#include "project2.h"

struct mypair {
	int index;
	double items;
};

bool compareindex(const mypair & a, const mypair & b)
{
	return a.items > b.items;
}

void first_fit(const std::vector<double>& items, std::vector<int>& assignment, std::vector<double>& free_space)
{
	int size = items.size();
	if(size == 0)
	{
		return;
	}
	for(int i = 0; i < size; i++)
	{
		bool fit = false;
		for(int j = 0; j < free_space.size(); j++ )
		{
			if(items[i] <= free_space[j])
			{
				free_space[j] -= items[i];
				assignment[i] = j;
				fit = true;
				break;
			}
		}
		if(!fit)
		{
			assignment[i] = free_space.size();
			free_space.push_back(1.0 - items[i]);
		}
	}
          
}
void first_fit_decreasing(const std::vector<double>& items, std::vector<int>& assignment, std::vector<double>& free_space)
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

	std::sort(sorted_items.begin(),sorted_items.end(),compareindex);


	for(int i = 0; i < size; i++)
	{
		bool fit = false;
		for(int j = 0; j < free_space.size(); j++ )
		{
			if(sorted_items[i].items <= free_space[j])
			{
				free_space[j] -= sorted_items[i].items;
				assignment[sorted_items[i].index] = j;
				fit = true;
				break;
			}
		}
		if(!fit)
		{
			assignment[sorted_items[i].index] = free_space.size();
			free_space.push_back(1.0 - sorted_items[i].items);
		}
	}
}

