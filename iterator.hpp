/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnakano <dnakano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 10:16:31 by dnakano           #+#    #+#             */
/*   Updated: 2021/02/17 14:48:47 by dnakano          ###   ########.fr       */
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
** iterator tags
*/

struct input_iterator_tag {};
struct output_iterator_tag {};
struct forward_iterator_tag : public input_iterator_tag {};
struct bidirectional_iterator_tag : public forward_iterator_tag {};
struct random_access_iterator_tag : public bidirectional_iterator_tag {};

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

template <class Type, class NodePointer, class DifferenceType>
class tree_iterator_ {
 public:
  typedef Type value_type;
  typedef DifferenceType difference_type;
  typedef value_type* pointer;
  typedef value_type& reference;
  typedef ft::bidirectional_iterator_tag iterator_category;
  typedef NodePointer node_pointer;

 private:
  node_pointer node_;
  node_pointer root_;

  virtual node_pointer findParent_(node_pointer node, node_pointer start) {
    if (node == NULL || start == NULL || node == start) {
      // case no parent found
      return NULL;
    } else if (node == start->left_ || node == start->right_) {
      // case parent found
      return start;
    }
    node_pointer parent;
    if ((parent = findParent_(node, start->left_)) != NULL) {
      return parent;
    }
    return findParent_(node, start->right_);
  }

  node_pointer findLeftest_(node_pointer node) {
    if (node == NULL || node->left_ == NULL) {
      return node;
    }
    return findLeftest_(node->left_);
  }

  node_pointer findRightest_(node_pointer node) {
    if (node == NULL || node->right_ == NULL) {
      return node;
    }
    return findRightest_(node->right_);
  }

  node_pointer getNextNode_() {
    node_->displayInfo();
    if (node_ == NULL) {
      return findLeftest_(root_);
    } else if (node_->right_) {
      return findLeftest_(node_->right_);
    }
    node_pointer parent = findParent_(node_, root_);
    parent->displayInfo();
    if (parent == NULL) {
      return NULL;
    } else if (parent->left_ == node_) {
      return parent;
    } else { // parent->right_ == node_
      return findParent_(parent, root_);
    }
    // std::cout << "parent" << parent->value_->first << "parent" << "next"
    // << findLeftest_(parent->right_)->value_->first << "next";
    return parent;
  }

  node_pointer getPrevNode_() {
    if (node_ == NULL) {
      return findRightest_(root_);
    } else if (node_->left_) {
      return findRightest_(node_->left_);
    }
    node_pointer parent = findParent_(node_, root_);
    if (parent == NULL || parent->right_ != node_) {
      return NULL;
    }
    return parent;
  }

 public:
  tree_iterator_() : node_(NULL), root_(NULL) {}

  tree_iterator_(node_pointer node, node_pointer root)
      : node_(node), root_(root) {}

  tree_iterator_(const tree_iterator_& x) : node_(x.node_), root_(x.root_) {}

  ~tree_iterator_(){};

  tree_iterator_& operator=(const tree_iterator_& rhs) {
    root_ = rhs.root_;
    node_ = rhs.node_;
    return *this;
  }

  reference operator*() const { return *node_->value_; }
  pointer operator->() const { return node_->value_; }

  tree_iterator_& operator++() {
    node_ = getNextNode_();
    return *this;
  }

  tree_iterator_ operator++(int) {
    tree_iterator_ tmp(*this);
    node_ = getNextNode_();
    return tmp;
  }

  tree_iterator_& operator--() {
    node_ = getPrevNode_();
    return *this;
  }

  tree_iterator_ operator--(int) {
    tree_iterator_ tmp(*this);
    node_ = getPrevNode_();
    return tmp;
  }

  friend void swap(const tree_iterator_& x, const tree_iterator_& y) {
    tree_iterator_ tmp(x);
    x = y;
    y = tmp;
  }

  friend bool operator==(const tree_iterator_& x, const tree_iterator_& y) {
    return x.node_ == y.node_;
  }

  friend bool operator!=(const tree_iterator_& x, const tree_iterator_& y) {
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

  template <class Itr>
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
