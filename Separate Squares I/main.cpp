#include <cfloat>
#include <vector>

void countAreas(std::vector<std::vector<int>> &squares, double y, double &top, double &down) {
  for (const std::vector<int> &square : squares) {
    double ty = square[1] + square[2];
    double dy = square[1];
    if (dy >= y) {
      top += static_cast<double>(square[2]) * square[2];
    } else if (ty <= y) {
      down += static_cast<double>(square[2]) * square[2];
    } else if (dy < y && ty > y) {
      top += static_cast<double>(ty - y) * square[2];
      down += static_cast<double>(y - dy) * square[2];
    }
  }
}

double separateSquares(std::vector<std::vector<int>> &squares) {
  const double EPS = 1e-7;
  double high = 0, low = DBL_MAX, topArea{}, downArea{};
  double mid{};
  for (const std::vector<int> &square : squares) {
    if (square[1] + square[2] > high) {
      high = square[1] + square[2];
    }
    if (square[1] < low) {
      low = square[1];
    }
  }
  for (int i = 0; i < 100; i++) {
    if (high - low < EPS) {
      break;
    }
    mid = low + (high - low) / 2;
    topArea = 0, downArea = 0;
    countAreas(squares, mid, topArea, downArea);
    if (topArea > downArea) {
      low = mid;
    } else {
      high = mid;
    }
  }
  return mid;
}
