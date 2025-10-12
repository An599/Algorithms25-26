#pragma once

#include <array>
#include <stdexcept>
#include <cstddef>

template <typename T, std::size_t N>
ArrDeque<T, N>::ArrDeque() noexcept : f_index(0), r_index(0), count(0){}

template <typename T, std::size_t N>
ArrDeque<T, N>::~ArrDeque() {}

template <typename T, std::size_t N>
bool ArrDeque<T, N>::empty() const noexcept
{
    return count == 0;
}

template <typename T, std::size_t N>
bool ArrDeque<T, N>::full() const noexcept
{
    return count == N;
}

template <typename T, std::size_t N>
std::size_t ArrDeque<T, N>::size() const noexcept
{
    return count;
}

template <typename T, std::size_t N>
const T& ArrDeque<T, N>::front() const
{
    if (empty())
        throw std::underflow_error("Deque is empty");
    return arr[f_index];
}

template <typename T, std::size_t N>
const T& ArrDeque<T, N>::rear() const
{
    if (empty())
        throw std::underflow_error("Deque is empty");
    std::size_t index = (r_index + N - 1) % N;
    return arr[index];
}

template <typename T, std::size_t N>
void ArrDeque<T, N>::push_back(const T& val)
{
    if (full())
        throw std::overflow_error("Deque is full");
    arr[r_index] = val;
    r_index = (r_index + 1) % N;
    ++count;
}

template <typename T, std::size_t N>
void ArrDeque<T, N>::push_back(T&& val)
{
    if (full())
        throw std::overflow_error("Deque is full");
    arr[r_index] = std::move(val);
    r_index = (r_index + 1) % N;
    ++count;
}

template <typename T, std::size_t N>
void ArrDeque<T, N>::push_front(const T& val)
{
    if (full())
        throw std::overflow_error("Deque is full");
    f_index = (f_index + N - 1) % N;
    arr[f_index] = val;
    ++count;
}

template <typename T, std::size_t N>
void ArrDeque<T, N>::push_front(T&& val)
{
    if (full())
        throw std::overflow_error("Deque is full");
    f_index = (f_index + N - 1) % N;
    arr[f_index] = std::move(val);
    ++count;
}

template <typename T, std::size_t N>
void ArrDeque<T, N>::pop_back()
{
    if (empty())
        throw std::underflow_error("Deque is empty");
    r_index = (r_index + N - 1) % N;
    --count;
}

template <typename T, std::size_t N>
void ArrDeque<T, N>::pop_front()
{
    if (empty())
        throw std::underflow_error("Deque is empty");
    f_index = (f_index + 1) % N;
    --count;
}

template <typename T, std::size_t N>
void ArrDeque<T, N>::clear()
{
    f_index = 0;
    r_index = 0;
    count = 0;
}
