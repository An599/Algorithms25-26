#pragma once

#include "ListQueue.h"
#include <stdexcept>

template <typename T>
bool ListQueue<T>::empty() const
{
	return m_front == nullptr;
}

template <typename T>
const T& ListQueue<T>::rear() const
{
	if (empty())
		throw std::underflow_error("Queue is empty");
	return m_rear->val;
}

template <typename T>
const T& ListQueue<T>::front() const
{
	if (empty())
		throw std::underflow_error("Queue is empty");
	return m_front->val;
}

template <typename T>
void ListQueue<T>::dequeue()
{
	if (empty())
		throw std::underflow_error("Queue is empty");
	Node<T>* temp = m_front;
	m_front = m_front->next;
	delete temp;
	if (m_front == nullptr)
		m_rear = nullptr;
}

template <typename T>
void ListQueue<T>::enqueue(const T& val)
{
	Node<T>* temp = new Node<T>(val);	
	if (empty())
		m_rear = m_front = temp;
	m_rear->next = temp;
	m_rear = temp;
}

template <typename T>
void ListQueue<T>::clear()
{
	while (!empty())
		dequeue();
}

template <typename T>
ListQueue<T>::ListQueue(const ListQueue& other) : m_front(nullptr), m_rear(nullptr)
{
	if (other.m_front == nullptr)
		return;
	m_front = new Node<T>(other.m_front->val);
	Node<T>* temp = m_front;
	Node<T>* other_temp = other.m_front;
	while (other_temp->next != nullptr)
	{
		temp->next = new Node<T>(other_temp->next->val);
		temp = temp->next;
		other_temp = other_temp->next;
	}
}

template <typename T>
ListQueue<T>::ListQueue(ListQueue&& other) noexcept : m_front(other.m_front), m_rear(other.m_rear){
	other.m_front = nullptr;
	other.m_rear = nullptr;
}

template <typename T>
ListQueue<T>& ListQueue<T>::operator=(const ListQueue& other)
{
	if (this == &other)
		return *this;
	clear();
	m_front = new Node<T>(other.m_front->val);
	Node<T>* temp = m_front;
	Node<T>* other_temp = other.m_front;
	while (other_temp->next != nullptr)
	{
		temp->next = new Node<T>(other_temp->next->val);
		temp = temp->next;
		other_temp = other_temp->next;
	}
	m_rear = temp;
	return *this;
}

template <typename T>
ListQueue<T>& ListQueue<T>::operator=(ListQueue&& other) noexcept {
	if (&other == this)
		return *this;
	clear();
	m_front = other.m_front;
	m_rear = other.m_rear;
	other.m_front = nullptr;
	other.m_rear = nullptr;
	return *this;
}
