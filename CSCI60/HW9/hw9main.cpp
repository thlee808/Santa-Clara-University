// Sample test file for HW9 - don't submit this, but modify it as you test.
// Some code is commented out so this compiles and runs with the starter files.
// Sara Krehbiel, 3/5/20

#include <iostream>
#include "lbag.cpp" // linked list implementation
#include "bag.cpp" // dynamic array implementation

using namespace std;

void q1test();
void q2test();
void q3test();

int main() {
  q1test();
  q2test();
  q3test();
  return 0;
}

void q1test() {
  cout << "\nQ1 test:\n";
  LBag<int> b;
  for (int i=0; i<5; i++) {
    b.insert(i);
  }
  cout << "(" << b << ") " << (b.isSorted()?"is":"is not") << " sorted\n";
  b.~LBag<int>();
  for (int i=10; i>0; i--) {
    b.insert(i);
  }
  cout << "(" << b << ") " << (b.isSorted()?"is":"is not") << " sorted\n";
}

void q2test() {
  cout << "\nQ2 test:\n";
  LBag<int> b;
  for (int i=0; i<1000; i++) {
    b.insert(4);
  }
  for (int i=0; i<1000; i++) {
    b.insert(2);
  }
  cout << b.count(2) << " 2's and " << b.count(4) << " 4's\n";
  cout << b.erase(4) << " 4's erased\n";
  cout << b.count(2) << " 2's and " << b.count(4) << " 4's\n";
}

void q3test() {
  cout << "\nQ3 test:\n";
  Bag<int> b;
  for (int i=0; i<5; i++) {
    b.insert(i);
  }
  for (auto e : b) cout << e*e << endl;
}
