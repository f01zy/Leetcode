#include <string>

bool isValid(std::string word) {
  if (word.size() < 3) {
    return false;
  }

  std::string nums = "1234567890";
  std::string symbols = "@#$";
  std::string vowels = "aeiouAEIOU";
  bool isVowel = false;
  bool isConsonant = false;

  for (char symbol : word) {
    if (symbols.find(symbol) != std::string::npos) {
      return false;
    }

    else if (vowels.find(symbol) != std::string::npos) {
      isVowel = true;
    }

    else if (nums.find(symbol) == std::string::npos) {
      isConsonant = true;
    }
  }

  return isVowel && isConsonant;
}
