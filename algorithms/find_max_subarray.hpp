/* Copyright 2018 TolyaTalamanov */
#ifndef ALGORITHMS_FIND_MAX_SUBARRAY_HPP_
#define ALGORITHMS_FIND_MAX_SUBARRAY_HPP_

#include <iostream>
#include <iterator>

template<typename Iterator>
decltype(auto) FindMaxSubarray(Iterator begin, Iterator end) {

}

template<typename Iterator>
decltype(auto) FindMaxCrossingSubarray(Iterator begin, Iterator end) {
	auto mid = begin;
	std::advance(mid, std::distance(begin, end) / 2 - 1);

	auto max_it_left  = mid;
	auto max_sum_left = *max_it_left;
	auto cur_sum      = 0;

	for (auto i = mid; i >= begin; --i) {
		cur_sum += *i;
		if (cur_sum > max_sum_left) {
			max_sum_left = cur_sum;
			max_it_left  = i;
		}
	}

	auto max_it_right  = mid + 1;
	auto max_sum_right = *max_it_right;
	cur_sum            = 0; 

	for (auto i = mid + 1; i < end; ++i) {
		cur_sum += *i;
		if (cur_sum > max_sum_right) {
			max_sum_right = cur_sum;
			max_it_right  = i;
		}
	}

	auto max_sum = max_sum_left + max_sum_right;
	typedef decltype(max_sum) sum_type;

	return std::make_tuple(max_it_left, max_it_right, max_sum);
}

#endif  // ALGORITHMS_FIND_MAX_SUBARRAY_HPP_
