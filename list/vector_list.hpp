#pragma once

#include <algorithm>
#include <vector>
#include "list.hpp"
using namespace std;

template <class T>
struct vectorList: virtual list<T> {
    vector<T> storage;

    unsigned size() {
        return storage.size();
    }

    T get(unsigned pos) {
        return storage[pos];
    }

    void remove(unsigned pos) {
        storage.erase(storage.begin() + pos);
    }

    void clear() {
        storage.clear();
    }

    void add(T data) {
        storage.push_back(data);
    }
};