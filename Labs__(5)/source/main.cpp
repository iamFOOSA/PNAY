#include <iostream>
#include <string>
#include "../header/arifmeticTree.h"

using namespace std;

int main() {
    ArithmeticTree tree;
    string expression;
    char repeat = '2';

    cout << "калькулятор арифметических выражений" << endl;

    while (repeat == '2' ) {
        cout << "\nВведите арифметическое выражение: ";
        getline(cin, expression);

        try {
            tree.build_expression(expression);

            cout << "Дерево выражения: ";
            tree.print_tree();

            double result = tree.evaluate();
            cout << "Результат: " << expression << " = " << result << endl;

        } catch (const exception& e) {
            cout << "Ошибка: " << e.what() << endl;
        }

        cout << "\n повторить операцию? (нажмите (2)): ";
        cin >> repeat;
        cin.ignore();
        tree.clear();
    }



    return 0;
}