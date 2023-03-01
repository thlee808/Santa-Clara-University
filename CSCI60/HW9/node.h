// interface and implementation file for HW9 -- don't modify or submit

#ifndef NODE_H
#define NODE_H
#include <iostream>

// class definition for a node representing one element in a linked list

template<typename T>
class node {
public:
  // 2-arg constructor with defaults
  node(const T & data = T(), node<T> * link = nullptr) : data_(data), link_(link) {}

  // accessors
  T data() const { return data_; }
  node<T> * link() const { return link_; }

  // mutators
  void set_data(const T & newdata) { data_ = newdata; }
  void set_link(node<T> * newlink) { link_ = newlink; }

private:
  T data_;
  node<T> * link_;
  // invariants: data_ is the node value and link_ points to next node
};

template<typename T>
std::size_t list_size(const node<T> * head) {
  int count=0;
  for (const node<T> * p=head; p!=nullptr; p=p->link()) {
    count++;
  }
  return count;
}

template<typename T>
std::ostream& operator <<(std::ostream& out, const node<T> * head) {
  for (const node<T> * p=head; p!=nullptr; p=p->link()) {
    out << p->data() << " ";
  }
  return out;
}

template<typename T>
void list_insert_head(node<T>*& head, node<T>*& tail, const T& val) {
  head = new node<T>(val,head); // point head to new node pointing to old head
  if (tail==nullptr) tail=head; // set tail ptr if list was empty before
}

template<typename T>
void list_insert_tail(node<T>*& head, node<T>*& tail, const T& val) {
  if (tail==nullptr) { // same as head insert if empty
    list_insert_head(head,tail,val);
    return;
  }
  // if size>0, link new node to current tail and update tail ptr
  tail->set_link(new node<T>(val,nullptr));
  tail = tail->link();
}

template<typename T>
void list_remove_head(node<T>*& head, node<T>*& tail) {
  if (head==nullptr) return; // do nothing if size=0
  // if size>0, find second, delete head node, and point head to second
  node<T>* second = head->link();
  delete head;
  head = second;
  if (second==nullptr) tail = nullptr; // if size *was* 1, update tail
}

template<typename T>
void list_remove_tail(node<T>*& head, node<T>*& tail) {
  if (head==tail) { // do nothing if size=0; delete and update head/tail if 1
    if (head==nullptr) return;
    delete head;
    head = tail = nullptr;
    return;
  }
  // if size>1, find second to last node before deleting and updating tail
  node<T> *penultimate;
  for (penultimate=head; penultimate->link()!=tail; penultimate=penultimate->link());
  delete tail;
  tail = penultimate;
  tail->set_link(nullptr);
}


#endif // NODE_H
