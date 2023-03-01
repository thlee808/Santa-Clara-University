//Travis Lee
#include <cstdlib>
#include <algorithm>
#include <ostream>
#include <iostream>
#include "dynamicset.h"

using namespace std;

int main()
{

  DynamicSet a;
  a.insert(1);
  a.insert(2);
  a.insert(3);
  a.insert(4);

  cout << "a: " << a << endl;

  DynamicSet b;
  b.insert(3);
  b.insert(4);
  b.insert(5);
  b.insert(6);

  cout << "b: " << b << endl;

  DynamicSet result;

  result = a + b;
  cout << "union result: " << result << endl;

  result = a * b;
  cout << "intersection result: " << result << endl;

  result = a - b;
  cout << "difference result: " << result << endl;

  a += b;
  cout << "union(+=): " << a << endl;

  //reseting a
  a.remove(5);
  a.remove(6);

  a *= b;
  cout << "intersection(*=): " << a << endl;

  //reseting a
  a.insert(1);
  a.insert(2);
  a.remove(3);
  a.remove(4);
  a.insert(3);
  a.insert(4);

  a -= b;
  cout << "difference(-=): " << a << endl;

  return 0;
}
