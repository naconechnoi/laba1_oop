#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <stack>
#include "binary_io.hpp"
#include "book_info.hpp"
#include "character_info.hpp"
#include "book_database.hpp"
#include "tests/test_lists.cpp"
#include "tests/test_sorts.cpp"
#include "tests/test_series.cpp"
using namespace std;

void showHelp() {
    cout << "Справка по командам:" << '\n';
    cout << "load: загрузить записи из файла" << '\n';
    cout << "add: добавить запись" << '\n';
    cout << "edit: редактировать запись" << '\n';
    cout << "remove: удалить запись" << '\n';
    cout << "show: показать запись" << '\n';
    cout << "list: показать список записей" << '\n';
    cout << "findAuthor: показать список записей по автору" << '\n';
    cout << "save: сохранить изменения в файл" << '\n';
    cout << "test: запустить тесты" << '\n';
    cout << "help: показать справку" << '\n';
    cout << "quit: выйти из программы" << '\n';
}

int main() {
    bookDatabase db("db.hex");
    cout << "Введите \"help\" что бы увидеть справку" << '\n' << '\n';

    while (true) {
        string action;
        cout << "> ";
        cin >> action;

        if (action == "load") {
            if (!db.load()) {
                cout << "Ошибка: невозможно открыть файл!" << '\n';
            }
        }
        else if (action == "add") {
            cout << "Введите данные записи:" << '\n';
            bookInfo bi = bookInfo::read();
            bi.genUid();
            cout << "индекс: " << bi.uid << '\n';
            db.add(bi);
        }
        else if (action == "edit") {
            cout << "Введите старые данные записи:" << '\n';
            unsigned uid;
            cout << "индекс: ";
            cin >> uid;
            cout << "Введите новые данные записи:" << '\n';
            bookInfo bi = bookInfo::read();
            if (!db.edit(bi, uid)) {
                cout << "Ошибка: запись не найдена!" << '\n';
            }
        }
        else if (action == "remove") {
            cout << "Введите данные удаляемой записи:" << '\n';
            unsigned uid;
            cout << "индекс: ";
            cin >> uid;
            if (!db.removeRec(uid)) {
                cout << "Ошибка: запись не найдена!" << '\n';
            }
        }
        else if (action == "show") {
            cout << "Введите данные искомой записи:" << '\n';
            unsigned uid;
            cout << "индекс: ";
            cin >> uid;
            auto res = db.find(uid);
            if (!res.success) {
                cout << "Ошибка: запись не найдена!" << '\n';
            }
            else {
                res.bi.print();
            }
        }
        else if (action == "list") {
            for (bookInfo bi: db.data) {
                bi.printShort();
            }
        }
        else if (action == "findAuthor") {
            cout << "Введите автора: ";
            string author;
            cin >> author;
            auto books = db.findByAuthor(author);
            cout << "Найдено книг: " << books.size() << '\n';
            for (bookInfo bi: books) {
                bi.printShort();
            }
        }
        else if (action == "save") {
            if (!db.save()) {
                cout << "Ошибка: невозможно открыть файл!" << '\n';
            }
        }
        else if (action == "test") {
            testLists();
            testSorts();
            testSeries();
        }
        else if (action == "help") {
            showHelp();
        }
        else if (action == "quit") {
            break;
        }
        else {
            cout << "Ошибка: команда \"" << action << "\" не найдена!" << '\n';
        }
        cout << '\n';
    }
}