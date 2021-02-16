/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnakano <dnakano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 10:16:31 by dnakano           #+#    #+#             */
/*   Updated: 2021/02/17 08:07:47 by dnakano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** this was made for avoid to use __xxx (like __wrap_iter) or anything that
** newer than c++98.
*/

#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include <iterator>

#include "type_traits.hpp"

namespace ft {

/*
** iterator
** base class of ft::iterators
*/

template <class IteratorCategory, class Type, class DifferenceType = ptrdiff_t,
          class Pointer = Type*, class Reference = Type&>
struct iterator {
  typedef Type value_type;
  typedef DifferenceType difference_type;
  typedef Pointer pointer;
  typedef Reference reference;
  typedef IteratorCategory iterator_category;
};

/*
** iterator tags
*/

struct input_iterator_tag {};
struct output_iterator_tag {};
struct forward_iterator_tag : public input_iterator_tag {};
struct bidirectional_iterator_tag : public forward_iterator_tag {};
struct random_access_iterator_tag : public bidirectional_iterator_tag {};

/*
** random_access_iterator_base_
**
** template of iterator class makes an random access iterator which wraps an
** array of type_name_.
*/

template <class type_name_, class distance_ = ptrdiff_t,
          class pointer_ = type_name_*, class reference_ = type_name_&>
class random_access_iterator_base_
    : public ft::iterator<ft::random_access_iterator_tag, type_name_, distance_,
                          pointer_, reference_> {
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

/*
** bidirectional_iterator_tree_
**
** template of iterator class makes an bidirectional access iterator which
** wraps an tree of type_name_.
**
** NOTE: node_pointer_ type should have members below
**  - pointer_* value_: pointer the value is stored
**  - node_poitner_ left_: pointer to left node
**  - node_poitner_ right_: pointer to right node
*/

template <class type_name_, class node_pointer_, class distance_ = ptrdiff_t,
          class pointer_ = type_name_*, class reference_ = type_name_&>
class bidirectional_iterator_tree_
    : public ft::iterator<ft::bidirectional_iterator_tag, type_name_, distance_,
                          pointer_, reference_> {
 private:
  node_pointer_ node_;
  node_pointer_ root_;

 public:
  bidirectional_iterator_tree_() {
    node_ = NULL;
    root_ = NULL;
  }

  bidirectional_iterator_tree_(node_pointer_ node, node_pointer_ root) {
    node_ = node;
    root_ = root;
  }

  bidirectional_iterator_tree_& operator=(
      const bidirectional_iterator_tree_& rhs) {
    node_ = rhs.node_;
    return *this;
  }

  reference_ operator*() const { return *node_->value_; }
  pointer_ operator->() const { return node_->value_; }

  bidirectional_iterator_tree_& operator++() {
    // node_ = node_->left_;
    return *this;
  }

  bidirectional_iterator_tree_ operator++(int) {
    bidirectional_iterator_tree_ tmp(*this);
    // node_ = node_->next_;
    return tmp;
  }

  bidirectional_iterator_tree_& operator--() {
    // node_ = node_->prev_;
    return *this;
  }

  bidirectional_iterator_tree_ operator--(int) {
    bidirectional_iterator_tree_ tmp(*this);
    // node_ = node_->prev_;
    return tmp;
  }

  friend void swap(const bidirectional_iterator_tree_& x,
                   const bidirectional_iterator_tree_& y) {
    bidirectional_iterator_tree_ tmp(x);
    x = y;
    y = tmp;
  }

  friend bool operator==(const bidirectional_iterator_tree_& x,
                         const bidirectional_iterator_tree_& y) {
    return x.node_ == y.node_;
  }

  friend bool operator!=(const bidirectional_iterator_tree_& x,
                         const bidirectional_iterator_tree_& y) {
    return !(x == y);
  }
};

/*
** reverse_itarator
*/

template <class Iterator>
class reverse_iterator {
 protected:
  Iterator normal_;

 public:
  typedef Iterator iterator;
  typedef typename Iterator::value_type value_type;
  typedef typename Iterator::difference_type difference_type;
  typedef typename Iterator::pointer pointer;
  typedef typename Iterator::reference reference;
  typedef typename Iterator::iterator_category iterator_category;

  reverse_iterator() { normal_ = Iterator(); };
  reverse_iterator(const Iterator& ref) : normal_(ref) {}

  template<class Itr>
  reverse_iterator(const reverse_iterator<Itr>& x) : normal_(x.base()) {}

  ~reverse_iterator(){};

  Iterator base() const { return normal_; }

  reverse_iterator& operator=(const reverse_iterator& rhs) {
    normal_ = rhs.normal_;
    return *this;
  }

  reference operator*() const {
    Iterator tmp = normal_;
    return *--tmp;
  }

  pointer operator->() const {
    Iterator tmp = normal_;
    return &(*--tmp);
  }

  reference operator[](difference_type idx) const { return *(*this + idx); }

  reverse_iterator& operator++() {
    --normal_;
    return *this;
  }

  reverse_iterator operator++(int) {
    reverse_iterator tmp(*this);
    ++(*this);
    return tmp;
  }

  reverse_iterator& operator--() {
    ++normal_;
    return *this;
  }

  reverse_iterator operator--(int) {
    reverse_iterator tmp(*this);
    --(*this);
    return tmp;
  }

  reverse_iterator& operator+=(difference_type diff) {
    normal_ -= diff;
    return *this;
  }

  reverse_iterator& operator-=(difference_type diff) {
    normal_ += diff;
    return *this;
  }

  friend reverse_iterator operator+(const reverse_iterator& lhs,
                                    difference_type rhs) {
    return reverse_iterator(lhs.normal_ - rhs);
  }

  friend reverse_iterator operator+(difference_type lhs,
                                    const reverse_iterator& rhs) {
    return reverse_iterator(rhs.normal_ - lhs);
  }

  friend difference_type operator-(const reverse_iterator& lhs,
                                   const reverse_iterator& rhs) {
    return rhs.normal_ - lhs.normal_;
  }

  friend reverse_iterator operator-(const reverse_iterator& lhs,
                                    difference_type rhs) {
    return reverse_iterator(lhs.normal_ + rhs);
  }

  friend reverse_iterator operator-(difference_type lhs,
                                    const reverse_iterator& rhs) {
    return reverse_iterator(rhs.normal_ + lhs);
  }

  friend void swap(const reverse_iterator& x, const reverse_iterator& y) {
    reverse_iterator tmp(x);
    x = y;
    y = tmp;
  }

  friend bool operator==(const reverse_iterator& x, const reverse_iterator& y) {
    return x.normal_ == y.normal_;
  }

  friend bool operator!=(const reverse_iterator& x, const reverse_iterator& y) {
    return !(x == y);
  }

  friend bool operator<(const reverse_iterator& x, const reverse_iterator& y) {
    return x.normal_ > y.normal_;
  }

  friend bool operator<=(const reverse_iterator& x, const reverse_iterator& y) {
    return !(x > y);
  }

  friend bool operator>(const reverse_iterator& x, const reverse_iterator& y) {
    return x.normal_ < y.normal_;
  }

  friend bool operator>=(const reverse_iterator& x, const reverse_iterator& y) {
    return !(x < y);
  }
};

// template <class ReverseIterator>
// class const_reverse_iterator {
//  protected:
//   ReverseIterator rev_;

//  public:
//   typedef typename Iterator::value_type value_type;
//   typedef typename Iterator::difference_type difference_type;
//   typedef const value_type* pointer;
//   typedef const value_type& reference;
//   typedef const typename Iterator::reference reference;
//   typedef typename Iterator::iterator_category iterator_category;

//   Iterator::normal_;

//   const_reverse_iterator() { normal_ = Iterator(); };
//   const_reverse_iterator(const ReverseIterator& x) normal_(x.normal_) {
//     normal_ = x.normal_;
//   }

//   const_reverse_iterator(const const_reverse_iterator& x) { *this = x; }
//   ~const_reverse_iterator(){};

//   const_reverse_iterator& operator=(const const_reverse_iterator& rhs) {
//     normal_ = rhs.normal_;
//     return *this;
//   }

//   reference operator*() const {
//     Iterator tmp = normal_;
//     return *--tmp;
//   }

//   pointer operator->() const {
//     Iterator tmp = normal_;
//     return &(*--tmp);
//   }

//   reference operator[](difference_type idx) const { return *(*this + idx); }

//   const_reverse_iterator& operator++() {
//     --normal_;
//     return *this;
//   }

//   const_reverse_iterator operator++(int) {
//     const_reverse_iterator tmp(*this);
//     ++(*this);
//     return tmp;
//   }

//   const_reverse_iterator& operator--() {
//     ++normal_;
//     return *this;
//   }

//   const_reverse_iterator operator--(int) {
//     const_reverse_iterator tmp(*this);
//     --(*this);
//     return tmp;
//   }

//   const_reverse_iterator& operator+=(difference_type diff) {
//     normal_ -= diff;
//     return *this;
//   }

//   const_reverse_iterator& operator-=(difference_type diff) {
//     normal_ += diff;
//     return *this;
//   }

//   friend const_reverse_iterator operator+(const const_reverse_iterator& lhs,
//                                           difference_type rhs) {
//     return const_reverse_iterator(lhs.normal_ - rhs);
//   }

//   friend const_reverse_iterator operator+(difference_type lhs,
//                                           const const_reverse_iterator& rhs) {
//     return const_reverse_iterator(rhs.normal_ - lhs);
//   }

//   friend difference_type operator-(const const_reverse_iterator& lhs,
//                                    const const_reverse_iterator& rhs) {
//     return rhs.normal_ - lhs.normal_;
//   }

//   friend const_reverse_iterator operator-(const const_reverse_iterator& lhs,
//                                           difference_type rhs) {
//     return const_reverse_iterator(lhs.normal_ + rhs);
//   }

//   friend const_reverse_iterator operator-(difference_type lhs,
//                                           const const_reverse_iterator& rhs) {
//     return const_reverse_iterator(rhs.normal_ + lhs);
//   }

//   friend void swap(const const_reverse_iterator& x,
//                    const const_reverse_iterator& y) {
//     const_reverse_iterator tmp(x);
//     x = y;
//     y = tmp;
//   }

//   friend bool operator==(const const_reverse_iterator& x,
//                          const const_reverse_iterator& y) {
//     return x.normal_ == y.normal_;
//   }

//   friend bool operator!=(const const_reverse_iterator& x,
//                          const const_reverse_iterator& y) {
//     return !(x == y);
//   }

//   friend bool operator<(const const_reverse_iterator& x,
//                         const const_reverse_iterator& y) {
//     return x.normal_ > y.normal_;
//   }

//   friend bool operator<=(const const_reverse_iterator& x,
//                          const const_reverse_iterator& y) {
//     return !(x > y);
//   }

//   friend bool operator>(const const_reverse_iterator& x,
//                         const const_reverse_iterator& y) {
//     return x.normal_ < y.normal_;
//   }

//   friend bool operator>=(const const_reverse_iterator& x,
//                          const const_reverse_iterator& y) {
//     return !(x < y);
//   }
// };

// template <class Iterator, class Reverse>
// class const_reverse_iterator {
//  protected:
//   Iterator normal_;

//  public:
//   typedef typename Iterator::value_type value_type;
//   typedef typename Iterator::difference_type difference_type;
//   typedef const typename Iterator::value_type* pointer;
//   typedef const typename Iterator::value_type& reference;
//   typedef typename Iterator::iterator_category iterator_category;

//   const_reverse_iterator() { normal_ = Iterator(); };
//   const_reverse_iterator(const Iterator& x) : normal_(x) {}
//   const_reverse_iterator(const const_reverse_iterator& x)
//       : normal_(x.normal_) {}
//   const_reverse_iterator(const reverse_iterator& x)
//       : normal_(x.normal_) {}
//   ~const_reverse_iterator(){};

//   const_reverse_iterator& operator=(const const_reverse_iterator& rhs) {
//     normal_ = rhs.normal_;
//     return *this;
//   }

//   reference operator*() const {
//     Iterator tmp = normal_;
//     return *--tmp;
//   }

//   pointer operator->() const {
//     Iterator tmp = normal_;
//     return &(*--tmp);
//   }

//   reference operator[](difference_type idx) const { return *(*this + idx); }

//   const_reverse_iterator& operator++() {
//     --normal_;
//     return *this;
//   }

//   const_reverse_iterator operator++(int) {
//     const_reverse_iterator tmp(*this);
//     ++(*this);
//     return tmp;
//   }

//   const_reverse_iterator& operator--() {
//     ++normal_;
//     return *this;
//   }

//   const_reverse_iterator operator--(int) {
//     const_reverse_iterator tmp(*this);
//     --(*this);
//     return tmp;
//   }

//   const_reverse_iterator& operator+=(difference_type diff) {
//     normal_ -= diff;
//     return *this;
//   }

//   const_reverse_iterator& operator-=(difference_type diff) {
//     normal_ += diff;
//     return *this;
//   }

//   friend const_reverse_iterator operator+(const const_reverse_iterator& lhs,
//                                           difference_type rhs) {
//     return const_reverse_iterator(lhs.normal_ - rhs);
//   }

//   friend const_reverse_iterator operator+(difference_type lhs,
//                                           const const_reverse_iterator& rhs)
//                                           {
//     return const_reverse_iterator(rhs.normal_ - lhs);
//   }

//   friend difference_type operator-(const const_reverse_iterator& lhs,
//                                    const const_reverse_iterator& rhs) {
//     return rhs.normal_ - lhs.normal_;
//   }

//   friend const_reverse_iterator operator-(const const_reverse_iterator& lhs,
//                                           difference_type rhs) {
//     return const_reverse_iterator(lhs.normal_ + rhs);
//   }

//   friend const_reverse_iterator operator-(difference_type lhs,
//                                           const const_reverse_iterator& rhs)
//                                           {
//     return const_reverse_iterator(rhs.normal_ + lhs);
//   }

//   friend void swap(const const_reverse_iterator& x,
//                    const const_reverse_iterator& y) {
//     const_reverse_iterator tmp(x);
//     x = y;
//     y = tmp;
//   }

// friend bool operator==(const const_reverse_iterator& x,
//                        const const_reverse_iterator& y) {
//   return x.normal_ == y.normal_;
// }

// friend bool operator!=(const const_reverse_iterator& x,
//                        const const_reverse_iterator& y) {
//   return !(x == y);
// }

// friend bool operator<(const const_reverse_iterator& x,
//                       const const_reverse_iterator& y) {
//   return x.normal_ > y.normal_;
// }

// friend bool operator<=(const const_reverse_iterator& x,
//                        const const_reverse_iterator& y) {
//   return !(x > y);
// }

// friend bool operator>(const const_reverse_iterator& x,
//                       const const_reverse_iterator& y) {
//   return x.normal_ < y.normal_;
// }

// friend bool operator>=(const const_reverse_iterator& x,
//                        const const_reverse_iterator& y) {
//   return !(x < y);
// }
// };

template <class InputIterator, typename = void>
struct is_input_iterator : public ft::false_type {};

template <class InputIterator>
struct is_input_iterator<
    InputIterator,
    typename ft::enable_if<
        ft::is_same<std::input_iterator_tag,
                    typename InputIterator::iterator_category>::value ||
            ft::is_same<std::forward_iterator_tag,
                        typename InputIterator::iterator_category>::value ||
            ft::is_same<std::bidirectional_iterator_tag,
                        typename InputIterator::iterator_category>::value ||
            ft::is_same<std::random_access_iterator_tag,
                        typename InputIterator::iterator_category>::value ||
            ft::is_same<ft::input_iterator_tag,
                        typename InputIterator::iterator_category>::value ||
            ft::is_same<ft::forward_iterator_tag,
                        typename InputIterator::iterator_category>::value ||
            ft::is_same<ft::bidirectional_iterator_tag,
                        typename InputIterator::iterator_category>::value ||
            ft::is_same<ft::random_access_iterator_tag,
                        typename InputIterator::iterator_category>::value,
        void>::type> : public ft::true_type {};

template <class InputIterator>
struct is_input_iterator<
    InputIterator,
    typename ft::enable_if<ft::is_pointer<InputIterator>::value, void>::type>
    : public ft::true_type {};

}  // namespace ft

#endif /* ITERATOR_HPP */
