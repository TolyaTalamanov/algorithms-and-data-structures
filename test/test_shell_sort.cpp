/* Copyright 2018 TolyaTalamanov */
#include "sort_test.hpp"
#include "shell_sort.hpp"

TEST_F(SortTest, CorrectSorted) {
  ShellSort(v1.begin(), v1.end());

  ASSERT_TRUE(v1 == v2);
}
