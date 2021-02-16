/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnakano <dnakano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 13:39:34 by dnakano           #+#    #+#             */
/*   Updated: 2021/02/16 14:20:16 by dnakano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
#define MAP_HPP

#include "iterator.hpp"

namespace ft {

// class of node tree
template <class Pointer>
struct TreeNode {
  Pointer value_;
  TreeNode* left_;
  TreeNode* right_;
  size_t height_;

  TreeNode(Pointer value = NULL, TreeNode* left = NULL,
           TreeNode* right = NULL) {
    value_ = value;
    left_ = left;
    right_ = right;
    updateHeight();
  }

  virtual ~TreeNode() {}

  void updateHeight() {
    if (value_ == NULL) {
      height_ = 0;
    } else {
      height_ = std::max((left_ ? left_->height_ + 1 : 1),
                         (right_ ? right_->height_ + 1 : 1));
    }
  }

  ssize_t heightDiff() {
    ssize_t left_height = left_ ? static_cast<ssize_t>(left_->height_) : 0;
    ssize_t right_height = right_ ? static_cast<ssize_t>(right_->height_) : 0;
    return left_height - right_height;
  }

  void rotateLeft() {
    if (right_ == NULL) {
      return;
    }
    // std::cout << "rotate left" << std::endl;
    // std::cout << "before:: ";
    // displayInfo();
    std::swap(value_, right_->value_);
    TreeNode* tmp_left = left_;
    left_ = right_;
    right_ = left_->right_;
    left_->right_ = left_->left_;
    left_->left_ = tmp_left;
    left_->updateHeight();
    updateHeight();
    // std::cout << "after:: ";
    // displayInfo();
  }

  void rotateRight() {
    if (left_ == NULL) {
      return;
    }
    std::swap(value_, left_->value_);
    TreeNode* tmp_right = right_;
    right_ = left_;
    left_ = right_->left_;
    right_->left_ = right_->right_;
    right_->right_ = tmp_right;
    right_->updateHeight();
    updateHeight();
    // std::cout << "after:: ";
    // displayInfo();
  }

  bool getBalanced() {
    updateHeight();
    ssize_t height_diff = heightDiff();
    if (height_diff > 1) {
      if (left_->heightDiff() < 0) {
        left_->rotateLeft();
      }
      rotateRight();
      return true;
    } else if (height_diff < -1) {
      if (right_->heightDiff() > 0) {
        right_->rotateRight();
      }
      rotateLeft();
      return true;
    }
    return false;
  }

  void displayInfo() {
    std::cout << "node: ";
    std::cout << value_->first << "=" << value_->second;
    std::cout << ", left: ";
    if (left_) {
      std::cout << left_->value_->first << "=" << left_->value_->second;
    }
    std::cout << ", right: ";
    if (right_) {
      std::cout << right_->value_->first << "=" << right_->value_->second;
    }
    std::cout << std::endl;
  }
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

  /*** private member functions ***/
  pointer cloneVal_(const value_type& val = value_type()) {
    pointer val_ptr = alloc_.allocate(1);
    alloc_.construct(val_ptr, val);
    return val_ptr;
  }

  void deleteVal_(pointer val_ptr) {
    if (val_ptr == NULL) {
      return;
    }
    alloc_.destroy(val_ptr);
    alloc_.deallocate(val_ptr, 1);
  }

  node_pointer findNode_(node_pointer node, const key_type& k) {
    if (node == NULL) {
      return NULL;
    } else if (comp_(k, (*node->value_).first)) {
      return findNode_(node->left_, k);
    } else if (comp_((*node->value_).first, k)) {
      return findNode_(node->right_, k);
    } else {
      return node;
    }
  }

  // This tries to insert new node with val_ptr (pointer to newly allocated
  // value) to node. If there is no element which has same key as val_ptr,
  // it will create new node to proper position and is kept balanced, then
  // returns pointer to the new node. Otherwise it will NOT create any new node
  // but returns pointer to the aleready exsiting node which has same key as
  // val_ptr.
  node_pointer insertVal_(node_pointer node, pointer val_ptr) {
    // this means node == root_ and not initialized
    if (node == NULL) {
      root_ = new node_type(val_ptr);
      return root_;
    }

    node_pointer new_node;
    if (comp_(val_ptr->first, node->value_->first)) {
      if (node->left_ == NULL) {
        new_node = new node_type(val_ptr);
        node->left_ = new_node;
      } else {
        new_node = insertVal_(node->left_, val_ptr);
      }
    } else if (comp_(node->value_->first, val_ptr->first)) {
      if (node->right_ == NULL) {
        new_node = new node_type(val_ptr);
        node->right_ = new_node;
      } else {
        new_node = insertVal_(node->right_, val_ptr);
      }
    } else {
      new_node = node;
    }
    if (node->getBalanced() && new_node->value_ != val_ptr) {
      return findNode_(node, val_ptr->first);
    }
    return new_node;
  }

  void deleteNodes_(node_pointer node) {
    if (node == NULL) {
      return;
    }
    deleteVal_(node->value_);
    deleteNodes_(node->left_);
    deleteNodes_(node->right_);
    delete node;
  }

  /*** constructors ***/
 public:
  explicit map(const key_compare& comp = key_compare(),
               const allocator_type& alloc = allocator_type()) {
    root_ = NULL;
    comp_ = comp;
    alloc_ = alloc;
  }

  // template <class InputIterator>
  // map(InputIterator first, InputIterator last,
  //     const key_compare& comp = key_compare(),
  //     const allocator_type& alloc = allocator_type());

  ~map() { deleteNodes_(root_); }

  /*** operator overloads ***/
  mapped_type& operator[](const key_type& k) {
    return (*(insert(value_type(k, mapped_type())).first)).second;
  }

  /*** modifiers ***/
  std::pair<iterator, bool> insert(const value_type& val) {
    pointer new_value = cloneVal_(val);
    node_pointer node = insertVal_(root_, new_value);
    if (node->value_ == new_value) {
      return std::pair<iterator, bool>(iterator(node, root_), true);
    } else {
      deleteVal_(new_value);
      return std::pair<iterator, bool>(iterator(node, root_), false);
    }
  }

  template <class InputIterator>
  typename ft::enable_if<ft::is_input_iterator<InputIterator>::value,
                         void>::type
  insert (InputIterator first, InputIterator last) {
    for (InputIterator itr = first; itr != last; ++itr) {
      insert(*itr);
    }
  }

  /*** operations ***/
  iterator find(const key_type& k) {
    node_pointer node = findNode_(root_, k);
    return iterator(node, root_);
  }

  const_iterator find(const key_type& k) const;
};

}  // namespace ft

#endif /* MAP_HPP */
