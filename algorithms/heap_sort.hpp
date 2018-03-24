/* Copyright 2018 TolyaTalamanov */
#ifndef ALGHORITHMS_HEAP_SORT_HPP_
#define ALGHORITHMS_HEAP_SORT_HPP_

#include <iterator>
#include "binary_heap.hpp"

template<typename Iterator>
void HeapSort(Iterator begin, Iterator end) {
  typedef typename std::iterator_traits<Iterator>::value_type iterator_type;
	BinaryHeap<iterator_type> heap(begin, end);

	std::for_each(begin, end, [&heap](auto& elem){
				elem = heap.getMax();
				heap.deleteMax();
			});
}

#endif  // ALGHORITHMS_HEAP_SORT_HPP_

