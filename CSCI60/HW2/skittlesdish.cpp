// Task: Separate interface, implementation, and testing into three files
// Sara Krehbiel, 1/13/20 (Day 4, file 3/3: the implementation file)

#include "skittlesdish.h"

SkittlesDish::SkittlesDish() : count(0), color("red") { }

SkittlesDish::SkittlesDish(int initialCount, string color) :
    count(initialCount), color(color) {}

int SkittlesDish::getCount() const{
  return count;
}

string SkittlesDish::getColor() const {
  return color;
}

void SkittlesDish::addSkittles(int numToAdd) {
  count += numToAdd;
}

void SkittlesDish::eatSkittles(int numToEat) {
  if (count<numToEat) {
    cout << "You tried to eat too many :-(\n";
  } else {
    count -= numToEat;
  }
}

// == as member function
bool SkittlesDish::operator ==(const SkittlesDish& rhs) const {
  return (count==rhs.count && color==rhs.color);
}

// < as a nonmember friend function
bool operator <(const SkittlesDish& lhs, const SkittlesDish& rhs) {
  return (lhs.count < rhs.count);
}

// += as a nonmember nonfriend function
SkittlesDish operator +=(SkittlesDish& lhs, SkittlesDish& rhs) {
  if (lhs.getColor()!=rhs.getColor()) { // check for illegal combine attempt
    cout << "Error! You can't combine those dishes\n";
  } else {
    int n = rhs.getCount(); // local copy of starting value in rhs
    rhs.eatSkittles(n); // "eat" as public way of emptying rhs
    lhs.addSkittles(n); // add the same number of skittles to lhs
  }
  return lhs; // convention for +=
}

// += as a member function (declaration in .h file would also change)
// note both private fields of "this" (previously lhs) and rhs are accessible
/*void SkittlesDish::operator +=(SkittlesDish& rhs) {
  if (color!=rhs.color) {
    cout << "Error! You can't combine those dishes\n";
  } else {
    count += rhs.count;
    rhs.count = 0;
  }
  // if we're fine with breaking convention, we can make this function void;
  // otherwise, as the SkittlesDish return val we'd have to return *this;
}*/
