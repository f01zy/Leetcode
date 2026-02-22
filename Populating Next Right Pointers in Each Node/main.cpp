#include <queue>
using namespace std;

class Node {
public:
  int val;
  Node *left;
  Node *right;
  Node *next;
  Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}
  Node(int _val) : val(_val), left(nullptr), right(nullptr), next(nullptr) {}
  Node(int _val, Node *_left, Node *_right, Node *_next) : val(_val), left(_left), right(_right), next(_next) {}
};

Node *connect(Node *root) {
  if (!root || !root->left) {
    return root;
  }
  queue<Node *> nodes;
  queue<Node *> temp;
  nodes.push(root->left);
  nodes.push(root->right);
  while (!nodes.empty()) {
    Node *node = nodes.front();
    nodes.pop();
    if (!nodes.empty()) {
      node->next = nodes.front();
    }
    if (node->left) {
      temp.push(node->left);
      temp.push(node->right);
    }
    if (nodes.empty() && !temp.empty()) {
      nodes.swap(temp);
    }
  }
  return root;
}
