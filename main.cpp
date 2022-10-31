#include <iostream>
#include "classes.hpp"

int main()
{
    std::cout << "\nlist:" << std::endl;
    list *h = new list(4);
    h->add(8);
    h->add(9);
    h->lookup(4);
    h->lookup(5);
    h->lookup(8);
    h->lookup(9);
    list::printAllUnits(h);

    std::cout << "\nstack:" << std::endl;
    int arr[3] = {2, 4, 1};
    stack s(arr, 3);
    std::cout << s.pop() << std::endl;
    std::cout << s.pop() << std::endl;
    std::cout << s.pop() << std::endl;
    std::cout << s.pop() << std::endl;

    std::cout << "\nqueue:" << std::endl;
    queue q(arr, 3);
    std::cout << q.dequeue() << std::endl;
    std::cout << q.dequeue() << std::endl;
    std::cout << q.dequeue() << std::endl;
    std::cout << q.dequeue() << std::endl;

    exit(0);
}