// Interface starter file for Homework 2; due 5pm 1/23/20
// Travis Lee

#ifndef SKITTLESBAG_H
#define SKITTLESBAG_H

#include "skittlesdish.h"
#include <iostream>

using std::cout;

class SkittlesBag {
public:
// two constructors
  // 0 argument constructor
  SkittlesBag() : red(0), yellow(0), green(0), orange(0), purple(0) {}
  // 5 argument constructor
  SkittlesBag(int redP, int yellowP, int greenP, int orangeP, int purpleP);
//3 member accessor functions
int size() const {return (red + yellow + green + orange + purple);}
int count(char color) const;
void printHistogram() const;
// bunch of mutators
void addOne(char color);
void eat(int numToEat, char color);
void evenOut();
void pourInDish(SkittlesDish& dishParameter);

//2 overloaded operators
void operator +=(SkittlesBag& rhs);

private:
  //int size;
  int red;
  int yellow;
  int green;
  int orange;
  int purple;

};

bool operator ==(const SkittlesBag lhs, const SkittlesBag rhs);

#endif
