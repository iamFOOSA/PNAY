#ifndef LABS___5__ARIFMETICTREE_H
#define LABS___5__ARIFMETICTREE_H

#include "Tree.h"
#include <iostream>
#include <string>
#include <stdexcept>

class ArithmeticTree {
private:
    Tree<std::string> expression_tree;
    std::string expression;
    int pos = 0;

    void skip_spaces();

    static bool is_operator(char c);

    std::string read_number();

    TreeNode<std::string> *read_expression();

    TreeNode<std::string> *read_term();

    TreeNode<std::string> *read_factor();

    double evaluate_node(TreeNode<std::string> *node) const;


public:
    ArithmeticTree()= default;

    ~ArithmeticTree() = default;

    ArithmeticTree(const ArithmeticTree&) = delete;

    ArithmeticTree& operator=(const ArithmeticTree&) = delete;

    void build_expression(std::string_view expr);

    double evaluate() const;

    void print_tree() const;

    void print_node(TreeNode<std::string> *node, int depth) const;

    void clear();

};

#endif
