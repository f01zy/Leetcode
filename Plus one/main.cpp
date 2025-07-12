#include <vector>
#include <iostream>

std::vector<int> plusOne(std::vector<int> &digits)
{
  int i = digits.size() - 1;

  while (1)
  {
    if (digits[i] == 9)
    {
      digits[i] = 0;

      if (i != 0)
      {
        i--;
      }
      else
      {
        digits.insert(digits.begin(), 1);
        break;
      }
    }
    else
    {
      digits[i]++;
      break;
    }
  }

  return digits;
}

int main()
{
  std::vector<int> digits = {9, 9, 9};
  digits = plusOne(digits);

  for (int i : digits)
  {
    std::cout << i;
  }
  std::cout << std::endl;
}