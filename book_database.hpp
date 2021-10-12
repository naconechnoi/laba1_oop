#pragma once

#include <string>
#include <fstream>
#include <vector>
#include "binary_io.hpp"
#include "book_info.hpp"
#include "character_info.hpp"
using namespace std;

struct bookDatabase {
    string filePath;
    vector<bookInfo> data;

    bookDatabase(string filePath) {
        this->filePath = filePath;
    }

    bookInfo operator[](int r) {
        return data[r];
    }

    bool load() {
        data.clear();

        ifstream fin(filePath, ios::binary);
        if (!fin) {
            return false;
        }

        unsigned count = binary_io::readUnsigned(fin);
        for (unsigned i = 0; i < count; i++) {
            bookInfo bi = bookInfo::binRead(fin);
            data.push_back(bi);

            if (bookInfo::uidCounter <= bi.uid) {
                bookInfo::uidCounter = bi.uid + 1;
            }
        }
        return true;
    }

    bool save() {
        ofstream fout(filePath);
        if (!fout) {
            return false;
        }

        unsigned count = data.size();
        binary_io::writeUnsigned(fout, count);
        for (bookInfo bi: data) {
            bi.binWrite(fout);
        }
        return true;
    }

    void add(bookInfo bi) {
        data.push_back(bi);
    }

    bool edit(bookInfo bi, unsigned uid) {
        for (bookInfo &e: data) {
            if (e.uid == uid) {
                bi.uid = uid;
                e = bi;
                return true;
            }
        }
        return false;
    }

    bool removeRec(unsigned uid) {
        auto i = data.begin();
        for (; i != data.end(); i++) {
            if (i->uid == uid) {
                data.erase(i);
                return true;
            }
        }
        return false;
    }

    struct findResult {
        bool success;
        bookInfo bi;
    };

    findResult find(unsigned uid) {
        for (bookInfo e: data) {
            if (e.uid == uid) {
                return {true, e};
            }
        }
        return {false, bookInfo()};
    }

    vector<bookInfo> findByAuthor(string author) {
        vector<bookInfo> books;
        for (bookInfo bi: data) {
            if (bi.autor == author) {
                books.push_back(bi);
            }
        }
        return books;
    }
};