#include <algorithm>

int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2)
{
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
  int s1 = w1 * h1;
  int s2 = w2 * h2;
  int s3 = w3 * h3;
  int s = s1 + s2;
  w3 > 0 && h3 > 0 ? s -= s3 : 0;
  return s;
}