#pragma once

template <typename T>
CyclicList<T>::CyclicList() : head(nullptr), tail(nullptr), count(0) {}

template <typename T>
CyclicList<T>::~CyclicList() 
{
    clear();
}

template <typename T>
void CyclicList<T>::insert(size_t pos, const T& value) 
{
    if (pos > count)
        throw std::out_of_range("Position out of range");

    Node* node = new Node(value);

    if (!head) 
    {
        head = tail = node;
        node->next = head;
    }
    else if (pos == 0) 
    {
        node->next = head;
        head = node;
        tail->next = head;
    }
    else if (pos == count) 
    {
        tail->next = node;
        tail = node;
        tail->next = head;
    }
    else 
    {
        Node* prev = head;
        for (size_t i = 0; i < pos - 1; ++i)
            prev = prev->next;

        node->next = prev->next;
        prev->next = node;
    }

    count++;
}

template <typename T>
void CyclicList<T>::erase(size_t pos) 
{
    if (empty())
        throw std::runtime_error("List is empty");
    if (pos >= count)
        throw std::out_of_range("Position out of range");

    Node* toDelete = nullptr;

    if (head == tail) 
    {
        toDelete = head;
        head = tail = nullptr;
    }
    else if (pos == 0) 
    {
        toDelete = head;
        head = head->next;
        tail->next = head;
    }
    else 
    {
        Node* prev = head;
        for (size_t i = 0; i < pos - 1; ++i)
            prev = prev->next;

        toDelete = prev->next;
        prev->next = toDelete->next;

        if (toDelete == tail)
            tail = prev;
    }

    delete toDelete;
    count--;
}

template <typename T>
T CyclicList<T>::getValue(size_t pos) const 
{
    if (empty())
        throw std::runtime_error("List is empty");
    if (pos >= count)
        throw std::out_of_range("Position out of range");

    Node* current = head;
    for (size_t i = 0; i < pos; ++i)
        current = current->next;

    return current->data;
}

template <typename T>
size_t CyclicList<T>::sizee() const 
{
    return count;
}

template <typename T>
bool CyclicList<T>::empty() const 
{
    return count == 0;
}

template <typename T>
void CyclicList<T>::clear() {
    if (!head) return;

    Node* current = head;
    do {
        Node* next = current->next;
        delete current;
        current = next;
    } while (current != head);

    head = tail = nullptr;
    count = 0;
}

template <typename T>
void CyclicList<T>::print() const {
    if (empty()) {
        std::cout << "List is empty" << std::endl;
        return;
    }

    Node* current = head;
    do {
        std::cout << current->data << " ";
        current = current->next;
    } while (current != head);

    std::cout << std::endl;
}
