/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnakano <dnakano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 10:19:40 by dnakano           #+#    #+#             */
/*   Updated: 2021/02/01 08:08:04 by dnakano          ###   ########.fr       */
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

#include <iterator>
#include <limits>
#include <memory>

namespace ft {

template <class T, class Allocator = std::allocator<T> >
class vector {
 public:
  /*** member type definitions ***/
  typedef T value_type;
  typedef Allocator allocator_type;
  typedef typename allocator_type::reference reference;
  typedef typename allocator_type::const_reference const_reference;
  typedef typename allocator_type::size_type size_type;
  typedef typename allocator_type::difference_type difference_type;
  typedef typename allocator_type::pointer pointer;
  typedef typename allocator_type::const_pointer const_pointer;
  typedef pointer iterator;
  typedef const_pointer const_iterator;
  typedef std::reverse_iterator<iterator> reverse_iterator;
  typedef std::reverse_iterator<const_iterator> const_reverse_iterator;

 private:
  value_type* values_;
  allocator_type alloc_;
  size_type size_;
  size_type capacity_;

 public:
  /*** constuctors ***/
  // default constructor
  explicit vector(const allocator_type& alloc = allocator_type()) {
    alloc_ = alloc;
    values_ = NULL;
    size_ = 0;
    capacity_ = 0;
  }

  // fill constructor
  explicit vector(size_type n, const value_type& value,
                  const allocator_type& alloc = allocator_type()) {
    alloc_ = alloc;
    values_ = alloc_.allocate(n);
    for (size_type idx = 0; idx < n; ++idx) {
      values_[idx] = value;
    }
    size_ = n;
    capacity_ = n;
  }

  // range constructor
  // template <class InputIterator>
  // vector(InputIterator first, InputIterator last,
  //        const allocator_type& alloc = allocator_type());

  // copy constructor
  vector(const vector& x) {
    alloc_ = x.alloc_;
    if (x.capacity_ != 0) {
      values_ = alloc_.allocate(x.size_);
      for (size_type idx = 0; idx < x.size_; ++idx) {
        values_[idx] = x.values_[idx];
      }
      capacity_ = x.size_;
    } else {
      values_ = NULL;
      capacity_ = 0;
    }
    size_ = x.size_;
  }

  virtual ~vector() {
    if (capacity_ == 0) {
      alloc_.deallocate(values_, capacity_);
      return;
    }
    for (size_type idx = 0; idx < size_; ++idx) {
      alloc_.destroy(&values_[idx]);
    }
    alloc_.deallocate(values_, capacity_);
  }

  /*** operator overload ***/
  vector& operator=(const vector& x) {
    if (size_ > 0) {
      for (size_type idx = 0; idx < size_; ++idx) {
        alloc_.destroy(&values_[idx]);
      }
      alloc_.deallocate(values_, capacity_);
    }
    alloc_ = x.alloc_;
    values_ = alloc_.allocate(x.capacity_);
    for (size_type idx = 0; idx < x.size_; ++idx) {
      values_[idx] = x.values_[idx];
    }
    size_ = x.size_;
    capacity_ = x.capacity_;
    return (*this);
  }

  reference operator[](size_type n) { return values_[n]; }

  const_reference operator[](size_type n) const { return values_[n]; }

  friend bool operator==(const vector& x, const vector& y) {
    if ((x.size_ != y.size_)) {
      return false;
    }
    for (size_type idx = 0; idx < x.size_; ++idx) {
      if (x.values_[idx] != y.values_[idx]) {
        return false;
      }
    }
    return true;
  }

  friend bool operator!=(const vector& x, const vector& y) { return !(x == y); }

  /*** iterators ***/
  iterator begin() { return values_; }
  const_iterator begin() const { return values_; }
  iterator end() { return values_ + size_; }
  const_iterator end() const { return values_ + size_; }
  reverse_iterator rbegin() { return std::reverse_iterator<iterator>(end()); }

  const_reverse_iterator rbegin() const {
    return std::reverse_iterator<const_iterator>(end());
  }

  reverse_iterator rend() { return std::reverse_iterator<iterator>(begin()); }

  const_reverse_iterator rend() const {
    return std::reverse_iterator<const_iterator>(begin());
  }

  /*** capacity ***/
  size_type size() const { return size_; }
  size_type max_size() const { return alloc_.max_size(); }
  size_type capacity() const { return capacity_; }
  bool empty() const { return (size_ == 0); }

  void reserve(size_type n) {
    // no need to reserve
    if (n <= capacity_) {
      return;
    }

    value_type* values_new = alloc_.allocate(n);
    if (values_) {
      for (size_type idx = 0; idx < size_; ++idx) {
        values_new[idx] = values_[idx];
      }
      alloc_.deallocate(values_, capacity_);
    }
    values_ = values_new;
    capacity_ = n;
  }

  void resize(size_type n, value_type val = value_type()) {
    if (n <= size_) {
      size_ = n;
      return;
    }
    if (n > capacity_) {
      value_type* values_new = alloc_.allocate(n);
      for (size_type idx = 0; idx < size_; ++idx) {
        values_new[idx] = values_[idx];
      }
      alloc_.deallocate(values_, capacity_);
      values_ = values_new;
      capacity_ = n;
    }
    for (size_type idx = size_; idx < n; ++idx) {
      values_[idx] = val;
    }
    size_ = n;
  }

  /*** Element access ***/
  reference at(size_type n) {
    if (n >= size_) {
      throw std::out_of_range("vector");
    }
    return values_[n];
  }

  reference front() { return values_[0]; }
  const_reference front() const { return values_[0]; }
  reference back() { return values_[size_ - 1]; }
  const_reference back() const { return values_[size_ - 1]; }

  /*** modifiers ***/
  void assign(size_type n, const value_type& val) {
    if (n > capacity_) {
      for (size_type idx = 0; idx < size_; ++idx) {
        alloc_.destroy(&values_[idx]);
      }
      delete[] values_;
      values_ = alloc_.allocate(n);
      capacity_ = n;
    }
    for (size_type idx = 0; idx < n; ++idx) {
      values_[idx] = val;
    }
    size_ = n;
  }

  // template <class InputIterator>
  // void assign(InputIterator first, InputIterator last);

  void push_back(const value_type& val) {
    if (size_ + 1 > capacity_) {
      if (size_ == 0) {
        reserve(1);
      } else {
        reserve(size_ * 2);
      }
    }
    values_[size_] = val;
    ++size_;
  }

  void pop_back() {
    if (size_ != 0) {
      alloc_.destroy(&values_[size_ - 1]);
    }
    --size_;
  }

  // iterator insert(iterator position, const value_type& val);
  // void insert(iterator position, size_type n, const value_type& val);
  // template <class InputIterator>
  // void insert(iterator position, InputIterator first, InputIterator last);
  // iterator erase (iterator position);
  // iterator erase (iterator first, iterator last);

  void swap(vector& x) {
    vector tmp(x);
    x = *this;
    *this = tmp;
  }

  void clear() {
    for (size_type idx = 0; idx < size_; ++idx) {
      alloc_.destroy(&values_[idx]);
    }
    size_ = 0;
  }
};

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
//   reference operator[](size_type n); done
//   const_reference operator[](size_type n) const; done

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
//   size_type size() const noexcept; done
//   size_type max_size() const noexcept; done
//   size_type capacity() const noexcept; done
//   bool empty() const noexcept; done
//   void reserve(size_type n); done

//   /*** Element access ***/
//   reference at(size_type n); done
//   const_reference at(size_type n) const; done
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
