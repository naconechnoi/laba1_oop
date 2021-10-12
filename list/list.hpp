#pragma once

template <class T>
struct list {
    virtual unsigned size() { throw -1; };
    virtual void add(T data) { throw -1; };
    virtual void remove(unsigned pos) { throw -1; };
    virtual T get(unsigned pos) { throw -1; };
    virtual void clear() { throw -1; };
};