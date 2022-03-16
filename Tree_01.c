#include<stdio.h>
#include<stdlib.h>
int queue[5];
int front=-1,rear=-1;
typedef struct node
{
int data;
struct node* left;
struct node* right;
}tree;
tree *root,*tptr,*newnode,*prev;

void addnode(int data)
{
  tree * newnode;
  newnode=(tree*)malloc(sizeof(tree));
  newnode->data=data;
  newnode->left=newnode->right=NULL;
  if(root==NULL) root=newnode;
  else
    {
      tptr=root;
    while(tptr)
  {
     if(newnode->data<tptr->data)
     {
       prev=tptr;
       tptr=tptr->left;
     }
     else
     {
       prev=tptr;
       tptr=tptr->right;
     }
  }
  if(newnode->data<prev->data)
    prev->left=newnode;
  else
    prev->right=newnode;
  }
return root;
}

void inorderdisplay(tree * tptr)
{
   if(tptr)
  {
    inorderdisplay(tptr->left);
       printf("%d ",tptr->data);
       inorderdisplay(tptr->right);
  }

  }

  void preorderdisplay(tree * tptr)
{
   if(tptr)
  {
     printf("%d ",tptr->data);
    preorderdisplay(tptr->left);

       preorderdisplay(tptr->right);
  }

  }
  void postorderdisplay(tree * tptr)
{
   if(tptr)
  {

    postorderdisplay(tptr->left);

       postorderdisplay(tptr->right);
       printf("%d ",tptr->data);
  }
}
 void enqueue(tree * tptr)
 {
    if(front==rear) front++;
    else
    {
         queue[++rear]=tptr;
    }
 }

tree * dequeue()
{
    tree * temp;
    temp=queue[front];
    front++;
    return temp;
}

void levelorder(tree * tptr)
{
  tree * temp;
  if(tptr==NULL) return;
  enqueue(tptr);
  while(tptr)
  {
    temp=dequeue();
  printf("%d ",temp->data);

  if(temp->left) enqueue(temp->left);
  if(temp->right ) enqueue(temp->right);
  }

}
  int search(int data)
  {
    tptr=root;
     while(tptr)
     {
       if(tptr->data==data) return 1;
       else if(data<tptr->data) tptr=tptr->left;
       else tptr=tptr->right;
      }
      if(tptr==NULL) return 0;
  }
int main()
{
addnode(2);
addnode(4);
addnode(99);
addnode(10000);
addnode(3000);
addnode(6);
addnode(9);
addnode(11);
printf("inorder display:\n");
inorderdisplay(root);
printf("\npreorder display:\n");
preorderdisplay(root);
printf("\npostorder display:\n");
postorderdisplay(root);

//levelorder(root);

if(search(11)) printf("\n\nfound\n\n");
else printf("\n\nnot found\n\n");
}
