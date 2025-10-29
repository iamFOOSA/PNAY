#include "../header/arifmeticTree.h"
#include "../header/Tree.h"
#include <cctype>

ArithmeticTree::ArithmeticTree() : expression(""), pos(0) {}

void ArithmeticTree::skip_spaces() {
    while (pos < expression.length() && expression[pos] == ' ') {
        pos++;
    }
}

bool ArithmeticTree::is_operator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

std::string ArithmeticTree::read_number() {
    std::string number;
    while (pos < expression.length() && (std::isdigit(expression[pos]) || expression[pos] == '.')) {
        number += expression[pos];
        pos++;
    }
    return number;
}
//////////////

TreeNode<std::string> *ArithmeticTree::read_expression() {
    TreeNode<std::string> *left = read_term();
    skip_spaces();

    while (pos < expression.length() && (expression[pos] == '+' || expression[pos] == '-')) {
        std::string symbol(1, expression[pos]);
        pos++;
        TreeNode<std::string> *right = read_term();

        auto *symbol_node = new TreeNode<std::string>(symbol);
        symbol_node->set_left_node(left);
        symbol_node->set_right_node(right);
        left = symbol_node;

        skip_spaces();
    }
    return left;
}

TreeNode<std::string> *ArithmeticTree::read_term() {
    TreeNode<std::string> *left = read_factor();
    skip_spaces();

    while (pos < expression.length() && (expression[pos] == '*' || expression[pos] == '/')) {
        std::string symbol(1, expression[pos]);
        pos++;
        TreeNode<std::string> *right = read_factor();

        auto *symbol_node = new TreeNode<std::string>(symbol);
        symbol_node->set_left_node(left);
        symbol_node->set_right_node(right);
        left = symbol_node;

        skip_spaces();
    }
    return left;
}

TreeNode<std::string> *ArithmeticTree::read_factor() {
    skip_spaces();

    if (expression[pos] == '(') {
        pos++;
        TreeNode<std::string> *node = read_expression();
        skip_spaces();

        if (pos >= expression.length() || expression[pos] != ')') {
            throw std::runtime_error(" ошибка!!! нет закрывающейся скобки");
        }
        pos++;
        return node;
    } else {
        std::string number = read_number();
        if (number.empty()) {
            throw std::runtime_error(" ошибка!!! в дереве нет чисел");
        }
        return new TreeNode<std::string>(number);
    }
}

double ArithmeticTree::evaluate_node(TreeNode<std::string> *node) {
    if (node == nullptr) {
        throw std::runtime_error(" узел пуст");
    }

    std::string data = node->get_data();

     if (!is_operator(data[0])) {
         try {
             return std::stod(data);
         } catch (const std::exception &e) {
             throw std::runtime_error(" неверный числовой формат: " + data);
         }
     }

    double left_val = evaluate_node(node->get_left_node());
    double right_val = evaluate_node(node->get_right_node());

    if (data == "+") return left_val + right_val;
    if (data == "-") return left_val - right_val;
    if (data == "*") return left_val * right_val;
    if (data == "/") {
        if (right_val == 0) {
            throw std::runtime_error("ошибка!!! нельзя делить на ноль");
        }
        return left_val / right_val;
    }
    return 0;
}

void ArithmeticTree::build_expression(const std::string &expr) {
    expression = expr;
    pos = 0;

    TreeNode<std::string> *root = read_expression();

    skip_spaces();
    if (pos < expression.length()) {
        delete root;
        throw std::runtime_error("ошибка!!! удалите символ: " + expression.substr(pos));
    }
    expression_tree.set_root(root);
}

double ArithmeticTree::evaluate() {
    if (expression_tree.get_root() == nullptr) {
        throw std::runtime_error("не удалось построить дерево");
    }
    return evaluate_node(expression_tree.get_root());
}


void ArithmeticTree::print_tree() const {
    if (expression_tree.get_root() != nullptr) {
        std::cout << std::endl;
        print_node(expression_tree.get_root(), 0);
        std::cout << std::endl;
    } else {
        std::cout << "нет дерева" << std::endl;
    }
}

void ArithmeticTree::print_node(TreeNode<std::string>* node, int depth) const {
    if (node == nullptr) return;

    print_node(node->get_right_node(), depth + 1);

    for (int i = 0; i < depth; i++) {
        std::cout << "    ";
    }
    std::cout << node->get_data() << std::endl;

    print_node(node->get_left_node(), depth + 1);
}

