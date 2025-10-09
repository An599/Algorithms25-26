#pragma once
#include <cstddef>

template <typename T>
class IQueue {
public:
	virtual void enqueue(const T&) = 0;
	virtual void dequeue() = 0;
	virtual bool empty() const= 0;
	virtual const T& rear() const = 0;
	virtual const T& front() const = 0;
	virtual void clear() = 0;
};
