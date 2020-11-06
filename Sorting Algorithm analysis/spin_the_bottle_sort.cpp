#include "project1.h"
#include "random_generator.h"

void spin_the_bottle_sort(std::vector<int>& nums)
{
	
	int size = nums.size();
	std::random_device dev;
	std::mt19937 generator(dev());
	std::uniform_int_distribution<int> uid = random_int_in_range(0,size-1);
	int temp;

	if((size == 1 ) || (size == 0))
		return;

	while(!(std::is_sorted(nums.begin(),nums.end())))
	{
		for(int i = 0; i <size ; i++)
		{
			temp = uid(generator);
			if(((i < temp) && (nums[i] > nums[temp])) || ((i > temp) && (nums[i] < nums[temp])))
				std::swap(nums[i],nums[temp]);
		}
	}
}

