#include <string>
#include <vector>
using namespace std;

class Robot {
public:
  int width, height;
  int dirX = 1, dirY = 0, posX = 0, posY = 0;

  Robot(int width, int height) {
    this->width = width;
    this->height = height;
  }

  void step(int num) {
    int steps = width * 2 + (height - 2) * 2;
    num %= steps;
    if (!num && !posX && !posY) {
      dirX = 0;
      dirY = -1;
    }
    while (num) {
      while ((posX == 0 && dirX == -1) || (posX == width - 1 && dirX == 1) || (posY == 0 && dirY == -1) || (posY == height - 1 && dirY == 1)) {
        int temp = dirX;
        dirX = -dirY;
        dirY = temp;
      }
      posX += dirX;
      posY += dirY;
      num--;
    }
  }

  vector<int> getPos() { return {posX, posY}; }

  string getDir() {
    if (dirX == 0 && dirY == 1) return "North";
    else if (dirX == 0 && dirY == -1)
      return "South";
    else if (dirX == 1 && dirY == 0)
      return "East";
    else
      return "West";
  }
};
