#include <cassert>
#include <iostream>
#include "../list/array_list.hpp"
#include "../list/vector_list.hpp"
#include "../list/linked_list.hpp"
using namespace std;

void testLists() {
    // arrayList
    arrayList<int> al;
    al.add(5);
    al.add(6);
    al.add(8);
    al.add(10);
    al.add(15);
    al.remove(1);
    assert(al.get(1) == 8);
    assert(al.size() == 4);
    cout << "arrayList passed" << '\n';

    // vectorList
    vectorList<int> vl;
    vl.add(5);
    vl.add(6);
    vl.add(8);
    vl.add(10);
    vl.add(15);
    vl.remove(1);
    assert(vl.get(1) == 8);
    assert(vl.size() == 4);
    cout << "vectorList passed" << '\n';

    // linkedList
    linkedList<int> ll;
    ll.add(5);
    ll.add(6);
    ll.add(8);
    ll.add(10);
    ll.add(15);
    ll.remove(1);
    assert(ll.get(1) == 8);
    assert(ll.size() == 4);
    cout << "linkedList passed" << '\n';
}