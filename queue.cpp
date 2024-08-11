#include<iostream>
using namespace std;
class queue{
  private:
  int *arr;
  int front;
  int rear;
  int cap;
  public:
  queue(int c)
  {
    cap=c;
    arr=new int[cap];
    front=-1;
    rear=-1;
  }
  void enqueue(int data)
  {
    if(isFull())
    {
      cout<<"the queue is full:";
      
    }
     if (isEmp())
     {
        front = 0;
        }
    else
    {
      rear++;
      arr[rear]=data;
    }
  }
  void dequeue()
  {
    if(front==rear)
    {
      front=-1;
      rear=-1;
    }
    else{
      front++;
      cout<<arr[front];
    }
  }

  bool isFull()
  {
    return rear==cap-1;
  }
  bool isEmp()
  {
    return front==-1;

  }
};
int main()
{
  int n;
  int d;
  cout<<"enter the capacity of the queue:";
  cin>>n;
  queue q(n);
  for(int i=0;i<n;i++)
  {
    cout<<"enter the element:";
    cin>>d;
    q.enqueue(d);
  }
  cout<<"element after deque:";
  for(int i=0;i<n;i++)
  {
    q.dequeue();
  }
  return 0;
}