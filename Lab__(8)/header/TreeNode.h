#ifndef LAB___8__TREENODE_H
#define LAB___8__TREENODE_H

template <typename T>
class TreeNode {
public:
    T data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(const T& value) : data(value), left(nullptr), right(nullptr) {}
};

#endif
