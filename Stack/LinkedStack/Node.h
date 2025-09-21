#pragma once

template <typename T>

struct Node
{
	Node(const T& val, Node* n = nullptr) : val(val), next(n) {}

	T val;
	Node<T>* next;
};
