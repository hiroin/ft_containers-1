/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Hoge.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnakano <dnakano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 15:20:56 by dnakano           #+#    #+#             */
/*   Updated: 2021/02/10 13:39:48 by dnakano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOGE_HPP
#define HOGE_HPP

#include <ostream>

class Hoge {
 private:
 public:
  const int idx_;
  int* num_;

  Hoge();
  Hoge(int idx, int num);
  Hoge(const Hoge& ref);
  ~Hoge();
  Hoge& operator=(const Hoge& rhs);
};

bool operator==(const Hoge& lhs, const Hoge& rhs);
bool operator!=(const Hoge& lhs, const Hoge& rhs);
bool operator<(const Hoge& lhs, const Hoge& rhs);
bool operator<=(const Hoge& lhs, const Hoge& rhs);
bool operator>(const Hoge& lhs, const Hoge& rhs);
bool operator>=(const Hoge& lhs, const Hoge& rhs);

// std::ostream& operator<<(std::ostream& out, Bureaucrat const& rhs);
std::ostream& operator<<(std::ostream& out, const Hoge& rhs);

#endif /* HOGE_HPP */
