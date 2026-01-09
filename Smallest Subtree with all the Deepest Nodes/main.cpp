#include <climits>
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
int maxRelativeDeep = 0;
int minRootDeep = INT_MAX;

int findSubtreeWithAllDeepest(TreeNode *node, int deep) {
  if (!node) {
    return 0;
  }
  int leftDeep = findSubtreeWithAllDeepest(node->left, deep + 1);
  int rightDeep = findSubtreeWithAllDeepest(node->right, deep + 1);
  int currentNodeDeep = std::max(leftDeep, rightDeep) + 1;
  if (leftDeep == rightDeep && deep < minRootDeep && currentNodeDeep > maxRelativeDeep) {
    result = node;
    minRootDeep = deep;
    maxRelativeDeep = currentNodeDeep;
  }
  return currentNodeDeep;
}

TreeNode *subtreeWithAllDeepest(TreeNode *root) {
  result = root;
  findSubtreeWithAllDeepest(root, 0);
  return result;
}
