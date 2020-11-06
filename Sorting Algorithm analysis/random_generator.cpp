#include "random_generator.h"
#include <iostream>
std::uniform_int_distribution<int> random_int_in_range(int lb, int ub)
{
	return std::uniform_int_distribution<int> (lb,ub);
}

std::mt19937 mt_with_current_seed()
{
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    return std::mt19937(seed);
}

std::vector<int> uniform_vector_generator(int size)
{
	std::vector<int> vec;
	int j;
	for(int i= 1; i< size+1; i++)
	{
		vec.push_back(i);
	}
	std::mt19937 mt = mt_with_current_seed();
	//Fisher-Yates shuffing
	for(int k = size -1; k > 0; k--)
	{
		std::uniform_int_distribution<int> uid = random_int_in_range(0,k);
		j = uid(mt);
		std::swap(vec[k],vec[j]);
	}
	return vec;
}


std::vector<int> almost_sorted_generator(int size)
{
	std::vector<int> vec;
	for(int i = 1; i< size +1; i++)
	{
		vec.push_back(i);
	}
	std::uniform_int_distribution<int> uid = random_int_in_range(0,size-1);
	std::mt19937 mt = mt_with_current_seed();
	int pairs = 2 * std::log10(size);
	int i;
	int j;
	for(int k = 0; k < pairs; k++)
	{
		i = uid(mt);
		j = uid(mt);
		std::swap(vec[i],vec[j]);
	}
	return vec;
}

std::vector<int> gap_generator_first(int size)
{
	std::vector<int> vec;
	int temp = size/2;
	while(temp > 0)
	{
		vec.push_back(temp);
		temp /= 2;
	}
	return vec;
}

std::vector<int> gap_generator_second(int size)
{
	std::vector<int> vec;
	int temp = 1;
	int k = 1;
	while(temp < size)
	{
		temp = (9* pow(9/4,k-1) - 4)/5;
		vec.push_back(temp);
		k += 1;
	}
	std::reverse(vec.begin(),vec.end());
	return vec;

}

std::vector<int> temp_generator_first(int size)
{
	std::vector<int> vec;
	int temp = size/2;
	while(temp > 0)
	{
		vec.push_back(temp);
		temp /= 2;
	}
	return vec;
}


std::vector<int> temp_generator_second(int size)
{
	std::vector<int> vec;
	int temp = size/2;
	while(temp > 0)
	{
		vec.push_back(temp);
		temp -= 20;
	}

	return vec;
}

std::vector<int> repetition_generator_first(int size,int vector_size)
{
	std::vector<int> vec;
	int num = vector_size/2;
	for(int i = 0; i< size; i++)
	{
		vec.push_back(num - i);
	}
	return vec;
}

std::vector<int> repetition_generator_second(int size,int vector_size)
{
	std::vector<int> vec;
	for(int i = 0; i< size; i++)
	{
		vec.push_back(vector_size - size -1);
	}
	return vec;

}


