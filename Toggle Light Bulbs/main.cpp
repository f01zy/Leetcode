#include <vector>
using namespace std;

vector<int> toggleLightBulbs(vector<int> &bulbs) {
  bool cache[101]{0};
  for (const int &bulb : bulbs) {
    cache[bulb] = !cache[bulb];
  }
  std::vector<int> result;
  for (int i = 0; i < 101; i++) {
    if (cache[i]) {
      result.push_back(i);
    }
  }
  return result;
}
