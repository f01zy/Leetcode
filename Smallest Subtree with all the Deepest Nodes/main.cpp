#include <iostream>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode *result;
int maxDeep = 0;

int findSubtreeWithAllDeepest(TreeNode *node, int deep) {
  if (!node) {
    return 0;
  }
  int leftDeep = findSubtreeWithAllDeepest(node->left, deep + 1);
  int rightDeep = findSubtreeWithAllDeepest(node->right, deep + 1);
  int currentDeep = std::max(leftDeep, rightDeep);
  int absoluteDeep = deep + currentDeep;
  if (leftDeep == rightDeep && absoluteDeep >= maxDeep) {
    result = node;
    maxDeep = absoluteDeep;
  }
  return currentDeep + 1;
}

TreeNode *subtreeWithAllDeepest(TreeNode *root) {
  result = root;
  findSubtreeWithAllDeepest(root, 0);
  return result;
}
