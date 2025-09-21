#pragma once

#include "ArrStack.h"
#include <array>
#include <cassert>

template <typename T>
bool ArrStack<T>::empty() const
{
    return size == 0;
}

template <typename T>
const T& ArrStack<T>::top() const
{
    assert(!empty());
    return arr[size - 1];
}

template <typename T>
void ArrStack<T>::pop()
{
    if (empty())
        return;
    --size;
}

template <typename T>
void ArrStack<T>::push(const T& value)
{
    assert(size < 15);
    arr[size++] = value;
}

template <typename T>
void ArrStack<T>::clear()
{
    size = 0;
}
