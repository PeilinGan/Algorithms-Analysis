#include "index.h"

void insertion_sort(std::vector<int>& nums)
{
	int size = nums.size();
	int temp;
	if((size == 1 ) || (size == 0))
		return;
	for(int i = 0; i < size - 1; i++)
	{
		if(nums[i+1] < nums[i])
		{
			temp = i+1;
			while(temp > 0)
			{
				if(nums[temp] < nums[temp -1])
				{
					std::swap(nums[temp],nums[temp-1]);
					temp -= 1;
				}
				else
				{
					break;
				}
			}

		}
	}
}
