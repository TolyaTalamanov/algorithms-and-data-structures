/* Copyright 2018 TolyaTalamanov */

#include <vector>
#include <list>
#include <gtest/gtest.h>
#include "find_max_subarray.hpp"

using std::make_reverse_iterator;

TEST(FindMaxSubarray, FindMaxSubarrayInHalfArrayAndShiftMidIt) {
  std::vector<int> v{-1000000, 1000, 1, 2, -3, 4, 5, 10, -15, 0, 100};
  auto begin = v.begin();
  auto end   = v.end();
  auto mid   = begin;
  std::advance(mid, std::distance(begin, end) / 2);
  auto m_l = mid;
  auto m_r = mid;
  auto r_it_mid = make_reverse_iterator(m_l);
  auto r_it_begin = make_reverse_iterator(begin);

  auto max_l = MaxSumInHalfArrayAndShiftMidIter(&r_it_mid, r_it_begin);
  auto max_r = MaxSumInHalfArrayAndShiftMidIter(&m_r, end);

  EXPECT_EQ(1000, max_l);
  EXPECT_EQ(1000, *r_it_mid);
  EXPECT_EQ(104, max_r);
  EXPECT_EQ(100, *m_r);
}

TEST(FindMaxSubarray, FindInPositiveArray) {
  std::vector<int> v{1, 2, 3, 4, 5, 10, 15};
  auto t = FindMaxSubarray(v.begin(), v.end());

  EXPECT_EQ(1, *std::get<0>(t));
  EXPECT_EQ(15, *std::get<1>(t));
  EXPECT_EQ(40, std::get<2>(t));
}

TEST(FindMaxSubarray, FindInPositiveAndNegativeArray) {
  std::vector<int> v{-2, -3, 4, -1, -2, 1, 5, -3, -100};
  auto t = FindMaxSubarray(v.begin(), v.end());

  EXPECT_EQ(4, *std::get<0>(t));
  EXPECT_EQ(5, *std::get<1>(t));
  EXPECT_EQ(7, std::get<2>(t));
}

TEST(FindMaxCrossingSubarray, CheckCorrectPositive) {
  std::vector<int> v{1, 2, 3, 5, 10, 15};
  auto t = FindMaxCrossingSubarray(v.begin(), v.end());

  EXPECT_EQ(1, *std::get<0>(t));
  EXPECT_EQ(15, *std::get<1>(t));
  EXPECT_EQ(36, std::get<2>(t));
}

TEST(FindMaxCrossingSubarray, CheckCorrectPositiveAndNegative) {
  std::vector<int> v{2, 3 -5, -19, 10, 13, 0, -4, 5};
  auto t = FindMaxCrossingSubarray(v.begin(), v.end());

  EXPECT_EQ(10, *std::get<0>(t));
  EXPECT_EQ(5, *std::get<1>(t));
  EXPECT_EQ(24, std::get<2>(t));
}

TEST(FindMaxCrossingSubarray, CheckCorrectPositiveAndNegativeDouble) {
  std::vector<double> v{2, 3.8 -5.6, -19.3, 10.8, 13.6, 0, -4, 5};
  auto t = FindMaxCrossingSubarray(v.begin(), v.end());

  EXPECT_EQ(10.8, *std::get<0>(t));
  EXPECT_EQ(5, *std::get<1>(t));
  EXPECT_EQ(25.4, std::get<2>(t));
}

TEST(FindMaxCrossingSubarray, CheckCorrectPositiveAndNegativeDoubleList) {
  std::list<double> l{2, 3.8 -5.6, -19.3, 10.8, 13.6, 0, -4, 5};
  auto t = FindMaxCrossingSubarray(l.begin(), l.end());

  EXPECT_EQ(10.8, *std::get<0>(t));
  EXPECT_EQ(5, *std::get<1>(t));
  EXPECT_EQ(25.4, std::get<2>(t));
}
