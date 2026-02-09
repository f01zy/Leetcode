#include <cstdlib>
#include <vector>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

std::vector<int> nums;
bool isBalanced = true;

int configureNums(TreeNode *node) {
  if (!node) {
    return 0;
  }
  int left = configureNums(node->left);
  nums.push_back(node->val);
  int right = configureNums(node->right);
  if (std::abs(left - right) > 1) {
    isBalanced = false;
  }
  return std::max(left, right) + 1;
}

TreeNode *generateSubTree(int i, int j) {
  if (i > j) {
    return nullptr;
  }
  int mid = (i + j) / 2;
  TreeNode *node = new TreeNode(nums[mid]);
  node->left = generateSubTree(i, mid - 1);
  node->right = generateSubTree(mid + 1, j);
  return node;
}

TreeNode *balanceBST(TreeNode *root) {
  configureNums(root);
  if (isBalanced) {
    return root;
  }
  return generateSubTree(0, nums.size() - 1);
}
