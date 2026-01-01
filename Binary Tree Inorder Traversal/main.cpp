#include <vector>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void traverse(TreeNode *node, std::vector<int> &nums) {
  if (node->left) {
    traverse(node->left, nums);
  }

  nums.push_back(node->val);

  if (node->right) {
    traverse(node->right, nums);
  }
}

std::vector<int> inorderTraversal(TreeNode *root) {
  std::vector<int> nums;

  if (!root) {
    return nums;
  }

  traverse(root, nums);
  return nums;
}
