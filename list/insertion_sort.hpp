#pragma once

#include <vector>
#include "list.hpp"

template<class T>
void insertionSort(list<T>& list, bool (*cmp)(T, T)) {
    vector<T> v;
    for (int i = 0; i < list.size(); i += 1) {
        v.push_back(list.get(i));
    }

    for (int i = 0; i < v.size(); i += 1) {
        int m = i;
        for (int k = i + 1; k < v.size(); k += 1) {
            if (cmp(v[m], v[k])) {
                m = k;
            }
        }
        swap(v[i], v[m]);
    }

    list.clear();
    for (int i = 0; i < v.size(); i+= 1) {
        list.add(v[i]);
    }
}