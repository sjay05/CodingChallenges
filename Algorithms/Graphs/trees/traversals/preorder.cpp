#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

/*
Preorder Traversal on Trees:

Traversal Instructions:
1) Access current node (visit root)
2) Traverse left subtree recursively
3) Traverse right subtree recursively

Uses/Applications/Facts:

1) Since the parent is visited before
(left) and (right) children, pre-order
traversal will be in topological order.

Sources for Implementation:
https://en.wikipedia.org/wiki/Tree_traversal#Implementations
*/

/*
Recursive Implementation (Pseudo-Code)

void preorder(node) {
  if (node == null) {
    return;
  }
  cout << node << " ";
  preorder(node.left);
  preorder(node.right);
}
*/

/*
Iterative Implementation (Pseudo-Code)

void preorder(node) {
  if (node == null) {
    return;
  }
  stack<int> s;
  s.push(node);
  while (!s.empty()) {
    int u = q.pop();
    cout << u << " ";
    if (u.right != null) {
      s.push(u.right);
    }
    if (u.left != null) {
      s.push(u.left);
    }
  }
}
*/

int main() {
  return 0;
}
