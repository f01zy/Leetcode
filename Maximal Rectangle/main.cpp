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

int maximalRectangle(std::vector<std::vector<char>> &matrix) {
  int result = 0;
  int rows = matrix.size();
  int cols = matrix[0].size();
  std::vector<int> heights(cols);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      if (matrix[i][j] == '0') {
        heights[j] = 0;
        continue;
      }
      heights[j]++;
    }
    result = std::max(result, largestRectangleArea(heights));
  }
  return result;
}
