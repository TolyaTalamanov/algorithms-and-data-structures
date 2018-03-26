/* Copyright 2018 TolyaTalamanov */
#ifndef TEST_SORT_TEST_HPP_
#define TEST_SORT_TEST_HPP_

#include <vector>
#include <algorithm>
#include <random>
#include <gtest/gtest.h>

class SortTest : public ::testing::Test {
 protected:
  std::vector<int> v1;
  std::vector<int> v2;

  virtual void SetUp() {
    v1.resize(10000);
    std::mt19937 gen{std::random_device()()};
    std::uniform_int_distribution<int> distr(-1000000, 1000000);
    std::generate(v1.begin(), v1.end(), [&gen, &distr](){
          return distr(gen);
        });
    v2 = v1;
    std::sort(v2.begin(), v2.end());
  }
};

#endif  // TEST_SORT_TEST_HPP_
