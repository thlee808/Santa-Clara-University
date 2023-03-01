// Implementation starter file for Homework 2; due 5pm 1/23/20
// Travis Lee

#include "skittlesbag.h"

SkittlesBag::SkittlesBag(int redP, int yellowP, int greenP, int orangeP, int purpleP)
{
  red = redP;
  yellow = yellowP;
  green = greenP;
  orange = orangeP;
  purple = purpleP;
}

int SkittlesBag::count(char color) const
{
  if (color == 'r')
  {
    return red;
  }
  else if (color == 'y')
  {
    return yellow;
  }
  else if (color == 'g')
  {
    return green;
  }
  else if (color == 'o')
  {
    return orange;
  }
  else if (color == 'p')
  {
    return purple;
  }
  else
  {
    cout << "Not a valid input\n";
    return 0;
  }
}

void SkittlesBag::printHistogram() const
{
  cout << "r: ";
  for (int i = 0; i < red; i++)
  {
    cout << '*';
  }
  cout << "\n";
  cout << "y: ";
  for (int i = 0; i < yellow; i++)
  {
    cout << '*';
  }
  cout << "\n";
  cout << "g: ";
  for (int i = 0; i < green; i++)
  {
    cout << '*';
  }
  cout << "\n";
  cout << "o: ";
  for (int i = 0; i < orange; i++)
  {
    cout << '*';
  }
  cout << "\n";
  cout << "p: ";
  for (int i = 0; i < purple; i++)
  {
    cout << '*';
  }
  cout << "\n";
}

void SkittlesBag::addOne(char color)
{
  if (color == 'r')
  {
    red++;
  }
  else if (color == 'y')
  {
    yellow++;
  }
  else if (color == 'g')
  {
    green++;
  }
  else if (color == 'o')
  {
    orange++;
  }
  else if (color == 'p')
  {
    purple++;
  }
  else
  {
    cout << "Not a valid input\n";
  }
}

void SkittlesBag::eat(int numToEat, char color)
{
  if (color == 'r')
  {
    if(numToEat > red)
    {
      red = 0;
    }
    else
    {
      red -= numToEat;
    }
  }
  else if (color == 'y')
  {
    if(numToEat > yellow)
    {
      yellow = 0;
    }
    else
    {
      yellow -= numToEat;
    }
  }
  else if (color == 'g')
  {
    if(numToEat > green)
    {
      green = 0;
    }
    else
    {
      green -= numToEat;
    }
  }
  else if (color == 'o')
  {
    if(numToEat > orange)
    {
      orange = 0;
    }
    else
    {
      orange -= numToEat;
    }
  }
  else if (color == 'p')
  {
    if(numToEat > purple)
    {
      purple = 0;
    }
    else
    {
      purple -= numToEat;
    }
  }
}

void SkittlesBag::evenOut()
{
  int lowest; //lowest number is the number each color will even out to
  lowest = red;
  //find lowest amount of skittles by comparing each color
  if (lowest > yellow) //if yellow is lower
  {
    lowest = yellow;
  }

  if (lowest > green)
  {
    lowest = green;
  }

  if (lowest > orange)
  {
    lowest = orange;
  }

  if (lowest > purple)
  {
    lowest = purple;
  }

  int eaten; //number of skittles eaten to even out
  eaten = red - lowest;
  red = lowest;
  cout << eaten << " red eaten" << endl;

  eaten = yellow - lowest;
  yellow = lowest;
  cout << eaten << " yellow eaten" << endl;

  eaten = green - lowest;
  green = lowest;
  cout << eaten << " green eaten" << endl;

  eaten = orange - lowest;
  orange = lowest;
  cout << eaten << " orange eaten" << endl;

  eaten = purple - lowest;
  purple = lowest;
  cout << eaten << " purple eaten" << endl;

  //lowest is the amount that remains because that means it is the least amount of skittles eaten
  cout << lowest << " of each remaining" << endl;
}

void SkittlesBag::pourInDish(SkittlesDish& dishParameter)
{
  //find the color of the SkittlesDish and match to color in bag
  if(dishParameter.getColor() == "red")
  {
    red += dishParameter.getCount();
  }

  if(dishParameter.getColor() == "yellow")
  {
    yellow += dishParameter.getCount();
  }

  if(dishParameter.getColor() == "green")
  {
    green += dishParameter.getCount();
  }

  if(dishParameter.getColor() == "orange")
  {
    orange += dishParameter.getCount();
  }

  if(dishParameter.getColor() == "purple")
  {
    purple += dishParameter.getCount();
  }

  //empty dish
  dishParameter.eatSkittles(dishParameter.getCount());
}

bool operator ==(const SkittlesBag lhs, const SkittlesBag rhs)
{
  return (lhs.count('r') == rhs.count('r') && lhs.count('y') == rhs.count('y') && lhs.count('g') == rhs.count('g')
          && lhs.count('o') == rhs.count('o') && lhs.count('p') == rhs.count('p'));
}

void SkittlesBag::operator +=(SkittlesBag& rhs)
{
  red += rhs.red;
  rhs.eat(rhs.red, 'r');

  yellow += rhs.yellow;
  rhs.eat(rhs.yellow, 'y');

  green += rhs.green;
  rhs.eat(rhs.green, 'g');

  orange += rhs.orange;
  rhs.eat(rhs.orange, 'o');

  purple += rhs.purple;
  rhs.eat(rhs.purple, 'p');

}
