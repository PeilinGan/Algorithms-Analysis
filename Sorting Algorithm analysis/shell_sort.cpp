#include "project1.h"

void shell_sort(std::vector<int>& nums, const std::vector<int>& gaps)
{
	int size = nums.size();
	int temp,buf,gap;
	if((size == 1 ) || (size == 0))
		return;
	for(int index =0; index < gaps.size(); index ++)
	{
		gap = gaps[index];
		for(int i = gap; i <size; i++)
		{
			temp = nums[i];
			buf = i;
			while((nums[buf-gap] > temp) && (gap <= buf))
			{
				nums[buf] = nums[buf - gap];
				buf -= gap;
			}
			nums[buf] = temp;
		}
	}
}