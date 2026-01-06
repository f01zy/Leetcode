#include <queue>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int maxLevelSum(TreeNode *root) {
  int sum = root->val, tempSum = 0, x = 1, tempX = 2;
  std::queue<TreeNode *> queue;
  std::queue<TreeNode *> tempQueue;
  if (root->left)
    queue.push(root->left);
  if (root->right)
    queue.push(root->right);
  while (!queue.empty()) {
    TreeNode *node = queue.front();
    queue.pop();
    tempSum += node->val;
    if (node->left)
      tempQueue.push(node->left);
    if (node->right)
      tempQueue.push(node->right);
    if (queue.empty()) {
      if (tempSum > sum) {
        x = tempX;
        sum = tempSum;
      }
      if (tempQueue.empty())
        break;
      tempSum = 0;
      tempX++;
      queue.swap(tempQueue);
    }
  }
  return x;
}
