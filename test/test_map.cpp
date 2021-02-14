/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_map.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnakano <dnakano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 13:37:31 by dnakano           #+#    #+#             */
/*   Updated: 2021/02/14 15:31:32 by dnakano          ###   ########.fr       */
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

  putTestInfo(test_no, "map<int, string>: default construction");
  try {
    std::map<int, std::string> std_map;
    ft::map<int, std::string> ft_map;
  } catch (std::exception& e) {
    throw std::runtime_error("failed");
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "map<int, string>: default construction");
  try {
    std::map<int, std::string> std_map(persons, persons + 10);
    std::map<int, std::string>::iterator std_itr;

    std::cout << std::endl;
    for (std_itr = std_map.begin(); std_itr != std_map.end(); ++std_itr) {
      std::cout << "map[" << (*std_itr).first << "] = " << (*std_itr).second
                << std::endl;
    }
  } catch (std::exception& e) {
    throw std::runtime_error("failed");
  }
  std::cout << " => OK :)" << std::endl;

  return;
}
