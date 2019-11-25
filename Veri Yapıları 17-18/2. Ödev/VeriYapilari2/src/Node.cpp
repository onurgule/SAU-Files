/**        
 * @file  Yonetim.cpp  
 * @description Veri Yapıları 2. Ödev
 * @course Veri Yapıları - 2B   
 * @date  25.11.2018 
 * @author  Onur Osman Güle - onur.gule@ogr.sakarya.edu.tr - G171210021   
 */
#include "Node.hpp"
#include "Stack.hpp"
#include <iostream>
#include <string>
using namespace std;
Node::Node(int newData, Node *pre, Node *nex)
{
    this->stack = new Stack();
    this->setPrevious(pre);
    this->setNext(nex);
    this->setData(newData);
}
Node::~Node(){
    delete this->stack;
}
void Node::setPrevious(Node *pre)
{
    this->previous = pre;
}
void Node::setNext(Node *nex)
{
    this->next = nex;
}
void Node::setData(int dat)
{
    this->stack->push(dat);
    this->data = dat;
}
Node *Node::getPrevious()
{
    return this->previous;
}
Node *Node::getNext()
{
    return this->next;
}
int Node::getData()
{
    return this->data;
}
/*Stack *Node::getStack(){
    return this->stack;
}*/
void Node::getAllStackStates(){
    this->stack->getAllStates();
}