#include <iostream>
#include <string>
#include "../header/arifmeticTree.h"

using namespace std;

int main() {
    ArithmeticTree tree;
    string expression;
    char repeat = '2';

    cout << "калькулятор арифметических выражений" << endl;

    while (repeat == '2') {
        cout << "\nВведите арифметическое выражение: ";
        getline(cin, expression);

        if (tree.build_expression(expression)) {
            cout << "Дерево выражения: ";
            tree.print_tree();

            double result;
            if (tree.evaluate(result)) {
                cout << "Результат: " << expression << " = " << result << endl;
            } else {
                cout << "Ошибка вычисления выражения" << endl;
            }
        } else {
            cout << "Ошибка: " << tree.get_error() << endl;
        }

        cout << "\nПовторить операцию? (нажмите 2): ";
        cin >> repeat;
        cin.ignore();
        tree.clear();
    }


    return 0;
}