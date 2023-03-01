// Starter file for HW9 Q3:
// Add begin and end member functions to the Bag class, and define A_iterator
// to work as an iterator for any array-based container-style class.

// Travis Lee

#ifndef BAG_H
#define BAG_H

#include <cstdlib>
#include <algorithm>
#include <ostream>
#include <iostream>

using std::size_t;

template <typename T>
class A_iterator{
public:
  A_iterator(T * p = nullptr) : current(p) {}
  T operator *() const {return *current;}
  //pre ++
  A_iterator<T> operator ++();
  //post ++
  A_iterator<T> operator ++(int);
  bool operator !=(const A_iterator<T>& rhs) const {return (current != rhs.current);}
  bool operator ==(const A_iterator<T>& rhs) const {return (current == rhs.current);}
private:
  T * current;
};

template<typename T>
class Bag {
public:
  typedef A_iterator<T> iterator;
  // 0-arg constructor, copy constructor, and destructor
  Bag();
  Bag(const Bag<T> & b);
  ~Bag();
  // accessors
  size_t size() const {return used_;}
  size_t count(T target) const;
  T operator [](size_t pos) const {return data_[pos];}
  // mutators
  void insert(T target);
  bool erase_one(T target);
  size_t erase(T target);
  // overloaded assignment operator
  void operator =(const Bag<T> &b);
  iterator begin() {return iterator(data_);}
  iterator end() {return iterator(data_ + used_);} //maybe used + 1
private:
  T *data_;
  size_t capacity_;
  size_t used_;
};

template<typename T>
A_iterator<T> A_iterator<T>::operator ++()
{
  ++current;
  return (*this);
}

template<typename T>
A_iterator<T> A_iterator<T>::operator ++(int)
{
  T * before = current;
  current + 1;
  return before;
}


// overloaded insertion operator: iteratively insert each entry into the ostream
template<typename T>
std::ostream& operator <<(std::ostream& out, const Bag<T>& b) {
  for (size_t i=0; i<b.size(); i++) {
    out << b[i] << " "; // << should be overloaded for T
  }
  return out;
}

// create an empty bag (no heap memory allocation)
template<typename T>
Bag<T>::Bag() {
  used_ = 0;
  capacity_ = 0;
  data_ = nullptr;
}

// copy constructor deep copies contents of b
template<typename T>
Bag<T>::Bag(const Bag<T> & b) {
  if (b.capacity_>0) {
    data_ = new T[b.capacity_];
    for (size_t i=0; i<b.used_; i++) {
      data_[i] = b.data_[i]; // this will shallow-copy T if = isn't overloaded
    }
  } else {
    data_ = nullptr;
  }
  capacity_ = b.capacity_;
  used_ = b.used_;
}

// destructor releases a bag's dynamic memory before it passes out of scope
template<typename T>
Bag<T>::~Bag() {
  delete [] data_;
  data_ = nullptr;
}


// sweep through data array, counting # occurrences of target (same as Bag)
template<typename T>
size_t Bag<T>::count(T target) const {
  size_t count = 0;
  for (size_t i=0; i<used_; i++) {
    if (data_[i]==target) count++; // T has to have == overloaded
  }
  return count;
}

// inserts target in next available slot, first increasing capacity if needed
template<typename T>
void Bag<T>::insert(T target) {
  if (capacity_ == 0) { // currently empty
    capacity_ = 1;
    data_ = new T[capacity_];
  } else if (capacity_ == used_) { // currently full (and nonempty)
    capacity_ *= 2;
    T *temp = new T[capacity_];
    for (size_t i = 0; i<used_; i++) {
      temp[i] = data_[i];
    }
    delete [] data_;
    data_ = temp;
  }
  // once capacity_>used_, insert the target into the first available slot
  data_[used_] = target;
  used_++;
}

// linear search for target; remove and possibly halve capacity if found
template<typename T>
bool Bag<T>::erase_one(T target) {
  size_t i=0;
  while (i<used_ && data_[i]!=target) i++; // also overload != for T
  if (i==used_) return false;
  for (i++; i<used_; i++) {
    data_[i-1]=data_[i];
  }
  used_--;
  if (used_ <= .25*capacity_ ) {
    capacity_ /= 2;
    T *temp = new T[capacity_];
    for (size_t i = 0; i<used_; i++) {
      temp[i] = data_[i];
    }
    delete [] data_;
    data_ = temp;
  }
  return true;
}

// iteratively call erase_one, keeping track of # removed while removing
template<typename T>
size_t Bag<T>::erase(T target) {
  size_t count=0;
  while (erase_one(target)) count++;
  return count;
}

// deep copy the contents of b into this bag
template<typename T>
void Bag<T>::operator =(const Bag<T> &b) {
  used_ = b.used_;
  if (capacity_ != b.capacity_) {
    capacity_ = b.capacity_;
    delete [] data_;
    data_ = new T[capacity_];
  }
  for (size_t i=0; i<used_; i++) {
    data_[i] = b.data_[i]; // only shallow-copies entries if T isn't overloaded
  }
}



#endif // BAG_H
