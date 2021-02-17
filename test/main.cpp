/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnakano <dnakano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 10:19:13 by dnakano           #+#    #+#             */
/*   Updated: 2021/02/17 16:52:48 by dnakano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <memory>
#include <vector>
#include <exception>
#include <iostream>
#include <cstdlib>
#include "test.hpp"

int main() {
  int test_no;

  test_no = 0;
  try {
    test_vector(test_no);
    test_list(test_no);
    test_map(test_no);
    test_stack(test_no);
    std::cout << "=== PASSED ALL TEST ===" << std::endl;
  } catch (std::exception& e) {
    std::cout << ": " << e.what() << std::endl;
    std::cout << "KO :(" << std::endl;
  }
  system("leaks test.out | grep 'total leaked bytes'");
  return 0;
}
