// HW5 test file for Question 1: DynamicSet as a class derived from DynamicBag

#include "dynamicbag.h"
#include "dynamicset.h"
#include <iostream>
#include <cstdlib>
using namespace std;

void bagTest();
void setTest();

int main() {
  bagTest();
  setTest();
  return 0;
}

void bagTest() {
  cout << "\nBag test!\n";
  DynamicBag b;
  cout << "\nInsert 1-7\n";
  for(int i=1; i<=7; i++) {
    b.insert(i);
  }

  cout << "\nInsert ten 8's\n";
  for (int i=1; i<=10; i++) {
    b.insert(8);
  }
  cout << b << endl;

  cout << "\nErase all " << b.erase(8) << " 8's\n";
  cout << b << endl;
}

void setTest() {
  cout << "\nSet test!\n";
  DynamicSet s;
  cout << "\nInsert 1-7\n";
  for(int i=1; i<=7; i++) {
    s.insert(i);
  }

  cout << "\nInsert ten 8's\n";
  for (int i=1; i<=10; i++) {
    s.insert(8);
  }
  cout << s << endl;

  cout << "\nErase all " << s.erase(8) << " 8's\n";
  cout << s << endl;

  cout << "\nRemove the 5\n";
  s.remove(5);
  cout << s << endl;

  cout << "\nRemove a 10\n";
  s.remove(10);
  cout << s << endl;
}
