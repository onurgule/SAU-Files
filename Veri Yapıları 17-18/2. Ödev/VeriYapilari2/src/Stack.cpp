/**        
 * @file  Yonetim.cpp  
 * @description Veri Yapıları 2. Ödev
 * @course Veri Yapıları - 2B   
 * @date  25.11.2018 
 * @author  Onur Osman Güle - onur.gule@ogr.sakarya.edu.tr - G171210021   
 */
#include "Stack.hpp"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
Stack::Stack()
{
    this->data = NULL;
    this->size = 0;
    this->capacity = 0;
}
Stack::~Stack(){
}
void Stack::push(int item)
{
    if (!this->isFull())
        data[this->getSize()] = item;
    else
    {
        this->increaseCapacity();
        this->data[this->getSize()] = item;
        //alanı büyüt, tekrar ekle.
    }
    this->increaseSize();
}
void Stack::pop()
{
    if (!isEmpty())
        this->decreaseSize();
}
int Stack::top()
{
    if (this->getSize() == 0)
    {
        return -1;
    }
    return this->data[getSize() - 1];
}

int Stack::getSize()
{
    return this->size;
}

int Stack::getCapacity()
{
    return this->capacity;
}
void Stack::increaseSize()
{
    if (!this->isFull())
        this->size++;
}
void Stack::decreaseSize()
{
    if (!this->isEmpty())
        this->size--;
}
void Stack::increaseCapacity()
{
    int newCap = this->getCapacity()*2+1;
    int *tmp = new int[newCap];
			 for(int j=0;j<this->getSize();j++) tmp[j]= this->data[j];
			 if(this->data != NULL) delete [] data;
			 this->data = tmp;
			 this->capacity = newCap;
}
bool Stack::isFull()
{
    return this->getSize() == this->getCapacity();
}
bool Stack::isEmpty()
{
    return this->getSize() == 0;
}
void Stack::getAllStates(){
const int currentSize=getSize();
int values[currentSize];

for(int i = 0; i < currentSize; i++)
{
    values[i] = top();
    cout <<" : " << setw(6) << values[i]  << left;
    pop();
}

for(int i = currentSize-1; i >= 0; i--)
{
    push(values[i]);
}
//eski haline geldi. valueler çekildi.


}