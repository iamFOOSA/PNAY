#ifndef LAB___8__TREEALGORITHM_H
#define LAB___8__TREEALGORITHM_H

#include "TreeNode.h"
#include "TreeIterator.h"
#include <vector>
#include <queue>
#include <string>
#include <iostream>
#include <cmath>

template<typename T>
class TreeAlgorithm {
public:
    static std::vector<T> traverse_with_iterator(TreeNode<T> *root) {
        std::vector<T> result;
        TreeIterator<T> it(root);
        TreeIterator<T> end;

        while (it != end) {
            result.push_back(*it);
            ++it;
        }
        return result;
    }

    static void traverse_in_order_recursive(TreeNode<T> *node, std::vector<T> &result) {
        if (!node) return;
        traverse_in_order_recursive(node->left, result);
        result.push_back(node->data);
        traverse_in_order_recursive(node->right, result);
    }

    static std::vector<T> traverse_in_order(TreeNode<T> *root) {
        std::vector<T> result;
        traverse_in_order_recursive(root, result);
        return result;
    }

    static TreeNode<T> *search(TreeNode<T> *root, const T &value) {
        if (!root || root->data == value) return root;

        if (value < root->data)
            return search(root->left, value);
        else
            return search(root->right, value);
    }


    static int get_height(TreeNode<T> *node) {
        if (!node) return 0;
        return 1 + std::max(get_height(node->left), get_height(node->right));
    }

    static void print_tree_horizontal(TreeNode<T> *root, int space = 0, int gap = 5) {
        if (!root) return;

        space += gap;

        print_tree_horizontal(root->right, space);

        std::cout << std::endl;
        for (int i = gap; i < space; i++) {
            std::cout << " ";
        }
        std::cout << root->data << std::endl;

        print_tree_horizontal(root->left, space);
    }
};

#endif
