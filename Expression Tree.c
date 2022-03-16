#include<stdio.h>
#include<windows.h>


COORD coord={0,0};

typedef struct btree
{
    char opR_opD;
    struct btree *left , *right;
}BNODE;
typedef BNODE * BNODEPTR;
typedef struct snode
{
   BNODEPTR data;
    struct snode *next;
}SNODE;
typedef SNODE*  SNODEPTR;

BNODEPTR  root , newnode ;
SNODEPTR top;
void push(BNODEPTR);
BNODEPTR pop();
int isOperator(char);
int LRP(BNODEPTR);

void gotoxy(int ,int );
void draw_tree( int   , int ,BNODEPTR );

int main()
{
char str[] = "982*+73+*93*52-/*";
int ind;
for( ind = 0 ; str[ind] ; ind++)
{
    if( isOperator(str[ind]) == 1)
    {
        newnode = (BNODEPTR)calloc(1 , sizeof(BNODE));
        newnode -> opR_opD = str[ind];
        newnode -> right = pop();
        newnode -> left = pop();
        push(newnode);
    }
    else
    {
        newnode = (BNODEPTR)calloc(1 , sizeof(BNODE));
        newnode -> opR_opD = str[ind];
        push(newnode);
    }
}
root = pop();

draw_tree(1 , 80 , root);

printf("\n\n\n%d" , LRP(root));


return 0;
}




int LRP(BNODEPTR tptr)
{
    int leftVal , rightVal;
    if(tptr->left == 0&&tptr->right==0) return tptr->opR_opD - '0';

    leftVal = LRP(tptr->left);
    rightVal = LRP(tptr->right);
    switch(tptr->opR_opD)
    {
        case '*' : return leftVal*rightVal;
        case '+' : return leftVal+rightVal;
        case '-' : return leftVal-rightVal;
        case '/' : return leftVal/rightVal;
    }


}













int isOperator(char ch)
{
    if( ch == '+' || ch== '-' || ch == '/' || ch == '*' || ch == '^') return 1;
return 0;
}


void gotoxy(int x,int y)
 {
   coord.X=x;
 coord.Y=y;
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
 }
void draw_tree( int start  , int end ,BNODEPTR dispptr)
{
   int col;
   static int row = 1;
   col = (end - start )/ 2 + start;
   if(dispptr)  {
   gotoxy(col,row);
   printf("%c",dispptr->opR_opD);
   row+=3;
   draw_tree(start,end/2 + start/2,dispptr->left);
   draw_tree(end/2  +start/2 + 1, end , dispptr -> right);
   row-=3;
   }
}




void push(BNODEPTR keepit)
{
    SNODEPTR newsnode = 0;
    newsnode = (SNODEPTR)calloc( 1 , sizeof(SNODE));
    newsnode -> data = keepit;
    if( top == 0)
         top = newsnode;
    else
    {
        newsnode -> next = top;
        top = newsnode;
    }

}

BNODEPTR pop()
{
    BNODEPTR safe = 0;
    SNODEPTR topsafe ;
    if(top == 0) return ;

        safe = top -> data;
        topsafe = top;
        top = top -> next;
        free(topsafe);
        return safe;

}


























