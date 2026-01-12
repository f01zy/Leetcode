#include <cstdlib>
#include <vector>

int minTimeToVisitAllPoints(std::vector<std::vector<int>> &points) {
  int time = 0;
  int positionX = points[0][0], positionY = points[0][1];
  for (int i = 1; i < points.size(); i++) {
    int pointX = points[i][0];
    int pointY = points[i][1];
    int areaWidth = std::abs(pointX - positionX);
    int areaHeight = std::abs(pointY - positionY);
    time += std::min(areaWidth, areaHeight) + std::abs(areaWidth - areaHeight);
    positionX = pointX;
    positionY = pointY;
  }
  return time;
}
