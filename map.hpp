/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnakano <dnakano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 13:39:34 by dnakano           #+#    #+#             */
/*   Updated: 2021/02/14 16:05:29 by dnakano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
#define MAP_HPP

namespace ft {

// template <class Pointer>
// struct TreeNode {
//   Pointer value_;
//   TreeNode
// };

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

  // typedef Node_ node_type;
  // typedef *node_type node_pointer;

  /*** private members ***/
 private:
  key_compare comp_;
  allocator_type alloc_;

  /*** constructors ***/
 public:
  explicit map(const key_compare& comp = key_compare(),
               const allocator_type& alloc = allocator_type()) {
    comp_ = comp;
    alloc_ = alloc;
  }
};

}  // namespace ft

#endif /* MAP_HPP */
