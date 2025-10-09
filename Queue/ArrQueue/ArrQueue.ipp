#pragma once

#include "ArrQueue.h"
#include <array>
#include <stdexcept>

template <typename T, size_t N>
ArrQueue<T, N>::ArrQueue()
{
	f_ind = 0;
	r_ind = 0;
}
template <typename T, size_t N>
const T& ArrQueue<T, N>::rear() const
{
	if (empty())
		throw std::underflow_error("Queue is empty");
	std::size_t index = (r_ind - 1) % CAP;
	return arr[index];
}

template <typename T, size_t N>
const T& ArrQueue<T, N>::front() const
{
	std::size_t index = f_ind % CAP;
	return arr[index];
}

template <typename T, size_t N>
void ArrQueue<T, N>::dequeue()
{
	if (empty())
		throw std::underflow_error("Queue is empty");
	++f_ind;
}

template <typename T, size_t N>
void ArrQueue<T, N>::enqueue(const T& val)
{
	if (full_helper())
		throw std::overflow_error("Queue is full");
	arr[r_ind] = val;
	r_ind = (r_ind + 1) % CAP;
}

template <typename T, size_t N>
void ArrQueue<T, N>::clear()
{
	f_ind = 0;
	r_ind = 0;
}

template <typename T, size_t N>
bool ArrQueue<T, N>::empty() const
{
	return f_ind == r_ind;
}

template <typename T, size_t N>
bool ArrQueue<T, N>::full_helper() const
{
	return (r_ind + 1) % CAP == f_ind;
}
