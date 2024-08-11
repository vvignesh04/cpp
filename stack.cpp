#include <iostream>
 using namespace std;
 template<class T> class Stack
 {
  private:
  int size;
  T* stack;
  int top;
  public:
  Stack(int cap)
  {
    size= cap;
    stack= new T[cap];
    top=-1;
  }
  void push(T val)
  {
    if (!isFull())
    {
    top++;
    stack[top] = val;
    }
    else
    {
      cout << "Stack overflow!" << endl;
    }
  }
  T pop()
 {
  if (!isEmpty())
  {
    T ele = stack[top];
    top--;
    return ele;
  }
  else
  {
    throw runtime_error("Stack underflow!");
  }
  }
T peek()
{
  if (!isEmpty())
  {
    T ele = stack[top];
    return ele;
 }
 else
 {
 throw runtime_error("Stack Empty!");
 }
 }
 bool isFull()
 {
  if (top == size-1){
  return true;
 }
 else
 {
 return false;
 }
 }
 bool isEmpty()
 {
 if (top ==-1)
 {
 return true;
 }
 else
 {
 return false;
 }
 }
};