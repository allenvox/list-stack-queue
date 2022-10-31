#pragma once

class list
{
public:
    int value;
    list *next;
    list(int val)
    {
        this->value = val;
        this->next = NULL;
    }
    ~list()
    {
        delete this->next;
    }
    static void printAllUnits(list *l)
    {
        list *r = l;
        while (r != NULL)
        {
            std::cout << r->value;
            if (r->next != NULL)
            {
                std::cout << " -> ";
            }
            r = r->next;
        }
        std::cout << std::endl;
    }
    void add(int val);
    list *remove(int val);
    list *lookup(int val);
};

class stack
{
private:
    list *top;

public:
    stack()
    {
        top = NULL;
    }
    stack(int *arr, int size);
    ~stack();
    int peek();
    void push(int i);
    int pop();
    bool isEmpty()
    {
        return (top == NULL);
    }
};

class queue
{
    stack s1, s2;

public:
    queue()
    {
        s1 = stack();
        s2 = stack();
    }
    queue(int *arr, int size);
    void enqueue(int val);
    int dequeue()
    {
        return s1.pop();
    }
};