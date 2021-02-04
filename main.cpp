/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnakano <dnakano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 10:19:13 by dnakano           #+#    #+#             */
/*   Updated: 2021/02/04 15:10:32 by dnakano          ###   ########.fr       */
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
    std::cout << "=== PASSED ALL TEST ===" << std::endl;
    system("leaks test.out | grep 'total leaked bytes'");
  } catch (std::exception& e) {
    std::cout << ": " << e.what() << std::endl;
    std::cout << "KO :(" << std::endl;
  }
  return 0;
}
