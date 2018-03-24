/* Copyright 2018 TolyaTalamanov */
#ifndef DATA_STRUCTURES_BINARY_HEAP_HPP_
#define DATA_STRUCTURES_BINARY_HEAP_HPP_

#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>

using std::iter_swap;

template<class T>
class BinaryHeap {
 public:
  BinaryHeap() = default;
  explicit BinaryHeap(int size_heap) { nodes.reserve(size_heap); }
  BinaryHeap(auto begin, auto end);
  BinaryHeap(std::initializer_list<T> l) : BinaryHeap(l.begin(), l.end()) {  }

  void add(T value);
  size_t getHeapSize() { return nodes.size(); }
  bool empty() { return nodes.empty(); }
  T getMax();
  void deleteElem(int elem_index);
  void deleteMax();
  T getElement(int i) { return nodes[i]; }

 private:
  void shiftUp(int node_index);
  void shiftDown(int node_index);

  int getLeftChild(int node_index);
  int getRightChild(int node_index);
  int getParrent(int node_index) { return (node_index - 1) / 2; }
  int getMaxChild(int node_index);

 private:
  std::vector<T> nodes;
};

//  O(log n)
template<class T>
void BinaryHeap<T>::add(T value) {
  nodes.push_back(value);
  shiftUp(nodes.size() - 1);
}

template<class T>
T BinaryHeap<T>::getMax() {
  if (empty()) {
    throw std::out_of_range("heap is empty");
  }
  return nodes.front();
}

//  O(log n)
template<class T>
void BinaryHeap<T>::shiftUp(int node_index) {
  int parrent = getParrent(node_index);

  while (node_index > 0 && nodes[node_index] > nodes[parrent]) {
    iter_swap(nodes.begin() + node_index, nodes.begin() + parrent);
    node_index = parrent;
    parrent = getParrent(parrent);
  }
}

//  O(log n)
template<class T>
void BinaryHeap<T>::shiftDown(int node_index) {
  int max_child_index = getMaxChild(node_index);

  while (max_child_index != -1 && nodes[node_index] < nodes[max_child_index]) {
    std::iter_swap(nodes.begin() + max_child_index, nodes.begin() + node_index);
    node_index = max_child_index;
    max_child_index = getMaxChild(max_child_index);
  }
}

template<class T>
int BinaryHeap<T>::getLeftChild(int node_index) {
  int j = 2 * node_index + 1;

  if (j >= getHeapSize()) {
    j = -1;
  }

  return j;
}

template<class T>
int BinaryHeap<T>::getRightChild(int node_index) {
  int j = getLeftChild(node_index);

  if (j != -1) {
    j = std::min<int>(j + 1, getHeapSize() - 1);
  }
  return j;
}

template<class T>
int BinaryHeap<T>::getMaxChild(int node_index) {
  int left_child_index  = getLeftChild(node_index);
  int right_child_index = getRightChild(node_index);
  int max_child_index;

  if (left_child_index == -1) {
    max_child_index = -1;
  } else if (right_child_index != -1) {
    max_child_index = nodes[left_child_index] > nodes[right_child_index] ?
                      left_child_index : right_child_index;
  } else {
    max_child_index = left_child_index;
  }

  return max_child_index;
}

//  O(n)
template<class T>
BinaryHeap<T>::BinaryHeap(auto begin, auto end) {
  std::copy(begin, end, std::back_inserter(nodes));

  for (int i = (nodes.size() - 2) / 2; i >= 0 ; --i) {
    shiftDown(i);
  }
}

//  (1)
template<class T>
void BinaryHeap<T>::deleteElem(int elem_index) {
  if (!empty()) {
    std::iter_swap(nodes.begin() + elem_index, nodes.end() - 1);
    nodes.erase(nodes.end() - 1);
    shiftDown(elem_index);
  }
}

template<class T>
void BinaryHeap<T>::deleteMax() {
  deleteElem(0);
}

#endif  // DATA_STRUCTURES_BINARY_HEAP_HPP_
