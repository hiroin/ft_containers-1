/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnakano <dnakano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 21:11:44 by dnakano           #+#    #+#             */
/*   Updated: 2021/01/31 20:27:50 by dnakano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void putTestInfo(int& test_no, const std::string& outline);

void test_vector(int& test_no);

template <typename T>
void divByTwo(T& n) {
  n = n / 2;
}
