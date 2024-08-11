#include<iostream>
using namespace std;
class circularqueue{
  private:
  int rear;
  int front;
  int size;
  int *arr;
  public:
  circularqueue(int n)
  {
    size=n;
    arr=new int[size];
    front=rear=-1;
  }
  void enqueue(int);
  void dequeue();
};
void circularqueue::enqueue(int data)
{
  if((front==0 && rear==size-1)||((rear+1)%size==front))
  {
    cout<<"the queue is full";
    return ;
  }
  else if(front==-1)
  {
    front=rear=0;
    arr[rear]=data;

  }
  else if(rear==size-1 && front!=0)
  {
    rear=0;
    arr[rear]=data;
  }
  else{
    rear++;
    arr[rear]=data;

  }
};
void circularqueue::dequeue()
{
  if(front==-1)
  {
    cout<<"the queue is empty";
  }
  cout<<arr[front]<<" ";
  if(front==rear)
  {
    front=-1;
    rear=-1;
  }
  else{
    if(front==size-1)
    {
      front=0;
    }
    else{x
      front=front+1;
    }
  }
};

int main()
{
  int n;
  int data;
  cout<<"enter the size of the queue:";
  cin>>n;
  circularqueue cq(n);
  for(int i=0;i<n;i++)
  {
    cout<<"enter the data:";
    cin>>data;
    cq.enqueue(data);
  }
  cq.dequeue();
  cq.enqueue(0);
  return 0;

}