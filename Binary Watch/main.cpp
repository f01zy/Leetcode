#include <string>
#include <utility>
#include <vector>

int countBits(int n) {
  int count = 0;
  while (n) {
    if (n & 1) {
      count++;
    }
    n >>= 1;
  }
  return count;
}

std::string formatTime(int i, int j) {
  std::string hours = std::to_string(i);
  std::string minutes = j < 10 ? "0" + std::to_string(j) : std::to_string(j);
  return hours + ":" + minutes;
}

std::vector<std::string> readBinaryWatch(int turnedOn) {
  static std::vector<std::pair<int, std::string>> times;
  if (times.size() == 0) {
    for (int i = 0; i < 12; i++) {
      for (int j = 0; j < 60; j++) {
        std::string time = formatTime(i, j);
        int count = countBits(i) + countBits(j);
        times.push_back({count, time});
      }
    }
  }
  std::vector<std::string> result;
  for (const std::pair<int, std::string> time : times) {
    if (time.first == turnedOn) {
      result.push_back(time.second);
    }
  }
  return result;
}
