/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnakano <dnakano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 08:11:53 by dnakano           #+#    #+#             */
/*   Updated: 2021/02/11 09:18:59 by dnakano          ###   ########.fr       */
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

// lineked list class template
template <class Pointer>
struct ListNode {
  Pointer value_;
  ListNode* prev_;
  ListNode* next_;

  ListNode() {
    value_ = NULL;
    prev_ = this;
    next_ = this;
  }

  ListNode(Pointer value, ListNode* prev, ListNode* next) {
    value_ = value;
    prev_ = prev;
    next_ = next;
  }

  ~ListNode(){};
};

template <class T, class Allocator = std::allocator<T> >
class list {
  /*** member type definitions ***/
 public:
  typedef T value_type;
  typedef Allocator allocator_type;
  typedef typename allocator_type::reference reference;
  typedef typename allocator_type::const_reference const_reference;
  typedef typename allocator_type::pointer pointer;
  typedef typename allocator_type::const_pointer const_pointer;
  typedef typename allocator_type::size_type size_type;
  typedef typename allocator_type::difference_type difference_type;
 private:
  typedef ListNode<pointer> node_type;
  typedef node_type* node_pointer;

 private:
  /*** private attributes ***/
  allocator_type alloc_;
  node_pointer head_;

  /*** private functions ***/
  pointer cloneVal_(const value_type& val) {
    // pointer val_ptr;
    pointer val_ptr = alloc_.allocate(1);
    alloc_.construct(val_ptr, val);
    return val_ptr;
  }

  node_pointer lastnode_type() {
    node_pointer node = head_;
    while (head_ != node->next_) {
      node = node->next_;
    }
    return node;
  }

  node_pointer delOnenode_type(node_pointer node) {
    node_pointer next = node->next_;
    alloc_.destroy(node->value_);
    alloc_.deallocate(node->value_, 1);
    delete node;
    return next;
  }

  void allClear_() {
    node_pointer node = head_->next_;
    while (node != head_) {
      node = delOnenode_type(node);
    }
    delete head_;
  }

 public:
  /*** constructor ***/
  // default constructor
  explicit list(const allocator_type& alloc = allocator_type()) {
    head_ = new node_type;
    alloc_ = alloc;
  }

  ~list() { allClear_(); }

  /*** capacity ***/
  size_type size() const {
    node_pointer node = head_;
    size_type cnt = 0;
    while (head_ != node->next_) {
      node = node->next_;
      ++cnt;
    }
    return cnt;
  }

  bool empty() const { return head_ == head_->next_; }

  size_type max_size() const {
    // I don't know why "/2"
    return alloc_.max_size() / 2;
  }

  /*** Element access ***/
  reference front() { return *head_->next_->value_; }
  const_reference front() const { return *head_->next_->value_; };
  reference back() { return *lastnode_type()->value_; }
  const_reference back() const { return *lastnode_type()->value_; }

  /*** Modifier ***/
  void push_front(const value_type& val) {
    pointer val_ptr = cloneVal_(val);
    node_pointer new_node = new node_type(val_ptr, head_, head_->next_);
    head_->next_->prev_ = new_node;
    head_->next_ = new_node;
  }

  void push_back(const value_type& val) {
    pointer val_ptr = cloneVal_(val);
    node_pointer new_node = new node_type(val_ptr, head_->prev_, head_);
    head_->prev_->next_ = new_node;
    head_->prev_ = new_node;
  }

  void pop_front() {
    head_->next_ = delOnenode_type(head_->next_);
    head_->next_->prev_ = head_;
  }

  void pop_back() {
    node_pointer new_last_node = head_->prev_->prev_;
    new_last_node->next_ = delOnenode_type(head_->prev_);
    head_->prev_ = new_last_node;
  }
};

}  // namespace ft

#endif /* LIST_HPP */
