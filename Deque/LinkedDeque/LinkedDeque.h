#pragma once

#include "IDeque.h"
#include "Node.h"
#include <cstddef>

template <typename T>
class LinkedDeque : public IDeque<T>
{
public:
	LinkedDeque() noexcept;
	~LinkedDeque();
	LinkedDeque(const LinkedDeque&);
	LinkedDeque(LinkedDeque&&) noexcept;
	LinkedDeque& operator=(const LinkedDeque&);
	LinkedDeque& operator=(LinkedDeque&&) noexcept;

	void push_back(const T&) override;
	void push_back(T&&) override;
	void pop_back() override;
	void pop_front() override;
	void push_front(const T&) override;
	void push_front(T&&) override;
	bool empty() const noexcept override;
	std::size_t size() const noexcept override;
	const T& front() const override;
	const T& rear() const override;
	void clear() override;

	void swap(LinkedDeque&) noexcept;
private:
	Node<T>* m_rear;
	Node<T>* m_front;
	std::size_t m_size;
};

#include "LinkedDeque.ipp"
