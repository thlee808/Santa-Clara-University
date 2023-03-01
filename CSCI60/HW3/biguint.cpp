//Travis Lee and Brycen Tanaka(Partner)

#include "biguint.h"
#include <string>
#include <cmath>

biguint::biguint()
{
  for (std::size_t i = 0; i < CAPACITY; i++)
  {
    data_[i] = 0;
  }
}

biguint::biguint(const std::string & s)
{
  for (std::size_t i = 0; i < s.length(); i++)
  {
    data_[i] = s[s.length() - i - 1] - '0';
  }

  for (std::size_t i = s.length(); i < CAPACITY; i++)
  {
    data_[i] = 0;
  }
}

unsigned short biguint::operator [](std::size_t pos) const
{
  if (pos > CAPACITY - 1)
  {
    return 0;
  }
  return data_[pos];
}

std::ostream& operator <<(std::ostream& out, const biguint& b)
{
  for (std::size_t i = 0; i < b.CAPACITY; i++)
  {
    out << b[b.CAPACITY - i - 1];
  }
   return out;
}


void biguint::operator += (const biguint & b)
{
  bool carry = false;
  for (std::size_t i = 0; i < CAPACITY; i++)
  {
    data_[i] += b[i];
    if (carry == true)
    {
      data_[i]++;
      carry = false;
    }
    if (data_[i] / 10 > 0)
    {
      carry = true;
      data_[i] = data_[i] % 10;
    }
  }
}

biguint operator + (const biguint & b1, const biguint & b2)
{
  std::size_t arrSum[biguint::CAPACITY]; //store sum in an array

  bool carry = false;
  for (std::size_t i = 0; i < biguint::CAPACITY; i++)
  {
    arrSum[i] = b1[i] + b2[i];
    if (carry == true)
    {
      arrSum[i]++;
      carry = false;
    }
    if (arrSum[i] / 10 > 0)
    {
      carry = true;
      arrSum[i] = arrSum[i] % 10;
    }
  }

  std::string sumString = ""; //string used to get number as an argument for constructor

  for (std::size_t i = 0; i < biguint::CAPACITY; i++)
  {
    sumString += ('0' + arrSum[biguint::CAPACITY - i - 1]);
  }

  biguint sum(sumString); //construct new biguint with string and return it
  return sum;
}

bool operator < (const biguint & lhs, const biguint & rhs)
{
  if (lhs.compare(rhs) == -1)
  {
    return true;
  }
  else
  {
    return false;
  }
}
bool operator <= (const biguint & lhs, const biguint & rhs)
{
  if (lhs.compare(rhs) == -1 || lhs.compare(rhs) == 0)
  {
    return true;
  }
  else
  {
    return false;
  }

}
bool operator != (const biguint & lhs, const biguint & rhs)
{
  if (lhs.compare(rhs) != 0)
  {
    return true;
  }
  else
  {
    return false;
  }
}
bool operator == (const biguint & lhs, const biguint & rhs)
{
  if (lhs.compare(rhs) == 0)
  {
    return true;
  }
  else
  {
    return false;
  }
}
bool operator >= (const biguint & lhs, const biguint & rhs)
{
  if (lhs.compare(rhs) == 1 || lhs.compare(rhs) == 0)
  {
    return true;
  }
  else
  {
    return false;
  }
}
bool operator > (const biguint & lhs, const biguint & rhs)
{
  if (lhs.compare(rhs) == 1)
  {
    return true;
  }
  else
  {
    return false;
  }
}

int biguint::compare(const biguint & rhs) const
{
  int result;
  for (std::size_t i = 0; i < CAPACITY; i++)
  {
    if (data_[CAPACITY - 1 - i] != rhs.data_[CAPACITY - 1 - i])
    {
      if (data_[CAPACITY - 1 - i] < rhs.data_[CAPACITY - 1 - i])
      {
        result = -1;
        break;
      }
      if (data_[CAPACITY - 1 - i] > rhs.data_[CAPACITY - 1 - i])
      {
        result = 1;
        break;
      }
    }
    else
    {
      result = 0;
    }
  }
  return result;
}

void biguint::operator -= (const biguint & b)
{
  bool carry;
  for (std::size_t i = 0; i < CAPACITY; i++)
  {
    if (carry == true)
    {
      data_[i]--;
      carry = false;
    }
    if(data_[i] < b[i])
    {
      carry = true;
      data_[i] = (data_[i] + 10) - b[i];
    }
    else
    {
      data_[i] -= b[i];
    }
  }
}

biguint operator - (const biguint & lhs, const biguint & rhs)
{
  std::size_t arrSum[biguint::CAPACITY]; //store sum in an array
  bool carry;
  for (std::size_t i = 0; i < biguint::CAPACITY; i++)
  {
    arrSum[i] = lhs[i];

    if (carry == true)
    {
      arrSum[i] = lhs[i] - 1;
      carry = false;
    }
    if(lhs[i] < rhs[i])
    {
      carry = true;
      arrSum[i] = ((lhs[i] + 10) - rhs[i]);
    }
    else
    {
      arrSum[i] = arrSum[i] - rhs[i];
    }
  }

  std::string sumString = ""; //string used to get number as an argument for constructor

  for (std::size_t i = 0; i < biguint::CAPACITY; i++)
  {
    sumString += ('0' + arrSum[biguint::CAPACITY - i - 1]);
  }

  biguint sum(sumString); //construct new biguint with string and return it
  return sum;
}

std::string biguint::toString() const
{
  std::string string = ""; //string used to get number as an argument for constructor

  for (std::size_t i = 0; i < biguint::CAPACITY; i++)
  {
    string += ('0' + data_[biguint::CAPACITY - i - 1]);
  }
  return string;
}
