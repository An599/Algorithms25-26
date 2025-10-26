#pragma once
#include <iostream>
#include <stdexcept>

template <typename T>
class CyclicList 
{
private:
    struct Node {
        T data;
        Node* next;
        Node(const T& value) : data(value), next(nullptr) {}
    };

    Node* head;
    Node* tail;
    size_t count;

public:
    CyclicList();
    ~CyclicList();

    void insert(size_t pos, const T& value);
    void erase(size_t pos);
    T getValue(size_t pos) const;

    size_t sizee() const;
    bool empty() const;
    void clear();
    void print() const;
};

#include "CyclicList.ipp"  

