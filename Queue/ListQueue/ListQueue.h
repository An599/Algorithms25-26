#pragma once

#include "Node.h"
#include "IQueue.h"

template <typename T>
class ListQueue : public IQueue <T>
{
public:
	ListQueue() : m_front(nullptr) {}

	void enqueue(const T&) override;
	void dequeue() override;
	bool empty() const override;
	const T& rear() const override;
	const T& front() const override;
	void clear() override;

	ListQueue(const ListQueue& other);
	ListQueue(ListQueue&& other) noexcept;
	ListQueue& operator=(const ListQueue& other);
	ListQueue& operator=(ListQueue&& other) noexcept;
private:
	Node<T>* m_front;
	Node<T>* m_rear;
};

#include "ListQueue.ipp"
