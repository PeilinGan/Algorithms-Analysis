#include <iostream>
#include "project1.h"
#include "timing.h"

int main()
{

	timing t;
    timing t1;	
	//-------------------------------------Test For Bubble Sort --------------------------------------------
	
	std::vector<int> sizes;
	for(int i = 500; i< 25000;i += 1000)
	{
		sizes.push_back(i);
	}

    create_empty_timings_file("bubble_sort_timings_un_vector.csv");
    create_empty_timings_file("bubble_sort_timings_as_vector.csv");


	for(int i = 0; i< sizes.size();i++)
	{
		std::vector<int> uniformed_vector = uniform_vector_generator(sizes[i]);
		std::vector<int> almost_sorted_vector =  almost_sorted_generator(sizes[i]);
		t = time_sort(uniformed_vector,3, bubble_sort);
		add_timings_to_file("uniformed_vector",t,"bubble_sort_timings_un_vector.csv");
		t1 = time_sort(almost_sorted_vector,3, bubble_sort);
		add_timings_to_file("almost_sorted_vector",t1,"bubble_sort_timings_as_vector.csv");
	}

	

	//-------------------------------------Test For Insertion Sort --------------------------------------------
    
    create_empty_timings_file("insertion_sort_timings_un_vector.csv");
    create_empty_timings_file("insertion_sort_timings_as_vector.csv");
	
	for(int i = 0; i< sizes.size();i++)
	{
		std::vector<int> uniformed_vector = uniform_vector_generator(sizes[i]);
		std::vector<int> almost_sorted_vector =  almost_sorted_generator(sizes[i]);
		t = time_sort(uniformed_vector,3, insertion_sort);
		add_timings_to_file("uniformed_vector",t,"insertion_sort_timings_un_vector.csv");
		t1 = time_sort(almost_sorted_vector,3, insertion_sort);
		add_timings_to_file("almost_sorted_vector",t1,"insertion_sort_timings_as_vector.csv");
	}


	//-------------------------------------Test For Spin the bottle Sort --------------------------------------------
    
    create_empty_timings_file("spin_the_bottle_timings_un_vector.csv");
    create_empty_timings_file("spin_the_bottle_timings_as_vector.csv");

  	std::vector<int> smaller_size;
	for(int i = 500; i< 10000;i += 500)
	{
		smaller_size.push_back(i);
	}

	for(int i = 0; i< smaller_size.size();i++)
	{
		std::vector<int> uniformed_vector = uniform_vector_generator(smaller_size[i]);
		std::vector<int> almost_sorted_vector =  almost_sorted_generator(smaller_size[i]);
		t = time_sort(uniformed_vector,3, spin_the_bottle_sort);
		add_timings_to_file("uniformed_vector",t,"spin_the_bottle_sort_timings_un_vector.csv");
		t1 = time_sort(almost_sorted_vector,3, spin_the_bottle_sort);
		add_timings_to_file("almost_sorted_vector",t1,"spin_the_bottle_sort_timings_as_vector.csv");
	}
	
		//-------------------------------------Test For Shell Sort --------------------------------------------
	
	
	
	std::vector<int> larger_size; 
    create_empty_timings_file("shell_sort_timings_gap1_un_vector.csv");
    create_empty_timings_file("shell_sort_timings_gap1_as_vector.csv");
    create_empty_timings_file("shell_sort_timings_gap2_un_vector.csv");
    create_empty_timings_file("shell_sort_timings_gap2_as_vector.csv");

	for(int i = 1000; i< 50000;i += 500)
	{
		larger_size.push_back(i);
	}    
	
	for(int i = 0; i< larger_size.size();i++)
	{
		std::vector<int> gap = gap_generator_first(larger_size.size());
		std::vector<int> uniformed_vector = uniform_vector_generator(larger_size[i]);
		std::vector<int> almost_sorted_vector =  almost_sorted_generator(larger_size[i]);
		t = shell_sort_time_sort(uniformed_vector,gap,3,shell_sort);
		add_timings_to_file("uniformed_vector",t,"shell_sort_timings_gap1_un_vector.csv");
		t1 = shell_sort_time_sort(almost_sorted_vector,gap,3,shell_sort);
		add_timings_to_file("almost_sorted_vector",t1,"shell_sort_timings_gap1_as_vector.csv");
	}
	
	for(int i = 0; i< larger_size.size();i++)
	{
		std::vector<int> gap = gap_generator_second(larger_size.size());
		std::vector<int> uniformed_vector = uniform_vector_generator(larger_size[i]);
		std::vector<int> almost_sorted_vector =  almost_sorted_generator(larger_size[i]);
		t = shell_sort_time_sort(uniformed_vector,gap,3,shell_sort);
		add_timings_to_file("uniformed_vector",t,"shell_sort_timings_gap2_un_vector.csv");
		t1 = shell_sort_time_sort(almost_sorted_vector,gap,3,shell_sort);
		add_timings_to_file("almost_sorted_vector",t1,"shell_sort_timings_gap2_as_vector.csv");
	}
	
	
	//-------------------------------------Test For Annealing Sort --------------------------------------------

    create_empty_timings_file("annealing_sort_timings_temp1_un_vector.csv");
    create_empty_timings_file("annealing_sort_timings_temp1_as_vector.csv");
    create_empty_timings_file("annealing_sort_timings_temp2_un_vector.csv");
    create_empty_timings_file("annealing_sort_timings_temp2_as_vector.csv");
	
	std::vector<int> Asizes;
	int success1;
	int success2;
	for(int i = 10; i< 2000;i += 100)
	{
		Asizes.push_back(i);
	}
	for(int i = 0; i< Asizes.size();i++)
	{
		std::vector<int> temps = temp_generator_first(Asizes[i]);
		std::vector<int> reps = repetition_generator_first(temps.size(),Asizes[i]);
		std::vector<int> uniformed_vector = uniform_vector_generator(Asizes[i]);
		std::vector<int> almost_sorted_vector =  almost_sorted_generator(Asizes[i]);
		t = annealing_sort_time_sort(uniformed_vector,temps,reps,3,annealing_sort);
		add_timings_to_file("uniformed_vector",t,"annealing_timings_temp1_un_vector.csv");

		if(std::is_sorted(uniformed_vector.begin(),uniformed_vector.end()) == 1)
		{
			success1 += 1;
		}
		t1 = annealing_sort_time_sort(almost_sorted_vector,temps,reps,3,annealing_sort);
		add_timings_to_file("almost_sorted_vector",t1,"annealing_timings_temp1_as_vector.csv");
	}
	std::cout<< "rate of success of temp1: "<< float(success1)/float(Asizes.size())<<std::endl;


	for(int i = 0; i< Asizes.size();i++)
	{
		std::vector<int> temps = temp_generator_second(Asizes[i]);
		std::vector<int> reps = repetition_generator_second(temps.size(),Asizes[i]);
		std::vector<int> uniformed_vector = uniform_vector_generator(Asizes[i]);
		std::vector<int> almost_sorted_vector =  almost_sorted_generator(Asizes[i]);
		t = annealing_sort_time_sort(uniformed_vector,temps,reps,3,annealing_sort);
		add_timings_to_file("uniformed_vector",t,"annealing_timings_temp2_un_vector.csv");
		if(std::is_sorted(uniformed_vector.begin(),uniformed_vector.end()) == 1)
		{
			success2 += 1;
		}
		t1 = annealing_sort_time_sort(almost_sorted_vector,temps,reps,3,annealing_sort);
		add_timings_to_file("almost_sorted_vector",t1,"annealing_timings_temp2_as_vector.csv");
	}
	std::cout<< "rate of success of temp2: "<< float(success2)/float(Asizes.size())<<std::endl;


	return 0;
}