#include "project2.h"

void next_fit(const std::vector<double>& items, std::vector<int>& assignment, std::vector<double>& free_space)
{
	int size = items.size();
	if(size == 0)
	{
		return;
	}
	free_space.push_back(1.0);
	int current_bin = 0;
	for(int i = 0; i < size; i++)
	{
		if(items[i] <= free_space[current_bin])
		{
			free_space[current_bin] -= items[i];
			assignment[i] = current_bin;

		}
		else
		{
			free_space.push_back(1.0);
			current_bin += 1;
			free_space[current_bin] -= items[i];
			assignment[i] = current_bin;
		}
	}

	if(free_space[0] == 1.0)
	{
		free_space.pop_back();
	}

}
