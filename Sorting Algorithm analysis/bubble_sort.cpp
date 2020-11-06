#include "index.h"

void bubble_sort(std::vector<int>& nums)
{
	int size = nums.size();
	int temp;
	if((size == 1 ) || (size == 0))
		return;
	for(int i = 0; i < size - 1; i++)
	{
		for(int j = 0; j < size-1; j++)
		{
			if (nums[j] > nums [j+1])
			{
				std::swap(nums[j],nums[j+1]);
			}
		}
	}
	return;
}