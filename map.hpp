/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnakano <dnakano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 13:39:34 by dnakano           #+#    #+#             */
/*   Updated: 2021/02/15 07:59:49 by dnakano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
#define MAP_HPP

#include "iterator.hpp"

namespace ft {

template <class Pointer>
struct TreeNode {
  Pointer value_;
  TreeNode* left_;
  TreeNode* right_;

  TreeNode() {
    value_ = NULL;
    left_ = NULL;
    right_ = NULL;
  }

  TreeNode(Pointer value) {
    value_ = value;
    left_ = NULL;
    right_ = NULL;
  }

  TreeNode(Pointer value, TreeNode* left, TreeNode* right) {
    value_ = value;
    left_ = left;
    right_ = right;
  }

  virtual ~TreeNode() {}
};

template <class Key, class T, class Compare = std::less<Key>,
          class Allocator = std::allocator<std::pair<const Key, T> > >
class map {
 public:
  /*** member type definitions ***/
  typedef Key key_type;
  typedef T mapped_type;
  typedef std::pair<const key_type, mapped_type> value_type;
  typedef Compare key_compare;
  typedef Allocator allocator_type;
  typedef typename allocator_type::reference reference;
  typedef typename allocator_type::const_reference const_reference;
  typedef typename allocator_type::pointer pointer;
  typedef typename allocator_type::const_pointer const_pointer;
  typedef typename allocator_type::size_type size_type;
  typedef typename allocator_type::difference_type difference_type;

  /*** public class definitions ***/
  class value_compare
      : public std::binary_function<value_type, value_type, bool> {
   protected:
    map::key_compare comp;
    value_compare(key_compare c) { comp = c; }

   public:
    bool operator()(const value_type& x, const value_type& y) const {
      return c(x, y);
    }
  };

  /*** private class definitions ***/
  typedef TreeNode<pointer> node_type;
  typedef node_type* node_pointer;

  /*** iterators ***/
  typedef bidirectional_iterator_tree_<value_type, node_pointer,
                                       difference_type, pointer, reference>
      iterator;
  typedef bidirectional_iterator_tree_<const value_type, node_pointer,
                                       difference_type, pointer, reference>
      const_iterator;
  typedef ft::reverse_iterator<iterator> reverse_iterator;
  typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;

  /*** private members ***/
 private:
  key_compare comp_;
  allocator_type alloc_;
  node_pointer root_;
  size_type depth_;

  /*** private member functions ***/
  pointer cloneVal_(const value_type& val) {
    pointer val_ptr = alloc_.allocate(1);
    alloc_.construct(val_ptr, val);
    return val_ptr;
  }

  void destructNodes_(node_pointer node) {
    if (node == NULL) {
      return ;
    }
    alloc_.destroy(node->value_);
    alloc_.deallocate(node->value_, 1);
    destructNodes_(node->left_);
    destructNodes_(node->right_);
    delete node;
  }

  /*** constructors ***/
 public:
  explicit map(const key_compare& comp = key_compare(),
               const allocator_type& alloc = allocator_type()) {
    root_ = NULL;
    comp_ = comp;
    alloc_ = alloc;
    depth_ = 0;
  }

  ~map() {
    destructNodes_(root_);
  }

  /*** operator overloads ***/
  mapped_type& operator[](const key_type& key) {
    (void)key;
    return (*root_->value_).second;
  }

  /*** modifiers ***/
  std::pair<iterator, bool> insert(const value_type& val) {
    if (root_ == NULL) {  // also means depth == 0
      root_ = new node_type(cloneVal_(val));
      std::cout << "inserted: " << (*root_->value_).first << ": " << (*root_->value_).second << std::endl;
      return std::pair<iterator, bool>(iterator(root_, root_), true);
    }

    node_pointer node = root_;
    size_type depth = 1;
    while (1) {
      if (comp_(val.first, (*node->value_).first)) {
        ++depth;
        // case val.key < node->val.key
        if (node->left_ == NULL) {
          node->left_ = new node_type(cloneVal_(val));
          break;
        } else {
          node = node->left_;
        }
      } else if (comp_((*node->value_).first, val.first)) {
        // case val.key > node->val.key
        if (node->right_ == NULL) {
          node->right_ = new node_type(cloneVal_(val));
          break;
        } else {
          node = node->right_;
        }
      } else {
        // case val.key already exists
        return std::pair<iterator, bool>(iterator(node, root_), false);
      }
    }
    if (depth > depth_ /*+ 1*/) {
      // kaiten
      depth_ = depth;
    }
    std::cout << "inserted: " << (*node->value_).first << ": " << (*node->value_).second << std::endl;
    return std::pair<iterator, bool>(iterator(node, root_), true);
  }
};

}  // namespace ft

#endif /* MAP_HPP */
