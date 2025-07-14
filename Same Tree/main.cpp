#include <vector>

struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void traverse(TreeNode *node, std::vector<int> &arr)
{
  arr.push_back(node->val);

  if (node->left)
  {
    traverse(node->left, arr);
  }

  else if (!node->left && node->right)
  {
    arr.push_back(0);
  }

  if (node->right)
  {
    traverse(node->right, arr);
  }
}

bool isSameTree(TreeNode *p, TreeNode *q)
{
  std::vector<int> a;
  if (p)
  {
    traverse(p, a);
  }

  std::vector<int> b;
  if (q)
  {
    traverse(q, b);
  }

  if (a.size() != b.size())
  {
    return false;
  }

  for (int i = 0; i < a.size(); i++)
  {
    if (a[i] != b[i])
    {
      return false;
    }
  }

  return true;
}