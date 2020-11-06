#include "timing.h"
using namespace std;
#include<vector>

timing time_sort(std::vector<int> & nums, int reps, std::function<void(std::vector<int> &)> func)
{
    double total_time = 0.0;
    for(int i = 0; i < reps; i++)
    {
        clock_t c_start = clock();
        func(nums);
        clock_t c_end = clock();
        total_time += (float)(c_end - c_start) / CLOCKS_PER_SEC;
    }
    timing t;
    t.n = nums.size();
    t.seconds = (float)total_time/reps;
    return t;
}

timing shell_sort_time_sort(std::vector<int> & nums, const std::vector<int>& gaps, int reps, std::function<void(std::vector<int> &, const std::vector<int>&)> func)
{
    double total_time = 0.0;
    for(int i = 0; i < reps; i++)
    {
        clock_t c_start = clock();
        func(nums,gaps);
        clock_t c_end = clock();
        total_time += (float)(c_end - c_start) / CLOCKS_PER_SEC;
    }
    timing t;
    t.n = nums.size();
    t.seconds = (float)total_time/reps;
    return t;    
}

timing annealing_sort_time_sort(std::vector<int> & nums, const std::vector<int>& temp,const std::vector<int>& rep, int reps, std::function<void(std::vector<int> &, const std::vector<int>&,const std::vector<int>&)> func)
{
    double total_time = 0.0;
    for(int i = 0; i < reps; i++)
    {
        clock_t c_start = clock();
        func(nums,temp,rep);
        clock_t c_end = clock();
        total_time += (float)(c_end - c_start) / CLOCKS_PER_SEC;
    }
    timing t;
    t.n = nums.size();
    t.seconds = (float)total_time/reps;
    return t;     
}

void create_empty_timings_file(string filename)
{
    ofstream f;
    f.open(filename, ios::trunc);
    f << "funcname,n,seconds\n";
    f.close();
}

void add_timings_to_file(string funcname, timing t, string filename)
{
    ofstream f;
    f.open(filename, ios::app);
    f << funcname << "," << t.n << "," << t.seconds << "\n";
    f.close();
}


