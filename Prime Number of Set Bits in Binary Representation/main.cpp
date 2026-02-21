#include <cmath>
using namespace std;

bool isPrime(int num) {
  if (num == 1) {
    return false;
  }
  for (int i = 2; i <= sqrt(num); i++) {
    if (num % i == 0) {
      return false;
    }
  }
  return true;
}

int countPrimeSetBits(int left, int right) {
  int result = 0;
  for (int i = left; i <= right; i++) {
    int num = i, count = 0;
    while (num) {
      if (num & 1) {
        count++;
      }
      num >>= 1;
    }
    if (isPrime(count)) {
      result++;
    }
  }
  return result;
}
