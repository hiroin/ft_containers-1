/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_map.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnakano <dnakano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 13:37:31 by dnakano           #+#    #+#             */
/*   Updated: 2021/02/15 12:04:39 by dnakano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <exception>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <utility>

#include "../map.hpp"
#include "Hoge.hpp"
#include "test.hpp"

void test_map(int& test_no) {
  std::cout << "=== TEST MAP ===" << std::endl;
  std::pair<int, std::string> persons[10] = {
      std::pair<int, std::string>(7, "dnakano"),
      std::pair<int, std::string>(2, "nop"),
      std::pair<int, std::string>(4, "bunjiro"),
      std::pair<int, std::string>(0, "deedee"),
      std::pair<int, std::string>(9, "sataharu"),
      std::pair<int, std::string>(8, "marvin"),
      std::pair<int, std::string>(5, "hoge"),
      std::pair<int, std::string>(1, "fuga"),
      std::pair<int, std::string>(6, "foobar"),
      std::pair<int, std::string>(3, "norminette")};

  std::pair<Hoge, Hoge> hoges[10] = {
      std::pair<Hoge, Hoge>(Hoge(0, 7), Hoge(0, 0)),
      std::pair<Hoge, Hoge>(Hoge(1, 2), Hoge(1, 1)),
      std::pair<Hoge, Hoge>(Hoge(2, 4), Hoge(2, 2)),
      std::pair<Hoge, Hoge>(Hoge(3, 0), Hoge(3, 3)),
      std::pair<Hoge, Hoge>(Hoge(4, 9), Hoge(4, 4)),
      std::pair<Hoge, Hoge>(Hoge(5, 8), Hoge(5, 5)),
      std::pair<Hoge, Hoge>(Hoge(6, 5), Hoge(6, 6)),
      std::pair<Hoge, Hoge>(Hoge(7, 1), Hoge(7, 7)),
      std::pair<Hoge, Hoge>(Hoge(8, 6), Hoge(8, 8)),
      std::pair<Hoge, Hoge>(Hoge(9, 3), Hoge(9, 9))};

  putTestInfo(test_no, "map<int, string>: default construction");
  try {
    std::map<int, std::string> std_map;
    ft::map<int, std::string> ft_map;
  } catch (std::exception& e) {
    throw std::runtime_error("failed");
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "map<int, string>: insert to map(0)");
  try {
    std::map<int, std::string> std_map;
    ft::map<int, std::string> ft_map;

    std_map.insert(persons[0]);
    ft_map.insert(persons[0]);
    if (std_map[7] != ft_map[7]) {
      throw std::runtime_error("value");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "map<int, string>: insert 2 to map(0)");
  try {
    std::map<int, std::string> std_map;
    ft::map<int, std::string> ft_map;

    std_map.insert(persons[0]);
    ft_map.insert(persons[0]);
    std_map.insert(persons[1]);
    ft_map.insert(persons[1]);
    if (std_map[7] != ft_map[7]) {
      throw std::runtime_error("value");
    }
    if (std_map[2] != ft_map[2]) {
      throw std::runtime_error("value");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "map<int, string>: insert 10 to map(0)");
  try {
    std::map<int, std::string> std_map;
    ft::map<int, std::string> ft_map;

    for (int i = 0; i < 10; i++) {
      std_map.insert(persons[i]);
      ft_map.insert(persons[i]);
    }
    for (int i = 0; i < 10; i++) {
      if (std_map[i] != ft_map[i]) {
        throw std::runtime_error("value");
      }
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  return ;

  putTestInfo(test_no, "map<int, string>: fill construction(10)");
  try {
    std::map<int, std::string> std_map(persons, persons + 10);
    std::map<int, std::string>::iterator std_itr;

    std::cout << std::endl;
    for (std_itr = std_map.begin(); std_itr != std_map.end(); ++std_itr) {
      std::cout << "map[" << (*std_itr).first << "] = " << (*std_itr).second
                << std::endl;
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "map<Hoge, Hoge>: fill construction(10)");
  try {
    std::map<Hoge, Hoge> std_map(hoges, hoges + 10);
    std::map<Hoge, Hoge>::iterator std_itr;

    std::cout << std::endl;
    for (std_itr = std_map.begin(); std_itr != std_map.end(); ++std_itr) {
      std::cout << "map[" << (*std_itr).first << "] = " << (*std_itr).second
                << std::endl;
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "map<Hoge, Hoge>: fill construction(10)");
  try {
    std::map<Hoge, Hoge> std_map(hoges, hoges + 10);
    std::map<Hoge, Hoge>::iterator std_itr;

    std_map[Hoge(1, 1)] = Hoge(-1, -1);
    std::cout << std::endl;
    for (std_itr = std_map.begin(); std_itr != std_map.end(); ++std_itr) {
      std::cout << "map[" << (*std_itr).first << "] = " << (*std_itr).second
                << std::endl;
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  return;
}
