// #include <cassert>
#include <iostream>
#include <vector>
#include "../book_info.hpp"
#include "../character_info.hpp"
#include "../find_series.hpp"
using namespace std;

void testSeries() {
    cout << "~ Series test ~" << '\n';

    vector<bookInfo> books;
    vector<characterInfo> characters;

    auto b1 = bookInfo::create();
    b1.title = "BOne";
    b1.year = 2020;
    b1.anotation = "";
    b1.autor = "";
    auto b2 = bookInfo::create();
    b2.title = "BTwo";
    b2.year = 1900;
    b2.anotation = "";
    b2.autor = "";
    auto b3 = bookInfo::create();
    b3.title = "BThree";
    b3.year = 2000;
    b3.anotation = "";
    b3.autor = "";

    characterInfo c1, c2, c3;
    c1.names.push_back("COne");
    c2.names.push_back("CTwo");
    c3.names.push_back("CThree");

    c1.books.insert(make_pair(b1.uid, MAIN));
    c1.books.insert(make_pair(b2.uid, SECONDARY));
    c1.books.insert(make_pair(b3.uid, EPIZODIC));

    c2.books.insert(make_pair(b1.uid, SECONDARY));
    c2.books.insert(make_pair(b2.uid, SECONDARY));
    c2.books.insert(make_pair(b3.uid, SECONDARY));

    c3.books.insert(make_pair(b1.uid, MAIN));
    c3.books.insert(make_pair(b2.uid, EPIZODIC));

    books.push_back(b1);
    books.push_back(b2);
    books.push_back(b3);
    characters.push_back(c1);
    characters.push_back(c2);
    characters.push_back(c3);

    auto series = findSeries(books, characters);
    for (auto seria: series) {
        cout << "Seria with character '" << seria.first << "':" << '\n';
        for (int i = 0; i < seria.second.size(); i += 1) {
            seria.second.get(i).printShort();
        }
    }
}