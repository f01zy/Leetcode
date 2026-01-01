struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool hasPathSum(TreeNode *node, int targetSum) {
  if (!node) {
    return false;
  }
  int currentSum = targetSum - node->val;
  if (currentSum == 0 && !node->left && !node->right) {
    return true;
  }
  if (node->left) {
    bool left = hasPathSum(node->left, currentSum);

    if (left) {
      return true;
    }
  }
  if (node->right) {
    bool right = hasPathSum(node->right, currentSum);

    if (right) {
      return true;
    }
  }
  return false;
}
