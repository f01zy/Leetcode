#include <vector>

long long computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
  int w1 = ax2 - ax1;
  int h1 = ay2 - ay1;
  int w2 = bx2 - bx1;
  int h2 = by2 - by1;
  int zx1 = std::max(ax1, bx1);
  int zy1 = std::max(ay1, by1);
  int zx2 = std::min(ax2, bx2);
  int zy2 = std::min(ay2, by2);
  int w3 = zx2 - zx1;
  int h3 = zy2 - zy1;
  long long side = std::min(w3, h3);
  long long area = side * side;
  if (w3 > 0 && h3 > 0) {
    return area;
  }
  return 0;
}

long long largestSquareArea(std::vector<std::vector<int>> &bottomLeft, std::vector<std::vector<int>> &topRight) {
  long long largestArea = 0;
  for (int i = 0; i < bottomLeft.size(); i++) {
    for (int j = 0; j < bottomLeft.size(); j++) {
      if (i == j) {
        continue;
      }
      largestArea = std::max(largestArea, computeArea(bottomLeft[i][0], bottomLeft[i][1], topRight[i][0], topRight[i][1], bottomLeft[j][0], bottomLeft[j][1], topRight[j][0], topRight[j][1]));
    }
  }
  return largestArea;
}
