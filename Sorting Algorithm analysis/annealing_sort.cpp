#include "index.h"

void annealing_sort(std::vector<int>& nums, const std::vector<int>& temps, const std::vector<int>& reps)
{
	int size = nums.size();
	int s; 
	std::random_device dev;
	std::mt19937 generator(dev());
	if((size == 1 ) || (size == 0))
		return;

	for(int i = 0; i< temps.size() -1; i++)
	{
		for(int j = 0; j < size -1 ; j++)
		{
			for(int k = 0; k < reps[i]; k++)
			{
				std::uniform_int_distribution<int> uid = random_int_in_range(j+1,std::min(size -1,j+temps[i]));
				s = uid(generator);
				if(nums[j] > nums[s])
				{
					std::swap(nums[j],nums[s]);
				}
			}
		}

		for(int j = size -1 ; j > 0;j--)
		{
			for(int k= 0; k<  reps[i]; k++)
			{
				std::uniform_int_distribution<int> uid = random_int_in_range(std::max(0,j - temps[i]), j);
				s = uid(generator);
				if(nums[s] > nums[j]){
					std::swap(nums[j],nums[s]);
				}
			}
		}
	}
	
}