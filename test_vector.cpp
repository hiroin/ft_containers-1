/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_vector.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnakano <dnakano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 20:50:10 by dnakano           #+#    #+#             */
/*   Updated: 2021/01/29 15:51:40 by dnakano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>
#include <iostream>
#include <vector>

#include "test.hpp"
#include "vector.hpp"

void test_vector(int& test_no) {
  putTestInfo(test_no, "Vector: default construction");
  try {
    ft::vector<int> vec;
  } catch (std::exception& e) {
    throw std::runtime_error("failed");
  }
  std::cout << " ==> OK :)" << std::endl;

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
  std::cout << " ==> OK :)" << std::endl;

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
  std::cout << " ==> OK :)" << std::endl;

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
  std::cout << " ==> OK :)" << std::endl;

  putTestInfo(test_no, "vector: fill construction with 42, 42");
  try {
    ft::vector<int> vec(42, 42);
  } catch (std::exception& e) {
    throw std::runtime_error("failed");
  }
  std::cout << " ==> OK :)" << std::endl;

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
  std::cout << " ==> OK :)" << std::endl;

  putTestInfo(test_no, "vector: check vec1 = vec2(42,42)");
  try {
    ft::vector<int> vec1;
    ft::vector<int> vec2(42, 42);
    vec1 = vec2;
    if (!(vec1 == vec2)) {
      throw std::runtime_error("should be equal");
    }
  } catch (std::exception& e) {
    throw std::runtime_error("failed");
  }
  std::cout << " ==> OK :)" << std::endl;
}
