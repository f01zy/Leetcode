#include <stdexcept>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

string curr;
vector<string> result;

void process(string &digits, unordered_map<char, string> &letters, int i) {
  if (i == digits.size()) {
    result.push_back(curr);
    return;
  }
  char digit = digits[i];
  for (const char &num : letters[digit]) {
    curr.push_back(num);
    process(digits, letters, i + 1);
    curr.pop_back();
  }
}

vector<string> letterCombinations(string digits) {
  unordered_map<char, string> letters{{'1', ""},    {'2', "abc"},  {'3', "def"}, {'4', "ghi"}, {'5', "jkl"},
                                      {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};
  process(digits, letters, 0);
  return result;
}
