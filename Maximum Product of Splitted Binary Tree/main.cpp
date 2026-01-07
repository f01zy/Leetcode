#include <iostream>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int getSum(TreeNode *root) {
  int treeSum = root->val;
  if (root->left) {
    treeSum += getSum(root->left);
  }
  if (root->right) {
    treeSum += getSum(root->right);
  }
  return treeSum;
}

int getMaxProduct(TreeNode *root, const int &treeSum, long long &maxProduct) {
  int a = 0, b = 0;
  if (!root) {
    return 0;
  }
  if (root->left) {
    a = getMaxProduct(root->left, treeSum, maxProduct);
  }
  if (root->right) {
    b = getMaxProduct(root->right, treeSum, maxProduct);
  }
  int subtreeSum = root->val + a + b;
  long long product = static_cast<long long>(treeSum - subtreeSum) * subtreeSum;
  if (product > maxProduct) {
    maxProduct = product;
  }
  return subtreeSum;
}

int maxProduct(TreeNode *root) {
  int treeSum = getSum(root);
  long long maxProduct = 0;
  getMaxProduct(root, treeSum, maxProduct);
  if (maxProduct > 1000000007) {
    maxProduct %= 1000000007;
  }
  return maxProduct;
}
