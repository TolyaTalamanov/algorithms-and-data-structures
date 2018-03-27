/* Copyright 2018 TolyaTalamanov */

#include <vector>
#include <gtest/gtest.h>
#include "find_max_subarray.hpp"

TEST(FindMaxSubarray, FindInPositiveArray) {
	std::vector<int> v{1, 2, 3, 4, 5, 10, 15};
	auto t = FindMaxSubarray(v.begin(), v.end());

	EXPECT_EQ(40, std::get<2>(t));
}

TEST(FindMaxSubarray, FindInPositiveAndNegativeArray) {
	std::vector<int> v{-2, -3, 4, -1, -2, 1, 5, -3, -100};
	auto t = FindMaxSubarray(v.begin(), v.end());

	EXPECT_EQ(7, std::get<2>(t));
}

TEST(FindMaxCrossingSubarray, CheckCorrectPositive) {
	std::vector<int> v{1, 2, 3, 5, 10, 15};
	auto t = FindMaxCrossingSubarray(v.begin(), v.end());

	EXPECT_EQ(36, std::get<2>(t));
}

TEST(FindMaxCrossingSubarray, CheckCorrectPositiveAndNegative) {
	std::vector<int> v{2, 3 -5, -19, 10, 13, 0, -4, 5};
	auto t = FindMaxCrossingSubarray(v.begin(), v.end());

	EXPECT_EQ(24, std::get<2>(t));
}

