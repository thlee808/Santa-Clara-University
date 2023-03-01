// HW5 Q1 starter header file for DynamicSet, which should inherit DynamicBag
// Travis Lee

#ifndef DYNAMICSET_H
#define DYNAMICSET_H

#include "dynamicbag.h"

using std::size_t;

class DynamicSet : public DynamicBag
{
public:
  bool contains(int target);
  void remove(int target);
  void insert(int target);

private:

};

#endif
