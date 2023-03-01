// HW5 starter file: a finished implementation of DynamicBag

#include "dynamicbag.h"

// create an empty bag (no heap memory allocation)
DynamicBag::DynamicBag() {
  used_ = 0;
  capacity_ = 0;
  data_ = nullptr;
}

// copy constructor deep copies contents of b
DynamicBag::DynamicBag(const DynamicBag & b) {
  if (b.capacity_>0) {
    data_ = new int[b.capacity_];
    for (size_t i=0; i<b.used_; i++) {
      data_[i] = b.data_[i];
    }
  } else {
    data_ = nullptr;
  }
  capacity_ = b.capacity_;
  used_ = b.used_;
}

// destructor releases a bag's dynamic memory before it passes out of scope
DynamicBag::~DynamicBag() {
  delete [] data_;
  data_ = nullptr; // not necessary but good practice
}


// sweep through data array, counting # occurrences of target (same as Bag)
size_t DynamicBag::count(int target) const {
  size_t count = 0;
  for (size_t i=0; i<used_; i++) {
    if (data_[i]==target) count++;
  }
  return count;
}

// inserts target in next available slot, first increasing capacity if needed:
// if empty, increase capacity to one; otherwise, double capacity
void DynamicBag::insert(int target) {
  if (capacity_ == 0) { // currently empty
    // allocate cap 1 array
    capacity_ = 1;
    data_ = new int[capacity_];
  } else if (capacity_ == used_) { // currently full (and nonempty)
    // allocate array of double capacity
    capacity_ *= 2;
    int *temp = new int[capacity_];
    // copy existing data into newly allocated array
    for (size_t i = 0; i<used_; i++) {
      temp[i] = data_[i];
    }
    // release old array memory after copying and reassign pointer to new array
    delete [] data_;
    data_ = temp;
  }
  // once capacity_>used_, insert the target into the first available slot
  data_[used_] = target;
  used_++;
}

// erase_one from static array implementation
bool DynamicBag::erase_one(int target) {
  // sweep array looking for first target
  size_t i=0;
  while (i<used_ && data_[i]!=target) i++;
  if (i==used_) return false; // if nothing is found

  // shift everything after target back one and decrement used_
  for (i++; i<used_; i++) {
    data_[i-1]=data_[i];
  }
  used_--;

  // downsize array if we get to quarter capacity
  if (used_ <= .25*capacity_ ) {
    capacity_ /= 2;
    int *temp = new int[capacity_];
    for (size_t i = 0; i<used_; i++) {
      temp[i] = data_[i];
    }
    delete [] data_;
    data_ = temp;
  }

  return true;
}

// as with static array implementation, erase iteratively calls erase_one
size_t DynamicBag::erase(int target) {
  size_t count=0;
  while (erase_one(target)) count++;
  return count;
}

// iteratively insert each entry into the ostream
std::ostream& operator <<(std::ostream& out, const DynamicBag& b) {
  for (size_t i=0; i<b.size(); i++) {
    out << b[i] << " ";
  }
  return out;
}

// assignment operator does a deep copy of the contents of b into this bag
void DynamicBag::operator =(const DynamicBag &b) {
  used_ = b.used_;
  if (capacity_ != b.capacity_) {
    capacity_ = b.capacity_;
    delete [] data_; // bad if lhs==rhs bc we're killing data we need
    data_ = new int[capacity_]; // unnecessary if capacities are the same
  }
  for (size_t i=0; i<used_; i++) {
    data_[i] = b.data_[i];
  }
}
