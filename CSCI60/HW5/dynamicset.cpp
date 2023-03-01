// HW5 Q1 starter implementation file for DynamicSet
// Travis Lee

#include "dynamicset.h"

bool DynamicSet::contains(int target)
{
  for (size_t i = 0; i < size(); i++)
  {
    if ((*this)[i] == target)
    {
      return true;
    }
  }
  return false;
}

void DynamicSet::remove(int target)
{
  if (contains(target))
  {
    (*this).erase_one(target);
  }
}

void DynamicSet::insert(int target)
{
  if (!contains(target))
  {
    (*this).DynamicBag::insert(target);
  }
}
