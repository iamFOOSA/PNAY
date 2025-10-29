#ifndef LABS___5__TREE_H
#define LABS___5__TREE_H
#include "../TreeNode.h"
#include <iostream>

template<typename T>
class Tree {
private:
    TreeNode<T> *root;

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

public:
    Tree() : root(nullptr) {}

    ~Tree() {
        delete_tree(root);
    }

    void create_tree(const T &value) {
        create_node(root, value);
    }

    void travers_tree() const {
        travers_node(root);
        std::cout << std::endl;
    }

    TreeNode<T> *search_tree(const T &value) const {
        return search_node(root, value);
    }

    void set_root(TreeNode<T>* new_root) {
        root = new_root;
    }

    TreeNode<T>* get_root() const {
        return root;
    }
};


#endif
