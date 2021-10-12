#pragma once

#include <vector>
#include "list.hpp"

template<class T>
void msMerge(vector<T>& array, int left, int mid, int right, bool (*cmp)(T, T)) {
    int subArrayOne = mid - left + 1;
    int subArrayTwo = right - mid;
    T* leftArray = new T[subArrayOne];
    T* rightArray = new T[subArrayTwo];
    for (auto i = 0; i < subArrayOne; i += 1) {
        leftArray[i] = array[left + i];
    } 
    for (auto j = 0; j < subArrayTwo; j += 1) {
        rightArray[j] = array[mid + 1 + j];
    } 
  
    int indexOfSubArrayOne = 0, indexOfSubArrayTwo = 0;
    int indexOfMergedArray = left;
    while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) {
        if (cmp(leftArray[indexOfSubArrayOne], rightArray[indexOfSubArrayTwo])) {
            array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo += 1;
        }
        else {
            array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne += 1;
        }
        indexOfMergedArray += 1;
    }
    while (indexOfSubArrayOne < subArrayOne) {
        array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne += 1;
        indexOfMergedArray += 1;
    }
    while (indexOfSubArrayTwo < subArrayTwo) {
        array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo += 1;
        indexOfMergedArray += 1;
    }
}

template<class T>
void msProcess(vector<T>& array, int begin, int end, bool (*cmp)(T, T)) {
    if (begin >= end) {
        return;
    }
    int mid = begin + (end - begin) / 2;
    msProcess(array, begin, mid, cmp);
    msProcess(array, mid + 1, end, cmp);
    msMerge(array, begin, mid, end, cmp);
}

template<class T>
void mergeSort(list<T>& list, bool (*cmp)(T, T)) {
    vector<T> v;
    for (int i = 0; i < list.size(); i += 1) {
        v.push_back(list.get(i));
    }

    msProcess(v, 0, v.size() - 1, cmp);

    list.clear();
    for (int i = 0; i < v.size(); i+= 1) {
        list.add(v[i]);
    }
}