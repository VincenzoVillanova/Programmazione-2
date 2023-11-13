#include "queue.h"

int main()
{

    Queue<int> q;
    q.enqueue(10);
    q.enqueue(12);
    q.enqueue(14);
    q.enqueue(16);

    std::cout << q << std::endl;

    DLNode<int> ptr = q.dequeue();
    std::cout << ptr << std::endl;
    ptr = q.dequeue();
    std::cout << ptr << std::endl;
}