/* Copyright 2018 TolyaTalamanov */

#ifndef ALGORITHMS_FIND_MAX_SUBARRAY_HPP_
#define ALGORITHMS_FIND_MAX_SUBARRAY_HPP_

#include <iterator>
#include <tuple>
#include <algorithm>

using std::tuple;
using std::iterator_traits;

template<typename Iterator>
auto MaxSumInHalfArrayAndShiftMidIter(Iterator* mid, Iterator end) {
  typedef typename iterator_traits<Iterator>::value_type obj_type;

  auto max_it  = *mid;
  auto max_sum = *max_it;
  obj_type cur_sum{};

  for (auto i = *mid; i != end; ++i) {
    cur_sum += *i;
    if (cur_sum > max_sum) {
      max_sum = cur_sum;
      max_it = i;
    }
  }

  *mid = max_it;

  return max_sum;
}
template<typename Iterator>
auto FindMaxCrossingSubarray(Iterator begin, Iterator end) {
  auto mid = begin;
  std::advance(mid, std::distance(begin, end) / 2);

  auto r_max_left = std::reverse_iterator(mid);
  auto end_left = std::reverse_iterator(begin);
  auto max_sum_left = MaxSumInHalfArrayAndShiftMidIter(&r_max_left, end_left);
  std::advance(r_max_left, 1);
  auto max_left = r_max_left.base();

  auto max_right = mid;
  auto max_sum_right = MaxSumInHalfArrayAndShiftMidIter(&max_right, end);

  auto max_sum = max_sum_left + max_sum_right;

  return std::make_tuple(max_left, max_right, max_sum);
}

template<typename Iterator>
tuple<Iterator, Iterator, typename iterator_traits<Iterator>::value_type>
FindMaxSubarray(Iterator begin, Iterator end) {
  typedef typename iterator_traits<Iterator>::value_type obj_type;
  typedef typename std::tuple<Iterator, Iterator, obj_type> tuple_t;

  if (std::distance(begin, end) == 1) {
    return std::make_tuple(begin, end, *begin);
  }

  auto mid = begin;
  std::advance(mid, std::distance(begin, end) / 2);

  tuple_t left_tuple  = FindMaxSubarray<Iterator>(begin, mid);
  tuple_t right_tuple = FindMaxSubarray<Iterator>(mid, end);
  tuple_t midle_tuple = FindMaxCrossingSubarray<Iterator>(begin, end);

  auto tuple_comp = [](const auto& t1, const auto& t2) {
                      return std::get<2>(t1) < std::get<2>(t2);
                    };

  auto max_tuple = std::max(left_tuple, right_tuple, tuple_comp);

  return std::max(max_tuple, midle_tuple, tuple_comp);
}

#endif  // ALGORITHMS_FIND_MAX_SUBARRAY_HPP_
