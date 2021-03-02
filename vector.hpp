/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnakano <dnakano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 10:19:40 by dnakano           #+#    #+#             */
/*   Updated: 2021/03/02 14:19:24 by dnakano          ###   ########.fr       */
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
#include <memory>

// self-made headers (rekkaban copy)
#include "algorithm.hpp"
#include "iterator.hpp"
#include "type_traits.hpp"

namespace ft {

template <class Type, class DifferenceType>
class vector_iterator_ {
 public:
  typedef Type value_type;
  typedef DifferenceType difference_type;
  typedef value_type* pointer;
  typedef value_type& reference;
  typedef ft::random_access_iterator_tag iterator_category;

  pointer ptr_;

  vector_iterator_() : ptr_(NULL){};
  vector_iterator_(pointer ptr) : ptr_(ptr){};
  vector_iterator_(const vector_iterator_& x) : ptr_(x.ptr_) {}
  ~vector_iterator_(){};

  vector_iterator_& operator=(const vector_iterator_& rhs) {
    ptr_ = rhs.ptr_;
    return *this;
  }

  reference operator*() const { return *ptr_; }
  pointer operator->() const { return ptr_; }
  reference operator[](difference_type idx) const { return *(ptr_ + idx); }

  vector_iterator_& operator++() {
    ++ptr_;
    return *this;
  }

  vector_iterator_ operator++(int) {
    vector_iterator_ tmp(*this);
    ++ptr_;
    return tmp;
  }

  vector_iterator_& operator--() {
    --ptr_;
    return *this;
  }

  vector_iterator_ operator--(int) {
    vector_iterator_ tmp(*this);
    --ptr_;
    return tmp;
  }

  vector_iterator_& operator+=(difference_type diff) {
    ptr_ += diff;
    return *this;
  }

  vector_iterator_& operator-=(difference_type diff) {
    ptr_ -= diff;
    return *this;
  }

  friend vector_iterator_ operator+(const vector_iterator_& lhs,
                                    difference_type rhs) {
    return vector_iterator_(lhs.ptr_ + rhs);
  }

  friend vector_iterator_ operator+(difference_type lhs,
                                    const vector_iterator_& rhs) {
    return vector_iterator_(rhs.ptr_ + lhs);
  }

  friend difference_type operator-(const vector_iterator_& lhs,
                                   const vector_iterator_& rhs) {
    return lhs.ptr_ - rhs.ptr_;
  }

  friend vector_iterator_ operator-(const vector_iterator_& lhs,
                                    difference_type rhs) {
    return vector_iterator_(lhs.ptr_ - rhs);
  }

  friend vector_iterator_ operator-(difference_type lhs,
                                    const vector_iterator_& rhs) {
    return vector_iterator_(rhs.ptr_ - lhs);
  }

  friend void swap(vector_iterator_& x, vector_iterator_& y) {
    vector_iterator_ tmp(x);
    x = y;
    y = tmp;
  }

  friend bool operator==(const vector_iterator_& x, const vector_iterator_& y) {
    return x.ptr_ == y.ptr_;
  }

  friend bool operator!=(const vector_iterator_& x, const vector_iterator_& y) {
    return !(x == y);
  }

  friend bool operator<(const vector_iterator_& x, const vector_iterator_& y) {
    return x.ptr_ < y.ptr_;
  }

  friend bool operator<=(const vector_iterator_& x, const vector_iterator_& y) {
    return x.ptr_ <= y.ptr_;
  }

  friend bool operator>(const vector_iterator_& x, const vector_iterator_& y) {
    return x.ptr_ > y.ptr_;
  }

  friend bool operator>=(const vector_iterator_& x, const vector_iterator_& y) {
    return x.ptr_ >= y.ptr_;
  }
};

template <class Type, class DifferenceType>
class vector_const_iterator_ {
 public:
  typedef const Type value_type;
  typedef DifferenceType difference_type;
  typedef const value_type* pointer;
  typedef const value_type& reference;
  typedef ft::random_access_iterator_tag iterator_category;

  pointer ptr_;

  vector_const_iterator_() : ptr_(NULL){};
  vector_const_iterator_(pointer ptr) : ptr_(ptr){};

  vector_const_iterator_(const vector_iterator_<Type, DifferenceType>& x)
      : ptr_(x.ptr_) {}

  vector_const_iterator_(const vector_const_iterator_& x) : ptr_(x.ptr_) {}
  ~vector_const_iterator_(){};

  vector_const_iterator_& operator=(const vector_const_iterator_& rhs) {
    ptr_ = rhs.ptr_;
    return *this;
  }

  reference operator*() const { return *ptr_; }
  pointer operator->() const { return ptr_; }
  reference operator[](difference_type idx) const { return *(ptr_ + idx); }

  vector_const_iterator_& operator++() {
    ++ptr_;
    return *this;
  }

  vector_const_iterator_ operator++(int) {
    vector_const_iterator_ tmp(*this);
    ++ptr_;
    return tmp;
  }

  vector_const_iterator_& operator--() {
    --ptr_;
    return *this;
  }

  vector_const_iterator_ operator--(int) {
    vector_const_iterator_ tmp(*this);
    --ptr_;
    return tmp;
  }

  vector_const_iterator_& operator+=(difference_type diff) {
    ptr_ += diff;
    return *this;
  }

  vector_const_iterator_& operator-=(difference_type diff) {
    ptr_ -= diff;
    return *this;
  }

  friend vector_const_iterator_ operator+(const vector_const_iterator_& lhs,
                                          difference_type rhs) {
    return vector_const_iterator_(lhs.ptr_ + rhs);
  }

  friend vector_const_iterator_ operator+(difference_type lhs,
                                          const vector_const_iterator_& rhs) {
    return vector_const_iterator_(rhs.ptr_ + lhs);
  }

  friend difference_type operator-(const vector_const_iterator_& lhs,
                                   const vector_const_iterator_& rhs) {
    return lhs.ptr_ - rhs.ptr_;
  }

  friend vector_const_iterator_ operator-(const vector_const_iterator_& lhs,
                                          difference_type rhs) {
    return vector_const_iterator_(lhs.ptr_ - rhs);
  }

  friend vector_const_iterator_ operator-(difference_type lhs,
                                          const vector_const_iterator_& rhs) {
    return vector_const_iterator_(rhs.ptr_ - lhs);
  }

  friend void swap(vector_const_iterator_& x, vector_const_iterator_& y) {
    vector_const_iterator_ tmp(x);
    x = y;
    y = tmp;
  }

  friend bool operator==(const vector_const_iterator_& x,
                         const vector_const_iterator_& y) {
    return x.ptr_ == y.ptr_;
  }

  friend bool operator!=(const vector_const_iterator_& x,
                         const vector_const_iterator_& y) {
    return !(x == y);
  }

  friend bool operator<(const vector_const_iterator_& x,
                        const vector_const_iterator_& y) {
    return x.ptr_ < y.ptr_;
  }

  friend bool operator<=(const vector_const_iterator_& x,
                         const vector_const_iterator_& y) {
    return x.ptr_ <= y.ptr_;
  }

  friend bool operator>(const vector_const_iterator_& x,
                        const vector_const_iterator_& y) {
    return x.ptr_ > y.ptr_;
  }

  friend bool operator>=(const vector_const_iterator_& x,
                         const vector_const_iterator_& y) {
    return x.ptr_ >= y.ptr_;
  }
};

template <class T, class Allocator = std::allocator<T> >
class vector {
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

  /*** iterators ***/
 public:
  typedef vector_iterator_<value_type, difference_type> iterator;
  typedef vector_const_iterator_<value_type, difference_type> const_iterator;
  typedef ft::reverse_iterator<iterator> reverse_iterator;
  typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;

 private:
  /*** private attributes ***/
  value_type* values_;
  allocator_type alloc_;
  size_type size_;
  size_type capacity_;

  /*** private functions ***/
  size_type getNewCapacity_(size_type cap_prev, size_type cap_req) {
    if (cap_prev == 0) {
      return cap_req;
    } else if (cap_prev * 2 >= cap_req) {
      return cap_prev * 2;
    } else {
      return cap_req;
    }
  }

  void allClear_() {
    if (capacity_ == 0) {
      return;
    }
    clear();
    alloc_.deallocate(values_, capacity_);
    values_ = NULL;
    capacity_ = 0;
  }

  template <class InputIterator>
  typename ft::enable_if<ft::is_input_iterator<InputIterator>::value,
                         size_type>::type
  getSizeFromIterator(InputIterator first, InputIterator last) {
    InputIterator iter = first;
    size_type n = 0;
    while (iter != last) {
      (void)*iter;
      ++iter;
      ++n;
    }
    return n;
  }

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
  explicit vector(size_type n, const value_type& val = value_type(),
                  const allocator_type& alloc = allocator_type()) {
    alloc_ = alloc;
    values_ = NULL;
    size_ = 0;
    capacity_ = 0;
    assign(n, val);
  }

  // range constructor
  template <class InputIterator>
  vector(InputIterator first,
         typename ft::enable_if<ft::is_input_iterator<InputIterator>::value,
                                InputIterator>::type last,
         const allocator_type& alloc = allocator_type()) {
    alloc_ = alloc;
    values_ = NULL;
    size_ = 0;
    capacity_ = 0;
    assign(first, last);
  }

  // copy constructor
  vector(const vector& x) {
    values_ = NULL;
    size_ = 0;
    capacity_ = 0;
    *this = x;
  }

  // destructor
  virtual ~vector() { allClear_(); }

  /*** operator overload ***/
  vector& operator=(const vector& x) {
    if (this == &x) {
      return *this;
    }
    assign(x.begin(), x.end());
    return *this;
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

  friend bool operator<(const vector& x, const vector& y) {
    return (
        ft::lexicographical_compare(x.begin(), x.end(), y.begin(), y.end()));
  }

  friend bool operator>(const vector& x, const vector& y) {
    return (
        ft::lexicographical_compare(y.begin(), y.end(), x.begin(), x.end()));
  }

  friend bool operator<=(const vector& x, const vector& y) { return !(x > y); }
  friend bool operator>=(const vector& x, const vector& y) { return !(x < y); }

  /*** iterators ***/
  iterator begin() { return iterator(values_); }
  iterator end() { return iterator(values_ + size_); }
  const_iterator begin() const { return const_iterator(values_); }
  const_iterator end() const { return const_iterator(values_ + size_); }
  reverse_iterator rbegin() { return reverse_iterator(end()); }
  reverse_iterator rend() { return reverse_iterator(begin()); }

  const_reverse_iterator rbegin() const {
    return ft::reverse_iterator<const_iterator>(end());
  }

  const_reverse_iterator rend() const {
    return ft::reverse_iterator<const_iterator>(begin());
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
        alloc_.construct(values_new + idx, values_[idx]);
        alloc_.destroy(values_ + idx);
      }
      alloc_.deallocate(values_, capacity_);
    }
    values_ = values_new;
    capacity_ = n;
  }

  void resize(size_type n, value_type val = value_type()) {
    if (size_ > n) {
      while (size_ > n) {
        alloc_.destroy(values_ + --size_);
      }
      return;
    }
    if (n > capacity_) {
      reserve(getNewCapacity_(capacity_, n));
    }
    for (size_type idx = size_; idx < n; ++idx) {
      alloc_.construct(values_ + idx, val);
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

  const_reference at(size_type n) const {
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
      allClear_();
      values_ = alloc_.allocate(n);
      capacity_ = n;
      for (size_type idx = 0; idx < n; ++idx) {
        alloc_.construct(values_ + idx, val);
      }
    } else {
      for (size_type idx = n; idx < size_; ++idx) {
        alloc_.destroy(&values_[idx]);
      }
      for (size_type idx = 0; idx < n; ++idx) {
        if (idx < size_) {
          values_[idx] = val;
        } else {
          alloc_.construct(values_ + idx, val);
        }
      }
    }
    size_ = n;
  }

  template <class InputIterator>
  typename ft::enable_if<ft::is_input_iterator<InputIterator>::value,
                         void>::type
  assign(InputIterator first, InputIterator last) {
    InputIterator iter = first;
    size_type n = getSizeFromIterator(first, last);
    if (n > capacity_) {
      allClear_();
      values_ = alloc_.allocate(n);
      capacity_ = n;
      for (iter = first, size_ = 0; iter != last; ++iter, ++size_) {
        alloc_.construct(values_ + size_, *iter);
      }
    } else {
      size_type idx;
      for (iter = first, idx = 0; iter != last; ++iter, ++idx) {
        if (idx < size_) {
          values_[idx] = *iter;
        } else {
          alloc_.construct(values_ + idx, *iter);
        }
      }
      for (idx = n; idx < size_; ++idx) {
        alloc_.destroy(values_ + idx);
      }
      size_ = n;
    }
  }

  void push_back(const value_type& val) {
    if (size_ + 1 > capacity_) {
      reserve(getNewCapacity_(capacity_, size_ + 1));
    }
    alloc_.construct(values_ + size_++, val);
  }

  void pop_back() {
    if (size_ > 0) {
      alloc_.destroy(values_ + size_ - 1);
    }
    --size_;
  }

  iterator insert(iterator position, const value_type& val) {
    if (position == iterator(NULL)) {
      assign(1, val);
      return begin();
    } else if (position == end()) {
      push_back(val);
      return end() - 1;
    }

    const size_type offset = position - begin();
    if (size_ + 1 > capacity_) {
      const size_type new_capacity = getNewCapacity_(capacity_, size_ + 1);
      value_type* new_values = alloc_.allocate(new_capacity);
      for (size_type idx = 0; idx < offset; ++idx) {
        alloc_.construct(new_values + idx, values_[idx]);
        alloc_.destroy(&values_[idx]);
      }
      alloc_.construct(new_values + offset, val);
      for (size_type idx = offset + 1; idx < size_ + 1; ++idx) {
        alloc_.construct(new_values + idx, values_[idx - 1]);
        alloc_.destroy(&values_[idx - 1]);
      }
      alloc_.deallocate(values_, capacity_);
      capacity_ = new_capacity;
      values_ = new_values;
    } else {
      alloc_.construct(values_ + size_, values_[size_ - 1]);
      for (size_type idx = size_ - 1; idx > offset; --idx) {
        values_[idx] = values_[idx - 1];
      }
      values_[offset] = val;
    }
    ++size_;
    return begin() + offset;
  }

  void insert(iterator position, size_type n, const value_type& val) {
    if (position == iterator(NULL)) {
      assign(n, val);
      return;
    }

    size_type idx;
    const size_type offset = position - begin();

    if (size_ + n > capacity_) {
      const size_type new_capacity = getNewCapacity_(capacity_, size_ + n);
      value_type* new_values = alloc_.allocate(new_capacity);
      for (idx = 0; idx < offset; ++idx) {
        alloc_.construct(new_values + idx, values_[idx]);
        alloc_.destroy(values_ + idx);
      }
      for (idx = offset; idx < offset + n; ++idx) {
        alloc_.construct(new_values + idx, val);
      }
      for (idx = offset + n; idx < size_ + n; ++idx) {
        alloc_.construct(new_values + idx, values_[idx - n]);
        alloc_.destroy(values_ + idx - n);
      }
      alloc_.deallocate(values_, capacity_);
      values_ = new_values;
      capacity_ = new_capacity;
    } else {
      for (idx = size_ + n; idx > size_; --idx) {
        if (idx > offset + n) {
          alloc_.construct(values_ + idx - 1, values_[idx - n - 1]);
        } else {
          alloc_.construct(values_ + idx - 1, val);
        }
      }
      for (idx = size_; idx > offset; --idx) {
        if (idx > offset + n) {
          values_[idx - 1] = values_[idx - n - 1];
        } else {
          values_[idx - 1] = val;
        }
      }
    }
    size_ += n;
  }

  template <class InputIterator>
  typename ft::enable_if<ft::is_input_iterator<InputIterator>::value,
                         void>::type
  insert(iterator position, InputIterator first, InputIterator last) {
    if (position == iterator(NULL)) {
      assign(first, last);
      return;
    }

    const size_type n = getSizeFromIterator(first, last);
    size_type idx;
    InputIterator iter;
    const size_type offset = position - begin();

    if (size_ + n > capacity_) {
      const size_type new_capacity = getNewCapacity_(capacity_, size_ + n);
      value_type* new_values = alloc_.allocate(new_capacity);
      for (idx = 0; idx < offset; ++idx) {
        alloc_.construct(new_values + idx, values_[idx]);
        alloc_.destroy(&values_[idx]);
      }
      for (idx = offset, iter = first; idx < offset + n; ++idx, ++iter) {
        alloc_.construct(new_values + idx, *iter);
      }
      for (idx = offset + n; idx < size_ + n; ++idx) {
        alloc_.construct(new_values + idx, values_[idx - n]);
        alloc_.destroy(&values_[idx - n]);
      }
      alloc_.deallocate(values_, capacity_);
      values_ = new_values;
      capacity_ = new_capacity;
    } else {
      for (idx = size_ + n; idx > size_ && idx > offset + n; --idx) {
        alloc_.construct(values_ + idx - 1, values_[idx - n - 1]);
      }
      for (idx = offset, iter = first; idx < offset + n; ++idx, ++iter) {
        if (idx < size_) {
          values_[idx] = *iter;
        } else {
          alloc_.construct(values_ + idx, *iter);
        }
      }
    }
    size_ += n;
  }

  iterator erase(iterator position) {
    for (iterator iter = position; iter + 1 != end(); ++iter) {
      *iter = *(iter + 1);
    }
    alloc_.destroy(values_ + --size_);
    return position;
  }

  iterator erase(iterator first, iterator last) {
    size_type offset = last - first;
    for (iterator iter = first; iter + offset != end(); ++iter) {
      *iter = *(iter + offset);
    }
    size_type new_size = size_ - offset;
    while (size_ > new_size) {
      alloc_.destroy(values_ + --size_);
    }
    return first;
  }

  void swap(vector& x) {
    pointer tmp_values = x.values_;
    size_type tmp_size = x.size_;
    size_type tmp_capacity = x.capacity_;

    x.values_ = values_;
    x.size_ = size_;
    x.capacity_ = capacity_;
    values_ = tmp_values;
    size_ = tmp_size;
    capacity_ = tmp_capacity;
  }

  void clear() {
    while (size_ > 0) {
      alloc_.destroy(values_ + --size_);
    }
  }
};

template <class T, class Allocator>
void swap(vector<T, Allocator>& a, vector<T, Allocator>& b) {
  a.swap(b);
}

// class vector_bool_iterator_ {
//   typedef bool value_type;
//   typedef ptrdiff_t difference_type;
//   typedef vector_bool_iterator_ pointer;
//   // typedef vector<bool>::reference
// };

// class bit_storage_wrapper_ {
//  public:
//   typedef size_t size_type;
//   typedef size_t storage_type;
//   typedef size_t* storage_pointer;
//   typedef ptrdiff_t difference_type;

//  private:
//   storage_pointer storage_;

//  public:
//   bit_storage_wrapper_() : storage_(NULL){};
//   bit_storage_wrapper_(storage_type* ptr) : storage_(ptr){};
//   bit_storage_wrapper_(const bit_storage_wrapper_& x) :
//   storage_(x.storage_){}; virtual ~bit_storage_wrapper_();

//   bit_storage_wrapper_& operator=(const bit_storage_wrapper_ rhs) {
//     storage_ = rhs.storage_;
//   }

//   bool operator[](size_type n) {
//     return storage_[n / (sizeof(storage_type) * CHAR_BIT)] &
//            ((storage_type)(1) << n % (sizeof(storage_type) * CHAR_BIT));
//   }
// };

class bit_reference_ {
  friend class vector<bool>;
  friend class bit_iterator_;

 public:
  typedef size_t size_type;
  typedef size_t storage_type;
  typedef size_t* storage_pointer;
  typedef ptrdiff_t difference_type;

 private:
  storage_pointer storage_;
  size_type idx_;
  bit_reference_() : storage_(NULL), idx_(0) {}
  bit_reference_(const bit_reference_& x)
      : storage_(x.storage_), idx_(x.idx_) {}
  bit_reference_(storage_pointer ptr, size_type idx)
      : storage_(ptr), idx_(idx) {}

 public:
  ~bit_reference_() {}

  operator bool() const {
    return storage_[idx_ / (sizeof(storage_type) * CHAR_BIT)] &
           (1ULL << idx_ % (sizeof(storage_type) * CHAR_BIT));
  }

  bit_reference_& operator=(const bool x) {
    if (x) {
      storage_[idx_ / (sizeof(storage_type) * CHAR_BIT)] |=
          (1ULL << idx_ % (sizeof(storage_type) * CHAR_BIT));
    } else {
      storage_[idx_ / (sizeof(storage_type) * CHAR_BIT)] &=
          ~(1ULL << idx_ % (sizeof(storage_type) * CHAR_BIT));
    }
    return *this;
  }

  bit_reference_& operator=(const bit_reference_& x) {
    if (bool(x)) {
      storage_[idx_ / (sizeof(storage_type) * CHAR_BIT)] |=
          (1ULL << idx_ % (sizeof(storage_type) * CHAR_BIT));
    } else {
      storage_[idx_ / (sizeof(storage_type) * CHAR_BIT)] &=
          ~(1ULL << idx_ % (sizeof(storage_type) * CHAR_BIT));
    }
    return *this;
  }

  void flip() {
    if (*this) {
      *this = false;
    } else {
      *this = true;
    }
  }

  void moveIdx_(difference_type x) { idx_ += x; }
  size_type getIdx_() const { return idx_; }
  storage_pointer getStorage_() const { return storage_; }
};

class bit_iterator_ {
 public:
  typedef bool value_type;
  typedef bit_reference_::difference_type difference_type;
  typedef bit_iterator_ pointer;
  typedef bit_reference_ reference;
  typedef ft::random_access_iterator_tag iterator_category;

  typedef bit_reference_::storage_pointer storage_ponter;
  typedef bit_reference_::size_type size_type;

 private:
  bit_reference_ ref_;

 public:
  bit_iterator_(){};
  bit_iterator_(storage_ponter ptr, size_type idx) : ref_(ptr, idx) {}
  bit_iterator_(const bit_reference_& ref) : ref_(ref.storage_, ref.idx_) {}
  bit_iterator_(const bit_iterator_& x) : ref_(x.ref_) {}

  bit_iterator_& operator=(const bit_iterator_& rhs) {
    ref_.storage_ = rhs.ref_.storage_;
    ref_.idx_ = rhs.ref_.idx_;
    return *this;
  }

  reference operator*() const { return ref_; }
  pointer operator->() const { return *this; }

  reference operator[](difference_type idx) const {
    return bit_reference_(ref_.storage_, ref_.idx_ + idx);
  }

  bit_iterator_ operator++() {
    ++(ref_.idx_);
    return *this;
  }

  bit_iterator_ operator++(int) {
    bit_iterator_ tmp(*this);
    ++(ref_.idx_);
    return tmp;
  }

  bit_iterator_ operator--() {
    ++(ref_.idx_);
    return *this;
  }

  bit_iterator_ operator--(int) {
    bit_iterator_ tmp(*this);
    --(ref_.idx_);
    return tmp;
  }

  bit_iterator_& operator+=(difference_type diff) {
    ref_.idx_ += diff;
    return *this;
  }

  bit_iterator_& operator-=(difference_type diff) {
    ref_.idx_ -= diff;
    return *this;
  }

  friend bit_iterator_ operator+(const bit_iterator_& lhs,
                                 difference_type rhs) {
    bit_reference_ tmp(*lhs);
    tmp.moveIdx_(rhs);
    return bit_iterator_(tmp);
  }

  friend bit_iterator_ operator+(difference_type lhs,
                                 const bit_iterator_& rhs) {
    bit_reference_ tmp(*rhs);
    tmp.moveIdx_(lhs);
    return bit_iterator_(tmp);
  }

  friend difference_type operator-(const bit_iterator_& lhs,
                                   const bit_iterator_& rhs) {
    if (lhs.ref_.getIdx_() < rhs.ref_.getIdx_()) {
      return -static_cast<difference_type>(rhs.ref_.getIdx_() -
                                           lhs.ref_.getIdx_());
    }
    return lhs.ref_.getIdx_() - rhs.ref_.getIdx_();
  }

  friend bit_iterator_ operator-(const bit_iterator_& lhs,
                                 difference_type rhs) {
    bit_reference_ tmp(*lhs);
    tmp.moveIdx_(-rhs);
    return bit_iterator_(tmp);
  }

  friend bit_iterator_ operator-(difference_type lhs,
                                 const bit_iterator_& rhs) {
    bit_reference_ tmp(*rhs);
    tmp.moveIdx_(lhs);
    return bit_iterator_(tmp);
  }

  friend void swap(bit_iterator_& x, bit_iterator_& y) {
    bit_iterator_ tmp(x);
    x = y;
    y = tmp;
  }

  friend bool operator==(const bit_iterator_& x, const bit_iterator_& y) {
    return (x.ref_.getStorage_() == y.ref_.getStorage_() &&
            x.ref_.getIdx_() == y.ref_.getIdx_());
  }

  friend bool operator!=(const bit_iterator_& x, const bit_iterator_& y) {
    return !(x == y);
  }

  friend bool operator<(const bit_iterator_& x, const bit_iterator_& y) {
    return (x.ref_.getStorage_() == y.ref_.getStorage_() &&
            x.ref_.getIdx_() < y.ref_.getIdx_()) ||
           (x.ref_.getStorage_() < y.ref_.getStorage_());
  }

  friend bool operator<=(const bit_iterator_& x, const bit_iterator_& y) {
    return !(x > y);
  }

  friend bool operator>(const bit_iterator_& x, const bit_iterator_& y) {
    return (x.ref_.getStorage_() == y.ref_.getStorage_() &&
            x.ref_.getIdx_() > y.ref_.getIdx_()) ||
           (x.ref_.getStorage_() > y.ref_.getStorage_());
  }

  friend bool operator>=(const bit_iterator_& x, const bit_iterator_& y) {
    return !(x < y);
  }
};

template <class Allocator>
class vector<bool, Allocator> {
  /*** public member types ***/
 public:
  typedef bool value_type;
  typedef Allocator allocator_type;
  typedef bit_reference_::size_type size_type;
  typedef bit_reference_::difference_type difference_type;
  typedef bit_iterator_ pointer;
  // typedef bit_iterator_ const_pointer;
  typedef pointer iterator;
  // typedef const_pointer                            const_iterator;
  // typedef _VSTD::reverse_iterator<iterator> reverse_iterator;
  // typedef _VSTD::reverse_iterator<const_iterator>   const_reverse_iterator;

  typedef bit_reference_::storage_type storage_type;
  typedef bit_reference_::storage_pointer storage_pointer;
  typedef std::allocator<storage_type> storage_allocator_type;

  typedef bit_reference_ reference;
  typedef const reference const_reference;

  /*** private member variables ***/
 private:
  storage_pointer storage_;
  size_type size_;
  size_type storage_size_;
  allocator_type alloc_;
  storage_allocator_type storage_alloc_;

  /*** private functions ***/
  size_type getNewCapacity_(size_type cap_prev, size_type cap_req) {
    if (cap_prev == 0) {
      return cap_req;
    } else if (cap_prev * 2 >= cap_req) {
      return cap_prev * 2;
    } else {
      return cap_req;
    }
  }

  template <class InputIterator>
  typename ft::enable_if<ft::is_input_iterator<InputIterator>::value,
                         size_type>::type
  getSizeFromIterator(InputIterator first, InputIterator last) {
    InputIterator iter = first;
    size_type n = 0;
    while (iter != last) {
      (void)*iter;
      ++iter;
      ++n;
    }
    return n;
  }

  size_type getStorageSize(size_type size) {
    size_type storage_size = size / (CHAR_BIT * sizeof(storage_type));
    return (size % (CHAR_BIT * sizeof(storage_type))) ? storage_size + 1
                                                      : storage_size;
  }
  // create bit mask
  // size = 4 11...1110000
  storage_type createMask_(size_type size) { return ~((1UL << size) - 1UL); }

 public:
  /*** constructors ***/
  // default constructor
  explicit vector(const allocator_type& alloc = allocator_type()) {
    alloc_ = alloc;
    storage_alloc_ = storage_allocator_type();
    storage_ = NULL;
    size_ = 0;
    storage_size_ = 0;
  }

  // fill constructor
  explicit vector(size_type n, const value_type& val = value_type(),
                  const allocator_type& alloc = allocator_type()) {
    alloc_ = alloc;
    storage_alloc_ = storage_allocator_type();
    storage_ = NULL;
    size_ = 0;
    storage_size_ = 0;
    assign(n, val);
  }

  // range constructor
  template <class InputIterator>
  vector(InputIterator first,
         typename ft::enable_if<ft::is_input_iterator<InputIterator>::value,
                                InputIterator>::type last,
         const allocator_type& alloc = allocator_type()) {
    alloc_ = alloc;
    storage_alloc_ = storage_allocator_type();
    storage_ = NULL;
    size_ = 0;
    storage_size_ = 0;
    assign(first, last);
  }

  // destructor
  ~vector() { storage_alloc_.deallocate(storage_, storage_size_); }

  reference operator[](size_type n) { return reference(storage_, n); }

  const_reference operator[](size_type n) const {
    return reference(storage_, n);
  }

  /*** iterators ***/
  iterator begin() { return iterator(storage_, 0); }
  iterator end() { return iterator(storage_, size_); }
  // const_iterator begin() const { return const_iterator(values_); }
  // const_iterator end() const { return const_iterator(values_ + size_); }
  // reverse_iterator rbegin() { return reverse_iterator(end()); }
  // reverse_iterator rend() { return reverse_iterator(begin()); }

  // const_reverse_iterator rbegin() const {
  //   return ft::reverse_iterator<const_iterator>(end());
  // }

  // const_reverse_iterator rend() const {
  //   return ft::reverse_iterator<const_iterator>(begin());
  // }

  /*** capacity ***/
  size_type size() const { return size_; }
  size_type max_size() const { return (alloc_.max_size() / 2); }
  size_type capacity() const {
    return storage_size_ * sizeof(storage_size_) * CHAR_BIT;
  }

  bool empty() const { return (size_ == 0); }

  void reserve(size_type n) {
    // no need to reserve
    if (n <= capacity()) {
      return;
    }
    size_type new_storage_size = getStorageSize(n);
    storage_pointer new_storage = storage_alloc_.allocate(new_storage_size);
    if (storage_) {
      for (size_type cnt = 0; cnt < storage_size_; ++cnt) {
        new_storage[cnt] = storage_[cnt];
      }
      storage_alloc_.deallocate(storage_, storage_size_);
    }
    storage_ = new_storage;
    storage_size_ = new_storage_size;
  }

  void resize(size_type n, value_type val = value_type()) {
    if (n <= size_) {
      size_ = n;
      return;
    }
    if (n > capacity()) {
      reserve(getNewCapacity_(storage_size_, getStorageSize(n)) *
              sizeof(storage_type) * CHAR_BIT);
    }
    size_type bit_to_save = size_ % (sizeof(storage_type) * CHAR_BIT);
    size_type idx_to_bitfill = size_ / (sizeof(storage_type) * CHAR_BIT);
    if (bit_to_save < sizeof(storage_type) * CHAR_BIT) {
      storage_type mask = createMask_(bit_to_save);
      if (val == true) {
        storage_[idx_to_bitfill] |= mask;
      } else {
        storage_[idx_to_bitfill] &= ~mask;
      }
    }
    if (val) {
      for (size_type idx = idx_to_bitfill + 1; idx < storage_size_; ++idx) {
        storage_[idx] = ~(static_cast<storage_type>(0));
      }
    } else {
      for (size_type idx = idx_to_bitfill + 1; idx < storage_size_; ++idx) {
        storage_[idx] = static_cast<storage_type>(0);
      }
    }
    size_ = n;
  }

  /*** Element access ***/
  reference at(size_type n) {
    if (n >= size_) {
      throw std::out_of_range("vector");
    }
    return reference(storage_, n);
  }

  const_reference at(size_type n) const;

  reference front() { return reference(storage_, 0); }
  // const_reference front() const { return values_[0]; }

  reference back() { return reference(storage_, size_ - 1); }
  // const_reference back() const { return values_[size_ - 1]; }

  /*** modifiers ***/
  void assign(size_type n, const value_type& val) {
    size_ = n;
    size_type new_storage_size = getStorageSize(size_);

    if (storage_size_ < new_storage_size) {
      if (storage_) {
        storage_alloc_.deallocate(storage_, storage_size_);
      }
      new_storage_size = getNewCapacity_(storage_size_, new_storage_size);
      storage_ = storage_alloc_.allocate(new_storage_size);
      storage_size_ = new_storage_size;
    }
    if (val) {
      for (size_type idx = 0; idx < storage_size_; ++idx) {
        storage_[idx] = ~(static_cast<storage_type>(0));
      }
    } else {
      for (size_type idx = 0; idx < storage_size_; ++idx) {
        storage_[idx] = static_cast<storage_type>(0);
      }
    }
  }

  template <class InputIterator>
  typename ft::enable_if<ft::is_input_iterator<InputIterator>::value,
                         void>::type
  assign(InputIterator first, InputIterator last) {
    size_ = getSizeFromIterator(first, last);
    size_type new_storage_size = getStorageSize(size_);

    if (storage_size_ < new_storage_size) {
      if (storage_) {
        storage_alloc_.deallocate(storage_, storage_size_);
      }
      storage_ = storage_alloc_.allocate(new_storage_size);
      storage_size_ = new_storage_size;
    }
    size_type idx;
    InputIterator iter;
    for (iter = first, idx = 0; iter != last; ++iter, ++idx) {
      if (*iter) {
        storage_[idx / (sizeof(storage_type) * CHAR_BIT)] |=
            (1ULL << idx % (sizeof(storage_type) * CHAR_BIT));
      } else {
        storage_[idx / (sizeof(storage_type) * CHAR_BIT)] &=
            ~(1ULL << idx % (sizeof(storage_type) * CHAR_BIT));
      }
    }
  }

  void push_back(const value_type& val) { resize(size_ + 1, val); }

  iterator insert(iterator position, const value_type& val) {
    if (size_ + 1 > capacity()) {
      reserve(size_ + 1);
    }
    // size_type posidx = position.ref_.getIdx_();
    size_type posidx = (*position).getIdx_();
    size_type idx = posidx % (sizeof(storage_type) * CHAR_BIT);
    size_type storageidx = posidx / (sizeof(storage_type) * CHAR_BIT);
    storage_type mask = createMask_(idx);  // 111...111000...000
    storage_type bits_no_move = storage_[storageidx] & ~mask;
    storage_[storageidx] = ((storage_[storageidx] << 1) & mask) | bits_no_move;
    // move
    if (val) {
      storage_[storageidx] |= (1ULL << idx);
    } else {
      storage_[storageidx] &= ~(1ULL << idx);
    }
    size_++;
    return position;
  }

  void pop_back() { --size_; }

  void flip() {
    for (size_type cnt = 0; cnt < storage_size_; ++cnt) {
      storage_[cnt] = ~storage_[cnt];
    }
  }
};

}  // namespace ft

#endif /* VECTOR_HPP */
