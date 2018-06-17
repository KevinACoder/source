#ifndef QT_BINARY_TREE_HPP
#define QT_BINARY_TREE_HPP

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

#endif // QT_BINARY_TREE_HPP
