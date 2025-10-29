#include "../header/arifmeticTree.h"
#include <string_view>
#include <cctype>


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
    bool has_dot = false;

    while (pos < expression.length()) {
        char c = expression[pos];
        if (std::isdigit(c)) {
            number += c;
        } else if (c == '.' && !has_dot) {
            number += c;
            has_dot = true;
        } else {
            break;
        }
        pos++;
    }
    return number;
}
//////////////

TreeNode<std::string> *ArithmeticTree::read_expression() {
    TreeNode<std::string> *left = read_term();
    if (left == nullptr) return nullptr;

    skip_spaces();

    while (pos < expression.length() && (expression[pos] == '+' || expression[pos] == '-')) {
        std::string symbol(1, expression[pos]);
        pos++;
        TreeNode<std::string> *right = read_term();
        if (right == nullptr) {
            delete left;
            return nullptr;
        }

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
    if (left == nullptr) return nullptr;

    skip_spaces();

    while (pos < expression.length() && (expression[pos] == '*' || expression[pos] == '/')) {
        std::string symbol(1, expression[pos]);
        pos++;
        TreeNode<std::string> *right = read_factor();
        if (right == nullptr) {
            delete left;
            return nullptr;
        }

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

    if (pos >= expression.length()) {
        error_message = "Неожиданный конец выражения";
        return nullptr;
    }

    if (expression[pos] == '(') {
        pos++;
        TreeNode<std::string> *node = read_expression();
        if (node == nullptr) return nullptr;

        skip_spaces();

        if (pos >= expression.length() || expression[pos] != ')') {
            delete node;
            error_message = "Ошибка!!! Нет закрывающейся скобки";
            return nullptr;
        }
        pos++;
        return node;
    } else {
        std::string number = read_number();
        if (number.empty()) {
            error_message = "Ожидается число или выражение в скобках";
            return nullptr;
        }
        return new TreeNode<std::string>(number);
    }
}

double ArithmeticTree::evaluate_node(TreeNode<std::string> *node) const {
    if (node == nullptr) {
        return 0;
    }

    std::string data = node->get_data();

    if (!is_operator(data[0])) {
        try {
            return std::stod(data);
        } catch (const std::exception &) {
            return 0;
        }
    }

    double left_val = evaluate_node(node->get_left_node());
    double right_val = evaluate_node(node->get_right_node());

    if (data == "+") return left_val + right_val;
    if (data == "-") return left_val - right_val;
    if (data == "*") return left_val * right_val;
    if (data == "/") {
        return left_val / right_val;
    }

    return 0;
}

bool ArithmeticTree::build_expression(std::string_view expr) {
    expression = std::string(expr);
    pos = 0;
    error_message.clear();

    if (expression.empty()) {
        error_message = "Выражение пусто";
        return false;
    }

    TreeNode<std::string> *root = read_expression();
    if (root == nullptr) {
        return false;
    }

    skip_spaces();

    if (pos < expression.length()) {
        delete root;
        error_message = "Ошибка!!! Удалите символ: " + expression.substr(pos, 1);
        return false;
    }
    expression_tree.set_root(root);
    return true;
}

bool ArithmeticTree::evaluate(double &result) const {
    if (expression_tree.get_root() == nullptr) {
        return false;
    }

    result = evaluate_node(expression_tree.get_root());
    return true;
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

void ArithmeticTree::print_node(TreeNode<std::string> *node, int depth) const {
    if (node == nullptr) return;

    print_node(node->get_right_node(), depth + 1);

    for (int i = 0; i < depth; i++) {
        std::cout << "    ";
    }
    std::cout << node->get_data() << std::endl;

    print_node(node->get_left_node(), depth + 1);
}

void ArithmeticTree::clear() {
    if (expression_tree.get_root() != nullptr) {
        expression_tree = Tree<std::string>();
    }
    expression.clear();
    pos = 0;
}
