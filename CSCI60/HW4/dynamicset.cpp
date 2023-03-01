//Travis Lee
#include <cstdlib>
#include <algorithm>
#include <ostream>
#include <iostream>
#include "dynamicset.h"

DynamicSet::DynamicSet()
{
  data_ = nullptr;
  capacity_ = 0;
  used_ = 0;
}

DynamicSet::DynamicSet(const DynamicSet & s)
{
  if (s.capacity_ > 0)
  {
    data_ = new int[s.capacity_];
    for (size_t i = 0; i < s.used_; i++)
    {
      data_[i] = s.data_[i];
    }
  }
  else
  {
    data_ = nullptr;
  }
  capacity_ = s.capacity_;
  used_ = s.used_;
}

void DynamicSet::operator =(const DynamicSet & s2)
{
  if (capacity_ != s2.capacity_)
  {
    capacity_ = s2.capacity_;
    delete [] data_;
    data_ = new int[capacity_];
  }
  used_ = s2.used_;
  for (size_t i = 0; i < s2.used_; i++)
  {
    data_[i] = s2.data_[i];
  }
}

DynamicSet::~DynamicSet()
{
  delete [] data_;
  data_ = nullptr;
}

bool DynamicSet::contains(int target) const
{
  for (size_t i = 0; i < used_; i++)
  {
    if (data_[i] == target)
    {
      return true;
    }
  }
  return false;
}

void DynamicSet::insert(int target)
{
  if (!contains(target))
  {
    if (capacity_ == 0)
    {
      capacity_ = 1;
      data_ = new int[capacity_];
    }
    else if(capacity_ == used_)
    {
      capacity_ *= 2;
      int *temp = new int[capacity_];
      for (size_t i = 0; i < used_; i++)
      {
        temp[i] = data_[i];
      }
      delete [] data_;
      data_ = temp;
    }
    data_[used_] = target;
    used_++;
  }
  /*else
  {
    std::cout << "target value already exists in set" << std::endl;
  }*/
}

std::ostream& operator <<(std::ostream& out, const DynamicSet & s)
{
  for (size_t i = 0; i < s.size(); i++)
  {
    out << s[i] << " ";
  }
  return out;
}

bool DynamicSet::remove(int target)
{
  if (!contains(target))
  {
    return false;
  }
  size_t removePos;
  for (size_t i = 0; i < used_; i++)
  {
    if (data_[i] == target)
    {
      removePos = i + 1;
    }
  }
  for (size_t i = removePos; i < used_; i++)
  {
    data_[i - 1] = data_[i];
  }
  used_--;

  if (used_ <= capacity_ / 4)
  {
    capacity_ /= 2;
    int *temp = new int[capacity_];
    for (size_t i = 0; i < used_; i++)
    {
      temp[i] = data_[i];
    }
    delete [] data_;
    data_ = temp;
  }

  return true;
}

void DynamicSet::operator +=(const DynamicSet & s2)
{
  for (size_t i = 0; i < s2.used_; i++)
  {
    insert(s2.data_[i]);
  }
}

DynamicSet operator +(const DynamicSet & s1, const DynamicSet & s2)
{
  DynamicSet unionSet;
  for (size_t i = 0; i < s1.size(); i++)
  {
    unionSet.insert(s1[i]);
  }
  for (size_t i = 0; i < s2.size(); i++)
  {
    unionSet.insert(s2[i]);
  }
  return unionSet;
}

void DynamicSet::operator *=(const DynamicSet & s2)
{
  for (size_t i = 0; i < used_; i++)
  {
    if (!s2.contains(data_[i]))
    {
      remove(data_[i]);
      i--;
    }
  }
}

DynamicSet operator *(const DynamicSet & s1, const DynamicSet & s2)
{
  DynamicSet intersectSet;
  for (size_t i = 0; i < s1.size(); i++)
  {
    intersectSet.insert(s1[i]);
  }
  for (size_t i = 0; i < s1.size(); i++)
  {
    if (!s2.contains(s1[i]))
    {
      intersectSet.remove(s1[i]);
    }
  }

  return intersectSet;
}

void DynamicSet::operator -=(const DynamicSet & s2)
{
  for (size_t i = 0; i < used_; i++)
  {
    if (s2.contains(data_[i]))
    {
      remove(data_[i]);
      i--;
    }
  }
}

DynamicSet operator -(const DynamicSet & s1, const DynamicSet & s2)
{
  DynamicSet differenceSet;
  for (size_t i = 0; i < s1.size(); i++)
  {
    differenceSet.insert(s1[i]);
  }
  for (size_t i = 0; i < s1.size(); i++)
  {
    if (s2.contains(s1[i]))
    {
      differenceSet.remove(s1[i]);
    }
  }

  return differenceSet;
}
