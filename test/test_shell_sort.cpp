#include <vector>
#include <algorithm>
#include <random>
#include <gtest/gtest.h>
#include "shell_sort.hpp"

TEST(ShellSortTest, CorrectSorted) {
  const int size_array = 100000;
  std::vector<int> v1(size_array);
  std::mt19937 gen{};
  std::uniform_int_distribution<int> distr(-1000000, 1000000);

  std::generate(v1.begin(), v1.end(), [&gen, &distr](){
        return distr(gen);
      });
  std::vector<int> v2(v1);
  std::sort(v2.begin(), v2.end());
  ShellSort(v1.begin(), v1.end());

  ASSERT_TRUE(v1 == v2);
}
