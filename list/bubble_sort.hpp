#pragma once

#include <vector>
#include "list.hpp"

template<class T>
void bubbleSort(list<T>& list, bool (*cmp)(T, T)) {
    vector<T> v;
    for (int i = 0; i < list.size(); i += 1) {
        v.push_back(list.get(i));
    }

    for (int i = 0; i < v.size(); i += 1) {
        for (int k = 1; k < v.size(); k += 1) {
            if (cmp(v[k - 1], v[k])) {
                swap(v[k - 1], v[k]);
            }
        }
    }

    list.clear();
    for (int i = 0; i < v.size(); i+= 1) {
        list.add(v[i]);
    }
}