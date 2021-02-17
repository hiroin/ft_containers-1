/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnakano <dnakano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 21:11:44 by dnakano           #+#    #+#             */
/*   Updated: 2021/02/17 16:43:05 by dnakano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_HPP
#define TEST_HPP

#include "Hoge.hpp"

void putTestInfo(int& test_no, const std::string& outline);

void test_vector(int& test_no);
void test_list(int& test_no);
void test_map(int& test_no);
void test_stack(int& test_no);

template <typename T>
void divByTwo(T& n) {
  n = n / 2;
}

bool is_even(const int& value);

struct is_odd {
  bool operator()(const int& value) { return (value % 2) == 1; }
};

#endif /* TEST_HPP */
