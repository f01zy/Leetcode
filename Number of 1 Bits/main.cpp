#include <cmath>

int hammingWeight(int n)
{
  int res = 0;

  while (1)
  {
    if (n < 1)
    {
      break;
    }

    int remainder = n % 2;
    n = std::floor(n / 2);

    if (remainder == 1)
    {
      res++;
    }
  }

  return res;
}