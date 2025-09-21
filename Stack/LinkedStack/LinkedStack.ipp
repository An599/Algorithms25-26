#pragma once

#include "LinkedStack.h"
#include <cassert>

template <typename T>
bool LinkedStack<T>::empty() const
{
	return m_top == nullptr;
}

template <typename T>
void LinkedStack<T>::pop()
{
	if (!m_top)
		return;
	Node<T>* temp = m_top;
	m_top = m_top->next;
	delete temp;
}

template <typename T>
const T& LinkedStack<T>::top() const
{
	assert(m_top != nullptr);
	return m_top->val;
}

template <typename T>
void LinkedStack<T>::push(const T& newVal)
{
	m_top = new Node<T>(newVal, m_top);
}

template <typename T>
void LinkedStack<T>::clear()
{
	while (!empty())
		pop();
}

template <typename T>
LinkedStack<T>::LinkedStack(const LinkedStack& other) : m_top(nullptr) {
	if (other.m_top == nullptr)
		return;
	m_top = new Node<T>(other.m_top->val);
	Node<T>* temp = m_top;
	Node<T>* other_temp = other.m_top;
	while (other_temp->next != nullptr)
	{
		temp->next = new Node<T>(other_temp->next->val);
		temp = temp->next;
		other_temp = other_temp->next;
	}
}

template <typename T>
LinkedStack<T>::LinkedStack(LinkedStack&& other) noexcept : m_top(other.m_top) {
	other.m_top = nullptr;
}

template <typename T>
LinkedStack<T>& LinkedStack<T>::operator=(const LinkedStack& other) {
	if (this == &other)
		return *this;
	clear();

	if (other.m_top == nullptr)
		return;
	m_top = new Node<T>(other.m_top->val);
	Node<T>* temp = m_top;
	Node<T>* other_temp = other.m_top;
	while (other_temp->next != nullptr)
	{
		temp->next = new Node<T>(other_temp->next->val);
		temp = temp->next;
		other_temp = other_temp->next;
	}
	
	return *this;
}

template <typename T>
LinkedStack<T>& LinkedStack<T>::operator=(LinkedStack&& other) noexcept {
	if (&other == this)
		return *this;
	m_top = other.m_top;
	other.m_top = nullptr;
	return *this;
}
