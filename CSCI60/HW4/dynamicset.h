// DynamicSet interface: A collection of NON-REPEATING ints; supports dynamic
//   memory management, size, contains, insert, remove, and operators overloaded
//   for array-style access [], deep copy assignment =, and set operations:
//   union +, intersection *, and difference -.

// Krehbiel, 1/31/20

#ifndef DYNAMICSET_H
#define DYNAMICSET_H

#include <cstdlib>
#include <algorithm>
#include <ostream>
#include <iostream>

using std::size_t;

class DynamicSet {
public:

  // CONSTRUCTORS & DESTRUCTOR

  // 0-arg constructor
  // pre: none
  // post: creates an empty DynamicSet
  DynamicSet();

  // pre: none
  // post: creates a new DynamicSet which is a copy of the given one
  DynamicSet(const DynamicSet & s);

  // pre: none
  // post: destroys dynamic memory associated with this DynamicSet
  ~DynamicSet();

  // CONSTANT ACCESSING MEMBERS

  // pre: none
  // post: returns the number of elements in this DynamicSet
  size_t size() const {return used_;}

  // pre: none
  // post: returns whether the target appears in this DynamicSet
  bool contains(int target) const;

  // pre: pos<capacity_
  // post: returns the pos(th) item in this DynamicSet
  int operator [](size_t pos) const {return data_[pos];}

  // MUTATING MEMBERS

  // pre: none
  // post: adds a copy of target to this DynamicSet if it is not already present
  void insert(int target);

  // pre: none
  // post: remove target and return true if it's in the set; else return false
  bool remove(int target);

  // pre: none
  // post: makes this set a copy of s2
  void operator =(const DynamicSet & s2);

  // pre: s2 is a DynamicSet object
  // post: this set has been UNIONED with s2 (now contains all of s2's contents)
  void operator +=(const DynamicSet & s2);

  // pre: s2 is a DynamicSet objects
  // post: this set has ben INTERSECTED with s2 (elems not in s2 are removed)
  void operator *=(const DynamicSet & s2);

  // pre: s2 is a DynamicSet object
  // post: elements in s2 have been removed from this set
  void operator -=(const DynamicSet & s2);

private:
  int *data_;
  size_t capacity_;
  size_t used_;

  // INVARIANTS:
  //   data_ points a dynamically allocated array of size capacity_
  //   data_[0], data_[1], ..., data_[used_-1] store the elements
  //   data_[used_], ..., data_[capacity_-1] contains garbage
};

// pre: s1 and s2 are DynamicSet objects
// post: UNION returns a DynamicSet with every element in s1 or s2
DynamicSet operator +(const DynamicSet & s1, const DynamicSet & s2);

// pre: s1 and s2 are DynamicSet objects
// post: INTERSECTION returns a DynamicSet with every elements in s1 and s2
DynamicSet operator *(const DynamicSet & s1, const DynamicSet & s2);

// pre: s1 and s2 are DynamicSet objects
// post: DIFFERENCE returns a DynamicSet with every element in s1 and not s2
DynamicSet operator -(const DynamicSet & s1, const DynamicSet & s2);

// pre: none
// post: each entry of s has been inserted into out
std::ostream& operator <<(std::ostream& out, const DynamicSet & s);

#endif // DYNAMICSET_H
