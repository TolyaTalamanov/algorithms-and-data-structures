#include <gtest/gtest.h>
#include "binary_heap.hpp"

TEST(BinaryHeapTest, MakeHeap) {
  ASSERT_NO_THROW(BinaryHeap<int> heap);
}

TEST(BinaryHeapTest, CheckEmptyHeap) {
  BinaryHeap<int> heap;

  ASSERT_TRUE(heap.empty());
}

TEST(BinaryHeapTest, CheckSizeNotEmptyHeap) {
  BinaryHeap<int> heap;

  for (int i = 0; i < 100; ++i) {
    heap.add(i);
  }

  EXPECT_EQ(100, heap.getHeapSize());
}

TEST(BinaryHeapTest, TryGetMaxInEmptyHeap) {
  BinaryHeap<int> heap;

  ASSERT_ANY_THROW(heap.getMax());
}

TEST(BinaryHeapTest, CheckGetMax) {
  BinaryHeap<int> heap;

  for (int i = 0; i < 4; ++i) {
    heap.add(i);
  }

  EXPECT_EQ(3, heap.getMax());
}

TEST(BinaryHeapTest, BinaryHeapFromRange) {
  std::vector<int> v{1, 2, 4, 5, 16, 3, 10};

  ASSERT_NO_THROW(BinaryHeap<int> heap(v.begin(), v.end()));
}

TEST(BinaryHeapTest, CheckGetMaxWhenBinaryHeapFromRange) {
  std::vector<int> v{1, 2, 4, 5, 16, 3, 10};

  BinaryHeap<int> heap(v.begin(), v.end());

  EXPECT_EQ(16, heap.getMax());
}

TEST(BinaryHeapTest, TryDeleteMaxInEmptyHeap) {
  BinaryHeap<int> heap;

  ASSERT_NO_THROW(heap.deleteMax());
}

TEST(BinaryHeapTest, DeleteMax) {
  BinaryHeap<int> heap = {3, 5, 10, 2, 1};

  heap.deleteMax();

  EXPECT_EQ(5, heap.getMax());
}
