#include <vector>

char nextGreatestLetter(std::vector<char> &letters, char target) {
  for (const char &i : letters) {
    if (i > target) {
      return i;
    }
  }
  return letters[0];
}
