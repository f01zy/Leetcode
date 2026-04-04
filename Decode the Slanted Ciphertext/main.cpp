#include <string>
using namespace std;

string decodeCiphertext(string encodedText, int rows) {
  int cols = encodedText.size() / rows;
  string originalText;
  for (int i = 0; i < cols; i++) {
    if (encodedText[i] == ' ') break;
    int j = 0, k = i;
    while (j < rows && k < cols) {
      originalText.push_back(encodedText[j++ * cols + k++]);
    }
  }
  for (int i = originalText.size() - 1; i >= 0; i--) {
    if (originalText[i] != ' ') break;
    originalText.pop_back();
  }
  return originalText;
}
