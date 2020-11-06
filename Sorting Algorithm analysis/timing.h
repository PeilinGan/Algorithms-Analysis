#include <iostream>
#include <fstream>
#include <algorithm>
#include <ctime>

struct timing 
{
    int n;
    double seconds;
};
timing time_sort(std::vector<int> & nums, int reps, std::function<void(std::vector<int> &)> func);
timing shell_sort_time_sort(std::vector<int> & nums, const std::vector<int>& gaps, int reps, std::function<void(std::vector<int> &, const std::vector<int>&)> func);
timing annealing_sort_time_sort(std::vector<int> & nums, const std::vector<int>& temp,const std::vector<int>& rep, int reps, std::function<void(std::vector<int> &, const std::vector<int>&,const std::vector<int>&)> func);
void create_empty_timings_file(std::string filename);
void add_timings_to_file(std::string funcname, timing t, std::string filename);

