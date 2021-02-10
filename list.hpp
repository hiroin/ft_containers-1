/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnakano <dnakano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 08:11:53 by dnakano           #+#    #+#             */
/*   Updated: 2021/02/10 11:59:07 by dnakano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** This file is re-impremantation of std::list<T> as ft::list<T>.
** Supports only C++98 features.
**
** References
** - 42 cursus subject
** - http://www.cplusplus.com/reference/list/list/
** - https://cpprefjp.github.io/reference/list/list.html
*/

#ifndef LIST_HPP
#define LIST_HPP

#include <iterator>
#include <memory>

#include "algorithm.hpp"
#include "iterator.hpp"
#include "type_traits.hpp"

namespace ft {

template <class T, class Allocator = std::allocator<T> >
class list {
 public:
  /*** member type definitions ***/
  typedef T value_type;
  typedef Allocator allocator_type;
  typedef typename allocator_type::reference reference;
  typedef typename allocator_type::const_reference const_reference;
  typedef typename allocator_type::pointer pointer;
  typedef typename allocator_type::const_pointer const_pointer;
  typedef typename allocator_type::size_type size_type;
  typedef typename allocator_type::difference_type difference_type;

 private:
  /*** node ***/
  class Node_ {
   public:
    pointer value_;
    Node_* prev_;
    Node_* next_;

    Node_() {
      value_ = NULL;
      prev_ = this;
      next_ = this;
    }

    Node_(pointer val_ptr, Node_* prev, Node_* next) {
      value_ = val_ptr;
      prev_ = prev;
      next_ = next;
    }

    ~Node_() {};
  };

  /*** private attributes ***/
  allocator_type alloc_;
  Node_* head_;

  /*** private functions ***/
  pointer cloneVal_(const value_type& val) {
    // pointer val_ptr;
    pointer val_ptr = alloc_.allocate(1);
    alloc_.construct(val_ptr, val);
    return val_ptr;
  }

  Node_* delOneNode_(Node_* node) {
    Node_* next = node->next_;
    alloc_.destroy(node->value_);
    alloc_.deallocate(node->value_, 1);
    delete node;
    return next;
  }

  void allClear_() {
    Node_* node = head_->next_;
    while (node != head_) {
      node = delOneNode_(node);
    }
    delete head_;
  }

 public:
  /*** constructor ***/
  // default constructor
  explicit list(const allocator_type& alloc = allocator_type()) {
    head_ = new Node_;
    alloc_ = alloc;
  }

  ~list() {
    allClear_();
  }

  /*** Element access ***/
  reference front() { return *head_->next_->value_; }
  const_reference front() const { return *head_->next_->value_; };

  reference back() {
    Node_ *node = head_;
    while (head_ != node->next_) {
      node = node->next_;
    }
    return *node->value_;
  }

  const_reference back() const {
    Node_ *node = head_;
    while (head_ != node->next_) {
      node = node->next_;
    }
    return *node->value_;
  }

  /*** Modifier ***/
  void push_front(const value_type& val) {
    pointer val_ptr = cloneVal_(val);
    head_->next_ = new Node_(val_ptr, head_, head_->next_);
  }
};

}  // namespace ft

#endif /* LIST_HPP */
