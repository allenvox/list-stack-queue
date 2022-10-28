#pragma once

class list
{
public:
    int value;
    list *next;
};

class stack
{
private:
    list *top;

public:
    stack();
    ~stack();
    void push(int i);
    int pop();
    bool isEmpty();
};

class queue
{
    stack s1, s2;

public:
    void enqueue(int value);
    int dequeue();
};