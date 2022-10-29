#include <iostream>
#include "classes.hpp"

list::list(int val)
{
    this->value = val;
    this->next = NULL;
}

list::~list()
{
    delete this->next;
}

void list::add(int val)
{
    list *temp = this;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    list *node = new list(val);
    node->value = val;
    node->next = NULL;
    temp->next = node;
}

list *list::lookup(int val)
{
    list *current = this;
    while (current != NULL)
    {
        if (current->value == val)
        {
            std::cout << "Found " << val << "!" << std::endl;
            return current;
        }
        current = current->next;
    }
    std::cout << val << " not found." << std::endl;
    return NULL;
}

list *list::remove(int val)
{
    list *searched = lookup(val);
    list *head = this;
    if (searched != NULL)
    {
        if (head != searched)
        {
            list *parent = this;
            while (parent->next != searched)
            {
                parent = parent->next;
            }
            parent->next = searched->next;
        }
        else
        {
            head = head->next;
        }
        delete searched;
    }
    return head;
}

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
    list *r = NULL;
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
    list *r = new list(i);
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
            if (r->value == -443987883)
            {
                throw "Underflow error.";
            }
            r = NULL;
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