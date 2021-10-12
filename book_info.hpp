#pragma once

#include <string>
#include <iostream>
#include <fstream>
#include "binary_io.hpp"
using namespace std;

struct bookInfo {
    static unsigned uidCounter;
    unsigned uid;
    string autor, title, genre, anotation;
    unsigned year;
    unsigned pages;
    
    static bookInfo create() {
        bookInfo bi;
        bi.genUid();
        return bi;
    }

    void genUid() {
        uid = uidCounter;
        uidCounter += 1;
    }

    static bookInfo binRead(ifstream& fin) {
        using namespace binary_io;
        bookInfo res;
        res.uid = readUnsigned(fin);
        res.autor = readString(fin);
        res.title = readString(fin);
        res.anotation = readString(fin);
        res.genre = readString(fin);
        res.year = readUnsigned(fin);
        res.pages = readUnsigned(fin);
        return res;
    }

    void binWrite(ofstream& fout) {
        using namespace binary_io;
        writeUnsigned(fout, uid);
        writeString(fout, autor);
        writeString(fout, title);
        writeString(fout, genre);
        writeString(fout, anotation);
        writeUnsigned(fout, year);
        writeUnsigned(fout, pages);
    }

    void print() {
    cout << "автор: " << autor << '\n';
    cout << "название книги: " << title << '\n';
    cout << "жанр: " << genre << '\n';
    cout << "количество страниц: " << pages << '\n';
    cout << "год выпуска: " << year << '\n';
    cout << "анотация: " << anotation << '\n';
}

    void printShort() {
        cout << uid << ": " << autor << " " << "[" << title << "]" << " " << genre << " " << pages << " " << year  << " " << anotation <<'\n';
    }

    static bookInfo read() {
        bookInfo res;
        cout << "автор: ";
        cin >> res.autor;
        cout << "название книги: ";
        cin >> res.title;
        cout << "жанр: ";
        cin >> res.genre;
        cout << "анотация: ";
        string line;
        cin.ignore();
        getline(cin, line);
        res.anotation = line;
        cout << "год выпуска: ";
        cin >> res.year;
        cout << "количество страниц: ";
        cin >> res.pages;
        return res;
    }
};

unsigned bookInfo::uidCounter = 0;