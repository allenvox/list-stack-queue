#include <iostream>
#include "classes.hpp"

stack::stack()
{
    top = NULL;
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