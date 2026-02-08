#include <cmath>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int checkTree(TreeNode *node, bool &isTreeBalanced) {
  if (!node) {
    return 1;
  }
  int left = checkTree(node->left, isTreeBalanced);
  int right = checkTree(node->right, isTreeBalanced);
  if (std::abs(left - right) > 1) {
    isTreeBalanced = false;
  }
  return std::max(left, right) + 1;
}

bool isBalanced(TreeNode *root) {
  if (!root) {
    return true;
  }
  bool isTreeBalanced = true;
  checkTree(root, isTreeBalanced);
  return isTreeBalanced;
}
