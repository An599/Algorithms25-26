#pragma once
#include "../IQueue.h"
#include <array>
#include <cstddef>

template <typename T, size_t N>
class ArrQueue : public IQueue <T> {
public:
	ArrQueue();

	void enqueue(const T&) override;
	void dequeue() override;
	bool empty() const override;
	const T& rear() const override;
	const T& front() const override;
	void clear() override;
private:
	static constexpr size_t CAP = N + 1;
	std::array<T, CAP> arr;
	size_t f_ind, r_ind;

	bool full_helper() const;
};

#include "ArrQueue.ipp"
