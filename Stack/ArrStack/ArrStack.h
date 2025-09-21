#pragma once

#include "Stack.h"
#include <array>

template <typename T>
class ArrStack : public Stack<T>
{
public:
	ArrStack() : size(0) {}
	void push(const T&) override;
	void pop() override;
	void clear() override;
	const T& top() const override;
	bool empty() const override;
private:
	std::array<T, 15> arr;
	std::size_t size;
};

#include "ArrStack.ipp"
