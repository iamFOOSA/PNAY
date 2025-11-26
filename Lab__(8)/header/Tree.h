#ifndef LAB___8__TREE_H
#define LAB___8__TREE_H

#include "TreeNode.h"
#include "TreeIterator.h"
#include "TreeAlgorithm.h"
#include <vector>

template<typename T>
class Tree {
private:
    TreeNode<T> *root_node;

    TreeNode<T> *insert_recursive(TreeNode<T> *node, const T &value) {
        if (!node) return new TreeNode<T>(value);

        if (value < node->data)
            node->left = insert_recursive(node->left, value);
        else if (value > node->data)
            node->right = insert_recursive(node->right, value);
        return node;
    }

    void clear_recursive(TreeNode<T> *node) {
        if (node) {
            clear_recursive(node->left);
            clear_recursive(node->right);
            delete node;
        }
    }

    TreeNode<T> *copy_recursive(TreeNode<T> *node) {
        if (!node) return nullptr;
        TreeNode<T> *new_node = new TreeNode<T>(node->data);
        new_node->left = copy_recursive(node->left);
        new_node->right = copy_recursive(node->right);
        return new_node;
    }

public:
    Tree() : root_node(nullptr) {}

    Tree(const Tree &other) {
        root_node = copy_recursive(other.root_node);
    }

    Tree &operator=(const Tree &other) {
        if (this != &other) {
            clear_recursive(root_node);
            root_node = copy_recursive(other.root_node);
        }
        return *this;
    }

    ~Tree() {
        clear_recursive(root_node);
    }

    void insert(const T &value) {
        root_node = insert_recursive(root_node, value);
    }

    TreeNode<T> *get_root() const { return root_node; }

    bool is_empty() const {
        return root_node == nullptr;
    }

    std::vector<T> traverse_with_iterator() {
        return TreeAlgorithm<T>::traverse_with_iterator(root_node);
    }

    std::vector<T> traverse_in_order() {
        return TreeAlgorithm<T>::traverse_in_order(root_node);
    }

    TreeNode<T> *search(const T &value) {
        return TreeAlgorithm<T>::search(root_node, value);
    }

    bool contains(const T &value) {
        return TreeAlgorithm<T>::search(root_node, value) != nullptr;
    }

    void print_tree_visual() {
        TreeAlgorithm<T>::print_tree_visual(root_node);
    }

    void print_tree_horizontal() {
        if (is_empty()) {
            std::cout << "Дерево пустое" << std::endl;
            return;
        }
        TreeAlgorithm<T>::print_tree_horizontal(root_node);
    }

    TreeIterator<T> begin() {
        return TreeIterator<T>(root_node);
    }

    TreeIterator<T> end() {
        return TreeIterator<T>();
    }
};

#endif
