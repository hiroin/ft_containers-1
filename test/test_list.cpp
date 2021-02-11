/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_list.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnakano <dnakano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 08:01:31 by dnakano           #+#    #+#             */
/*   Updated: 2021/02/11 10:34:48 by dnakano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>
#include <forward_list>
#include <iostream>
#include <list>
#include <vector>

#include "../list.hpp"
#include "Hoge.hpp"
#include "test.hpp"

void test_list(int& test_no) {
  Hoge hoge[10] = {Hoge(0, 0), Hoge(1, 1), Hoge(2, 2), Hoge(3, 3), Hoge(4, 4),
                   Hoge(5, 5), Hoge(6, 6), Hoge(7, 7), Hoge(8, 8), Hoge(9, 9)};
  std::vector<Hoge> hoge_vec(hoge, &hoge[10]);
  std::list<Hoge> hoge_lst(hoge, &hoge[10]);
  std::forward_list<Hoge> hoge_flst(hoge, &hoge[10]);

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

  return;
}
