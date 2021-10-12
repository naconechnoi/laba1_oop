#include <cassert>
#include <iostream>
#include "../list/array_list.hpp"
#include "../list/insertion_sort.hpp"
#include "../list/quick_sort.hpp"
#include "../list/bubble_sort.hpp"
#include "../list/merge_sort.hpp"
using namespace std;

bool cmp(int a, int b) {
    return a > b;
}

void testSorts() {
    arrayList<int> al;

    // insertionSort
    al.add(5);
    al.add(2);
    al.add(7);
    al.add(4);
    insertionSort(al, &cmp);
    assert(al.get(0) == 2);
    assert(al.get(1) == 4);
    assert(al.get(2) == 5);
    assert(al.get(3) == 7);
    cout << "insertionSort passed" << '\n';
    al.clear();

    // quickSort
    al.add(5);
    al.add(2);
    al.add(7);
    al.add(4);
    quickSort(al, &cmp);
    assert(al.get(0) == 2);
    assert(al.get(1) == 4);
    assert(al.get(2) == 5);
    assert(al.get(3) == 7);
    cout << "quickSort passed" << '\n';
    al.clear();

    // bubbleSort
    al.add(5);
    al.add(2);
    al.add(7);
    al.add(4);
    bubbleSort(al, &cmp);
    assert(al.get(0) == 2);
    assert(al.get(1) == 4);
    assert(al.get(2) == 5);
    assert(al.get(3) == 7);
    cout << "bubbleSort passed" << '\n';
    al.clear();

    // mergeSort
    al.add(5);
    al.add(2);
    al.add(7);
    al.add(4);
    mergeSort(al, &cmp);
    assert(al.get(0) == 2);
    assert(al.get(1) == 4);
    assert(al.get(2) == 5);
    assert(al.get(3) == 7);
    cout << "mergeSort passed" << '\n';
    al.clear();
}