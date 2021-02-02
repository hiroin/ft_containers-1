/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnakano <dnakano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 10:16:31 by dnakano           #+#    #+#             */
/*   Updated: 2021/02/02 16:03:07 by dnakano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** this was made for avoid to use __xxx (like __wrap_iter) or anything that
** newer than c++98.
*/

#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include <iterator>

namespace ft {

/*
** random_access_iterator_base_
**
** template of iterator class makes an random access iterator which wraps an
** array of type_name_.
*/

template <class type_name_, class distance_ = ptrdiff_t,
          class pointer_ = type_name_*, class reference_ = type_name_&>
class random_access_iterator_base_
    : public std::iterator<std::random_access_iterator_tag, type_name_,
                           distance_, pointer_, reference_> {
 private:
  // pointer to data
  pointer_ ptr_;

 public:
  random_access_iterator_base_() { ptr_ = NULL; };

  random_access_iterator_base_(pointer_ ptr) { ptr_ = ptr; }

  random_access_iterator_base_(const random_access_iterator_base_& x) {
    *this = x;
  }

  ~random_access_iterator_base_(){};

  random_access_iterator_base_& operator=(
      const random_access_iterator_base_& rhs) {
    ptr_ = rhs.ptr_;
    return *this;
  }

  reference_ operator*() const { return *ptr_; }
  pointer_ operator->() const { return ptr_; }
  reference_ operator[](distance_ idx) const { return *(ptr_ + idx); }

  random_access_iterator_base_& operator++() {
    ++ptr_;
    return *this;
  }

  random_access_iterator_base_ operator++(int) {
    random_access_iterator_base_ tmp(*this);
    ++ptr_;
    return tmp;
  }

  random_access_iterator_base_& operator--() {
    --ptr_;
    return *this;
  }

  random_access_iterator_base_ operator--(int) {
    random_access_iterator_base_ tmp(*this);
    --ptr_;
    return tmp;
  }

  random_access_iterator_base_& operator+=(distance_ diff) {
    ptr_ += diff;
    return *this;
  }

  random_access_iterator_base_& operator-=(distance_ diff) {
    ptr_ -= diff;
    return *this;
  }

  friend random_access_iterator_base_ operator+(
      const random_access_iterator_base_& lhs, distance_ rhs) {
    return random_access_iterator_base_(lhs.ptr_ + rhs);
  }

  friend random_access_iterator_base_ operator+(
      distance_ lhs, const random_access_iterator_base_& rhs) {
    return random_access_iterator_base_(rhs.ptr_ + lhs);
  }

  friend distance_ operator-(const random_access_iterator_base_& lhs,
                             const random_access_iterator_base_& rhs) {
    return lhs.ptr_ - rhs.ptr_;
  }

  friend random_access_iterator_base_ operator-(
      const random_access_iterator_base_& lhs, distance_ rhs) {
    return random_access_iterator_base_(lhs.ptr_ - rhs);
  }

  friend random_access_iterator_base_ operator-(
      distance_ lhs, const random_access_iterator_base_& rhs) {
    return random_access_iterator_base_(rhs.ptr_ - lhs);
  }

  friend void swap(const random_access_iterator_base_& x,
                   const random_access_iterator_base_& y) {
    random_access_iterator_base_ tmp(x);
    x = y;
    y = tmp;
  }

  friend bool operator==(const random_access_iterator_base_& x,
                         const random_access_iterator_base_& y) {
    return x.ptr_ == y.ptr_;
  }

  friend bool operator!=(const random_access_iterator_base_& x,
                         const random_access_iterator_base_& y) {
    return !(x == y);
  }

  friend bool operator<(const random_access_iterator_base_& x,
                        const random_access_iterator_base_& y) {
    return x.ptr_ < y.ptr_;
  }

  friend bool operator<=(const random_access_iterator_base_& x,
                         const random_access_iterator_base_& y) {
    return x.ptr_ <= y.ptr_;
  }

  friend bool operator>(const random_access_iterator_base_& x,
                        const random_access_iterator_base_& y) {
    return x.ptr_ > y.ptr_;
  }

  friend bool operator>=(const random_access_iterator_base_& x,
                         const random_access_iterator_base_& y) {
    return x.ptr_ >= y.ptr_;
  }
};

}  // namespace ft

#endif /* ITERATOR_HPP */
