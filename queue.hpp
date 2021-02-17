/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnakano <dnakano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 17:46:07 by dnakano           #+#    #+#             */
/*   Updated: 2021/02/17 18:03:18 by dnakano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUEUE_HPP
#define QUEUE_HPP

#include "list.hpp"

namespace ft {

template <class T, class Container = list<T> >
class queue {
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
  explicit queue(const container_type& ctnr = container_type()) : c(ctnr) {}

 public:
  bool empty() const { return c.empty(); }
  size_type size() const { return c.size(); }
  value_type& front() { return c.front(); }
  const value_type& front() const { return c.front(); };
  value_type& back() { return c.back(); }
  const value_type& back() const { return c.back(); };
  void push(const value_type& val) { c.push_back(val); }
  void pop() { c.pop_front(); }

  /*** non member operator overloads ***/
  friend bool operator==(const queue<T, Container>& lhs,
                         const queue<T, Container>& rhs) {
    return lhs.c == rhs.c;
  }

  friend bool operator!=(const queue<T, Container>& lhs,
                         const queue<T, Container>& rhs) {
    return lhs.c != rhs.c;
  }

  friend bool operator<(const queue<T, Container>& lhs,
                         const queue<T, Container>& rhs) {
    return lhs.c < rhs.c;
  }

  friend bool operator<=(const queue<T, Container>& lhs,
                         const queue<T, Container>& rhs) {
    return lhs.c <= rhs.c;
  }

  friend bool operator>(const queue<T, Container>& lhs,
                         const queue<T, Container>& rhs) {
    return lhs.c > rhs.c;
  }

  friend bool operator>=(const queue<T, Container>& lhs,
                         const queue<T, Container>& rhs) {
    return lhs.c >= rhs.c;
  }
};

}  // namespace ft

#endif /* QUEUE_HPP */
