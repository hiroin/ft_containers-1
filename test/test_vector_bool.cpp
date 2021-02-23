/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_vector_bool.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnakano <dnakano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 08:32:48 by dnakano           #+#    #+#             */
/*   Updated: 2021/02/23 21:07:15 by dnakano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define ALLOW_USE_CPP03

#include <exception>
#include <forward_list>
#include <iostream>
#include <list>
#include <sstream>
#include <vector>
#ifdef ALLOW_USE_CPP03
#include <algorithm>
#endif /* ALLOW_USE_CPP03 */

#include "test.hpp"
#include "vector.hpp"

static void test_value_assign(int& test_no, size_t size1, bool val1,
                              size_t size2, bool val2) {
  std::stringstream sout;
  sout << std::boolalpha << "Vector<bool>: vector(" << size1 << ", " << val1
       << ") and assign(" << size2 << ", " << val2 << ")";
  putTestInfo(test_no, sout.str());
  try {
    std::vector<bool> std_vec(size1, val1);
    ft::vector<bool> ft_vec(size1, val1);

    std_vec.assign(size2, val2);
    ft_vec.assign(size2, val2);
    for (size_t idx = 0; idx < size2; ++idx) {
      if (std_vec[idx] != ft_vec[idx]) {
        std::cout << std::endl << "idx = " << idx << std::endl;
        std::cout << "std: " << std_vec[idx] << std::endl;
        std::cout << " ft: " << ft_vec[idx] << std::endl;
        throw std::runtime_error("value");
      }
    }
    if (std_vec.empty() != ft_vec.empty()) {
      throw std::runtime_error("empty");
    }
    if (std_vec.size() != ft_vec.size()) {
      throw std::runtime_error("size");
    }
    if (std_vec.capacity() != ft_vec.capacity()) {
      std::cout << std::endl;
      std::cout << "std: " << std_vec.capacity() << std::endl;
      std::cout << " ft: " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("value");
      throw std::runtime_error("capacity");
    }
    if (std_vec.max_size() != ft_vec.max_size()) {
      throw std::runtime_error("max_size");
    }
  } catch (std::runtime_error& e) {
    throw e;
  }
  std::cout << " => OK :)" << std::endl;
}

void test_vector_bool(int& test_no) {
  std::cout << "=== TEST VECTOR<BOOL> ===" << std::endl;
  std::cout << std::boolalpha;
  size_t size = 0;
  size_t size_ary[] = {1,   2,   63,   64,   65,   100,  127,
                       128, 129, 1023, 1024, 1025, 2000, 4000};

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

  for (size = 0; size <= 150; size++) {
    std::stringstream sout;
    sout << "Vector<bool>: vector(" << size << ")";
    putTestInfo(test_no, sout.str());
    try {
      std::vector<bool> std_vec(size);
      ft::vector<bool> ft_vec(size);

      printf("hoge\n");
      for (size_t idx = 0; idx < size; ++idx) {
        if (std_vec[idx] != ft_vec[idx]) {
          std::cout << std::endl << "idx = " << idx << std::endl;
          std::cout << "std: " << std_vec[idx] << std::endl;
          std::cout << " ft: " << ft_vec[idx] << std::endl;
          throw std::runtime_error("value");
        }
      }
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
        throw std::runtime_error("max_size");
      }
    } catch (std::runtime_error& e) {
      throw e;
    }
    std::cout << " => OK :)" << std::endl;
  }

  for (size = 0; size <= 150; size++) {
    std::stringstream sout;
    sout << "Vector<bool>: vector(" << size << ", false)";
    putTestInfo(test_no, sout.str());
    try {
      std::vector<bool> std_vec(size, false);
      ft::vector<bool> ft_vec(size, false);

      for (size_t idx = 0; idx < size; ++idx) {
        if (std_vec[idx] != ft_vec[idx]) {
          std::cout << std::endl << "idx = " << idx << std::endl;
          std::cout << "std: " << std_vec[idx] << std::endl;
          std::cout << " ft: " << ft_vec[idx] << std::endl;
          throw std::runtime_error("value");
        }
      }
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
        throw std::runtime_error("max_size");
      }
    } catch (std::runtime_error& e) {
      throw e;
    }
    std::cout << " => OK :)" << std::endl;
  }

  for (size = 0; size <= 150; size++) {
    std::stringstream sout;
    sout << "Vector<bool>: vector(" << size << ", true)";
    putTestInfo(test_no, sout.str());
    try {
      std::vector<bool> std_vec(size, false);
      ft::vector<bool> ft_vec(size, false);

      for (size_t idx = 0; idx < size; ++idx) {
        if (std_vec[idx] != ft_vec[idx]) {
          std::cout << std::endl << "idx = " << idx << std::endl;
          std::cout << "std: " << std_vec[idx] << std::endl;
          std::cout << " ft: " << ft_vec[idx] << std::endl;
          throw std::runtime_error("value");
        }
      }
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
        throw std::runtime_error("max_size");
      }
    } catch (std::runtime_error& e) {
      throw e;
    }
    std::cout << " => OK :)" << std::endl;
  }

  size = 420;
  putTestInfo(test_no, "Vector<bool>: assign random to vec(420)");
  try {
    bool val;
    std::vector<bool> std_vec(size);
    ft::vector<bool> ft_vec(size);

    for (size_t idx = 0; idx < size; ++idx) {
      val = rand() % 2;
      std_vec[idx] = val;
      ft_vec[idx] = val;
    }
    for (size_t idx = 0; idx < size; ++idx) {
      if (std_vec[idx] != ft_vec[idx]) {
        std::cout << std::endl << "idx = " << idx << std::endl;
        std::cout << "std: " << std_vec[idx] << std::endl;
        std::cout << " ft: " << ft_vec[idx] << std::endl;
        throw std::runtime_error("value");
      }
    }
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

  size = 420;
  putTestInfo(test_no, "Vector<bool>: assign random to vec(420) then flip");
  try {
    bool val;
    std::vector<bool> std_vec(size);
    ft::vector<bool> ft_vec(size);

    for (size_t idx = 0; idx < size; ++idx) {
      val = rand() % 2;
      std_vec[idx] = val;
      ft_vec[idx] = val;
    }
    std_vec.flip();
    ft_vec.flip();
    for (size_t idx = 0; idx < size; ++idx) {
      if (std_vec[idx] != ft_vec[idx]) {
        std::cout << std::endl << "idx = " << idx << std::endl;
        std::cout << "std: " << std_vec[idx] << std::endl;
        std::cout << " ft: " << ft_vec[idx] << std::endl;
        throw std::runtime_error("value");
      }
    }
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

  for (size_t i = 0; i < 14; i++) {
    for (size_t j = 0; j < 14; j++) {
      test_value_assign(test_no, size_ary[i], true, size_ary[j], false);
    }
  }

  for (size_t i = 0; i < 14; i++) {
    for (size_t j = 0; j < 14; j++) {
      test_value_assign(test_no, size_ary[i], false, size_ary[j], true);
    }
  }

  for (size_t i = 0; i < 14; i++) {
    for (size_t j = 0; j < 14; j++) {
      test_value_assign(test_no, size_ary[i], true, size_ary[j], true);
    }
  }

  for (size_t i = 0; i < 14; i++) {
    for (size_t j = 0; j < 14; j++) {
      test_value_assign(test_no, size_ary[i], false, size_ary[j], false);
    }
  }

  for (size_t i = 0; i < 14; ++i) {
    size = size_ary[i];
    std::stringstream sout;
    sout << "Vector<bool>: range construct " << size << " by pointer";
    putTestInfo(test_no, sout.str());
    try {
      bool val[size];
      for (size_t idx = 0; idx < size; ++idx) {
        val[idx] = rand() % 2;
      }

      std::vector<bool> std_vec(val, val + size);
      ft::vector<bool> ft_vec(val, val + size);
      for (size_t idx = 0; idx < size; ++idx) {
        if (std_vec[idx] != ft_vec[idx]) {
          std::cout << std::endl << "idx = " << idx << std::endl;
          std::cout << "std: " << std_vec[idx] << std::endl;
          std::cout << " ft: " << ft_vec[idx] << std::endl;
          throw std::runtime_error("value");
        }
      }
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
  }

  for (size_t i = 0; i < 14; ++i) {
    for (size_t j = 0; j < 14; ++j) {
      std::stringstream sout;
      sout << "Vector<bool>: assgin(" << size_ary[i] << ") by pointer to vec("
           << size_ary[j] << ")";
      putTestInfo(test_no, sout.str());
      try {
        bool val[size_ary[i]];
        for (size_t idx = 0; idx < size_ary[i]; ++idx) {
          val[idx] = rand() % 2;
        }

        // std::vector<bool>::iterator::
        // std::vector<bool>::iterator::reference

        std::vector<bool> std_vec(size_ary[j]);
        ft::vector<bool> ft_vec(size_ary[j]);
        std_vec.assign(val, val + size_ary[i]);
        ft_vec.assign(val, val + size_ary[i]);
        for (size_t idx = 0; idx < size_ary[i]; ++idx) {
          if (std_vec[idx] != ft_vec[idx]) {
            std::cout << std::endl << "idx = " << idx << std::endl;
            std::cout << "std: " << std_vec[idx] << std::endl;
            std::cout << " ft: " << ft_vec[idx] << std::endl;
            throw std::runtime_error("value");
          }
        }
        if (std_vec.empty() != ft_vec.empty()) {
          throw std::runtime_error("empty");
        }
        if (std_vec.size() != ft_vec.size()) {
          throw std::runtime_error("size");
        }
        if (std_vec.capacity() != ft_vec.capacity()) {
          std::cout << std::endl;
          std::cout << "std: " << std_vec.capacity() << std::endl;
          std::cout << " ft: " << ft_vec.capacity() << std::endl;
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
    }
  }

  std::cout << std::noboolalpha;
}
