#include <iostream>
#include "classes.hpp"

stack::stack()
{
    top = NULL;
}

stack::stack(int *arr, int size)
{
    stack();
    for (int i = 0; i < size; i++)
    {
        push(arr[i]);
    }
}

stack::~stack()
{
    list *r = new list();
    while (!isEmpty())
    {
        r = top;
        top = top->next;
        delete r;
    }
    delete top;
}

void stack::push(int i)
{
    list *r = new list();
    r->value = i;
    r->next = top;
    top = r;
}

int stack::pop()
{
    try
    {
        if (isEmpty())
        {
            throw "Underflow error.";
        }
        else
        {
            list *r = top;
            top = top->next;
            int x = r->value;
            delete r;
            return x;
        }
    }
    catch (const char *str)
    {
        std::cout << str << " Thrown ";
    }
    return -1;
}

bool stack::isEmpty()
{
    return (top == NULL);
}

queue::queue()
{
    s1 = stack();
    s2 = stack();
}

queue::queue(int *arr, int size)
{
    queue();
    for (int i = 0; i < size; i++)
    {
        enqueue(arr[i]);
    }
}

void queue::enqueue(int value)
{
    while (!s1.isEmpty())
    {
        s2.push(s1.pop());
    }
    s1.push(value);
    while (!s2.isEmpty())
    {
        s1.push(s2.pop());
    }
}

int queue::dequeue()
{
    return s1.pop();
}