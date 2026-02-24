struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int result = 0;
int curr = 0;

void process(TreeNode *node) {
  if (!node) {
    return;
  }
  int prev = curr;
  curr <<= 1;
  curr |= node->val;
  if (!node->left && !node->right) {
    result += curr;
  }
  process(node->left);
  process(node->right);
  curr = prev;
}

int sumRootToLeaf(TreeNode *root) {
  process(root);
  return result;
}
