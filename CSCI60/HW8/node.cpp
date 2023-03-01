// Implementation file for HW8
// Travis Lee

#include "node.h"

// 2-arg node constructor
node::node(const value_type& data, node * link) : data_(data), link_(link) {}

// overloaded << for debugging
std::ostream& operator <<(std::ostream& out, const node * head) {
  for (const node* p=head; p!=nullptr; p=p->link()) {
    out << p->data() << " ";
  }
  return out;
}

// TODO: your implementations go here!

int sequence(int n)
{
  int output;
  if (n <= 1)
  {
    return 1;
  }
  else
  {
    return sequence(n-2) + n - 1;
  }

}

void list_clear(node * & head_ptr, node * & tail_ptr)
{
  node * pointer = head_ptr;
  if (pointer == tail_ptr)
  {
    delete pointer;
    head_ptr = tail_ptr = nullptr;
    return;
  }
  else
  {
    head_ptr = pointer->link();
    delete pointer;
    list_clear(head_ptr, tail_ptr);
  }
}

void reverse(int a[], int start, int end)
{
  if (end - start <= 1)
  {
    if (end - start == 0) return;
    int temp;
    temp = a[end];
    a[end] = a[start];
    a[start] = temp;
    return;
  }
  else
  {
    int temp;
    temp = a[end];
    a[end] = a[start];
    a[start] = temp;
    reverse(a, start + 1, end - 1);
  }
}

void list_reverse(node*& head, node*& tail)
{
  std::cout<<"hello";
  node *swapFirst = head->link();
  node *swapSecond;
  for (node *p = head; p != tail; p = p->link())
  {
    swapSecond = p;
  }

  std::cout << swapFirst->data() << std::endl;
  std::cout << swapSecond->data() << std::endl;

  if (swapFirst == swapSecond) std::cout << "helloP2" << std::endl;

  node::value_type temp;
  while (swapFirst != swapSecond)
  {
    std::cout << "here" << std::endl;
    if (swapFirst->link() != swapSecond)
    {
      ]
      temp = swapFirst->data();
      swapFirst->set_data(swapSecond->data());
      swapSecond->set_data(temp);
      return;
    }
    std::cout << "here2" << std::endl;
    node::value_type temp;
    temp = swapFirst->data();
    swapFirst->set_data(swapSecond->data());
    swapSecond->set_data(temp);
    swapFirst->link();
    node *newStop = swapSecond;
    for (swapSecond = head; swapSecond != newStop; swapSecond = swapSecond->link()) {}
  }

  temp = head->data();
  head->set_data(tail->data());
  tail->set_data(temp);
  return;

  std::cout<<"hello";
  //need to find node * one before tail everytime to make swap work
  node *headR = head->link();
  node *tailR = tail;
  if(headR == tailR || headR->link() == tailR)
  {
    if (headR == tailR) return;
    node::value_type temp;
    temp = headR->data();
    std::cout << temp << std::endl;
    std::cout << tailR->data() << std::endl;
    headR->set_data(tailR->data());
    tailR->set_data(temp);
    return;
  }
  else
  {
    node::value_type temp;
    temp = headR->data();
    headR->set_data(tailR->data());
    tailR->set_data(temp);
    node *newTail;
    for (node *newTail = head; newTail != tailR; newTail = newTail->link()) {}
    tailR = newTail;
    //headR = headR->link();
    list_reverse(headR, newTail);
  }*/
}
//actual
/*node *swapFirst = head->link();
node *swapSecond;
for (node *p = head; p != tail; p = p->link())
{
  swapSecond = p;
}
node::value_type temp;
while (swapFirst != swapSecond)
{
  if (swapFirst->link() == swapSecond)
  {
    temp = swapFirst->data();
    swapFirst->set_data(swapSecond->data());
    swapSecond->set_data(temp);
    return;
  }
  node::value_type temp;
  temp = swapFirst->data();
  swapFirst->set_data(swapSecond->data());
  swapSecond->set_data(temp);
  swapFirst = swapFirst->link();
  node *newStop = swapSecond;
  for (node *p = head; p != newStop; p = p->link())
  {
    swapSecond = p;
  }
}

temp = head->data();
head->set_data(tail->data());
tail->set_data(temp);
return;*/
