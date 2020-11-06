#include <random>
std::uniform_int_distribution<int> random_int_in_range(int lb, int ub);
std::vector<int> gap_generator_first(int size);
std::vector<int> gap_generator_second(int size);
std::mt19937 mt_with_current_seed();
std::vector<int> uniform_vector_generator(int size);
std::vector<int> almost_sorted_generator(int size);
std::vector<int> temp_generator_first(int size);
std::vector<int> temp_generator_second(int size);
std::vector<int> repetition_generator_first(int size,int vector_size);
std::vector<int> repetition_generator_second(int size,int vector_size);