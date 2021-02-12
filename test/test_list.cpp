/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_list.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnakano <dnakano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 08:01:31 by dnakano           #+#    #+#             */
/*   Updated: 2021/02/12 13:12:15 by dnakano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>
#include <forward_list>
#include <iostream>
#include <list>
#include <vector>

#include "../list.hpp"
#include "../vector.hpp"
#include "Hoge.hpp"
#include "test.hpp"

void test_list(int& test_no) {
  Hoge hoge[10] = {Hoge(0, 0), Hoge(1, 1), Hoge(2, 2), Hoge(3, 3), Hoge(4, 4),
                   Hoge(5, 5), Hoge(6, 6), Hoge(7, 7), Hoge(8, 8), Hoge(9, 9)};
  std::vector<Hoge> hoge_vec(hoge, &hoge[10]);
  std::list<Hoge> hoge_lst(hoge, &hoge[10]);
  std::forward_list<Hoge> hoge_flst(hoge, &hoge[10]);

  int num[10] = {0, 1, 2, 3, 42, 5, 6, 7, 8, 9};
  std::vector<int> num_vec(num, &num[10]);

  std::cout << "=== TEST LIST ===" << std::endl;

  // default constuction
  putTestInfo(test_no, "list<Hoge>: default construction");
  try {
    std::list<Hoge> lst_std;
    ft::list<Hoge> lst_ft;
  } catch (std::exception& e) {
    throw std::runtime_error("failed");
  }
  std::cout << " => OK :)" << std::endl;

  // default push_front(), front() and back()
  putTestInfo(test_no, "list<int>: push_front() and get it by front()");
  try {
    std::list<int> lst_std;
    ft::list<int> lst_ft;

    lst_std.push_front(4);
    lst_ft.push_front(4);
    if (lst_std.front() != lst_ft.front()) {
      throw std::runtime_error("value");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list<Hoge>: push_front() and get it by front()");
  try {
    std::list<Hoge> lst_std;
    ft::list<Hoge> lst_ft;

    lst_std.push_front(hoge[4]);
    lst_ft.push_front(hoge[4]);
    if (lst_std.front() != lst_ft.front()) {
      throw std::runtime_error("value");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list<Hoge>: push_front() and get it by back()");
  try {
    std::list<Hoge> lst_std;
    ft::list<Hoge> lst_ft;

    lst_std.push_front(hoge[4]);
    lst_ft.push_front(hoge[4]);
    if (lst_std.back() != lst_ft.back()) {
      throw std::runtime_error("value");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(
      test_no,
      "list<Hoge>: push_front() twice and get it by front() and back()");
  try {
    std::list<Hoge> lst_std;
    ft::list<Hoge> lst_ft;

    lst_std.push_front(hoge[4]);
    lst_ft.push_front(hoge[4]);
    if (lst_std.front() != lst_ft.front()) {
      throw std::runtime_error("front");
    }
    if (lst_std.back() != lst_ft.back()) {
      throw std::runtime_error("back");
    }
    lst_std.push_front(hoge[2]);
    lst_ft.push_front(hoge[2]);
    if (lst_std.front() != lst_ft.front()) {
      throw std::runtime_error("front");
    }
    if (lst_std.back() != lst_ft.back()) {
      throw std::runtime_error("back");
    }
    // try twice
    if (lst_std.front() != lst_ft.front()) {
      throw std::runtime_error("front");
    }
    if (lst_std.back() != lst_ft.back()) {
      throw std::runtime_error("back");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(
      test_no,
      "list<Hoge>: push_front() 10 times and front/back/size/empty/max_size");
  try {
    std::list<Hoge> lst_std;
    ft::list<Hoge> lst_ft;

    if (lst_std.size() != lst_ft.size() ||
        lst_std.max_size() != lst_ft.max_size() ||
        lst_std.empty() != lst_ft.empty()) {
      throw std::runtime_error("size/empty/max_size");
    }
    if (lst_std.max_size() != lst_ft.max_size()) {
      throw std::runtime_error("size");
    }
    for (std::vector<Hoge>::iterator iter = hoge_vec.begin();
         iter != hoge_vec.end(); ++iter) {
      lst_std.push_front(*iter);
      lst_ft.push_front(*iter);
      if (lst_std.front() != lst_ft.front()) {
        throw std::runtime_error("front");
      }
      if (lst_std.back() != lst_ft.back()) {
        throw std::runtime_error("back");
      }
      if (lst_std.size() != lst_ft.size() ||
          lst_std.max_size() != lst_ft.max_size() ||
          lst_std.empty() != lst_ft.empty()) {
        throw std::runtime_error("size/empty/max_size");
      }
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(
      test_no,
      "list<Hoge>: push_back() 10 times and front/back/size/empty/max_size");
  try {
    std::list<Hoge> lst_std;
    ft::list<Hoge> lst_ft;

    if (lst_std.size() != lst_ft.size() ||
        lst_std.max_size() != lst_ft.max_size() ||
        lst_std.empty() != lst_ft.empty()) {
      throw std::runtime_error("size/empty/max_size");
    }
    if (lst_std.max_size() != lst_ft.max_size()) {
      throw std::runtime_error("size");
    }
    for (std::vector<Hoge>::iterator iter = hoge_vec.begin();
         iter != hoge_vec.end(); ++iter) {
      lst_std.push_back(*iter);
      lst_ft.push_back(*iter);
      if (lst_std.front() != lst_ft.front()) {
        throw std::runtime_error("front");
      }
      if (lst_std.back() != lst_ft.back()) {
        throw std::runtime_error("back");
      }
      if (lst_std.size() != lst_ft.size() ||
          lst_std.max_size() != lst_ft.max_size() ||
          lst_std.empty() != lst_ft.empty()) {
        throw std::runtime_error("size/empty/max_size");
      }
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no,
              "list<Hoge>: push_back/front 10 times and "
              "front/back/size/empty/max_size");
  try {
    std::list<Hoge> lst_std;
    ft::list<Hoge> lst_ft;

    if (lst_std.size() != lst_ft.size() ||
        lst_std.max_size() != lst_ft.max_size() ||
        lst_std.empty() != lst_ft.empty()) {
      throw std::runtime_error("size/empty/max_size");
    }
    if (lst_std.max_size() != lst_ft.max_size()) {
      throw std::runtime_error("size");
    }
    for (std::vector<Hoge>::iterator iter = hoge_vec.begin();
         iter != hoge_vec.end(); ++iter) {
      lst_std.push_front(*iter);
      lst_ft.push_front(*iter);
      lst_std.push_back(*iter);
      lst_ft.push_back(*iter);
      if (lst_std.front() != lst_ft.front()) {
        throw std::runtime_error("front");
      }
      if (lst_std.back() != lst_ft.back()) {
        throw std::runtime_error("back");
      }
      if (lst_std.size() != lst_ft.size() ||
          lst_std.max_size() != lst_ft.max_size() ||
          lst_std.empty() != lst_ft.empty()) {
        throw std::runtime_error("size/empty/max_size");
      }
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no,
              "list<Hoge>: push_back/front 10 times and pop_front until empty");
  try {
    std::list<Hoge> lst_std;
    ft::list<Hoge> lst_ft;

    for (std::vector<Hoge>::iterator iter = hoge_vec.begin();
         iter != hoge_vec.end(); ++iter) {
      lst_std.push_front(*iter);
      lst_ft.push_front(*iter);
      lst_std.push_back(*iter);
      lst_ft.push_back(*iter);
    }
    while (!lst_std.empty()) {
      if (lst_std.front() != lst_ft.front()) {
        throw std::runtime_error("front");
      }
      if (lst_std.back() != lst_ft.back()) {
        throw std::runtime_error("back");
      }
      if (lst_std.size() != lst_ft.size() ||
          lst_std.max_size() != lst_ft.max_size() ||
          lst_std.empty() != lst_ft.empty()) {
        throw std::runtime_error("size/empty/max_size");
      }
      lst_std.pop_front();
      lst_ft.pop_front();
    }
    if (!lst_ft.empty()) {
      throw std::runtime_error("empty");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no,
              "list<Hoge>: push_back/front 10 times and pop_back until empty");
  try {
    std::list<Hoge> lst_std;
    ft::list<Hoge> lst_ft;

    for (std::vector<Hoge>::iterator iter = hoge_vec.begin();
         iter != hoge_vec.end(); ++iter) {
      lst_std.push_front(*iter);
      lst_ft.push_front(*iter);
      lst_std.push_back(*iter);
      lst_ft.push_back(*iter);
    }
    // std::cout << std::endl;
    while (!lst_std.empty()) {
      // std::cout << "size = " << lst_ft.size() << std::endl;
      // std::cout << "std = " << lst_std.front() << std::endl;
      // std::cout << "std = " << lst_std.back() << std::endl;
      // std::cout << "ft = " << lst_ft.front() << std::endl;
      // std::cout << "ft = " << lst_ft.back() << std::endl;
      if (lst_std.front() != lst_ft.front()) {
        throw std::runtime_error("front");
      }
      if (lst_std.back() != lst_ft.back()) {
        throw std::runtime_error("back");
      }
      if (lst_std.size() != lst_ft.size() ||
          lst_std.max_size() != lst_ft.max_size() ||
          lst_std.empty() != lst_ft.empty()) {
        throw std::runtime_error("size/empty/max_size");
      }
      lst_std.pop_back();
      lst_ft.pop_back();
    }
    if (!lst_ft.empty()) {
      throw std::runtime_error("empty");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no,
              "list<Hoge>: push_back/front 10 times and check value using "
              "iterator (increase by ++iter)");
  try {
    std::list<Hoge> lst_std;
    ft::list<Hoge> lst_ft;
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    for (std::vector<Hoge>::iterator iter = hoge_vec.begin();
         iter != hoge_vec.end(); ++iter) {
      lst_std.push_front(*iter);
      lst_ft.push_front(*iter);
      lst_std.push_back(*iter);
      lst_ft.push_back(*iter);
    }
    std::cout << std::endl;
    for (itr_ft = lst_ft.begin(), itr_std = lst_std.begin();
         itr_ft != lst_ft.end(); ++itr_ft, ++itr_std) {
      if (*itr_ft != *itr_std) {
        std::cout << "std :: ft = " << *itr_std << " :: " << *itr_ft
                  << std::endl;
        throw std::runtime_error("iterator value");
      }
    }
    if (itr_std != lst_std.end()) {
      throw std::runtime_error("iteratation");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no,
              "list<Hoge>: push_back/front 10 times and check value using "
              "iterator (increase by iter++)");
  try {
    std::list<Hoge> lst_std;
    ft::list<Hoge> lst_ft;
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    for (std::vector<Hoge>::iterator iter = hoge_vec.begin();
         iter != hoge_vec.end(); ++iter) {
      lst_std.push_front(*iter);
      lst_ft.push_front(*iter);
      lst_std.push_back(*iter);
      lst_ft.push_back(*iter);
    }
    itr_ft = lst_ft.begin();
    itr_std = lst_std.begin();
    while (itr_ft != lst_ft.end()) {
      if (*itr_std++ != *itr_ft++) {
        throw std::runtime_error("iterator value");
      }
    }
    if (itr_std != lst_std.end()) {
      throw std::runtime_error("iteratation");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no,
              "list<Hoge>: push_back/front 10 times, then rewrite all value to "
              "zero and check value using iterator");
  try {
    std::list<Hoge> lst_std;
    ft::list<Hoge> lst_ft;
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    for (std::vector<Hoge>::iterator iter = hoge_vec.begin();
         iter != hoge_vec.end(); ++iter) {
      lst_std.push_front(*iter);
      lst_ft.push_front(*iter);
      lst_std.push_back(*iter);
      lst_ft.push_back(*iter);
    }
    itr_ft = lst_ft.begin();
    itr_std = lst_std.begin();
    while (itr_ft != lst_ft.end()) {
      *itr_std++ = hoge[0];
      *itr_ft++ = hoge[0];
    }
    itr_ft = lst_ft.begin();
    itr_std = lst_std.begin();
    while (itr_ft != lst_ft.end()) {
      if (*itr_std++ != *itr_ft++) {
        throw std::runtime_error("iterator value");
      }
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no,
              "list<Hoge>: push_back 10 times and check value using "
              "iterator (increase by ++iter)");
  try {
    std::list<Hoge> lst_std;
    ft::list<Hoge> lst_ft;
    std::list<Hoge>::reverse_iterator itr_std;
    ft::list<Hoge>::reverse_iterator itr_ft;

    for (std::vector<Hoge>::iterator iter = hoge_vec.begin();
         iter != hoge_vec.end(); ++iter) {
      lst_std.push_front(*iter);
      lst_ft.push_front(*iter);
      lst_std.push_back(*iter);
      lst_ft.push_back(*iter);
    }
    std::cout << std::endl;
    for (itr_ft = lst_ft.rbegin(), itr_std = lst_std.rbegin();
         itr_ft != lst_ft.rend(); ++itr_ft, ++itr_std) {
      if (*itr_ft != *itr_std) {
        std::cout << "std :: ft = " << *itr_std << " :: " << *itr_ft
                  << std::endl;
        throw std::runtime_error("iterator value");
      }
    }
    if (itr_std != lst_std.rend()) {
      throw std::runtime_error("iteratation");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no,
              "list<Hoge>: push_back 10 times and check value using "
              "iterator (increase by iter++)");
  try {
    std::list<Hoge> lst_std;
    ft::list<Hoge> lst_ft;
    std::list<Hoge>::reverse_iterator itr_std;
    ft::list<Hoge>::reverse_iterator itr_ft;

    for (std::vector<Hoge>::iterator iter = hoge_vec.begin();
         iter != hoge_vec.end(); ++iter) {
      lst_std.push_front(*iter);
      lst_ft.push_front(*iter);
      lst_std.push_back(*iter);
      lst_ft.push_back(*iter);
    }
    itr_ft = lst_ft.rbegin();
    itr_std = lst_std.rbegin();
    while (itr_ft != lst_ft.rend()) {
      if (*itr_std++ != *itr_ft++) {
        throw std::runtime_error("iterator value");
      }
    }
    if (itr_std != lst_std.rend()) {
      throw std::runtime_error("iteratation");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no,
              "list<Hoge>: push_back/front 10 times, then rewrite all value to "
              "zero and check value using iterator");
  try {
    std::list<Hoge> lst_std;
    ft::list<Hoge> lst_ft;
    std::list<Hoge>::reverse_iterator itr_std;
    ft::list<Hoge>::reverse_iterator itr_ft;

    for (std::vector<Hoge>::iterator iter = hoge_vec.begin();
         iter != hoge_vec.end(); ++iter) {
      lst_std.push_front(*iter);
      lst_ft.push_front(*iter);
      lst_std.push_back(*iter);
      lst_ft.push_back(*iter);
    }
    itr_ft = lst_ft.rbegin();
    itr_std = lst_std.rbegin();
    while (itr_ft != lst_ft.rend()) {
      *itr_std++ = hoge[0];
      *itr_ft++ = hoge[0];
    }
    itr_ft = lst_ft.rbegin();
    itr_std = lst_std.rbegin();
    while (itr_ft != lst_ft.rend()) {
      if (*itr_std++ != *itr_ft++) {
        throw std::runtime_error("iterator value");
      }
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list<Hoge>: clear() of default constucted");
  try {
    std::list<Hoge> lst_std;
    ft::list<Hoge> lst_ft;

    lst_std.clear();
    lst_ft.clear();
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size() ||
        lst_std.max_size() != lst_ft.max_size()) {
      throw std::runtime_error("error");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list<Hoge>: clear() of 1 elem contained");
  try {
    std::list<Hoge> lst_std;
    ft::list<Hoge> lst_ft;

    lst_std.push_front(hoge[1]);
    lst_ft.push_front(hoge[1]);
    lst_std.clear();
    lst_ft.clear();
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size() ||
        lst_std.max_size() != lst_ft.max_size()) {
      throw std::runtime_error("error");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list<Hoge>: push_front 10 times, then clear()");
  try {
    std::list<Hoge> lst_std;
    ft::list<Hoge> lst_ft;

    for (std::vector<Hoge>::iterator iter = hoge_vec.begin();
         iter != hoge_vec.end(); ++iter) {
      lst_std.push_front(*iter);
      lst_ft.push_front(*iter);
      lst_std.push_back(*iter);
      lst_ft.push_back(*iter);
    }
    lst_std.clear();
    lst_ft.clear();
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size() ||
        lst_std.max_size() != lst_ft.max_size()) {
      throw std::runtime_error("error");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list<Hoge>: clear add clear add clear");
  try {
    std::list<Hoge> lst_std;
    ft::list<Hoge> lst_ft;

    lst_std.clear();
    lst_ft.clear();
    for (std::vector<Hoge>::iterator iter = hoge_vec.begin();
         iter != hoge_vec.end(); ++iter) {
      lst_std.push_front(*iter);
      lst_ft.push_front(*iter);
      lst_std.push_back(*iter);
      lst_ft.push_back(*iter);
    }
    lst_std.clear();
    lst_ft.clear();
    lst_std.push_front(hoge[1]);
    lst_ft.push_front(hoge[1]);
    lst_std.clear();
    lst_ft.clear();
    for (std::vector<Hoge>::iterator iter = hoge_vec.begin();
         iter != hoge_vec.end(); ++iter) {
      lst_std.push_front(*iter);
      lst_ft.push_front(*iter);
    }
    lst_std.clear();
    lst_ft.clear();
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size() ||
        lst_std.max_size() != lst_ft.max_size()) {
      throw std::runtime_error("error");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  // assign(n, val) <int>
  putTestInfo(test_no, "list<int>: assign(0, 42) to empty");
  try {
    std::list<int> lst_std;
    ft::list<int> lst_ft;
    std::list<int>::iterator itr_std;
    ft::list<int>::iterator itr_ft;

    lst_std.assign(1, 42);
    lst_ft.assign(1, 42);
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list<int>: assign(1, 42) to empty");
  try {
    std::list<int> lst_std;
    ft::list<int> lst_ft;
    std::list<int>::iterator itr_std;
    ft::list<int>::iterator itr_ft;

    lst_std.assign(1, 42);
    lst_ft.assign(1, 42);
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list<int>: assign(42, 42) to empty");
  try {
    std::list<int> lst_std;
    ft::list<int> lst_ft;
    std::list<int>::iterator itr_std;
    ft::list<int>::iterator itr_ft;

    lst_std.assign(42, 42);
    lst_ft.assign(42, 42);
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list<int>: assign 42 -> 0 -> 1 -> 42 -> 1 to empty");
  try {
    std::list<int> lst_std;
    ft::list<int> lst_ft;
    std::list<int>::iterator itr_std;
    ft::list<int>::iterator itr_ft;

    lst_std.assign(42, 42);
    lst_ft.assign(42, 42);
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }

    lst_std.assign(0, 42);
    lst_ft.assign(0, 42);
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }

    lst_std.assign(1, 42);
    lst_ft.assign(1, 42);
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }

    lst_std.assign(42, 42);
    lst_ft.assign(42, 42);
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }

    lst_std.assign(1, 42);
    lst_ft.assign(1, 42);
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  // assign(n, val) <Hoge>
  putTestInfo(test_no, "list<Hoge>: assign(0, hoge[4]) to empty");
  try {
    std::list<Hoge> lst_std;
    ft::list<Hoge> lst_ft;
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    lst_std.assign(1, hoge[4]);
    lst_ft.assign(1, hoge[4]);
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list<Hoge>: assign(1, hoge[4]) to empty");
  try {
    std::list<Hoge> lst_std;
    ft::list<Hoge> lst_ft;
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    lst_std.assign(1, hoge[4]);
    lst_ft.assign(1, hoge[4]);
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list<Hoge>: assign(42, hoge[4]) to empty");
  try {
    std::list<Hoge> lst_std;
    ft::list<Hoge> lst_ft;
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    lst_std.assign(42, hoge[4]);
    lst_ft.assign(42, hoge[4]);
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list<Hoge>: assign 42 -> 0 -> 1 -> 42 -> 1 to empty");
  try {
    std::list<Hoge> lst_std;
    ft::list<Hoge> lst_ft;
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    lst_std.assign(42, hoge[4]);
    lst_ft.assign(42, hoge[4]);
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }

    lst_std.assign(0, hoge[4]);
    lst_ft.assign(0, hoge[4]);
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }

    lst_std.assign(1, hoge[4]);
    lst_ft.assign(1, hoge[4]);
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }

    lst_std.assign(42, hoge[4]);
    lst_ft.assign(42, hoge[4]);
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }

    lst_std.assign(1, hoge[4]);
    lst_ft.assign(1, hoge[4]);
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  // assign(itr, itr) <int>
  putTestInfo(test_no, "list<int>: assign(begin, end) to empty");
  try {
    std::list<int> lst_std;
    ft::list<int> lst_ft;
    std::list<int>::iterator itr_std;
    ft::list<int>::iterator itr_ft;

    lst_std.assign(num_vec.begin(), num_vec.end());
    lst_ft.assign(num_vec.begin(), num_vec.end());
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list<int>: assign(rbegin, rend) to empty");
  try {
    std::list<int> lst_std;
    ft::list<int> lst_ft;
    std::list<int>::iterator itr_std;
    ft::list<int>::iterator itr_ft;

    lst_std.assign(num_vec.rbegin(), num_vec.rend());
    lst_ft.assign(num_vec.rbegin(), num_vec.rend());
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list<int>: assign(begin, begin) to empty");
  try {
    std::list<int> lst_std;
    ft::list<int> lst_ft;
    std::list<int>::iterator itr_std;
    ft::list<int>::iterator itr_ft;

    lst_std.assign(num_vec.begin(), num_vec.begin());
    lst_ft.assign(num_vec.begin(), num_vec.begin());
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list<int>: assign(end, end) to empty");
  try {
    std::list<int> lst_std;
    ft::list<int> lst_ft;
    std::list<int>::iterator itr_std;
    ft::list<int>::iterator itr_ft;

    lst_std.assign(num_vec.end(), num_vec.end());
    lst_ft.assign(num_vec.end(), num_vec.end());
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list<int>: assign(begin, ++begin) to empty");
  try {
    std::list<int> lst_std;
    ft::list<int> lst_ft;
    std::list<int>::iterator itr_std;
    ft::list<int>::iterator itr_ft;

    lst_std.assign(num_vec.begin(), ++num_vec.begin());
    lst_ft.assign(num_vec.begin(), ++num_vec.begin());
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no,
              "list<int>: assign(begin, end) -> (begin,begin)->(rbegin,rend) "
              "-> (begin,++begin) -> (begin,end) to empty");
  try {
    std::list<int> lst_std;
    ft::list<int> lst_ft;
    std::list<int>::iterator itr_std;
    ft::list<int>::iterator itr_ft;

    lst_std.assign(num_vec.begin(), num_vec.end());
    lst_ft.assign(num_vec.begin(), num_vec.end());
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }

    lst_std.assign(num_vec.begin(), num_vec.begin());
    lst_ft.assign(num_vec.begin(), num_vec.begin());
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }

    lst_std.assign(num_vec.rbegin(), num_vec.rend());
    lst_ft.assign(num_vec.rbegin(), num_vec.rend());
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }

    lst_std.assign(num_vec.begin(), num_vec.begin());
    lst_ft.assign(num_vec.begin(), num_vec.begin());
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }

    lst_std.assign(num_vec.begin(), num_vec.end());
    lst_ft.assign(num_vec.begin(), num_vec.end());
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }

  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  // assign(ptr, ptr) <int>
  putTestInfo(test_no, "list<int>: assign([0], [9]) to empty");
  try {
    std::list<int> lst_std;
    ft::list<int> lst_ft;
    std::list<int>::iterator itr_std;
    ft::list<int>::iterator itr_ft;

    lst_std.assign(&num[0], &num[9]);
    lst_ft.assign(&num[0], &num[9]);
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list<int>: assign([0], [0]) to empty");
  try {
    std::list<int> lst_std;
    ft::list<int> lst_ft;
    std::list<int>::iterator itr_std;
    ft::list<int>::iterator itr_ft;

    lst_std.assign(&num[0], &num[0]);
    lst_ft.assign(&num[0], &num[0]);
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list<int>: assign([0], [0]) to empty");
  try {
    std::list<int> lst_std;
    ft::list<int> lst_ft;
    std::list<int>::iterator itr_std;
    ft::list<int>::iterator itr_ft;

    lst_std.assign(&num[2], &num[4]);
    lst_ft.assign(&num[2], &num[4]);
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  // assign(itr, itr) <Hoge>
  putTestInfo(test_no, "list<Hoge>: assign(begin, end) to empty");
  try {
    std::list<Hoge> lst_std;
    ft::list<Hoge> lst_ft;
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    lst_std.assign(hoge_vec.begin(), hoge_vec.end());
    lst_ft.assign(hoge_vec.begin(), hoge_vec.end());
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list<Hoge>: assign(rbegin, rend) to empty");
  try {
    std::list<Hoge> lst_std;
    ft::list<Hoge> lst_ft;
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    lst_std.assign(hoge_vec.rbegin(), hoge_vec.rend());
    lst_ft.assign(hoge_vec.rbegin(), hoge_vec.rend());
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list<Hoge>: assign(begin, begin) to empty");
  try {
    std::list<Hoge> lst_std;
    ft::list<Hoge> lst_ft;
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    lst_std.assign(hoge_vec.begin(), hoge_vec.begin());
    lst_ft.assign(hoge_vec.begin(), hoge_vec.begin());
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list<Hoge>: assign(end, end) to empty");
  try {
    std::list<Hoge> lst_std;
    ft::list<Hoge> lst_ft;
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    lst_std.assign(hoge_vec.end(), hoge_vec.end());
    lst_ft.assign(hoge_vec.end(), hoge_vec.end());
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list<Hoge>: assign(begin, ++begin) to empty");
  try {
    std::list<Hoge> lst_std;
    ft::list<Hoge> lst_ft;
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    lst_std.assign(hoge_vec.begin(), ++hoge_vec.begin());
    lst_ft.assign(hoge_vec.begin(), ++hoge_vec.begin());
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no,
              "list<Hoge>: assign(begin, end) -> (begin,begin)->(rbegin,rend) "
              "-> (begin,++begin) -> (begin,end) to empty");
  try {
    std::list<Hoge> lst_std;
    ft::list<Hoge> lst_ft;
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    lst_std.assign(hoge_vec.begin(), hoge_vec.end());
    lst_ft.assign(hoge_vec.begin(), hoge_vec.end());
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }

    lst_std.assign(hoge_vec.begin(), hoge_vec.begin());
    lst_ft.assign(hoge_vec.begin(), hoge_vec.begin());
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }

    lst_std.assign(hoge_vec.rbegin(), hoge_vec.rend());
    lst_ft.assign(hoge_vec.rbegin(), hoge_vec.rend());
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }

    lst_std.assign(hoge_vec.begin(), hoge_vec.begin());
    lst_ft.assign(hoge_vec.begin(), hoge_vec.begin());
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }

    lst_std.assign(hoge_vec.begin(), hoge_vec.end());
    lst_ft.assign(hoge_vec.begin(), hoge_vec.end());
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }

  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  // fill constructor <int>
  putTestInfo(test_no, "list<int>: int(0)");
  try {
    std::list<int> lst_std(0);
    ft::list<int> lst_ft(0);
    std::list<int>::iterator itr_std;
    ft::list<int>::iterator itr_ft;

    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list<int>: int(0, 42)");
  try {
    std::list<int> lst_std(0, 42);
    ft::list<int> lst_ft(0, 42);
    std::list<int>::iterator itr_std;
    ft::list<int>::iterator itr_ft;

    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list<int>: int(1)");
  try {
    std::list<int> lst_std(1);
    ft::list<int> lst_ft(1);
    std::list<int>::iterator itr_std;
    ft::list<int>::iterator itr_ft;

    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list<int>: int(1, 42)");
  try {
    std::list<int> lst_std(1, 42);
    ft::list<int> lst_ft(1, 42);
    std::list<int>::iterator itr_std;
    ft::list<int>::iterator itr_ft;

    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list<int>: int(24)");
  try {
    std::list<int> lst_std(24);
    ft::list<int> lst_ft(24);
    std::list<int>::iterator itr_std;
    ft::list<int>::iterator itr_ft;

    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list<int>: int(24, 42)");
  try {
    std::list<int> lst_std(24, 42);
    ft::list<int> lst_ft(24, 42);
    std::list<int>::iterator itr_std;
    ft::list<int>::iterator itr_ft;

    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  // fill constructor <Hoge>
  putTestInfo(test_no, "list<Hoge>: Hoge(0)");
  try {
    std::list<Hoge> lst_std(0);
    ft::list<Hoge> lst_ft(0);
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list<Hoge>: Hoge(0, hoge[4])");
  try {
    std::list<Hoge> lst_std(0, hoge[4]);
    ft::list<Hoge> lst_ft(0, hoge[4]);
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list<Hoge>: Hoge(1)");
  try {
    std::list<Hoge> lst_std(1);
    ft::list<Hoge> lst_ft(1);
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list<Hoge>: Hoge(1, hoge[4])");
  try {
    std::list<Hoge> lst_std(1, hoge[4]);
    ft::list<Hoge> lst_ft(1, hoge[4]);
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list<Hoge>: Hoge(24)");
  try {
    std::list<Hoge> lst_std(24);
    ft::list<Hoge> lst_ft(24);
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list<Hoge>: Hoge(24, hoge[4])");
  try {
    std::list<Hoge> lst_std(24, hoge[4]);
    ft::list<Hoge> lst_ft(24, hoge[4]);
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  // range constuctor(itr, itr) <int>
  putTestInfo(test_no, "list<int>: list(begin, end)");
  try {
    std::list<int> lst_std(num_vec.begin(), num_vec.end());
    ft::list<int> lst_ft(num_vec.begin(), num_vec.end());
    std::list<int>::iterator itr_std;
    ft::list<int>::iterator itr_ft;

    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list<int>: list(begin, begin)");
  try {
    std::list<int> lst_std(num_vec.begin(), num_vec.begin());
    ft::list<int> lst_ft(num_vec.begin(), num_vec.begin());
    std::list<int>::iterator itr_std;
    ft::list<int>::iterator itr_ft;

    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list<int>: list(rbegin, rend)");
  try {
    std::list<int> lst_std(num_vec.rbegin(), num_vec.rend());
    ft::list<int> lst_ft(num_vec.rbegin(), num_vec.rend());
    std::list<int>::iterator itr_std;
    ft::list<int>::iterator itr_ft;

    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  // range constuctor(ptr, ptr) <int>
  putTestInfo(test_no, "list<int>: list([0], [9])");
  try {
    std::list<int> lst_std(num, &num[9]);
    ft::list<int> lst_ft(num, &num[9]);
    std::list<int>::iterator itr_std;
    ft::list<int>::iterator itr_ft;

    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list<int>: list([4], [4])");
  try {
    std::list<int> lst_std(&num[4], &num[4]);
    ft::list<int> lst_ft(&num[4], &num[4]);
    std::list<int>::iterator itr_std;
    ft::list<int>::iterator itr_ft;

    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  // range constuctor(itr, itr) <Hoge>
  putTestInfo(test_no, "list<Hoge>: list(begin, end)");
  try {
    std::list<Hoge> lst_std(hoge_vec.begin(), hoge_vec.end());
    ft::list<Hoge> lst_ft(hoge_vec.begin(), hoge_vec.end());
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list<Hoge>: list(begin, begin)");
  try {
    std::list<Hoge> lst_std(hoge_vec.begin(), hoge_vec.begin());
    ft::list<Hoge> lst_ft(hoge_vec.begin(), hoge_vec.begin());
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list<Hoge>: list(rbegin, rend)");
  try {
    std::list<Hoge> lst_std(hoge_vec.rbegin(), hoge_vec.rend());
    ft::list<Hoge> lst_ft(hoge_vec.rbegin(), hoge_vec.rend());
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  // copy constructor
  putTestInfo(test_no, "list<Hoge>: copy constructor");
  try {
    std::list<Hoge> lst_std_src(hoge_vec.begin(), hoge_vec.end());
    ft::list<Hoge> lst_ft_src(hoge_vec.begin(), hoge_vec.end());
    std::list<Hoge> lst_std(lst_std_src);
    ft::list<Hoge> lst_ft(lst_ft_src);
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list<Hoge>: copy constructor from empty");
  try {
    std::list<Hoge> lst_std_src;
    ft::list<Hoge> lst_ft_src;
    std::list<Hoge> lst_std(lst_std_src);
    ft::list<Hoge> lst_ft(lst_ft_src);
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  // operator=
  putTestInfo(test_no, "list<Hoge>: lst = lst");
  try {
    std::list<Hoge> lst_std_src;
    ft::list<Hoge> lst_ft_src;
    std::list<Hoge> lst_std;
    ft::list<Hoge> lst_ft;
    lst_std = lst_std_src;
    lst_ft = lst_ft_src;
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list<Hoge>: lst = lst(begin, ++begin)");
  try {
    std::list<Hoge> lst_std_src(hoge_vec.begin(), ++hoge_vec.begin());
    ft::list<Hoge> lst_ft_src(hoge_vec.begin(), ++hoge_vec.begin());
    std::list<Hoge> lst_std;
    ft::list<Hoge> lst_ft;
    lst_std = lst_std_src;
    lst_ft = lst_ft_src;
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list<Hoge>: lst = lst(begin, end)");
  try {
    std::list<Hoge> lst_std_src(hoge_vec.begin(), hoge_vec.end());
    ft::list<Hoge> lst_ft_src(hoge_vec.begin(), hoge_vec.end());
    std::list<Hoge> lst_std;
    ft::list<Hoge> lst_ft;
    lst_std = lst_std_src;
    lst_ft = lst_ft_src;
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list<Hoge>: lst(begin, ++begin) = lst");
  try {
    std::list<Hoge> lst_std_src;
    ft::list<Hoge> lst_ft_src;
    std::list<Hoge> lst_std(hoge_vec.begin(), ++hoge_vec.begin());
    ft::list<Hoge> lst_ft(hoge_vec.begin(), ++hoge_vec.begin());
    lst_std = lst_std_src;
    lst_ft = lst_ft_src;
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list<Hoge>: lst(begin, ++begin) = lst(begin, ++begin)");
  try {
    std::list<Hoge> lst_std_src(hoge_vec.begin(), ++hoge_vec.begin());
    ft::list<Hoge> lst_ft_src(hoge_vec.begin(), ++hoge_vec.begin());
    std::list<Hoge> lst_std(hoge_vec.begin(), ++hoge_vec.begin());
    ft::list<Hoge> lst_ft(hoge_vec.begin(), ++hoge_vec.begin());
    lst_std = lst_std_src;
    lst_ft = lst_ft_src;
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list<Hoge>: lst(begin, ++begin) = lst(begin, end)");
  try {
    std::list<Hoge> lst_std_src(hoge_vec.begin(), hoge_vec.end());
    ft::list<Hoge> lst_ft_src(hoge_vec.begin(), hoge_vec.end());
    std::list<Hoge> lst_std(hoge_vec.begin(), ++hoge_vec.begin());
    ft::list<Hoge> lst_ft(hoge_vec.begin(), ++hoge_vec.begin());
    lst_std = lst_std_src;
    lst_ft = lst_ft_src;
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list<Hoge>: lst(begin, end) = lst");
  try {
    std::list<Hoge> lst_std_src;
    ft::list<Hoge> lst_ft_src;
    std::list<Hoge> lst_std(hoge_vec.begin(), hoge_vec.end());
    ft::list<Hoge> lst_ft(hoge_vec.begin(), hoge_vec.end());
    lst_std = lst_std_src;
    lst_ft = lst_ft_src;
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list<Hoge>: lst(begin, end) = lst(begin, ++begin)");
  try {
    std::list<Hoge> lst_std_src(hoge_vec.begin(), ++hoge_vec.begin());
    ft::list<Hoge> lst_ft_src(hoge_vec.begin(), ++hoge_vec.begin());
    std::list<Hoge> lst_std(hoge_vec.begin(), hoge_vec.end());
    ft::list<Hoge> lst_ft(hoge_vec.begin(), hoge_vec.end());
    lst_std = lst_std_src;
    lst_ft = lst_ft_src;
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list<Hoge>: lst(begin, end) = lst(begin, end)");
  try {
    std::list<Hoge> lst_std_src(hoge_vec.begin(), hoge_vec.end());
    ft::list<Hoge> lst_ft_src(hoge_vec.begin(), hoge_vec.end());
    std::list<Hoge> lst_std(hoge_vec.begin(), hoge_vec.end());
    ft::list<Hoge> lst_ft(hoge_vec.begin(), hoge_vec.end());
    lst_std = lst_std_src;
    lst_ft = lst_ft_src;
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  // insert(pos, val) <int>
  putTestInfo(test_no, "list<int>: insert(begin, 42) to list(rbegin, rbegin)");
  try {
    std::list<int> lst_std(num_vec.rbegin(), num_vec.rbegin());
    ft::list<int> lst_ft(num_vec.rbegin(), num_vec.rbegin());
    std::list<int>::iterator itr_std;
    ft::list<int>::iterator itr_ft;

    itr_std = lst_std.insert(lst_std.begin(), 42);
    itr_ft = lst_ft.insert(lst_ft.begin(), 42);
    if (*itr_std != *itr_ft) {
      throw std::runtime_error("return value");
    }
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list<int>: insert(begin, 42) to list(rbegin,++rbegin)");
  try {
    std::list<int> lst_std(num_vec.rbegin(), ++num_vec.rbegin());
    ft::list<int> lst_ft(num_vec.rbegin(), ++num_vec.rbegin());
    std::list<int>::iterator itr_std;
    ft::list<int>::iterator itr_ft;

    itr_std = lst_std.insert(lst_std.begin(), 42);
    itr_ft = lst_ft.insert(lst_ft.begin(), 42);
    if (*itr_std != *itr_ft) {
      throw std::runtime_error("return value");
    }
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list<int>: insert(begin, 42) to list(rbegin, rend)");
  try {
    std::list<int> lst_std(num_vec.rbegin(), num_vec.rend());
    ft::list<int> lst_ft(num_vec.rbegin(), num_vec.rend());
    std::list<int>::iterator itr_std;
    ft::list<int>::iterator itr_ft;

    itr_std = lst_std.insert(lst_std.begin(), 42);
    itr_ft = lst_ft.insert(lst_ft.begin(), 42);
    if (*itr_std != *itr_ft) {
      throw std::runtime_error("return value");
    }
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list<int>: insert(end, 42) to list(rbegin, rbegin)");
  try {
    std::list<int> lst_std(num_vec.rbegin(), num_vec.rbegin());
    ft::list<int> lst_ft(num_vec.rbegin(), num_vec.rbegin());
    std::list<int>::iterator itr_std;
    ft::list<int>::iterator itr_ft;

    itr_std = lst_std.insert(lst_std.end(), 42);
    itr_ft = lst_ft.insert(lst_ft.end(), 42);
    if (*itr_std != *itr_ft) {
      throw std::runtime_error("return value");
    }
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list<int>: insert(end, 42) to list(rbegin,++rbegin)");
  try {
    std::list<int> lst_std(num_vec.rbegin(), ++num_vec.rbegin());
    ft::list<int> lst_ft(num_vec.rbegin(), ++num_vec.rbegin());
    std::list<int>::iterator itr_std;
    ft::list<int>::iterator itr_ft;

    itr_std = lst_std.insert(lst_std.end(), 42);
    itr_ft = lst_ft.insert(lst_ft.end(), 42);
    if (*itr_std != *itr_ft) {
      throw std::runtime_error("return value");
    }
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list<int>: insert(end, 42) to list(rbegin, rend)");
  try {
    std::list<int> lst_std(num_vec.rbegin(), num_vec.rend());
    ft::list<int> lst_ft(num_vec.rbegin(), num_vec.rend());
    std::list<int>::iterator itr_std;
    ft::list<int>::iterator itr_ft;

    itr_std = lst_std.insert(lst_std.end(), 42);
    itr_ft = lst_ft.insert(lst_ft.end(), 42);
    if (*itr_std != *itr_ft) {
      throw std::runtime_error("return value");
    }
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list<int>: insert(begin + 5, 42) to list(begin, end)");
  try {
    std::list<int> lst_std(num_vec.begin(), num_vec.end());
    ft::list<int> lst_ft(num_vec.begin(), num_vec.end());
    std::list<int>::iterator itr_std;
    ft::list<int>::iterator itr_ft;

    itr_std = lst_std.begin();
    itr_ft = lst_ft.begin();
    for (int n = 0; n < 5; n++) {
      ++itr_std;
      ++itr_ft;
    }
    itr_std = lst_std.insert(itr_std, 42);
    itr_ft = lst_ft.insert(itr_ft, 42);
    if (*itr_std != *itr_ft) {
      throw std::runtime_error("return value");
    }
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  // insert(pos, val) <Hoge>
  putTestInfo(test_no,
              "list<Hoge>: insert(begin, hoge[4]) to list(rbegin, rbegin)");
  try {
    std::list<Hoge> lst_std(hoge_vec.rbegin(), hoge_vec.rbegin());
    ft::list<Hoge> lst_ft(hoge_vec.rbegin(), hoge_vec.rbegin());
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    itr_std = lst_std.insert(lst_std.begin(), hoge[4]);
    itr_ft = lst_ft.insert(lst_ft.begin(), hoge[4]);
    if (*itr_std != *itr_ft) {
      throw std::runtime_error("return value");
    }
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no,
              "list<Hoge>: insert(begin, hoge[4]) to list(rbegin,++rbegin)");
  try {
    std::list<Hoge> lst_std(hoge_vec.rbegin(), ++hoge_vec.rbegin());
    ft::list<Hoge> lst_ft(hoge_vec.rbegin(), ++hoge_vec.rbegin());
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    itr_std = lst_std.insert(lst_std.begin(), hoge[4]);
    itr_ft = lst_ft.insert(lst_ft.begin(), hoge[4]);
    if (*itr_std != *itr_ft) {
      throw std::runtime_error("return value");
    }
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no,
              "list<Hoge>: insert(begin, hoge[4]) to list(rbegin, rend)");
  try {
    std::list<Hoge> lst_std(hoge_vec.rbegin(), hoge_vec.rend());
    ft::list<Hoge> lst_ft(hoge_vec.rbegin(), hoge_vec.rend());
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    itr_std = lst_std.insert(lst_std.begin(), hoge[4]);
    itr_ft = lst_ft.insert(lst_ft.begin(), hoge[4]);
    if (*itr_std != *itr_ft) {
      throw std::runtime_error("return value");
    }
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no,
              "list<Hoge>: insert(end, hoge[4]) to list(rbegin, rbegin)");
  try {
    std::list<Hoge> lst_std(hoge_vec.rbegin(), hoge_vec.rbegin());
    ft::list<Hoge> lst_ft(hoge_vec.rbegin(), hoge_vec.rbegin());
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    itr_std = lst_std.insert(lst_std.end(), hoge[4]);
    itr_ft = lst_ft.insert(lst_ft.end(), hoge[4]);
    if (*itr_std != *itr_ft) {
      throw std::runtime_error("return value");
    }
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no,
              "list<Hoge>: insert(end, hoge[4]) to list(rbegin,++rbegin)");
  try {
    std::list<Hoge> lst_std(hoge_vec.rbegin(), ++hoge_vec.rbegin());
    ft::list<Hoge> lst_ft(hoge_vec.rbegin(), ++hoge_vec.rbegin());
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    itr_std = lst_std.insert(lst_std.end(), hoge[4]);
    itr_ft = lst_ft.insert(lst_ft.end(), hoge[4]);
    if (*itr_std != *itr_ft) {
      throw std::runtime_error("return value");
    }
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no,
              "list<Hoge>: insert(end, hoge[4]) to list(rbegin, rend)");
  try {
    std::list<Hoge> lst_std(hoge_vec.rbegin(), hoge_vec.rend());
    ft::list<Hoge> lst_ft(hoge_vec.rbegin(), hoge_vec.rend());
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    itr_std = lst_std.insert(lst_std.end(), hoge[4]);
    itr_ft = lst_ft.insert(lst_ft.end(), hoge[4]);
    if (*itr_std != *itr_ft) {
      throw std::runtime_error("return value");
    }
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no,
              "list<Hoge>: insert(begin + 5, hoge[4]) to list(begin, end)");
  try {
    std::list<Hoge> lst_std(hoge_vec.begin(), hoge_vec.end());
    ft::list<Hoge> lst_ft(hoge_vec.begin(), hoge_vec.end());
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    itr_std = lst_std.begin();
    itr_ft = lst_ft.begin();
    for (size_t n = 0; n < 5; n++) {
      ++itr_std;
      ++itr_ft;
    }
    itr_std = lst_std.insert(itr_std, hoge[4]);
    itr_ft = lst_ft.insert(itr_ft, hoge[4]);
    if (*itr_std != *itr_ft) {
      throw std::runtime_error("return value");
    }
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  // insert(pos, n, val) <int>
  putTestInfo(test_no,
              "list<int>: insert(begin, 24, 42) to list");
  try {
    std::list<int> lst_std;
    ft::list<int> lst_ft;
    std::list<int>::iterator itr_std;
    ft::list<int>::iterator itr_ft;

    lst_std.insert(lst_std.begin(), 24, 42);
    lst_ft.insert(lst_ft.begin(), 24, 42);
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no,
              "list<int>: insert(++begin, 24, 42) to list");
  try {
    std::list<int> lst_std;
    ft::list<int> lst_ft;
    std::list<int>::iterator itr_std;
    ft::list<int>::iterator itr_ft;

    lst_std.insert(++lst_std.begin(), 24, 42);
    lst_ft.insert(++lst_ft.begin(), 24, 42);
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no,
              "list<int>: insert(end, 24, 42) to list");
  try {
    std::list<int> lst_std(1, 42);
    ft::list<int> lst_ft(1, 42);
    std::list<int>::iterator itr_std;
    ft::list<int>::iterator itr_ft;

    lst_std.insert(lst_std.begin(), 24, 42);
    lst_ft.insert(lst_ft.begin(), 24, 42);
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no,
              "list<int>: insert(begin, 24, 42) to list(1, 42)");
  try {
    std::list<int> lst_std(1, 42);
    ft::list<int> lst_ft(1, 42);
    std::list<int>::iterator itr_std;
    ft::list<int>::iterator itr_ft;

    lst_std.insert(lst_std.begin(), 24, 42);
    lst_ft.insert(lst_ft.begin(), 24, 42);
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no,
              "list<int>: insert(++begin, 24, 42) to list(1, 42)");
  try {
    std::list<int> lst_std(1, 42);
    ft::list<int> lst_ft(1, 42);
    std::list<int>::iterator itr_std;
    ft::list<int>::iterator itr_ft;

    lst_std.insert(++lst_std.begin(), 24, 42);
    lst_ft.insert(++lst_ft.begin(), 24, 42);
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no,
              "list<int>: insert(end, 24, 42) to list(1,42)");
  try {
    std::list<int> lst_std(1, 42);
    ft::list<int> lst_ft(1, 42);
    std::list<int>::iterator itr_std;
    ft::list<int>::iterator itr_ft;

    lst_std.insert(lst_std.begin(), 24, 42);
    lst_ft.insert(lst_ft.begin(), 24, 42);
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no,
              "list<int>: insert(begin, 24, 42) to list(begin, end)");
  try {
    std::list<int> lst_std(num_vec.begin(), num_vec.end());
    ft::list<int> lst_ft(num_vec.begin(), num_vec.end());
    std::list<int>::iterator itr_std;
    ft::list<int>::iterator itr_ft;

    lst_std.insert(lst_std.begin(), 24, 42);
    lst_ft.insert(lst_ft.begin(), 24, 42);
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no,
              "list<int>: insert(end, 24, 42) to list(begin, end)");
  try {
    std::list<int> lst_std(num_vec.begin(), num_vec.end());
    ft::list<int> lst_ft(num_vec.begin(), num_vec.end());
    std::list<int>::iterator itr_std;
    ft::list<int>::iterator itr_ft;

    lst_std.insert(lst_std.end(), 24, 42);
    lst_ft.insert(lst_ft.end(), 24, 42);
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no,
              "list<int>: insert(begin + 5, 24, 42) to list(begin, end)");
  try {
    std::list<int> lst_std(num_vec.begin(), num_vec.end());
    ft::list<int> lst_ft(num_vec.begin(), num_vec.end());
    std::list<int>::iterator itr_std;
    ft::list<int>::iterator itr_ft;

    itr_std = lst_std.begin();
    itr_ft = lst_ft.begin();
    for (size_t n = 0; n < 5; n++) {
      ++itr_std;
      ++itr_ft;
    }
    lst_std.insert(itr_std, 24, 42);
    lst_ft.insert(itr_ft, 24, 42);
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  // insert(pos, n, val) <Hoge>
  putTestInfo(test_no,
              "list<Hoge>: insert(begin, 24, hoge[4]) to list");
  try {
    std::list<Hoge> lst_std;
    ft::list<Hoge> lst_ft;
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    lst_std.insert(lst_std.begin(), 24, hoge[4]);
    lst_ft.insert(lst_ft.begin(), 24, hoge[4]);
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no,
              "list<Hoge>: insert(++begin, 24, hoge[4]) to list");
  try {
    std::list<Hoge> lst_std;
    ft::list<Hoge> lst_ft;
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    lst_std.insert(++lst_std.begin(), 24, hoge[4]);
    lst_ft.insert(++lst_ft.begin(), 24, hoge[4]);
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no,
              "list<Hoge>: insert(end, 24, hoge[4]) to list");
  try {
    std::list<Hoge> lst_std(1, hoge[4]);
    ft::list<Hoge> lst_ft(1, hoge[4]);
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    lst_std.insert(lst_std.begin(), 24, hoge[4]);
    lst_ft.insert(lst_ft.begin(), 24, hoge[4]);
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no,
              "list<Hoge>: insert(begin, 24, hoge[4]) to list(1, hoge[4])");
  try {
    std::list<Hoge> lst_std(1, hoge[4]);
    ft::list<Hoge> lst_ft(1, hoge[4]);
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    lst_std.insert(lst_std.begin(), 24, hoge[4]);
    lst_ft.insert(lst_ft.begin(), 24, hoge[4]);
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no,
              "list<Hoge>: insert(++begin, 24, hoge[4]) to list(1, hoge[4])");
  try {
    std::list<Hoge> lst_std(1, hoge[4]);
    ft::list<Hoge> lst_ft(1, hoge[4]);
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    lst_std.insert(++lst_std.begin(), 24, hoge[4]);
    lst_ft.insert(++lst_ft.begin(), 24, hoge[4]);
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no,
              "list<Hoge>: insert(end, 24, hoge[4]) to list(1,hoge[4])");
  try {
    std::list<Hoge> lst_std(1, hoge[4]);
    ft::list<Hoge> lst_ft(1, hoge[4]);
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    lst_std.insert(lst_std.begin(), 24, hoge[4]);
    lst_ft.insert(lst_ft.begin(), 24, hoge[4]);
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no,
              "list<Hoge>: insert(begin, 24, hoge[4]) to list(begin, end)");
  try {
    std::list<Hoge> lst_std(hoge_vec.begin(), hoge_vec.end());
    ft::list<Hoge> lst_ft(hoge_vec.begin(), hoge_vec.end());
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    lst_std.insert(lst_std.begin(), 24, hoge[4]);
    lst_ft.insert(lst_ft.begin(), 24, hoge[4]);
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no,
              "list<Hoge>: insert(end, 24, hoge[4]) to list(begin, end)");
  try {
    std::list<Hoge> lst_std(hoge_vec.begin(), hoge_vec.end());
    ft::list<Hoge> lst_ft(hoge_vec.begin(), hoge_vec.end());
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    lst_std.insert(lst_std.end(), 24, hoge[4]);
    lst_ft.insert(lst_ft.end(), 24, hoge[4]);
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no,
              "list<Hoge>: insert(begin + 5, 24, hoge[4]) to list(begin, end)");
  try {
    std::list<Hoge> lst_std(hoge_vec.begin(), hoge_vec.end());
    ft::list<Hoge> lst_ft(hoge_vec.begin(), hoge_vec.end());
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    itr_std = lst_std.begin();
    itr_ft = lst_ft.begin();
    for (size_t n = 0; n < 5; n++) {
      ++itr_std;
      ++itr_ft;
    }
    lst_std.insert(itr_std, 24, hoge[4]);
    lst_ft.insert(itr_ft, 24, hoge[4]);
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  return;
}
