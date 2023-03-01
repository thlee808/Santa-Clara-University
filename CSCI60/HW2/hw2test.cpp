// Test program for Homework 2; interface and implementation due 5pm 1/23/20
// Sara Krehbiel

#include <iostream>
#include "skittlesbag.h"
#include "skittlesdish.h"

using namespace std;

void test();

int main() {
  test();
  return 0;
}

//cout<<"I run"<<endl;
void test() {
  cout << "A small bag with nothing in it yet: ";
  SkittlesBag smallBag;
  cout << smallBag.size() << " skittles\n";
  cout << "The big bag on my desk: ";
  SkittlesBag bigBag(4,3,5,9,7);
  cout << bigBag.size() << " total, " << bigBag.count('r') << " reds\n";
  bigBag.printHistogram();


  cout << "\nLet's add a green to the small bag. ";
  smallBag.addOne('g');
  cout << "Number of greens: " << smallBag.count('g') << endl;

  cout << "\nSnack time! Let's balance that big bag out.\n";
  bigBag.evenOut();
  cout << "Let's try to eat 5 yellows from the big one.\n";
  bigBag.eat(5,'y');
  bigBag.printHistogram();

  cout << "\nA dish has entered the picture: ";
  SkittlesDish dish(10, "red");
  cout << dish.getCount() << " " << dish.getColor() << " skittles\n";
  cout << "Let's pour it in the big bag.\n";
  bigBag.pourInDish(dish);
  cout << "Bag contents:\n";
  bigBag.printHistogram();
  cout << "Dish: " << dish.getCount() << " " << dish.getColor() << "s\n";

  cout << "\nA new bag with just one green has entered the picture.\nIt is ";
  SkittlesBag newBag(0,0,1,0,0);
  cout << (newBag==smallBag ? "" : "not ") << "equal to the original and ";
  cout << (newBag==bigBag ? "" : "not ") << "equal to the big one.\n";

  cout << "\nFinally, let's add the new bag to the big bag.\n";
  bigBag+=newBag;
  cout << "New bag contents: " << newBag.size() << " skittles.\n";
  cout << "Big bag contents: \n";
  bigBag.printHistogram();

}
