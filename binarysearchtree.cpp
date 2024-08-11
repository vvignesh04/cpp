#include <iostream>
using namespace std;
class node{
  public:
  int data;
  node *left;
  node *right;
  node(int d)
  {
    data=d;
    left=nullptr;
    right=nullptr;
  }
};
class bst{
  public:
  node *root;
  bst()
  {
    root=nullptr;
  }
  void insert(int d)
  {
    if(root==nullptr)
    {
      root=new node(d);
    }
    else
    {
      node *temp=root;
      while(true)
      {
        if(d< temp->data)
        {
          if(temp->left==nullptr)
          {
            temp->left=new node(d);
            break;
          }
          else
          {
            temp=temp->left;
          }  
        }
        else
        {
          if(temp->right==nullptr)
          {
            temp->right=new node(d);
            break;
          }
          else{
            temp=temp->right;
          }
        }
      }
    }
  }
  void inorder(node *root)
  {
    if(root==nullptr)
    {
      return;
    }
    else{
      inorder(root->left);
      cout<<root->data <<" ";
      inorder(root->right);
    }
  }
  void preorder(node *root)
  {
    if(root==nullptr)
    {
      return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->left);
  }
  void postorder(node *root)
  {
    if(root==nullptr)
    {
      return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
  }
  int height(node *root)
  {
    if(root==nullptr)
    {
      return -1;
    }
    int lh=height(root->left);
    int rh=height(root->right);
    return max(lh,rh)+1;
  }
  void printlevelorder(node *root,int level)
  {
    if(root==nullptr)
    {
      return;
    }
    if(level==1)
    {
      cout<<root->data<<" ";
    }
    else if(level > 1)
    {
      printlevelorder(root->left,level-1);
      printlevelorder(root->right,level);
    }
  }
  void levelorder(node *root)
  {
    int h=height(root);
    for(int i=1;i<h;i++)
    {
     printlevelorder(root,i);
    }
  }
  int findmin(node *root)
  {
    int min;
    while(root!=nullptr)
    {
      min=root->data;
      root=root->left;
    }
    return min;
  }
  int findmax(node *root)
  {
    int max;
    while(root!=nullptr)
    {
      max=root->data;
      root=root->right;
    }
    return max;
  }
  node *locate(node *root)
  {
    if()
  }
};
int main()
{
  bst b;
  int n;int l;
  cout<<"ente the number of node req:";
  cin>>n;
  int d;
  for(int i=0;i<n;i++)
  {
    cout<<"enter the data:";
    cin>>d;
    b.insert(d);
  }
  cout<<"";
  cout<<"preorder traversal:";
  b.preorder(b.root);
  cout<<"\n";
  cout<<"";
  cout<<"inorder traversal:";
  b.inorder(b.root);
  cout<<"\n";
  cout<<"";
  cout<<"postorder traversal:";
  b.postorder(b.root);
  cout<<"\n";
  cout<<"";
  cout <<"the level order is:";
  b.levelorder(b.root);
  cout<<"\n";
  cout<<"";
  cout<<"the min element is:";
  cout<<b.findmin(b.root);
  cout<<"\n";
  cout<<"";
  cout<<"the max element is:";
  cout<<b.findmax(b.root);
  cout<<"\n";
  cout<<"";
  cout<<"enter the element to be located:";
  cin>>l;
  cout<<"the element is located at:";
  cout<<b.locate(b.root,l);
  return 0;
  }