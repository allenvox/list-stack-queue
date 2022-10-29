#pragma once

class list
{
public:
    int value;
    list *next;
    list(int val);
    ~list();
    void add(int val);
    list *remove(int val);
    list *lookup(int val);
};

class stack
{
private:
    list *top;

public:
    stack();
    stack(int *arr, int size);
    ~stack();
    int peek();
    void push(int i);
    int pop();
    bool isEmpty();
};

class queue
{
    stack s1, s2;

public:
    queue();
    queue(int *arr, int size);
    void enqueue(int val);
    int dequeue();
};