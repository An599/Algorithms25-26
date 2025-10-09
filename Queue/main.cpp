#include <iostream>
#include "IQueue.h"
#include "ArrQueue/ArrQueue.h"
#include "ListQueue/ListQueue.h"
#include <stdexcept>
#include <string>

template <typename QueueType>
void testQueueBasics(const std::string& name)
{
    std::cout << "Testing " << name << std::endl;

    QueueType q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    std::cout << "Front: " << q.front() << std::endl;
    std::cout << "Rear:  " << q.rear()  << std::endl;

    q.dequeue();
    std::cout << "After dequeue, front: " << q.front() << std::endl;

    q.enqueue(40);
    std::cout << "Rear after enqueue(40): " << q.rear() << std::endl;

    q.clear();
    std::cout << "After clear, empty: " << q.empty() << std::endl;

    try {
        q.dequeue();
    } catch (const std::underflow_error& e) {
        std::cout << "Caught: " << e.what() << std::endl;
    }
}

template <typename QueueType>
void testQueueCopyAndMove(const std::string& name)
{
    std::cout << "Testing copy & move for " << name <<std::endl;

    QueueType q1;
    q1.enqueue(1);
    q1.enqueue(2);
    q1.enqueue(3);

    QueueType q2(q1);
    std::cout << "Copied queue front: " << q2.front() <<  std::endl;

    QueueType q3;
    q3 = q1;
    std::cout << "Assigned queue rear: " << q3.rear()  <<std::endl;

    QueueType q4(std::move(q1));
    std::cout << "Move-constructed queue front: " << q4.front()<< std::endl;


}

int main()
{
    try {
        testQueueBasics<ArrQueue<int, 5>>("Array-based Queue<int, 5>");
        std::cout << std::endl;
        testQueueCopyAndMove<ArrQueue<int, 5>>("Array-based Queue<int, 5>");
        std::cout << std::endl;
        testQueueBasics<ListQueue<int>>("Linked-list Queue<int>");
        std::cout << std::endl;
        testQueueCopyAndMove<ListQueue<int>>("Linked-list Queue<int>");
        std::cout << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "Unhandled exception: " << e.what() << "\n";
    }
}
