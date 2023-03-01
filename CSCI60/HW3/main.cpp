//Travis Lee and Brycen Tanaka

#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include "biguint.h"

int main()
{
  biguint a("1234");
  biguint b("7");
  biguint c("1233");
  cout << a[3] << endl;
  cout << a << endl;
  cout << endl;
  biguint d("40");
  cout << a - d << endl;
  cout << a - b <<endl;
  cout<<endl;
  a -= d;
  cout << a <<endl;
  cout << a.toString() << endl;

  return 0;
}
