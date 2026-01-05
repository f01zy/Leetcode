#include <climits>
#include <cmath>
#include <vector>

long long maxMatrixSum(std::vector<std::vector<int>> &matrix) {
  long long sum = 0;
  int minNum = INT_MAX;
  int negativeCount = 0;
  for (int i = 0; i < matrix.size(); i++) {
    for (int j = 0; j < matrix[i].size(); j++) {
      int num = matrix[i][j];
      sum += std::abs(num);
      minNum = std::min(std::abs(num), minNum);
      if (num <= 0) {
        negativeCount++;
      }
    }
  }
  if (negativeCount % 2 != 0) {
    sum -= minNum * 2;
  }
  return sum;
}
