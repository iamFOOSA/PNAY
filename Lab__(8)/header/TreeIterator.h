#ifndef LAB___8__TREEITERATOR_H
#define LAB___8__TREEITERATOR_H

#include "TreeNode.h"
#include <stack>

template<typename T>
class TreeIterator {
private:
    std::stack<TreeNode<T> *> node_stack;
    TreeNode<T> *current_node;

    void push_left(TreeNode<T> *node) {
        while (node) {
            node_stack.push(node);
            node = node->left;
        }
    }

public:
    explicit TreeIterator(TreeNode<T> *root) {
        push_left(root);
        if (!node_stack.empty()) {
            current_node = node_stack.top();
            node_stack.pop();
        } else {
            current_node = nullptr;
        }
    }

    TreeIterator() : current_node(nullptr) {}

    T &operator*() {
        return current_node->data;
    }

    TreeIterator &operator++() {
        if (current_node) {
            push_left(current_node->right);
            if (!node_stack.empty()) {
                current_node = node_stack.top();
                node_stack.pop();
            } else {
                current_node = nullptr;
            }
        }
        return *this;
    }

    bool operator==(const TreeIterator &other) const {
        return current_node == other.current_node;
    }

};


#endif
