#ifndef STACK_HPP
#define STACK_HPP
#include <iostream>
class Stack
{
  private:
    int *data;
    int capacity;
    int size;

  public:
    Stack();
    ~Stack();
    void push(int);
    void pop();
    int top();
    int getSize();
    bool isFull();
    bool isEmpty();
    int getCapacity();
    void increaseSize();
    void decreaseSize();
    void increaseCapacity();
    void getAllStates();
};

#endif