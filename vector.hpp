/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnakano <dnakano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 10:19:40 by dnakano           #+#    #+#             */
/*   Updated: 2021/01/29 15:51:02 by dnakano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** This file is re-impremantation of std::vector<T> as ft::vector<T>.
** Supports only C++98 features.
**
** References
** - 42 cursus subject
** - http://www.cplusplus.com/reference/vector/vector/
** - https://cpprefjp.github.io/reference/vector/vector.html
*/

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <memory>
#include <limits>

namespace ft {

template <class T, class Allocator = std::allocator<T> >
class vector {
 public:
  /*** member type definitions ***/
  typedef T value_type;
  typedef Allocator allocator_type;
  // typedef typename allocator_type::reference reference;
  // typedef typename allocator_type::const_reference const_reference;
  typedef typename allocator_type::size_type size_type;
  typedef typename allocator_type::difference_type difference_type;
  // typedef typename allocator_type::pointer pointer;
  // typedef typename allocator_type::const_pointer const_pointer;

 private:
  value_type* values_;
  allocator_type alloc_;
  size_type size_;
  size_type capacity_;

 public:
  /*** constuctors ***/
  // default constructor
  explicit vector(const allocator_type& alloc = allocator_type()) {
    (void)alloc;
    size_ = 0;
    capacity_ = 0;
  }

  // fill constructor
  explicit vector(size_type n, const value_type& value,
                  const allocator_type& alloc = allocator_type()) {
    // TODO: allocation
    // TODO: fill with value
    (void)n;
    (void)value;
    (void)alloc;
    size_ = 0;
    capacity_ = 0;
  }

  /*** operator overload ***/
  vector& operator=(const vector& x) {
    (void)x;
    return (*this);
  }

  /*** capacity ***/
  size_type size() const {
    return size_;
  }

  size_type max_size() const {
    return alloc_.max_size();
  }

  size_type capacity() const {
    return capacity_;
  }

  /*
    // range constructor
    template <class InputIterator>
    vector(InputIterator first, InputIterator last,
           const allocator_type& alloc = allocator_type()) {
      alloc_ = alloc;
      // TODO: allocation and assign value using iterator
    }

    // copy constructor
    vector(const vector& x) { *this = x; }
    */
};

template <class T, class Allocator>
bool operator==(const vector<T, Allocator>& x, const vector<T, Allocator>& y) {
  (void)x;
  (void)y;
  return true;
}

// class vector<T> {
//  private:
//   T* values_;
//   Allocator alloc_;

//  public:
//   /*** member type definitions ***/
//   typedef T value_type;
//   typedef Allocator allocator_type;
//   typedef typename allocator_type::reference reference;
//   typedef typename allocator_type::const_reference const_reference;
//   typedef typename allocator_type::size_type size_type;
//   typedef typename allocator_type::difference_type difference_type;
//   typedef typename allocator_type::pointer pointer;
//   typedef typename allocator_type::const_pointer const_pointer;

//   /*** iterators ***/
//   // iterator
//   class iterator {
//     // TODO: imprementation
//   };

//   // const_iterator
//   class const_iterator {
//     // TODO: imprementation
//   };

//   // reverse_iterator
//   class iterator {
//     // TODO: imprementation
//   };

//   // reverse_const_iterator
//   class const_iterator {
//     // TODO: imprementation
//   };

//   /*** constuctors ***/
//   // default constructor
//   explicit vector(const allocator_type& alloc = allocator_type()) {
//     alloc_ = alloc;
//   }

//   // fill constructor
//   explicit vector(size_type n, const value_type& value,
//                   const allocator_type& alloc = allocator_type()) {
//     alloc_ = alloc;
//     // TODO: allocation
//     // TODO: fill with value
//   }

//   // range constructor
//   template <class InputIterator>
//   vector(InputIterator first, InputIterator last,
//          const allocator_type& alloc = allocator_type()) {
//     alloc_ = alloc;
//     // TODO: allocation and assign value using iterator
//   }

//   // copy constructor
//   vector(const vector& x) { *this = x; }

//   /*** destructor ***/
//   ~vector() {
//     // TODO: release allocated memory
//   }

//   /*** operator overload ***/
//   vector& operator=(const vector& x);
//   reference operator[](size_type n);
//   const_reference operator[](size_type n) const;

//   /*** iterators ***/
//   iterator begin();
//   const_iterator begin() const;
//   iterator end();
//   const_iterator end() const;
//   reverse_iterator rbegin();
//   const_reverse_iterator rbegin() const;
//   reverse_iterator rend();
//   const_reverse_iterator rend() const;

//   /*** capacity ***/
//   size_type size() const noexcept;
//   size_type max_size() const noexcept;
//   size_type capacity() const noexcept;
//   bool empty() const noexcept;
//   void reserve(size_type n);

//   /*** Element access ***/
//   reference at(size_type n);
//   const_reference at(size_type n) const;
//   reference front();
//   const_reference front() const;
//   reference back();
//   const_reference back() const;

//   /*** Modifiers ***/
//   template <class InputIterator>
//   void assign(InputIterator first, InputIterator last);
//   void assign(size_type n, const value_type& u);
//   void push_back(const value_type& x);
//   void pop_back();
//   iterator insert(const_iterator position, const value_type& x);
//   iterator insert(const_iterator position, size_type n, const value_type& x);
//   template <class InputIterator>
//   iterator insert(const_iterator position, InputIterator first,
//                   InputIterator last);
//   iterator erase(const_iterator position);
//   iterator erase(const_iterator first, const_iterator last);
//   void swap(vector&);
//   void clear() noexcept;

//   /*** allocator ***/
//   allocator_type get_allocator() const noexcept;
// }

// /******/

// /*** non member operator overloads ***/
// template <class T, class Allocator>
// bool operator==(const vector<T, Allocator>& x, const vector<T, Allocator>&
// y); template <class T, class Allocator> bool operator<(const vector<T,
// Allocator>& x, const vector<T, Allocator>& y); template <class T, class
// Allocator> bool operator!=(const vector<T, Allocator>& x, const vector<T,
// Allocator>& y); template <class T, class Allocator> bool operator>(const
// vector<T, Allocator>& x, const vector<T, Allocator>& y); template <class T,
// class Allocator> bool operator>=(const vector<T, Allocator>& x, const
// vector<T, Allocator>& y); template <class T, class Allocator> bool
// operator<=(const vector<T, Allocator>& x, const vector<T, Allocator>& y);
// };

}  // namespace ft

#endif /* VECTOR_HPP */
