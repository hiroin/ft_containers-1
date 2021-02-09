/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnakano <dnakano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 21:11:44 by dnakano           #+#    #+#             */
/*   Updated: 2021/02/04 15:47:04 by dnakano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_HPP
#define TEST_HPP

#include "Hoge.hpp"

void putTestInfo(int& test_no, const std::string& outline);

void test_vector(int& test_no);

template <typename T>
void divByTwo(T& n) {
  n = n / 2;
}

#endif /* TEST_HPP */
