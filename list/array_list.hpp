#pragma once

#include <algorithm>
#include "list.hpp"
using namespace std;

template <class T>
struct arrayList: public list<T> {
    T* storage;
    unsigned capacity;
    unsigned s_size;

    arrayList(unsigned initialCapacity = 1) {
        storage = new T[initialCapacity];
        capacity = initialCapacity;
        s_size = 0;
    }

    virtual unsigned size() {
        return s_size;
    }

    virtual T get(unsigned pos) {
        return storage[pos];
    }

    virtual void remove(unsigned pos) {
        for (int i = pos + 1; i < s_size; i += 1) {
            storage[i - 1] = storage[i];
        }
        s_size -= 1;
    }

    virtual void clear() {
        s_size = 0;
    }

    void grow() {
        capacity *= 2;
        T* newStorage = new T[capacity];
        copy(storage, storage + s_size, newStorage);
        storage = newStorage;
    }

    virtual void add(T data) {
        if (s_size == capacity) {
            grow();
        }
        storage[s_size] = data;
        s_size += 1;
    }
};