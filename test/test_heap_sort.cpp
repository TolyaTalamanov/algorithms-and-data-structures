/* Copyright 2018 TolyaTalalmanov*/
#include "sort_test.hpp"
#include "heap_sort.hpp"

TEST_F(SortTest, CorrectSorted) {
  HeapSort(v1.rbegin(), v1.rend());

  ASSERT_TRUE(v1 == v2);
}
