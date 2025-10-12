#include <iostream>
#include "IDeque.h"
#include "ArrDeque/ArrDeque.h"
#include "LinkedDeque/LinkedDeque.h"
#include <stdexcept>
#include <string>

template <typename DequeType>
void testQueueBasics(const std::string& name)
{
    std::cout << "Testing " << name << std::endl;

    DequeType dq;

    dq.push_front(10);
    dq.push_front(20);
    dq.push_back(30);
    dq.push_back(40);

    std::cout << "Front: " << dq.front() << std::endl;
    std::cout << "Rear:  " << dq.rear() << std::endl;

    dq.pop_front();
    dq.pop_back();
    std::cout << "After dequeue, front: " << dq.front() << std::endl;

    std::cout << "Rear after enqueue(40): " << dq.rear() << std::endl;

    dq.clear();
    std::cout << "After clear, empty: " << dq.empty() << std::endl;

}

template <typename DequeType>
void testQueueCopyAndMove(const std::string& name)
{
    std::cout << "Testing copy & move for " << name << std::endl;

    DequeType dq1;
    dq1.push_front(1);
    dq1.push_front(2);
    dq1.push_front(3);
    dq1.push_front(4);

    DequeType dq2(dq1);
    std::cout << "Copied queue: " << dq2.front() << std::endl;

    DequeType dq3;
    dq3 = dq1;
    std::cout << "Assigned queue: " << dq3.rear() << std::endl;

    DequeType dq4(std::move(dq1));
    std::cout << "Move-constructed queue front: " << dq4.front() << std::endl;

}

int main()
{
    try {
        testQueueBasics<ArrDeque<int, 5>>("Array-based Deque<int, 5>");
        std::cout << std::endl;
        testQueueCopyAndMove<ArrDeque<int, 5>>("Array-based Deque<int, 5>");
        std::cout << std::endl;
        testQueueBasics<LinkedDeque<int>>("Linked-list Deque<int>");
        std::cout << std::endl;
        testQueueCopyAndMove<LinkedDeque<int>>("Linked-list Deque<int>");
        std::cout << std::endl;

    }
    catch (const std::exception& e) {
        std::cerr << "Unhandled exception: " << e.what() << "\n";
    }
}
