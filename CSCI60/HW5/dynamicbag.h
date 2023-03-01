// HW5 starter file: a complete interface for DynamicBag

#ifndef DYNAMICBAG_H
#define DYNAMICBAG_H

#include <cstdlib>
#include <algorithm>
#include <ostream>
#include <iostream>

using std::size_t;

class DynamicBag {
public:

  // CONSTRUCTORS & DESTRUCTOR

  // 0-arg constructor
  // pre: none
  // post: creates an empty DynamicBag
  DynamicBag();

  // pre: none
  // post: creates a new DynamicBag which is a copy of the given one
  DynamicBag(const DynamicBag & b);

  // pre: none
  // post: destroys dynamic memory associated with this DynamicBag
  ~DynamicBag();

  // CONSTANT ACCESSING MEMBERS

  // pre: none
  // post: returns the number of elements in this DynamicBag
  size_t size() const {return used_;}

  // pre: none
  // post: returns the number of elements in this DynamicBag
  size_t count(int t) const;

  // pre: pos<capacity_
  // post: returns the pos(th) item in this DynamicBag
  int operator [](size_t pos) const {return data_[pos];}

  // MUTATING MEMBERS

  // pre: none
  // post: adds a copy of target to this DynamicBag
  void insert(int target);

  // pre: none
  // post: if target appears in this DynamicBag, remove one copy and
  //       return true; else return false
  bool erase_one(int target);

  // pre: none
  // post: removes every copy of target in this DynamicBag and
  //       returns the number of elements removed
  size_t erase(int target);

  // pre: none
  // post: makes this bag a copy of rhs
  void operator =(const DynamicBag &rhs);

private:
  int *data_;
  size_t capacity_;
  size_t used_;

  // INVARIANTS:
  //   data_ points a dynamically allocated array of size capacity_
  //   data_[0], data_[1], ..., data_[used_-1] store the elements
  //   data_[used_], ..., data_[capacity_-1] contains garbage
};


// pre: none
// post: each entry of b has been inserted into out
std::ostream& operator <<(std::ostream& out, const DynamicBag& b);

#endif // DYNAMICSET_H
