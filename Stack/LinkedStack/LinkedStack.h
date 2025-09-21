#pragma once

#include "Node.h"
#include "Stack.h"

template <typename T>
class LinkedStack : public Stack<T>
{
public:
	LinkedStack() : m_top(nullptr) {}

	void push(const T&);
	void pop();
	void clear();
	const T& top() const;
	bool empty() const;

	LinkedStack(const LinkedStack& other);
	LinkedStack(LinkedStack&& other) noexcept;
	LinkedStack& operator=(const LinkedStack& other);
	LinkedStack& operator=(LinkedStack&& other) noexcept;
private:
	Node<T>* m_top;
};

#include "LinkedStack.ipp"
