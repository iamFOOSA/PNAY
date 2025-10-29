#ifndef LABS___5__TREENODE_H
#define LABS___5__TREENODE_H

template<typename T>
class TreeNode {
private:
    T data;
    TreeNode<T> *left_node;
    TreeNode<T> *right_node;

public:
    TreeNode(const T &value) : data(value), left_node(nullptr), right_node(nullptr) {}

    ~TreeNode() {
        delete left_node;
        delete right_node;
    }

    T get_data() const {
        return data;
    }


    const TreeNode<T> *get_left_node() const {
        return left_node;
    }

    const TreeNode<T> *get_right_node() const {
        return right_node;
    }

    TreeNode<T> *get_left_node(){
        return left_node;
    }

    TreeNode<T> *get_right_node(){
        return right_node;
    }

    void set_left_node(TreeNode<T> *node) {
        left_node = node;
    }

    void set_right_node(TreeNode<T> *node) {
        right_node = node;
    }
};

#endif