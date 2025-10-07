#include "../header/ABCCatalog.h"
#include "../header/article.h"
#include "../header/BookCard.h"
#include "../header/function.h"
#include "../header/ThematicCatalog.h"
#include <iostream>
#include <array>
#define MAX_SIZE 200

using namespace std;

void show_menu() {
    auto *main_catalog = new Catalog();
    auto *thematic_catalog = new ThematicCatalog();
    auto *abc_catalog = new ABCCatalog();

    array<CollectionCard *, MAX_SIZE> collections{};
    int collection_count = 0;

    int choice;

    do {
        cout << "\n    МЕНЮ    " << endl;
        cout << "1. Добавить сборник статей" << endl;
        cout << "2. Добавить книгу" << endl;
        cout << "3. Добавить статью в сборник" << endl;
        cout << "4. Поиск по шифру" << endl;
        cout << "5. Поиск по автору или названию" << endl;
        cout << "6. Показать все в алфавитном порядке" << endl;
        cout << "0. Выход" << endl;
        cout << "Выберите действие: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1: {
                string author;
                string title;
                string code;
                string publisher;
                int year;
                int circulation;
                int pages;

                cout << "Автор сборника: ";
                getline(cin, author);
                cout << "Название сборника: ";
                getline(cin, title);
                cout << "Код каталога: ";
                getline(cin, code);
                cout << "Издательство: ";
                getline(cin, publisher);
                cout << "Год издания: ";
                cin >> year;
                cout << "Тираж: ";
                cin >> circulation;
                cout << "Количество страниц: ";
                cin >> pages;
                cin.ignore();

                auto *collection = new CollectionCard(
                        author, title, code, publisher, year, circulation, pages);

                if (collection_count < MAX_SIZE) {
                    collections[collection_count] = collection;
                    collection_count++;
                }

                int article_count;
                cout << "Сколько статей добавить в сборник? ";
                cin >> article_count;
                cin.ignore();

                for (int i = 0; i < article_count; i++) {
                    string article_author;
                    string article_title;
                    cout << "Статья " << (i + 1) << " автор: ";
                    getline(cin, article_author);
                    cout << "Статья " << (i + 1) << " название: ";
                    getline(cin, article_title);

                    auto *article = new Article(article_title, article_author);
                    collection->add_article(article);
                }

                main_catalog->add_card(collection);
                thematic_catalog->add_card(collection);
                abc_catalog->add_card(collection);

                cout << "Сборник статей добавлен!" << endl;
                break;
            }

            case 2: {
                string author;
                string title;
                string code;
                string publisher;
                int year;
                int circulation;
                int pages;

                cout << "Автор: ";
                getline(cin, author);
                cout << "Название: ";
                getline(cin, title);
                cout << "Код каталога: ";
                getline(cin, code);
                cout << "Издательство: ";
                getline(cin, publisher);
                cout << "Год издания: ";
                cin >> year;
                cout << "Тираж: ";
                cin >> circulation;
                cout << "Количество страниц: ";
                cin >> pages;
                cin.ignore();

                auto *book_article = new Article(title, author);
                auto book = new BookCard(BookData{author, title, code, publisher, year, circulation, pages},
                                         book_article);

                main_catalog->add_card(book);
                thematic_catalog->add_card(book);
                abc_catalog->add_card(book);

                cout << "Книга добавлена!" << endl;
                break;
            }

            case 3: {
                if (collection_count == 0) {
                    cout << "Сначала добавьте сборник статей!" << endl;
                    break;
                }

                cout << "Доступные сборники:" << endl;
                for (int i = 0; i < collection_count; i++) {
                    cout << (i + 1) << ". " << collections[i]->get_title() << endl;
                }

                int collection_choice;
                cout << "Выберите сборник: ";
                cin >> collection_choice;
                cin.ignore();

                if (collection_choice < 1 || collection_choice > collection_count) {
                    cout << "Неверный выбор!" << endl;
                    break;
                }

                string article_author;
                string article_title;
                cout << "Автор статьи: ";
                getline(cin, article_author);
                cout << "Название статьи: ";
                getline(cin, article_title);

                auto *new_article = new Article(article_title, article_author);
                collections[collection_choice - 1]->add_article(new_article);

                cout << "Статья добавлена!" << endl;
                break;
            }

            case 4: {
                string cipher;
                cout << "Введите шифр для поиска: ";
                getline(cin, cipher);
                main_catalog->search_by_cipher(cipher);
                break;
            }

            case 5: {
                string search_term;
                cout << "Введите автора или название: ";
                getline(cin, search_term);
                main_catalog->search_by_author_or_title(search_term);
                break;
            }

            case 6: {
                abc_catalog->show_all_sorted();
                break;
            }

            case 0:
                cout << "Выход из программы..." << endl;
                break;

            default:
                cout << "Неверный выбор!" << endl;
        }

    } while (choice != 0);

    for (int i = 0; i < collection_count; i++) {
        delete collections[i];
    }

    delete main_catalog;
    delete thematic_catalog;
    delete abc_catalog;
}