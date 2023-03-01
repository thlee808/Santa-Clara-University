//Travis Lee
//The parent class is a pair of shoes and the child class is a pair of Nikes.
//Nikes have swooshes and shoes dont, so the new private member is number of swooshes.
//The new function is counting the number of swooshes on the pair of nikes.
//The redefined version of the function areTheyCool takes into account the number of swooshes
//on the shoe. It isn't a cool pair of shoes if there are too many swooshes (over 10).
//You could also say that the constructors are redefined functions too.
//My child class constructors didnt work unless they were in line.

#include <iostream>
#include <cstdlib>
using namespace std;

void coolCheck(bool coolness);

class PairOfShoes
{
public:
  PairOfShoes();
  PairOfShoes(double size, double price, bool colors, bool design);
  double getSize() const {return shoeSize_;}
  double getPrice() const {return price_;}
  bool checkColor() const {return niceColors_;}
  bool checkDesign() const {return niceDesign_;}
  bool areTheyCool();
private:
  double shoeSize_;
  double price_;
  bool niceColors_;
  bool niceDesign_;
};

class PairOfNikes : public PairOfShoes
{
public:
  PairOfNikes() : PairOfShoes(), numOfSwooshes_(0) {}
  PairOfNikes(double size, double price, bool colors, bool design, size_t swooshes) : PairOfShoes(size, price, colors, design), numOfSwooshes_(swooshes) {}
  size_t countSwooshes() const {return numOfSwooshes_;}
  bool areTheyCool();
private:
  size_t numOfSwooshes_;
};

int main()
{
  //expected: dont like
  PairOfShoes a(9.5, 95.50, true, false);
  coolCheck(a.areTheyCool());

  //expected: like
  PairOfShoes b(6, 60.00, true, true);
  coolCheck(b.areTheyCool());

  //expected: 14 and dont like
  PairOfNikes c(10.0, 110.00, true, true, 14);
  cout << c.countSwooshes() << endl;
  coolCheck(c.areTheyCool());

  //expected: 6 and like
  PairOfNikes d(15.5, 225.00, true, true, 6);
  cout << d.countSwooshes() << endl;
  coolCheck(d.areTheyCool());

  return 0;
}

PairOfShoes::PairOfShoes()
{
  shoeSize_ = 0;
  price_ = 0;
  niceColors_ = false;
  niceDesign_ = false;
}

PairOfShoes::PairOfShoes(double size, double price, bool colors, bool design)
{
  shoeSize_ = size;
  price_ = price;
  niceColors_ = colors;
  niceDesign_ = design;
}

bool PairOfShoes::areTheyCool()
{
  if (niceColors_ == true && niceDesign_ == true)
  {
    return true;
  }
  return false;
}

/*PairOfNikes::PairOfNikes()
{
  PairOfShoes();
  numOfSwooshes_ = 0;
}

PairOfNikes::PairOfNikes(double size, double price, bool colors, bool design, size_t swooshes)
{
  PairOfShoes(size, price, colors, design);
  if (checkColor() == true)
  {
    cout << "true" << endl;
  }
  else
  {
    cout<<"false"<<endl;
  }
  numOfSwooshes_ = swooshes;
}*/

bool PairOfNikes::areTheyCool()
{
  if (numOfSwooshes_ > 10)
  {
    return false;
  }

  if (checkColor() == true && checkDesign() == true)
  {
    return true;
  }
  return false;
}

void coolCheck(bool coolness)
{
  if (coolness == true)
  {
    cout << "Those are some nice shoes!" << endl;
  }
  else
  {
    cout << "I dont like those shoes." << endl;
  }
}
