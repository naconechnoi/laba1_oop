#pragma once

#include "list.hpp"
using namespace std;

template <class T>
struct linkedList: public list<T> {
    struct node {
        T data;
        node* next = nullptr;
    };

    unsigned s_size;
    node* begin;

    linkedList() {
        s_size = 0;
        begin = new node;
    }

    virtual unsigned size() {
        return s_size;
    }

    virtual T get(unsigned pos) {
        node* i = begin->next;
        for (int k = 0; k < pos; k += 1) {
            i = i->next;
        }
        return i->data;
    }

    virtual void remove(unsigned pos) {
        node* i = begin;
        for (int k = 0; k < pos; k += 1) {
            i = i->next;
        }
        node* m = i->next;
        i->next = i->next->next;
        delete m;
        s_size -= 1;
    }

    virtual void clear() {
        node* i = begin->next;
        while (i != nullptr) {
            node* m = i->next;
            delete i;
            i = m;
        }
        s_size = 0;
    }

    virtual void add(T data) {
        node* i = begin;
        while (i->next != nullptr) {
            i = i->next;
        }
        i->next = new node;
        i->next->data = data;
        s_size += 1;
    }
};