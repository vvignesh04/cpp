#include <iostream>
using namespace std;
class node{
  public:
  int data;
  node *next;
  node(int value)
  {
    this->data=value;
    this->next=NULL;
  }

};
class linkedlist{
  private:
  node *head;
  public:
  linkedlist()
  {
    this->head=NULL;
  }
  void insertnode(int);
  void printlist();

};
void linkedlist::insertnode(int data)
{
  node *newnode=new node(data);
  if(head==NULL)
  {
    head=newnode;
    return;
  }
  node* temp=head;
  while(temp->next!=NULL)
  {
    temp=temp->next;
  }
  temp->next=newnode;
}
void linkedlist::printlist()
{
  node* temp=head;
  if(head=NULL)
  {
    cout<<"list is empty"<<"\n";
    return;
  }
  while(temp!=NULL)
  {
    cout<<temp->data<<" ";
    temp=temp->next;

  }
}
int main()
{
  linkedlist ls;
  int n;
  int data;
  cout<<"enter the number of nodes required:";
  cin>>n;
  for(int i=0;i<n;i++)
  {
    cout<<"enter the data:";
    cin>>data;
    ls.insertnode(data);
  }
  ls.printlist();
}