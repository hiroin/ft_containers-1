/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_vector.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnakano <dnakano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 20:50:10 by dnakano           #+#    #+#             */
/*   Updated: 2021/01/31 15:28:58 by dnakano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>
#include <iostream>
#include <vector>

#include "test.hpp"
#include "vector.hpp"

void test_vector(int& test_no) {
  bool flg = 0;

  std::cout << "=== TEST VECTOR ===" << std::endl;

  putTestInfo(test_no, "Vector: default construction");
  try {
    ft::vector<int> vec;
  } catch (std::exception& e) {
    throw std::runtime_error("failed");
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector: fill construction with 42, 42");
  try {
    ft::vector<int> vec(42, 42);
  } catch (std::exception& e) {
    throw std::runtime_error("failed");
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector: copy construction with default");
  try {
    std::vector<int> vec_std1;
    std::vector<int> vec_std2(vec_std1);
    ft::vector<int> vec_ft1;
    ft::vector<int> vec_ft2(vec_ft1);
    if (vec_ft1 != vec_ft2 || vec_ft2.capacity() != vec_std2.capacity() ||
        vec_ft2.size() != vec_std2.size()) {
      throw std::runtime_error("failed");
    }
  } catch (std::exception& e) {
    throw std::runtime_error("failed");
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector: copy construction with vec(42,42)");
  try {
    std::vector<int> vec_std1(42, 42);
    std::vector<int> vec_std2(vec_std1);
    ft::vector<int> vec_ft1(42, 42);
    ft::vector<int> vec_ft2(vec_ft1);
    for (size_t idx = 0; idx < vec_std2.size(); idx++) {
      if (vec_std2[idx] != vec_ft2[idx]) {
        throw std::runtime_error("failed");
      }
    }
    if (vec_ft1 != vec_ft2 || vec_ft2.capacity() != vec_std2.capacity() ||
        vec_ft2.size() != vec_std2.size()) {
      throw std::runtime_error("failed");
    }
  } catch (std::exception& e) {
    throw std::runtime_error("failed");
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no,
              "vector: copy construction with vec(42,42) with cap(84)");
  try {
    std::vector<int> vec_std1(42, 42);
    vec_std1.reserve(84);
    std::vector<int> vec_std2(vec_std1);
    ft::vector<int> vec_ft1(42, 42);
    vec_ft1.reserve(84);
    ft::vector<int> vec_ft2(vec_ft1);
    for (size_t idx = 0; idx < vec_std2.size(); idx++) {
      if (vec_std2[idx] != vec_ft2[idx]) {
        throw std::runtime_error("failed");
      }
    }
    if (vec_ft1 != vec_ft2 || vec_ft2.capacity() != vec_std2.capacity() ||
        vec_ft2.size() != vec_std2.size()) {
      throw std::runtime_error("failed");
    }
  } catch (std::exception& e) {
    throw std::runtime_error("failed");
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector: check vec1 == vec2 (default construction");
  try {
    ft::vector<int> vec1;
    ft::vector<int> vec2;
    if (!(vec1 == vec2)) {
      throw std::runtime_error("should be true");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector: check vec1(42,42) == vec2(42,42)");
  try {
    ft::vector<int> vec1(42, 42);
    ft::vector<int> vec2(42, 42);
    if (!(vec1 == vec2)) {
      throw std::runtime_error("should be true");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector: check vec1(42,42) == vec2(21,42)");
  try {
    ft::vector<int> vec1(42, 42);
    ft::vector<int> vec2(21, 42);
    if (vec1 == vec2) {
      throw std::runtime_error("should not be true");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector: check vec1(42,42) == vec2(42,21)");
  try {
    ft::vector<int> vec1(42, 42);
    ft::vector<int> vec2(42, 21);
    if (vec1 == vec2) {
      throw std::runtime_error("should not be true");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector: vec1(42,42) == vec2(42,42) but capacity diffs");
  try {
    ft::vector<int> vec1(42, 42);
    ft::vector<int> vec2(42, 42);
    vec2.reserve(84);
    // std::cout << "\nvec1.capacity() = " << vec1.capacity() << std::endl;
    // std::cout << "vec2.capacity() = " << vec2.capacity() << std::endl;
    // std::cout << "vec1 == vec2: " << (vec1 == vec2) << std::endl;
    if (vec1 != vec2) {
      throw std::runtime_error("should be true");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  // case different allocator

  putTestInfo(test_no, "vector: check vec1 = vec2(42,42)");
  try {
    ft::vector<int> vec1;
    ft::vector<int> vec2(42, 42);
    vec1 = vec2;
    if (vec1 != vec2) {
      throw std::runtime_error("should not be equal");
    }
  } catch (std::exception& e) {
    throw std::runtime_error("failed");
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector: check vec1 = vec2(42,42) with 84 capacity");
  try {
    ft::vector<int> vec1;
    ft::vector<int> vec2(42, 42);
    vec2.reserve(84);
    vec1 = vec2;
    // std::cout << "\nvec1.capacity() = " << vec1.capacity() << std::endl;
    // std::cout << "vec2.capacity() = " << vec2.capacity() << std::endl;
    if (vec1 != vec2) {
      throw std::runtime_error("should not be equal");
    }
  } catch (std::exception& e) {
    throw std::runtime_error("failed");
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector: check vec1(42, 42) = vec2");
  try {
    ft::vector<int> vec1(42, 42);
    ft::vector<int> vec2;
    vec1 = vec2;
    if (!(vec1 == vec2)) {
      throw std::runtime_error("should be equal");
    }
  } catch (std::exception& e) {
    throw std::runtime_error("failed");
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector: size() of empty vector construct with default");
  try {
    std::vector<int> std_vec;
    ft::vector<int> ft_vec;
    if (std_vec.size() != ft_vec.size()) {
      throw std::exception();
    }
  } catch (std::exception& e) {
    throw std::runtime_error("failed");
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector: size() of fill construction with 42, 42");
  try {
    std::vector<int> std_vec(42, 42);
    ft::vector<int> ft_vec(42, 42);
    if (std_vec.size() != ft_vec.size()) {
      throw std::exception();
    }
  } catch (std::exception& e) {
    throw std::runtime_error("failed");
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no,
              "vector: max_size() of empty vector construct with default");
  try {
    std::vector<int> std_vec;
    ft::vector<int> ft_vec;
    if (std_vec.max_size() != ft_vec.max_size()) {
      throw std::exception();
    }
  } catch (std::exception& e) {
    throw std::runtime_error("failed");
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector: max_size() of fill construction with 42, 42");
  try {
    std::vector<int> std_vec(42, 42);
    ft::vector<int> ft_vec(42, 42);
    if (std_vec.max_size() != ft_vec.max_size()) {
      throw std::exception();
    }
  } catch (std::exception& e) {
    throw std::runtime_error("failed");
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no,
              "vector: capacity() of empty vector construct with default");
  try {
    std::vector<int> std_vec;
    ft::vector<int> ft_vec;
    if (std_vec.capacity() != ft_vec.capacity()) {
      throw std::runtime_error("failed");
    }
  } catch (std::exception& e) {
    throw std::runtime_error("failed");
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector: capacity() of fill construction with 42, 42");
  try {
    std::vector<int> std_vec(42, 42);
    ft::vector<int> ft_vec(42, 42);
    if (std_vec.capacity() != ft_vec.capacity()) {
      std::cout << std_vec.capacity() << std::endl;
      throw std::exception();
    }
  } catch (std::exception& e) {
    throw std::runtime_error("failed");
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no,
              "vector: empty() of empty vector construct with default");
  try {
    std::vector<int> std_vec;
    ft::vector<int> ft_vec;
    if (std_vec.empty() != ft_vec.empty()) {
      throw std::runtime_error("failed");
    }
  } catch (std::exception& e) {
    throw std::runtime_error("failed");
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector: empty() of fill construction with 42, 42");
  try {
    std::vector<int> std_vec;
    ft::vector<int> ft_vec;
    if (std_vec.empty() != ft_vec.empty()) {
      throw std::runtime_error("failed");
    }
  } catch (std::exception& e) {
    throw std::runtime_error("failed");
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "Vector: vec[0] (int) of fill construction with 42, 42");
  flg = 0;
  try {
    std::vector<int> std_vec(42, 42);
    ft::vector<int> ft_vec(42, 42);
    int std_res = std_vec[0];
    int ft_res = ft_vec[0];
    if (std_res != ft_res) {
      throw std::runtime_error("failed");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no,
              "Vector: vec[21] (int) of fill construction with 42, 42");
  flg = 0;
  try {
    std::vector<int> std_vec(42, 42);
    ft::vector<int> ft_vec(42, 42);
    int std_res = std_vec[21];
    int ft_res = ft_vec[21];
    if (std_res != ft_res) {
      throw std::runtime_error("failed");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no,
              "Vector: vec[40] (int) of fill construction with 42, 42");
  flg = 0;
  try {
    std::vector<int> std_vec(42, 42);
    ft::vector<int> ft_vec(42, 42);
    int std_res = std_vec[40];
    int ft_res = ft_vec[40];
    if (std_res != ft_res) {
      throw std::runtime_error("failed");
    }
  } catch (std::out_of_range& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no,
              "Vector: assign vec[i] = i with constructed with 42, 42");
  flg = 0;
  try {
    std::vector<int> std_vec(42, 42);
    ft::vector<int> ft_vec(42, 42);
    for (int i = 0; i < 42; i++) {
      std_vec[i] = i;
      ft_vec[i] = i;
      if (std_vec[i] != ft_vec[i]) {
        throw std::runtime_error("failed");
      }
    }
  } catch (std::out_of_range& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no,
              "Vector: vec[0] (const int) of fill construction with 42, 42");
  flg = 0;
  try {
    std::vector<int> std_vec(42, 42);
    ft::vector<int> ft_vec(42, 42);
    const int std_res = std_vec[0];
    const int ft_res = ft_vec[0];
    if (std_res != ft_res) {
      throw std::runtime_error("failed");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no,
              "Vector: vec[21] (const int) of fill construction with 42, 42");
  flg = 0;
  try {
    std::vector<int> std_vec(42, 42);
    ft::vector<int> ft_vec(42, 42);
    const int std_res = std_vec[21];
    const int ft_res = ft_vec[21];
    if (std_res != ft_res) {
      throw std::runtime_error("failed");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no,
              "Vector: vec[40] (const int) of fill construction with 42, 42");
  flg = 0;
  try {
    std::vector<int> std_vec(42, 42);
    ft::vector<int> ft_vec(42, 42);
    const int std_res = std_vec[40];
    const int ft_res = ft_vec[40];
    if (std_res != ft_res) {
      throw std::runtime_error("failed");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "Vector: at(0) of default constructed vector");
  flg = 0;
  try {
    ft::vector<int> vec;
    std::cout << vec.at(0) << std::endl;
  } catch (std::out_of_range& e) {
    if (std::string(e.what()) == "vector") {
      flg = true;
    }
  }
  if (!flg) {
    throw std::runtime_error("failed");
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "Vector: at(0) of fill construction with 42, 42");
  flg = 0;
  try {
    std::vector<int> std_vec(42, 42);
    ft::vector<int> ft_vec(42, 42);
    if (std_vec.at(0) != ft_vec.at(0)) {
      throw std::runtime_error("failed");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "Vector: at(21) of fill construction with 42, 42");
  flg = 0;
  try {
    std::vector<int> std_vec(42, 42);
    ft::vector<int> ft_vec(42, 42);
    if (std_vec.at(21) != ft_vec.at(21)) {
      throw std::runtime_error("failed");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "Vector: at(41) of fill construction with 42, 42");
  flg = 0;
  try {
    std::vector<int> std_vec(42, 42);
    ft::vector<int> ft_vec(42, 42);
    if (std_vec.at(41) != ft_vec.at(41)) {
      throw std::runtime_error("failed");
    }
  } catch (std::out_of_range& e) {
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "Vector: reserve(42) for default construction");
  flg = 0;
  try {
    std::vector<int> std_vec;
    ft::vector<int> ft_vec;
    std_vec.reserve(42);
    ft_vec.reserve(42);
    std_vec[21] = 21;
    ft_vec[21] = 21;
    std_vec[41] = 41;
    ft_vec[41] = 41;
    if (std_vec.capacity() != ft_vec.capacity() ||
        std_vec.size() != ft_vec.size() ||
        std_vec.max_size() != ft_vec.max_size() || std_vec[41] != ft_vec[41] ||
        std_vec[21] != ft_vec[21]) {
      std::cout << "21: " << std_vec[21] << ", " << ft_vec[21] << std::endl;
      std::cout << "24: " << std_vec[24] << ", " << ft_vec[24] << std::endl;
      std::cout << "41: " << std_vec[41] << ", " << ft_vec[41] << std::endl;
      throw std::runtime_error("failed");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "Vector: reserve(42) for construction with 42, 42");
  flg = 0;
  try {
    std::vector<int> std_vec(42, 42);
    ft::vector<int> ft_vec(42, 42);
    std_vec.reserve(42);
    ft_vec.reserve(42);
    std_vec[21] = 21;
    ft_vec[21] = 21;
    std_vec[41] = 41;
    ft_vec[41] = 41;
    if (std_vec.capacity() != ft_vec.capacity() ||
        std_vec.size() != ft_vec.size() ||
        std_vec.max_size() != ft_vec.max_size() || std_vec[41] != ft_vec[41] ||
        std_vec[21] != ft_vec[21]) {
      throw std::runtime_error("failed");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "Vector: reserve(84) for construction with 42, 42");
  flg = 0;
  try {
    std::vector<int> std_vec(42, 42);
    ft::vector<int> ft_vec(42, 42);
    std_vec.reserve(84);
    ft_vec.reserve(84);
    std_vec[21] = 21;
    ft_vec[21] = 21;
    std_vec[41] = 41;
    ft_vec[41] = 41;
    std_vec[83] = 83;
    ft_vec[83] = 83;
    if (std_vec.capacity() != ft_vec.capacity() ||
        std_vec.size() != ft_vec.size() ||
        std_vec.max_size() != ft_vec.max_size() || std_vec[41] != ft_vec[41] ||
        std_vec[21] != ft_vec[21] || std_vec[83] != ft_vec[83]) {
      // std::cout << "24: " << std_vec[24] << ", " << ft_vec[24] << std::endl;
      // std::cout << "41: " << std_vec[41] << ", " << ft_vec[41] << std::endl;
      // std::cout << "80: " << std_vec[83] << ", " << ft_vec[83] << std::endl;
      throw std::runtime_error("failed");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "Vector: reserve(INT_MAX) for default construction");
  flg = 0;
  try {
    std::vector<int> std_vec;
    ft::vector<int> ft_vec;
    std_vec.reserve(INT32_MAX);
    ft_vec.reserve(INT32_MAX);
    std_vec[21] = 21;
    ft_vec[21] = 21;
    std_vec[41] = 41;
    ft_vec[41] = 41;
    if (std_vec.capacity() != ft_vec.capacity() ||
        std_vec.size() != ft_vec.size() ||
        std_vec.max_size() != ft_vec.max_size() || std_vec[41] != ft_vec[41] ||
        std_vec[21] != ft_vec[21]) {
      throw std::runtime_error("failed");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no,
              "Vector: reserve(max_size() + 1) for default construction");
  flg = 0;
  try {
    ft::vector<int> ft_vec;
    ft_vec.reserve(42);
    try {
      ft_vec.reserve(ft_vec.max_size() + 1);
    } catch (std::length_error& e) {
      if (!strcmp(
              e.what(),
              "allocator<T>::allocate(size_t n) 'n' exceeds maximum supported "
              "size")) {
        flg = 1;
      }
    }
    if (!flg) {
      throw std::runtime_error("failed");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "Vector: resize(42, 21) for default construction");
  flg = 0;
  try {
    std::vector<int> std_vec;
    ft::vector<int> ft_vec;
    std_vec.resize(42, 21);
    ft_vec.resize(42, 21);
    if (std_vec[0] != ft_vec[0] || std_vec[41] != ft_vec[41] ||
        std_vec.capacity() != ft_vec.capacity() ||
        std_vec.size() != ft_vec.size()) {
      throw std::runtime_error("failed");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "Vector: resize(42, 21) for vec(42, 42)");
  flg = 0;
  try {
    std::vector<int> std_vec(42, 42);
    ft::vector<int> ft_vec(42, 42);
    std_vec.resize(42, 21);
    ft_vec.resize(42, 21);
    if (std_vec[0] != ft_vec[0] || std_vec[41] != ft_vec[41] ||
        std_vec.capacity() != ft_vec.capacity() ||
        std_vec.size() != ft_vec.size()) {
      throw std::runtime_error("failed");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "Vector: resize(42, 21) for vec(21, 42)");
  flg = 0;
  try {
    std::vector<int> std_vec(21, 42);
    ft::vector<int> ft_vec(21, 42);
    std_vec.resize(42, 21);
    ft_vec.resize(42, 21);
    for (size_t idx = 0; idx < std_vec.capacity(); idx++) {
      if (std_vec[idx] != ft_vec[idx]) {
        throw std::runtime_error("failed");
      }
    }
    if (std_vec.capacity() != ft_vec.capacity() ||
        std_vec.size() != ft_vec.size()) {
      throw std::runtime_error("failed");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "Vector: resize(21, 42) for vec(42, 21)");
  flg = 0;
  try {
    std::vector<int> std_vec(42, 21);
    ft::vector<int> ft_vec(42, 21);
    std_vec.resize(21, 42);
    ft_vec.resize(21, 42);
    for (size_t idx = 0; idx < std_vec.capacity(); idx++) {
      if (std_vec[idx] != ft_vec[idx]) {
        throw std::runtime_error("failed");
      }
    }
    if (std_vec.capacity() != ft_vec.capacity() ||
        std_vec.size() != ft_vec.size()) {
      throw std::runtime_error("failed");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "Vector: resize(42, 21) for vec() after reserve(84)");
  flg = 0;
  try {
    std::vector<int> std_vec;
    ft::vector<int> ft_vec;
    std_vec.reserve(84);
    ft_vec.reserve(84);
    std_vec.resize(42, 21);
    ft_vec.resize(42, 21);
    for (size_t idx = 0; idx < std_vec.size(); idx++) {
      if (std_vec[idx] != ft_vec[idx]) {
        throw std::runtime_error("failed");
      }
    }
    if (std_vec.capacity() != ft_vec.capacity() ||
        std_vec.size() != ft_vec.size()) {
      throw std::runtime_error("failed");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no,
              "Vector: resize(42, 21) for vec(21, 42) after reserve(84)");
  flg = 0;
  try {
    std::vector<int> std_vec(21, 42);
    ft::vector<int> ft_vec(21, 42);
    std_vec.reserve(84);
    ft_vec.reserve(84);
    std_vec.resize(42, 21);
    ft_vec.resize(42, 21);
    for (size_t idx = 0; idx < std_vec.size(); idx++) {
      if (std_vec[idx] != ft_vec[idx]) {
        throw std::runtime_error("failed");
      }
    }
    if (std_vec.capacity() != ft_vec.capacity() ||
        std_vec.size() != ft_vec.size()) {
      throw std::runtime_error("failed");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no,
              "Vector: resize(42, 21) for vec(42, 21) after reserve(84)");
  flg = 0;
  try {
    std::vector<int> std_vec(42, 21);
    ft::vector<int> ft_vec(42, 21);
    std_vec.reserve(84);
    ft_vec.reserve(84);
    std_vec.resize(42, 21);
    ft_vec.resize(42, 21);
    for (size_t idx = 0; idx < std_vec.size(); idx++) {
      if (std_vec[idx] != ft_vec[idx]) {
        throw std::runtime_error("failed");
      }
    }
    if (std_vec.capacity() != ft_vec.capacity() ||
        std_vec.size() != ft_vec.size()) {
      throw std::runtime_error("failed");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no,
              "Vector: resize(21, 42) for vec(42, 21) after reserve(84)");
  flg = 0;
  try {
    std::vector<int> std_vec(42, 21);
    ft::vector<int> ft_vec(42, 21);
    std_vec.reserve(84);
    ft_vec.reserve(84);
    std_vec.resize(21, 42);
    ft_vec.resize(21, 42);
    for (size_t idx = 0; idx < std_vec.size(); idx++) {
      if (std_vec[idx] != ft_vec[idx]) {
        throw std::runtime_error("failed");
      }
    }
    if (std_vec.capacity() != ft_vec.capacity() ||
        std_vec.size() != ft_vec.size()) {
      throw std::runtime_error("failed");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  // case segv
  // putTestInfo(test_no, "Vector: front() for default construction");

  putTestInfo(test_no, "Vector: front() of vec(1, 42)");
  flg = 0;
  try {
    std::vector<int> std_vec(1, 42);
    ft::vector<int> ft_vec(1, 42);
    if (std_vec.front() != ft_vec.front()) {
      throw std::runtime_error("failed");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "Vector: front() = 21 of vec(1, 42)");
  flg = 0;
  try {
    std::vector<int> std_vec(1, 42);
    ft::vector<int> ft_vec(1, 42);
    std_vec.front() = 21;
    ft_vec.front() = 21;
    if (std_vec.front() != ft_vec.front()) {
      throw std::runtime_error("failed");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "Vector: front() of vec(42, 42)");
  flg = 0;
  try {
    std::vector<int> std_vec(1, 42);
    ft::vector<int> ft_vec(1, 42);
    if (std_vec.front() != ft_vec.front()) {
      throw std::runtime_error("failed");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "Vector: front() = 21 of vec(42, 42)");
  flg = 0;
  try {
    std::vector<int> std_vec(42, 42);
    ft::vector<int> ft_vec(42, 42);
    std_vec.front() = 21;
    ft_vec.front() = 21;
    if (std_vec.front() != ft_vec.front()) {
      throw std::runtime_error("failed");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  // segv
  // putTestInfo(test_no, "Vector: front() of vec()");

  putTestInfo(test_no, "Vector: back() of vec(1, 42)");
  flg = 0;
  try {
    std::vector<int> std_vec(1, 42);
    ft::vector<int> ft_vec(1, 42);
    if (std_vec.back() != ft_vec.back()) {
      throw std::runtime_error("failed");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "Vector: back() = 21 of vec(1, 42)");
  flg = 0;
  try {
    std::vector<int> std_vec(1, 42);
    ft::vector<int> ft_vec(1, 42);
    std_vec.back() = 21;
    ft_vec.back() = 21;
    if (std_vec.back() != ft_vec.back()) {
      throw std::runtime_error("failed");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "Vector: back() of vec(42, 42)");
  flg = 0;
  try {
    std::vector<int> std_vec(1, 42);
    ft::vector<int> ft_vec(1, 42);
    if (std_vec.back() != ft_vec.back()) {
      throw std::runtime_error("failed");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "Vector: back() of vec(42, 42) (rewrite vec[41]");
  flg = 0;
  try {
    std::vector<int> std_vec(1, 42);
    ft::vector<int> ft_vec(1, 42);

    std_vec[41] = 21;
    ft_vec[41] = 21;
    if (std_vec.back() != ft_vec.back()) {
      throw std::runtime_error("failed");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "Vector: back() = 21 of vec(42, 42)");
  flg = 0;
  try {
    std::vector<int> std_vec(42, 42);
    ft::vector<int> ft_vec(42, 42);
    std_vec.back() = 21;
    ft_vec.back() = 21;
    if (std_vec.back() != ft_vec.back()) {
      throw std::runtime_error("failed");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "push_back(42) to vec()");
  flg = 0;
  try {
    std::vector<int> std_vec;
    ft::vector<int> ft_vec;
    std_vec.push_back(42);
    ft_vec.push_back(42);
    for (size_t idx = 0; idx < std_vec.size(); idx++) {
      if (std_vec[idx] != ft_vec[idx]) {
        throw std::runtime_error("failed");
      }
    }
    if (std_vec.capacity() != ft_vec.capacity() ||
        std_vec.size() != ft_vec.size()) {
      throw std::runtime_error("failed");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "push_back(42) to vec(21, 21)");
  flg = 0;
  try {
    std::vector<int> std_vec(21, 21);
    ft::vector<int> ft_vec(21, 21);
    std_vec.push_back(42);
    ft_vec.push_back(42);
    for (size_t idx = 0; idx < std_vec.size(); idx++) {
      if (std_vec[idx] != ft_vec[idx]) {
        throw std::runtime_error("failed");
      }
    }
    if (std_vec.capacity() != ft_vec.capacity() ||
        std_vec.size() != ft_vec.size()) {
      throw std::runtime_error("failed");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }

  putTestInfo(test_no, "push_back(42) to vec(1, 1)");
  flg = 0;
  try {
    std::vector<int> std_vec(1, 1);
    ft::vector<int> ft_vec(1, 1);
    std_vec.push_back(42);
    ft_vec.push_back(42);
    for (size_t idx = 0; idx < std_vec.size(); idx++) {
      if (std_vec[idx] != ft_vec[idx]) {
        throw std::runtime_error("failed");
      }
    }
    if (std_vec.capacity() != ft_vec.capacity() ||
        std_vec.size() != ft_vec.size()) {
      throw std::runtime_error("failed");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "push_back(42) to vec(2, 2)");
  flg = 0;
  try {
    std::vector<int> std_vec(2, 2);
    ft::vector<int> ft_vec(2, 2);
    std_vec.push_back(42);
    ft_vec.push_back(42);
    for (size_t idx = 0; idx < std_vec.size(); idx++) {
      if (std_vec[idx] != ft_vec[idx]) {
        throw std::runtime_error("failed");
      }
    }
    if (std_vec.capacity() != ft_vec.capacity() ||
        std_vec.size() != ft_vec.size()) {
      throw std::runtime_error("failed");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "push_back(42) to vec(4242, 4242)");
  flg = 0;
  try {
    std::vector<int> std_vec(4242, 4242);
    ft::vector<int> ft_vec(4242, 4242);
    std_vec.push_back(42);
    ft_vec.push_back(42);
    for (size_t idx = 0; idx < std_vec.size(); idx++) {
      if (std_vec[idx] != ft_vec[idx]) {
        throw std::runtime_error("failed");
      }
    }
    if (std_vec.capacity() != ft_vec.capacity() ||
        std_vec.size() != ft_vec.size()) {
      std::cout << std::endl
                << std_vec.size() << ": " << ft_vec.size() << std::endl;
      std::cout << std::endl
                << std_vec.capacity() << ": " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("failed");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  // was ok but takes a few minutes
  // putTestInfo(test_no, "push_back(42) to vec(1234567890, 12345)");

  putTestInfo(test_no, "push_back(42) to vec(12345, 12345)");
  flg = 0;
  try {
    std::vector<int> std_vec(12345, 12345);
    ft::vector<int> ft_vec(12345, 12345);
    std_vec.push_back(42);
    ft_vec.push_back(42);
    for (size_t idx = 0; idx < std_vec.size(); idx++) {
      if (std_vec[idx] != ft_vec[idx]) {
        throw std::runtime_error("failed");
      }
    }
    if (std_vec.capacity() != ft_vec.capacity() ||
        std_vec.size() != ft_vec.size()) {
      throw std::runtime_error("failed");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "push_back(42) to vec(1, 1) after reserve(21)");
  flg = 0;
  try {
    std::vector<int> std_vec(4242, 4242);
    ft::vector<int> ft_vec(4242, 4242);
    std_vec.reserve(21);
    ft_vec.reserve(21);
    std_vec.push_back(42);
    ft_vec.push_back(42);
    for (size_t idx = 0; idx < std_vec.size(); idx++) {
      if (std_vec[idx] != ft_vec[idx]) {
        throw std::runtime_error("failed");
      }
    }
    if (std_vec.capacity() != ft_vec.capacity() ||
        std_vec.size() != ft_vec.size()) {
      throw std::runtime_error("failed");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "pop_back() to vec()");
  flg = 0;
  try {
    std::vector<int> std_vec;
    ft::vector<int> ft_vec;
    std_vec.pop_back();
    ft_vec.pop_back();
    // don't refer (causing segv)
    // for (size_t idx = 0; idx < std_vec.size(); idx++) {
    //   if (std_vec[idx] != ft_vec[idx]) {
    //     throw std::runtime_error("failed");
    //   }
    // }
    if (std_vec.capacity() != ft_vec.capacity() ||
        std_vec.size() != ft_vec.size()) {
      throw std::runtime_error("failed");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "pop_back() to vec(21, 21)");
  flg = 0;
  try {
    std::vector<int> std_vec(21, 21);
    ft::vector<int> ft_vec(21, 21);
    std_vec.pop_back();
    ft_vec.pop_back();
    for (size_t idx = 0; idx < std_vec.size(); idx++) {
      if (std_vec[idx] != ft_vec[idx]) {
        throw std::runtime_error("failed");
      }
    }
    if (std_vec.capacity() != ft_vec.capacity() ||
        std_vec.size() != ft_vec.size()) {
      throw std::runtime_error("failed");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "pop_back() to vec() after resize(1, 1)");
  flg = 0;
  try {
    std::vector<int> std_vec;
    ft::vector<int> ft_vec;
    std_vec.resize(1, 1);
    ft_vec.resize(1, 1);
    std_vec.pop_back();
    ft_vec.pop_back();
    for (size_t idx = 0; idx < std_vec.size(); idx++) {
      if (std_vec[idx] != ft_vec[idx]) {
        throw std::runtime_error("failed");
      }
    }
    if (std_vec.capacity() != ft_vec.capacity() ||
        std_vec.size() != ft_vec.size()) {
      throw std::runtime_error("failed");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "swap vec() and vec(21, 21)");
  flg = 0;
  try {
    std::vector<int> std_vec1;
    std::vector<int> std_vec2(21, 21);
    ft::vector<int> ft_vec1;
    ft::vector<int> ft_vec2(21, 21);
    std_vec1.swap(std_vec2);
    ft_vec1.swap(ft_vec2);
    for (size_t idx = 0; idx < std_vec1.size(); idx++) {
      if (std_vec1[idx] != ft_vec1[idx]) {
        throw std::runtime_error("failed");
      }
    }
    for (size_t idx = 0; idx < std_vec2.size(); idx++) {
      if (std_vec2[idx] != ft_vec2[idx]) {
        throw std::runtime_error("failed");
      }
    }
    if (std_vec1.capacity() != ft_vec1.capacity() ||
        std_vec1.size() != ft_vec1.size() ||
        std_vec2.capacity() != ft_vec2.capacity() ||
        std_vec2.size() != ft_vec2.size()) {
      throw std::runtime_error("failed");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "swap vec(21, 21) and vec()");
  flg = 0;
  try {
    std::vector<int> std_vec1(21, 21);
    std::vector<int> std_vec2;
    ft::vector<int> ft_vec1(21, 21);
    ft::vector<int> ft_vec2;
    std_vec1.swap(std_vec2);
    ft_vec1.swap(ft_vec2);
    for (size_t idx = 0; idx < std_vec1.size(); idx++) {
      if (std_vec1[idx] != ft_vec1[idx]) {
        throw std::runtime_error("failed");
      }
    }
    for (size_t idx = 0; idx < std_vec2.size(); idx++) {
      if (std_vec2[idx] != ft_vec2[idx]) {
        throw std::runtime_error("failed");
      }
    }
    if (std_vec1.capacity() != ft_vec1.capacity() ||
        std_vec1.size() != ft_vec1.size() ||
        std_vec2.capacity() != ft_vec2.capacity() ||
        std_vec2.size() != ft_vec2.size()) {
      throw std::runtime_error("failed");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "swap vec(42, 42) and vec(21, 21)");
  flg = 0;
  try {
    std::vector<int> std_vec1(42, 42);
    std::vector<int> std_vec2(21, 21);
    ft::vector<int> ft_vec1(42, 42);
    ft::vector<int> ft_vec2(21, 21);
    std_vec1.swap(std_vec2);
    ft_vec1.swap(ft_vec2);
    for (size_t idx = 0; idx < std_vec1.size(); idx++) {
      if (std_vec1[idx] != ft_vec1[idx]) {
        throw std::runtime_error("failed");
      }
    }
    for (size_t idx = 0; idx < std_vec2.size(); idx++) {
      if (std_vec2[idx] != ft_vec2[idx]) {
        throw std::runtime_error("failed");
      }
    }
    if (std_vec1.capacity() != ft_vec1.capacity() ||
        std_vec1.size() != ft_vec1.size() ||
        std_vec2.capacity() != ft_vec2.capacity() ||
        std_vec2.size() != ft_vec2.size()) {
      throw std::runtime_error("failed");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "clear with vec()");
  flg = 0;
  try {
    std::vector<int> std_vec;
    ft::vector<int> ft_vec;
    std_vec.clear();
    ft_vec.clear();
    // std::cout << std::endl;
    // std::cout << "size = " << std_vec.size() << std::endl;
    // std::cout << "capacity = " << std_vec.capacity() << std::endl;
    if (std_vec.capacity() != ft_vec.capacity() ||
        std_vec.size() != ft_vec.size()) {
      throw std::runtime_error("failed");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "clear with vec(42,42)");
  flg = 0;
  try {
    std::vector<int> std_vec(42, 42);
    ft::vector<int> ft_vec(42, 42);
    std_vec.clear();
    ft_vec.clear();
    // std::cout << std::endl;
    // std::cout << "size = " << std_vec.size() << std::endl;
    // std::cout << "capacity = " << std_vec.capacity() << std::endl;
    if (std_vec.capacity() != ft_vec.capacity() ||
        std_vec.size() != ft_vec.size()) {
      throw std::runtime_error("failed");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "clear with vec(1,42)");
  flg = 0;
  try {
    std::vector<int> std_vec(1, 42);
    ft::vector<int> ft_vec(1, 42);
    std_vec.clear();
    ft_vec.clear();
    // std::cout << std::endl;
    // std::cout << "size = " << std_vec.size() << std::endl;
    // std::cout << "capacity = " << std_vec.capacity() << std::endl;
    if (std_vec.capacity() != ft_vec.capacity() ||
        std_vec.size() != ft_vec.size()) {
      throw std::runtime_error("failed");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  // this case passed but takes minutes of time
  // putTestInfo(test_no, "clear with vec(1234567890,42)");

  putTestInfo(test_no, "clear with vec(12345, 42)");
  flg = 0;
  try {
    std::vector<int> std_vec(12345,42);
    ft::vector<int> ft_vec(12345,42);
    std_vec.clear();
    ft_vec.clear();
    // std::cout << std::endl;
    // std::cout << "size = " << std_vec.size() << std::endl;
    // std::cout << "capacity = " << std_vec.capacity() << std::endl;
    if (std_vec.capacity() != ft_vec.capacity() ||
        std_vec.size() != ft_vec.size()) {
      throw std::runtime_error("failed");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  return;
}
