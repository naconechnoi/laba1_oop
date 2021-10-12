#pragma once

#include <vector>
#include "list.hpp"

template<class T>
int qsPartition(vector<T>& arr, int low, int high, bool (*cmp)(T, T)) { 
    T pivot = arr[high];
    int i = (low - 1);
    for (int k = low; k <= high - 1; k += 1) {
        if (cmp(pivot, arr[k])) {
            i += 1;
            swap(arr[i], arr[k]); 
        } 
    } 
    swap(arr[i + 1], arr[high]); 
    return (i + 1); 
}

template<class T>
void qsProcess(vector<T>& arr, int low, int high, bool (*cmp)(T, T)) {
    if (low < high) { 
        int pi = qsPartition(arr, low, high, cmp); 
        qsProcess(arr, low, pi - 1, cmp); 
        qsProcess(arr, pi + 1, high, cmp); 
    } 
} 

template<class T>
void quickSort(list<T>& list, bool (*cmp)(T, T)) {
    vector<T> v;
    for (int i = 0; i < list.size(); i += 1) {
        v.push_back(list.get(i));
    }

    qsProcess(v, 0, v.size() - 1, cmp);

    list.clear();
    for (int i = 0; i < v.size(); i+= 1) {
        list.add(v[i]);
    }
}
