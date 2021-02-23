/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_vector_bool.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnakano <dnakano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 08:32:48 by dnakano           #+#    #+#             */
/*   Updated: 2021/02/23 10:21:39 by dnakano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define ALLOW_USE_CPP03

#include <exception>
#include <forward_list>
#include <iostream>
#include <list>
#include <vector>
#ifdef ALLOW_USE_CPP03
#include <algorithm>
#endif /* ALLOW_USE_CPP03 */

#include "test.hpp"
#include "vector.hpp"

void test_vector_bool(int& test_no) {
  std::cout << "=== TEST VECTOR<BOOL> ===" << std::endl;

  putTestInfo(test_no, "Vector<bool>: default construction");
  try {
    std::vector<bool> std_vec;
    ft::vector<bool> ft_vec;
  } catch (std::runtime_error& e) {
    throw e;
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "Vector<bool>: size/capacity of default construction");
  try {
    std::vector<bool> std_vec;
    ft::vector<bool> ft_vec;

    if (std_vec.empty() != ft_vec.empty()) {
      throw std::runtime_error("empty");
    }
    if (std_vec.size() != ft_vec.size()) {
      throw std::runtime_error("size");
    }
    if (std_vec.capacity() != ft_vec.capacity()) {
      throw std::runtime_error("capacity");
    }
    if (std_vec.max_size() != ft_vec.max_size()) {
      std::cout << std::endl;
      std::cout << "max_size(std) = " << std_vec.max_size() << std::endl;
      std::cout << "max_size(ft)  = " << ft_vec.max_size() << std::endl;
      throw std::runtime_error("max_size");
    }
  } catch (std::runtime_error& e) {
    throw e;
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "Vector<bool>: vector(1)");
  try {
    std::vector<bool> std_vec(1);
    ft::vector<bool> ft_vec(1);

    if (std_vec.empty() != ft_vec.empty()) {
      throw std::runtime_error("empty");
    }
    if (std_vec.size() != ft_vec.size()) {
      throw std::runtime_error("size");
    }
    if (std_vec.capacity() != ft_vec.capacity()) {
      std::cout << std::endl;
      std::cout << "capacity(std) = " << std_vec.capacity() << std::endl;
      std::cout << "capacity(ft)  = " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("capacity");
    }
    if (std_vec.max_size() != ft_vec.max_size()) {
      throw std::runtime_error("max_size");
    }
  } catch (std::runtime_error& e) {
    throw e;
  }
  std::cout << " => OK :)" << std::endl;

  return;
}
