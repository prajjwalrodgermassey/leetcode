#include "array_queue.hpp"
#include <iostream>

int main()
{
    Array_Queue<int> q(2);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    std::cout << "Now Displaying the Queue" << std::endl;
    q.display();

    std::cout << "Now Dequeuing" << std::endl;

    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();

    Circular_Array_Queue<int> cq(4);
    cq.enqueue(12);
    cq.enqueue(13);
    cq.enqueue(14);
    cq.enqueue(15);
    cq.enqueue(16);
    // cq.dequeue();
    // cq.enqueue(17);
    cq.enqueue(16);

    std::cout << "Now Displaying the Circular Queue" << std::endl;
    cq.display();

    std::cout << "Now Dequeuing Circular Queue" << std::endl;

    cq.dequeue();
    cq.dequeue();
    cq.dequeue();
    cq.dequeue();
    cq.dequeue();
    cq.dequeue();

    return 0;
}