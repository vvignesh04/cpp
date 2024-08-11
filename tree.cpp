#include<iostream>
#include<stdlib.h>
using namespace std;
struct node 
{
  int data;
  struct node *left;
  struct node *right;
};
void traversepreorder(struct node *temp)
{
  if(temp!=NULL)
  {
    cout<<" "<<temp->data;
    traversepreorder(temp->left);
    traversepreorder(temp->right);
  }
}
void traverseinorder(struct node *temp)
{
  if(temp!=NULL)
  {
    traverseinorder(temp->left);
    cout<<" "<<temp->data;
    traverseinorder(temp->right);
  }
}
void traversepostorder( struct node *temp)
{
  if(temp!=NULL)
  {
    traversepostorder(temp->left);
    traversepostorder(temp->right);
    cout<<" "<<temp->data;
  }
}
struct node *Newnode(int data)
{
  struct node *node=(struct node*)malloc(sizeof(struct node));
  node-> data=data;
  node->left=NULL;
  node->right=NULL;
  return(node);
}
int main()
{
  int n;
  cout<<"enter the height required:";
  cin>>n
  struct node *root=Newnode(1);
  struct node *temp=root;

  for(int i=0;i<n;i++)
  {
    int data;
    cout<<"enter the data:";
    cin>>data;
    if(temp->left == NULL)
    temp->left = Newnode(data);
  else if(temp->right == NULL)
    temp->right = Newnode(data);
  }
  
  
  cout<<"preorder traversal:";
  traversepreorder(root);
  cout<<" ";
  cout<<"inorder traversal";
  traverseinorder(root);
  cout<<" ";
  cout<<"postorder traversal";
  traversepostorder(root);
}