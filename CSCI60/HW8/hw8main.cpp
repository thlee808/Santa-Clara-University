// Sample test file for HW8 (don't turn this in)
// Sara Krehbiel, 2/26/20

#include <iostream>
#include "node.h"

using namespace std;

int main() {
  cout << "Q1 test:\n";
  for (int i=0; i<10; i++) {
    cout << "a_" << i << "=" << sequence(i) << endl;
  }

  cout << "\nQ3 test:\n";
  int a1[7] = {1,2,3,4,5,6,7};
  reverse(a1,0,6);
  for (int i=0; i<7; cout << a1[i++] << " ") {}
  cout << endl;
  int a2[4] = {4, 7, 3, 12};
  reverse(a2,0,3);
  for (int i=0; i<4; cout << a2[i++] << " ") {}
  cout << endl;

  cout << "\nQ2 and Q4 tests:\n";
  node *head=nullptr, *tail=nullptr;
  head = tail = new node(3,head);
  head = new node(4,head);
  head = new node(5,head);
  cout << "Initially: " << head << endl;

  list_reverse(head,tail);
  cout << "After reversing: " << head << endl;

  list_clear(head,tail);
  cout << "After clearing: " << head << endl;

  return 0;
}
