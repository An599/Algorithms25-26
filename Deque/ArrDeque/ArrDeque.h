#pragma once

#include "IDeque.h"
#include <cstddef>
#include <array>

template <typename T, size_t N>
class ArrDeque : public IDeque<T>
{
public:
	ArrDeque() noexcept;
	~ArrDeque();

	void push_back(const T&) override;
	void push_back(T&&) override;
	void pop_back() override;
	void pop_front() override;
	void push_front(const T&) override;
	void push_front(T&&) override;
	bool empty() const noexcept override;
	bool full() const noexcept;
	std::size_t size() const noexcept override;
	const T& front() const override;
	const T& rear() const override;
	void clear() override;
	void swap(ArrDeque&) noexcept;
private:
	std::size_t count , f_index, r_index;
	std::array<T, N> arr; 
};

#include "ArrDeque.ipp"
