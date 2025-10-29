#ifndef LABS___5__TREE_H
#define LABS___5__TREE_H
#include "TreeNode.h"
#include <iostream>

template<typename T>
class Tree {
private:
    TreeNode<T> *root = nullptr;

    void create_node(TreeNode<T> *&node, const T value) {
        if (node == nullptr) {
            node = new TreeNode<T>(value);
        } else if (value < node->get_data()) {
            create_node(node->get_left_node(), value);
        } else {
            create_node(node->get_right_node(), value);
        }
    }

    void travers_node(TreeNode<T> *node) const {
        if (node != nullptr) {
            travers_node(node->get_left_node());
            std::cout << node->get_data() << " ";
            travers_node(node->get_right_node());
        }
    }

    void delete_tree(TreeNode<T> *node) {
        if (node != nullptr) {
            delete_tree(node->get_left_node());
            delete_tree(node->get_right_node());
            delete node;
        }
    }

    TreeNode<T> *search_node(TreeNode<T> *node, const T value) {
        if (node == nullptr) {
            return nullptr;
        }
        if (node->get_data() == value) {
            return node;
        }
        if (value < node->get_data()) {
            return search_node(node->get_left_node(), value);
        } else {
            return search_node(node->get_right_node(), value);
        }
    }

    TreeNode<T>* copy_tree(const TreeNode<T>* node) {
        if (node == nullptr) {
            return nullptr;
        }
        auto* new_node = new TreeNode<T>(node->get_data());
        new_node->set_left_node(copy_tree(node->get_left_node()));
        new_node->set_right_node(copy_tree(node->get_right_node()));
        return new_node;
    }

public:
    Tree() = default;

    Tree(const Tree& other) {
        if (other.root != nullptr) {
            root = copy_tree(other.root);
        }
    }

    Tree& operator=(const Tree& other) {
        if (this != &other) {
            delete_tree(root);
            root = nullptr;

            if (other.root != nullptr) {
                root = copy_tree(other.root);
            }
        }
        return *this;
    }

    Tree(Tree&& other) noexcept : root(other.root) {
        other.root = nullptr;
    }

    Tree& operator=(Tree&& other) noexcept {
        if (this != &other) {
            delete_tree(root);

            root = other.root;
            other.root = nullptr;
        }
        return *this;
    }

    ~Tree() {
        delete_tree(root);
    }

    void set_root(TreeNode<T>* new_root) {
        root = new_root;
    }

    TreeNode<T>* get_root() const {
        return root;
    }
};


#endif
