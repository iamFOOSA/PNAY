#include <iostream>
#include <limits>
#include "../header/Tree.h"

using namespace std;

void display_menu() {
    cout << "\n    Меню      " << endl;
    cout << "1. Создать новое дерево" << endl;
    cout << "2. Добавить значение в дерево" << endl;
    cout << "3. Показать обход дерева (без рекурсии)" << endl;
    cout << "4. Показать обход дерева (рекурсивный)" << endl;
    cout << "5. Найти значение в дереве" << endl;
    cout << "6. Показать дерево " << endl;
    cout << "7. Очистить дерево" << endl;
    cout << "0. Выход" << endl;
    cout << "Выберите опцию: ";
}

void create_tree(Tree<int>& tree) {
    tree = Tree<int>();
    cout << "Новое дерево создано" << endl;

    char choice;
    do {
        int value;
        cout << "Введите значение для вставки: ";
        cin >> value;
        tree.insert(value);

        cout << "Если хотите добавить значение нажмите (1): ";
        cin >> choice;
    } while (choice == '1');
}

void add_value(Tree<int>& tree) {
    int value;
    cout << "Введите значение для вставки: ";
    cin >> value;
    tree.insert(value);
    cout << "Значение " << value << " добавлено в дерево" << endl;
}

void display_iterator_traversal(Tree<int>& tree) {
    if (tree.is_empty()) {
        cout << "Дерево пустое" << endl;
        return;
    }

    cout << "Обход дерева с итератором: ";
    auto elements = tree.traverse_with_iterator();
    for (int val : elements) {
        cout << val << " ";
    }
    cout << endl;
}

void display_algorithm_traversal(Tree<int>& tree) {
    if (tree.is_empty()) {
        cout << "Дерево пустое" << endl;
        return;
    }

    cout << "Рекурсивный обход дерева: ";
    auto elements = tree.traverse_in_order();
    for (int val : elements) {
        cout << val << " ";
    }
    cout << endl;
}

void search_value(Tree<int>& tree) {
    if (tree.is_empty()) {
        cout << "Дерево пустое" << endl;
        return;
    }

    int value;
    cout << "Введите значение для поиска: ";
    cin >> value;

    auto found_node = tree.search(value);
    if (found_node) {
        cout << "Значение " << value << " найдено в дереве" << endl;

        cout << "Контекст узла: ";
        if (found_node->left)
            cout << "левое поддерево = " << found_node->left->data << " ";
        if (found_node->right)
            cout << "правое поддерево = " << found_node->right->data << " ";
        if (!found_node->left && !found_node->right)
            cout << "листовой узел";
        cout << endl;
    } else {
        cout << "Значение " << value << " не найдено в дереве" << endl;
    }
}

void display_tree_horizontal(Tree<int>& tree) {
    if (tree.is_empty()) {
        cout << "Дерево пустое" << endl;
        return;
    }

    cout << "Структура дерева:" << endl;
    tree.print_tree_horizontal();
}

void clear_tree(Tree<int>& tree) {
    tree = Tree<int>();
    cout << "Дерево успешно очищено" << endl;
}

int main() {
    setlocale(LC_ALL, "Russian");

    Tree<int> tree;
    int choice;

    do {
        display_menu();

        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Ошибка, введите число от 1 до 7" << endl;
            continue;
        }

        switch (choice) {
            case 1:
                create_tree(tree);
                break;
            case 2:
                add_value(tree);
                break;
            case 3:
                display_iterator_traversal(tree);
                break;
            case 4:
                display_algorithm_traversal(tree);
                break;
            case 5:
                search_value(tree);
                break;
            case 6:
                display_tree_horizontal(tree);
                break;
            case 7:
                clear_tree(tree);
                break;
            case 0:
                break;
            default:
                cout << "Неверный выбор, выберите от 1 до 7" << endl;
                break;
        }

        if (choice != 0) {
            cin.ignore();
            cin.get();
        }

    } while (choice != 9);

    return 0;
}