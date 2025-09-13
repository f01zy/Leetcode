#include <string>
#include <unordered_map>

int maxFreqSum(std::string s) {
  std::unordered_map<char, int> letters;
  int vowel = 0;
  int consonant = 0;

  for (const char &ch : s) {
    if (letters.count(ch) == 0) {
      letters[ch] = 0;
    }
    letters[ch]++;
  }

  for (const auto &pair : letters) {
    if (pair.first == 'a' || pair.first == 'e' || pair.first == 'o' ||
        pair.first == 'i' || pair.first == 'u') {
      if (pair.second > vowel) {
        vowel = pair.second;
      }
    }

    else {
      if (pair.second > consonant) {
        consonant = pair.second;
      }
    }
  }

  return vowel + consonant;
}
