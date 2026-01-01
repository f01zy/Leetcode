#include <algorithm>
#include <vector>

bool compare(const int &left, const int &right) { return left > right; }

int matchPlayersAndTrainers(std::vector<int> &players, std::vector<int> &trainers) {
  std::sort(players.begin(), players.end(), compare);
  std::sort(trainers.begin(), trainers.end(), compare);

  int result = 0;

  for (int i = 0; i < players.size(); i++) {
    if (trainers.size() == 0) {
      break;
    }

    for (int j = 0; j < trainers.size(); j++) {
      if (players[i] <= trainers[j]) {
        trainers.erase(trainers.begin() + j);
        result++;
        break;
      }
    }
  }

  return result;
}
