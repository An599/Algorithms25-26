#pragma once
#include "LinkedDeque.h"
#include <stdexcept>
#include <cstddef>

template <typename T>
LinkedDeque<T>::LinkedDeque() noexcept : m_front(nullptr), m_rear(nullptr), m_size(0) {}

template <typename T>
LinkedDeque<T>::LinkedDeque(const LinkedDeque& other) : LinkedDeque()
{
    Node<T>* temp = other.m_front;

    while (temp)
    {
        push_back(temp->val);
        temp = temp->next;
    }
}

template <typename T>
LinkedDeque<T>::LinkedDeque(LinkedDeque&& other) noexcept
    : m_front(other.m_front), m_rear(other.m_rear), m_size(other.m_size)
{
    other.m_front = nullptr;
    other.m_rear = nullptr;
    other.m_size = 0;
}

template <typename T>
LinkedDeque<T>& LinkedDeque<T>::operator=(const LinkedDeque& other)
{
    if (this == &other)
        return *this;

    LinkedDeque<T> temp(other);
    swap(temp);

    return *this;
}

template <typename T>
LinkedDeque<T>& LinkedDeque<T>::operator=(LinkedDeque&& other) noexcept
{
    if (this == &other)
        return *this;

    LinkedDeque<T> temp(std::move(other));
    swap(temp);

    return *this;
}

template <typename T>
bool LinkedDeque<T>::empty() const noexcept
{
    return m_size == 0;
}

template <typename T>
void LinkedDeque<T>::push_back(const T& val)
{
    if (empty())
        m_front = m_rear = new Node<T>(val);
    else
    {
        Node<T>* temp = new Node<T>(val);
        temp->prev = m_rear;
        m_rear->next = temp;
        m_rear = temp;
    }
    ++m_size;
}

template <typename T>
void LinkedDeque<T>::push_back(T&& val)
{
    if (empty())
        m_front = m_rear = new Node<T>(std::move(val));
    else
    {
        Node<T>* temp = new Node<T>(std::move(val));
        temp->prev = m_rear;
        m_rear->next = temp;
        m_rear = temp;
    }
    ++m_size;
}
template <typename T>
void LinkedDeque<T>::pop_back()
{
    if (empty())
        return;
    if (size() == 1)
    {
        delete m_rear;
        m_rear = m_front = nullptr;
    }
    else
    {
        Node<T>* temp = m_rear->prev;
        delete m_rear;
        temp->next = nullptr;
        m_rear = temp;
    }
    --m_size;
}

template <typename T>
const T& LinkedDeque<T>::rear() const
{
    if (!m_rear)
        throw std::runtime_error("empty deque");
    return m_rear->val;
}

template <typename T>
const T& LinkedDeque<T>::front() const
{
    if (!m_front)
        throw std::runtime_error("empty deque");
    return m_front->val;
}

template <typename T>
void LinkedDeque<T>::push_front(const T& val)
{
    if (empty())
        m_front = m_rear = new Node<T>(val);
    else
    {
        Node<T>* temp = new Node<T>(val);
        temp->next = m_front;
        m_front->prev = temp;
        m_front = temp;
    }
    ++m_size;
}

template <typename T>
void LinkedDeque<T>::push_front(T&& val)
{
    if (empty())
        m_front = m_rear = new Node<T>(std::move(val));
    else
    {
        Node<T>* temp = new Node<T>(std::move(val));
        temp->next = m_front;
        m_front->prev = temp;
        m_front = temp;
    }
    ++m_size;
}

template <typename T>
void LinkedDeque<T>::pop_front()
{
    if (empty())
        return;
    if (size() == 1)
    {
        delete m_rear;
        m_rear = m_front = nullptr;
    }
    else
    {
        Node<T>* temp = m_front->next;
        delete m_front;
        temp->prev = nullptr;
        m_front = temp;
    }
    --m_size;
}

template <typename T>
std::size_t LinkedDeque<T>::size() const noexcept
{
    return m_size;
}

template <typename T>
void LinkedDeque<T>::clear()
{
    while (!empty())
        pop_back();
}

template <typename T>
LinkedDeque<T>::~LinkedDeque()
{
    clear();
}

template <typename T>
void LinkedDeque<T>::swap(LinkedDeque& other) noexcept
{
    std::swap(m_front, other.m_front);
    std::swap(m_rear, other.m_rear);
    std::swap(m_size, other.m_size);

}
