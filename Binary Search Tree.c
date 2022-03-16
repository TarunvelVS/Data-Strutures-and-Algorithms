#include<stdio.h>
#include<windows.h>


COORD coord={0,0};
typedef struct bintreenode
{
     int data;
     struct bintreenode * left;
     struct bintreenode *right;

} BINTREENODE;
typedef BINTREENODE * BINTREENODEPTR;
typedef struct queuenode
{
     BINTREENODEPTR inQ;
     struct queuenode * qnext;

} QUEUENODE;

typedef QUEUENODE * QUEUENODEPTR;
QUEUENODEPTR front, rear;

void enq(BINTREENODEPTR keepit)
{
    QUEUENODEPTR qnn = NULL;
    qnn = (QUEUENODEPTR) malloc(sizeof(QUEUENODE));
    qnn->inQ = keepit;
    qnn->qnext = NULL;
    if(front == NULL)
    {
        front = rear = qnn;
        return;
    }
    rear->qnext = qnn;
    rear = qnn;


}


 BINTREENODEPTR deq()
 {
     BINTREENODEPTR temp=NULL;
     QUEUENODEPTR safe =NULL;
     if(front ==  NULL) return NULL;
     if(front==rear)
     {
           temp = front->inQ;
         safe = front;
         front=rear=NULL;
         free(safe);
         return temp;
     }
     if(front)
     {
         temp = front->inQ;
         safe = front;
         front=front->qnext;
         free(safe);
         return temp;
     }


 }

BINTREENODEPTR addNode2Tree(BINTREENODEPTR root, int value);
void gotoxy(int col,int row );
void draw_tree( int  startCol, int endCol,BINTREENODEPTR);
void inOrder(BINTREENODEPTR root);
void preOrder(BINTREENODEPTR root);
void postOrder(BINTREENODEPTR root);
void levelOrder(BINTREENODEPTR root);
BINTREENODEPTR delNode(BINTREENODEPTR, int delval);


int main()
{
      int values[] = {50, 30,80, 20,40,60,90, 15,25,35,45,55,65,85,95,6,5,100};
      int size, index, popo;
      BINTREENODEPTR root = NULL;
      size = sizeof(values) / sizeof(int);
      for(index =0; index < size; index++)
           root = addNode2Tree(root, values[index]);
   draw_tree(1,80, root);
//   printf("\n\n");
  /* inOrder(root);
    printf("\n\n");
   preOrder(root);
    printf("\n\n");
   postOrder(root);
   printf("\n\n");
   levelOrder(root);

   root = delNode(root, 100);
 inOrder(root);
  root = delNode(root,80);
   printf("\n\n");
 inOrder(root);*/

    return 0;
}

BINTREENODEPTR addNode2Tree(BINTREENODEPTR root, int value)
{
    BINTREENODEPTR tptr = NULL, prev = NULL, nn;
    nn = (BINTREENODEPTR) malloc(sizeof(BINTREENODE));
    nn->data = value;
    nn->left = nn->right = NULL;

    if(root == NULL) return nn;

    for(tptr = root; tptr; prev=tptr, tptr = nn->data > tptr->data ? tptr->right : tptr->left);
    if(prev->data > nn->data)
        prev->left =nn;
    else
        prev->right = nn;
    return root;
}


void gotoxy(int x,int y)
 {
   coord.X=x;
 coord.Y=y;
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
 }
void draw_tree( int start  , int end ,BINTREENODEPTR dispptr)
{
   int col;
   static int row = 1;
   col = (end - start )/ 2 + start;
   if(dispptr)  {
   gotoxy(col,row);
   printf("%d",dispptr->data);
   row+=3;
   draw_tree(start,end/2 + start/2,dispptr->left);
   draw_tree(end/2  +start/2 + 1, end , dispptr -> right);
   row-=3;
   }
}


void inOrder(BINTREENODEPTR root)
{
    if(root == NULL) return;
    inOrder(root->left);
    printf("%d ", root->data);
    inOrder(root->right);
}


void preOrder(BINTREENODEPTR root)
{
    if(root == NULL) return;
        printf("%d ", root->data);
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(BINTREENODEPTR root)
{
    if(root == NULL) return;
    postOrder(root->left);
    postOrder(root->right);
    printf("%d ", root->data);
}

void levelOrder(BINTREENODEPTR process)
{
    BINTREENODEPTR toProcess = NULL;
    if(process==NULL) return;
    enq(process);
    toProcess = deq();
    do
    {
        printf("%d ", toProcess->data);
        if(toProcess->left) enq(toProcess->left);
        if(toProcess->right) enq(toProcess->right);
        toProcess = deq();
    }while(toProcess);

}

BINTREENODEPTR delNode(BINTREENODEPTR root, int delval)
{

    BINTREENODEPTR prev=NULL, tptr=NULL, stepRight=NULL;
    for(tptr = root; tptr && tptr->data != delval; prev = tptr,
          tptr = delval > tptr->data ? tptr->right : tptr->left);
            if(tptr->left && tptr->right)
           {
                stepRight = tptr->right;
                while(stepRight->left)
                    stepRight = stepRight->left;
                stepRight->left = tptr->left;
                tptr->left = NULL;
           }
    if(tptr->left == NULL)
    {
        if(prev->data > tptr->data)
            prev->left = tptr->right;
        else
            prev->right = tptr->right;
    } else
    {
        if(prev->data > tptr->data)
            prev->left = tptr->left;
        else
            prev->right = tptr->left;
    }
    return root;
}
