// HW6 starter file
// Travis Lee

#include <iostream>
#include <vector>

using namespace std;

/* Part 1 */
template<typename T>
ostream& operator <<(ostream& out, vector<T> v)
{
  for (auto elem : v)
  {
    out << elem << ", ";
  }
  return out;
}


/* Part 2 */
template<typename T1, typename T2>
class Pair{
public:
  Pair() : x(T1()), y(T2()) {}
  Pair(T1 xParameter, T2 yParameter) : x(xParameter), y(yParameter) {}
  T1 getX() const {return x;}
  T2 getY() const {return y;}
  Pair operator +(const Pair& rhs) const;
private:
  T1 x;
  T2 y;
};

template<typename T1, typename T2>
Pair<T1, T2> Pair<T1, T2>::operator +(const Pair& rhs) const
{
  T1 xSum = getX() + rhs.getX();
  T2 ySum = getY() + rhs.getY();
  Pair sum(xSum, ySum);
  return sum;
}

template<typename T1, typename T2>
ostream& operator <<(ostream& out, const Pair<T1, T2>& p)
{
  out << '(' << p.getX() << ", " << p.getY() << ')';
  return out;
}


/* Part 3 */
class Rational {
public:
  Rational(int n, int d) : n(n), d(d) { reduce(); } // sets up n/d, reduced
  Rational(int n) : n(n), d(1) {}; // sets up n/1
  Rational() : n(0), d(1) {} // sets up 0/1
  int getN() const { return n; }
  int getD() const { return d; }
  double getVal() const { return 1.0*n/d; } // returns the double value
  void set(int n, int d) { this->n = n; this->d = d; reduce(); } // sets values
  void reduce(); // TODO: implement this out-of-line below
  Rational operator +(const Rational& rhs) const; // TODO: implement this too!
private:
  int n, d;
};

void Rational::reduce()
{
  int modValue, modResult, factor;
  if (n > d)
  {
    modValue = n%d;
  }
  else
  {
    modValue = d%n;
  }
  if (n%modValue == d%modValue)
  {
    modResult = n%modValue;
    factor = modValue - modResult;
    n /= factor;
    d /= factor;
  }

  if (d < 0 && n > 0)
  {
    d *= -1;
    n *= -1;
  }
}

/*void Rational::operator +()
{

}*/

ostream& operator <<(ostream& out, const Rational& r)
{
  out << r.getN();
  if (r.getD() != 1)
  {
    out << '/' << r.getD();
  }

  return out;
}



/* Part 4 */
int main() {

  //part 1 check
  vector<int> intVec = {2,4,4,-1};
  cout << intVec << endl;

  //part 2 check
  Pair<int, double> p1(1, 0.6);
  Pair<int, double> p2(4, 0.8);
  cout << p1 + p2 << endl;

  //part 3 check
  Rational r1(18, 66);
  cout << r1 << endl;
  Rational r2(3, -6);
  cout << r2 << endl;
  Rational r3(-8, -4);
  cout << r3 << endl;

  //Rational test
  cout << endl;
  cout << "Rational Test" << endl;
  vector<Rational> rationalVec = {r1, r2, r3};
  cout << rationalVec << endl;

  //Pair of Rationals test
  Pair<double, Rational> p3(1.0, r1);
  Pair<double, Rational> p4(4.3, r2);
  Pair<double, Rational> p5(-8.9, r3);
  vector<Pair<double, Rational>> pairVec = {p3, p4, p5};
  cout << pairVec << endl;

  return 0;
}
