#include <iostream>
#include <ctime>
#include <map>
#include <unordered_map>
#include <vector>
#include <utility>
#include <numeric>
int main()
{
	std::unordered_multimap<int, int> hash;
	std::vector<double> hash_times;
	std::vector<double> tree_times;
	for (int n = 10; n <= 10000000; n *= 10)
	{
		std::clock_t start = std::clock();

		for (int i = 0; i < n; ++i)
		{
			hash.insert(std::pair<int, int> (rand(), rand()));
		}

		std::clock_t end = std::clock() - start;
		double hash_time = ((double)end)/ ((double)CLOCKS_PER_SEC);
		hash_times.push_back(hash_time);
	}
	std::multimap<int, int> tree;
	for (int m = 10; m <= 10000000; m*=10)
	{
		std::clock_t tree_start = std::clock();
		for (int j = 0; j < m; ++j)
		{
			tree.insert(std::pair<int, int> (rand(), rand()));
		}
		std::clock_t tree_end = std::clock() - tree_start;
		double tree_time = ((double)tree_end)/((double)CLOCKS_PER_SEC);
		tree_times.push_back(tree_time);
	}
	int num = 10;
	std::cout << "unordered_multimap" << std::endl;
	for (int l = 0; l < hash_times.size(); ++l)
	{
		std::cout << num << " " << hash_times[l] << std::endl;
		num *= 10;
	}
	num = 10;
	std::cout << std::endl;
	std::cout << "multimap" << std::endl;
	for (int k = 0; k < tree_times.size(); ++k)
	{
		std::cout << num << " " << tree_times[k] << std::endl;
		num *= 10;
	}
}
