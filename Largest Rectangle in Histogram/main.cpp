#include <stack>
#include <vector>

int largestRectangleArea(std::vector<int> &heights) {
  heights.push_back(0);
  std::stack<int> stack;
  int maxArea = 0;
  for (int i = 0; i < heights.size(); i++) {
    while (!stack.empty() && heights[i] < heights[stack.top()]) {
      int j = stack.top();
      int top = heights[j];
      stack.pop();
      int width = stack.empty() ? i : i - stack.top() - 1;
      maxArea = std::max(maxArea, top * width);
    }
    stack.push(i);
  }
  return maxArea;
}
