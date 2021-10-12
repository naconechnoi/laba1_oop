#pragma once

#include "list/array_list.hpp"
#include "list/quick_sort.hpp"
#include "book_info.hpp"
#include "character_info.hpp"

bool cmp(bookInfo a, bookInfo b) {
    return a.year > b.year;
}

vector<pair<string /* character name */, arrayList<bookInfo>>> findSeries(
    vector<bookInfo> books,
    vector<characterInfo> characters
) {
    vector<pair<string, arrayList<bookInfo>>> series;
    for (auto ch: characters) {
        arrayList<bookInfo> seria;
        for (auto rec: ch.books) {
            if (rec.second == MAIN || rec.second == SECONDARY) {
                for (auto b: books) {
                    if (b.uid == rec.first) {
                        seria.add(b);
                    }
                }
            }
        }
        if (seria.size() > 1) {
            quickSort(seria, &cmp);
            series.push_back(make_pair(ch.names[0], seria));
        }
    }
    return series;
}