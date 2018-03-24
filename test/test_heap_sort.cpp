#include <iostream>
#include <vector>
#include <algorithm>
#include <gtest/gtest.h>
#include "heap_sort.hpp"

TEST(HeapSortTest, CorrectSorted) { 
	std::vector<int> v{4, 5, 1, 6, 112, 6, 7, 2};

	HeapSort(v.rbegin(), v.rend());

	ASSERT_TRUE(std::is_sorted(v.begin(), v.end()));
}
