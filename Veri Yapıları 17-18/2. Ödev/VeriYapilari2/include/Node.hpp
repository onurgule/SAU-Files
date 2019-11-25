#ifndef NODE_HPP
#define NODE_HPP

#include <iostream>
#include "Stack.hpp"
class Node
{
  private:
	Node *previous;
	Node *next;
	int data;
	Stack *stack;
  public:
	Node(int, Node *, Node *);
	~Node();
	void setPrevious(Node *);
	void setNext(Node *);
	void setData(int);
	Node *getPrevious();
	Node *getNext();
	int getData();
	void getAllStackStates();
};

#endif