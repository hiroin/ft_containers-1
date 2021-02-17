/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnakano <dnakano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 16:11:40 by dnakano           #+#    #+#             */
/*   Updated: 2021/02/17 17:17:13 by dnakano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
#define STACK_HPP

#include "list.hpp"

namespace ft {

template <class T, class Container = ft::list<T> >
class stack {
  /*** type definition ***/
 public:
  typedef T value_type;
  typedef Container container_type;
  typedef typename container_type::size_type size_type;

  /*** member vairiables ***/
 protected:
  container_type c;

  /*** constructors ***/
 public:
  explicit stack(const container_type& ctnr = container_type()) : c(ctnr) {}

  /*** member functions ***/
  bool empty() const { return c.empty(); }
  size_type size() const { return c.size(); }
  value_type& top() { return c.top(); }
  const value_type& top() const { return c.top(); }
  void push(const value_type& val) { c.push_back(val); }
  void pop() { c.pop_back(); }

  /*** non member operator overloads ***/
  friend bool operator==(const stack<T, Container>& lhs,
                         const stack<T, Container>& rhs) {
    return lhs.c == rhs.c;
  }

  friend bool operator!=(const stack<T, Container>& lhs,
                         const stack<T, Container>& rhs) {
    return lhs.c != rhs.c;
  }

  friend bool operator<(const stack<T, Container>& lhs,
                         const stack<T, Container>& rhs) {
    return lhs.c < rhs.c;
  }

  friend bool operator<=(const stack<T, Container>& lhs,
                         const stack<T, Container>& rhs) {
    return lhs.c <= rhs.c;
  }

  friend bool operator>(const stack<T, Container>& lhs,
                         const stack<T, Container>& rhs) {
    return lhs.c > rhs.c;
  }

  friend bool operator>=(const stack<T, Container>& lhs,
                         const stack<T, Container>& rhs) {
    return lhs.c >= rhs.c;
  }
};

}  // namespace ft

#endif /* STACK_HPP */
