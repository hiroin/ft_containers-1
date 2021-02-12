/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnakano <dnakano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 08:11:53 by dnakano           #+#    #+#             */
/*   Updated: 2021/02/12 13:00:59 by dnakano          ###   ########.fr       */
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

  /*** iterators ***/
 public:
  typedef bidirectional_iterator_<value_type, node_pointer, difference_type,
                                  pointer, reference>
      iterator;
  typedef bidirectional_iterator_<const value_type, node_pointer,
                                  difference_type, pointer, reference>
      const_iterator;
  typedef ft::reverse_iterator<iterator> reverse_iterator;
  typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;

 private:
  /*** private attributes ***/
  allocator_type alloc_;
  node_pointer head_;

  /*** private functions ***/
  pointer cloneVal_(const value_type& val) {
    pointer val_ptr = alloc_.allocate(1);
    alloc_.construct(val_ptr, val);
    return val_ptr;
  }

  node_pointer delOnenode_type(node_pointer node) {
    node_pointer next = node->next_;
    alloc_.destroy(node->value_);
    alloc_.deallocate(node->value_, 1);
    delete node;
    return next;
  }

  node_pointer findNodeFromIterator_(const iterator& itr) const {
    node_pointer node = head_->next_;
    while (node->value_ != &(*itr) && node != head_) {
      node = node->next_;
    }
    return node;
  }

  void allClear_() {
    clear();
    delete head_;
  }

 public:
  /*** constructor ***/
  // default constructor
  explicit list(const allocator_type& alloc = allocator_type()) {
    head_ = new node_type;
    alloc_ = alloc;
  }

  // fill construtcor
  explicit list(size_type n, const value_type& val = value_type(),
                const allocator_type& alloc = allocator_type()) {
    head_ = new node_type;
    alloc_ = alloc;
    assign(n, val);
  }

  // range construtcor
  template <class InputIterator>
  list(InputIterator first,
       typename ft::enable_if<ft::is_input_iterator<InputIterator>::value,
                              InputIterator>::type last,
       const allocator_type& alloc = allocator_type()) {
    head_ = new node_type;
    alloc_ = alloc;
    assign(first, last);
  }

  // copy constructor
  list(const list& x) {
    head_ = new node_type;
    alloc_ = x.alloc_;
    *this = x;
  }

  ~list() { allClear_(); }

  /*** operator overload ***/
  list& operator=(const list& x) {
    if (this == &x) {
      return *this;
    }
    assign(x.begin(), x.end());
    return *this;
  }

  /*** iterators ***/
  iterator begin() { return iterator(head_->next_); }
  const_iterator begin() const { return const_iterator(head_->next_); }
  iterator end() { return iterator(head_); }
  const_iterator end() const { return const_iterator(head_); }
  reverse_iterator rbegin() { return reverse_iterator(end()); }

  const_reverse_iterator rbegin() const {
    return const_reverse_iterator(end());
  }

  reverse_iterator rend() { return reverse_iterator(begin()); }

  const_reverse_iterator rend() const {
    return const_reverse_iterator(begin());
  }

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
  const_reference front() const { return *head_->next_->value_; }
  reference back() { return *head_->prev_->value_; }
  const_reference back() const { return *head_->prev_->value_; }

  /*** Modifier ***/
  template <class InputIterator>
  typename ft::enable_if<ft::is_input_iterator<InputIterator>::value,
                         void>::type
  assign(InputIterator first, InputIterator last) {
    node_pointer node;
    node_pointer new_node;

    clear();
    node = head_;
    for (InputIterator itr = first; itr != last; ++itr) {
      new_node = new node_type(cloneVal_(*itr), node, node->next_);
      node->next_ = new_node;
      node = new_node;
    }
    head_->prev_ = node;
  }

  void assign(size_type n, const value_type& val) {
    node_pointer node;
    node_pointer new_node;

    clear();
    node = head_;
    while (n > 0) {
      new_node = new node_type(cloneVal_(val), node, node->next_);
      node->next_ = new_node;
      node = new_node;
      --n;
    }
    head_->prev_ = node;
  }

  void push_front(const value_type& val) {
    node_pointer new_node = new node_type(cloneVal_(val), head_, head_->next_);
    head_->next_->prev_ = new_node;
    head_->next_ = new_node;
  }

  void push_back(const value_type& val) {
    node_pointer new_node = new node_type(cloneVal_(val), head_->prev_, head_);
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

  iterator insert (iterator position, const value_type& val) {
    node_pointer node = findNodeFromIterator_(position);
    node_pointer new_node = new node_type(cloneVal_(val), node->prev_, node);
    node->prev_->next_ = new_node;
    node->prev_ = new_node;
    return iterator(new_node);
  }

  void insert (iterator position, size_type n, const value_type& val) {
    node_pointer node = findNodeFromIterator_(position);
    node_pointer new_node;
    while (n > 0) {
      new_node = new node_type(cloneVal_(val), node->prev_, node);
      node->prev_->next_ = new_node;
      node->prev_ = new_node;
      node = new_node;
      --n;
    }
  }

  void clear() {
    node_pointer node = head_->next_;
    while (node != head_) {
      node = delOnenode_type(node);
    }
    head_->next_ = head_;
    head_->prev_ = head_;
  }
};

}  // namespace ft

#endif /* LIST_HPP */
