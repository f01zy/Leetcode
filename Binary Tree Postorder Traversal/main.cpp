#include <vector>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void traverse(std::vector<int> &result, TreeNode *node) {
  if (node->left) {
    traverse(result, node->left);
  }

  if (node->right) {
    traverse(result, node->right);
  }

  result.push_back(node->val);
}

std::vector<int> postorderTraversal(TreeNode *root) {
  std::vector<int> result;
  traverse(result, root);
  return result;
}
