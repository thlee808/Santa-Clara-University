// Node interface/implementation for HW8 (don't turn this in)
// Sara Krehbiel, modified code from Natalie Linnell and Nicholas Tran, 2/26/20

#ifndef NODE_H
#define NODE_H
#include <iostream>

// class definition for a node representing one element in a linked list
class node {
public:
  typedef int value_type;

  // constructor, accessors, and mutators
  node(const value_type & = value_type(), node * = nullptr);
  value_type data() const { return data_; }
  node * link() const { return link_; }
  void set_data(const value_type & newdata) { data_ = newdata; }
  void set_link(node * newlink) { link_ = newlink; }

private:
  value_type data_;
  node * link_;
};

// overloaded operator for testing
std::ostream& operator <<(std::ostream& out, const node * head);

// declarations for HW8 functions
int sequence(int n); // Q1
void list_clear(node * & head_ptr, node * & tail_ptr); // Q2
void reverse(int a[], int first, int last); // Q3
void list_reverse(node*& head, node*& tail); // Q4

#endif // NODE_H
