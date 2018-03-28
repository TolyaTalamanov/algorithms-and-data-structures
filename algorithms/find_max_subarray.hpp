/* Copyright 2018 TolyaTalamanov */

#ifndef ALGORITHMS_FIND_MAX_SUBARRAY_HPP_
#define ALGORITHMS_FIND_MAX_SUBARRAY_HPP_

#include <iterator>
#include <tuple>

template<typename Iterator>
auto FindMaxSubarrayInHalfArrayAndShiftMidIt(Iterator& mid, Iterator end) {
	auto max_it  = mid;
	auto max_sum = *max_it;
 	auto cur_sum = 0;

	for (auto i = mid; i < end; ++i) {
			cur_sum += *i;
		if (cur_sum > max_sum) {
			max_sum = cur_sum;
			max_it = i;
		}
	}	
	mid = max_it;
	return max_sum;
}
template<typename Iterator>
auto FindMaxCrossingSubarray(Iterator begin, Iterator end) {
	auto mid = begin;
	std::advance(mid, std::distance(begin, end) / 2);

	auto max_it_left  = mid - 1;
	auto max_sum_left = *max_it_left;
	auto cur_sum      = 0;

	for (auto i = mid - 1; i >= begin; --i) {
		cur_sum += *i;
		if (cur_sum > max_sum_left) {
			max_sum_left = cur_sum;
			max_it_left  = i;
		}
	}

	auto max_it_right  = mid;
	auto max_sum_right = *max_it_right;
	cur_sum            = 0; 

	for (auto i = mid; i < end; ++i) {
		cur_sum += *i;
		if (cur_sum > max_sum_right) {
			max_sum_right = cur_sum;
			max_it_right  = i;
		}
	}

	auto max_sum = max_sum_left + max_sum_right;
	auto t = std::make_tuple(max_it_left, max_it_right, max_sum);
	return t; 
}

template<typename Iterator>
std::tuple<Iterator, Iterator, typename std::iterator_traits<Iterator>::value_type>
FindMaxSubarray(Iterator begin, Iterator end) {
	typedef typename std::iterator_traits<Iterator>::value_type obj_type;
	typedef typename std::tuple<Iterator, Iterator, obj_type> tuple;

	if (std::distance(begin, end) == 1) {
		auto t = std::make_tuple(begin, end, *begin);
		return t; 
	}

	auto mid = begin;
	std::advance(mid, std::distance(begin, end) / 2);

	tuple left_tuple  = FindMaxSubarray<Iterator>(begin, mid);
	tuple right_tuple = FindMaxSubarray<Iterator>(mid, end);
	tuple midle_tuple = FindMaxCrossingSubarray<Iterator>(begin, end);

	if (std::get<2>(left_tuple) >= std::get<2>(right_tuple) &&
			std::get<2>(left_tuple) >= std::get<2>(midle_tuple)) {
		return left_tuple;
	}

	if (std::get<2>(right_tuple) >= std::get<2>(left_tuple) &&
			std::get<2>(right_tuple) >= std::get<2>(midle_tuple)) {
		return right_tuple;
	}

	return midle_tuple;
}

#endif  // ALGORITHMS_FIND_MAX_SUBARRAY_HPP_
