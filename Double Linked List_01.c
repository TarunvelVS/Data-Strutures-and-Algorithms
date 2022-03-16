#include<stdio.h>
typedef struct node
{
    int data;
    struct node *prev , *next;
}NODE;
void insertDataIntoDLL(NODE** , NODE** , int);
void displayDLLForward(NODE*);
int main()
{
int arr[]  = { 30 ,20 , 10 , 50 , 60 ,70 , 33};
int ind , N ;
N = sizeof arr / sizeof arr[0];
  NODE *start , *end ;
  start = end = NULL;
for(ind = 0 ; ind < 7; ind++)
       insertDataIntoDLL( &start , &end , arr[ind]);
displayDLLForward(start);
return 0;
}
void displayDLLForward(NODE* copyofstart)
{
    NODE * tptr = NULL;
    for(tptr = copyofstart ; tptr ; printf("%d ->" , tptr->data) , tptr = tptr -> next);
    printf("NULL");
}
void insertDataIntoDLL(NODE** addofstart, NODE**addofend , int insertVal)
{
    NODE *newnode , *tptr ;
    newnode = tptr = 0;

      newnode = (NODE*)calloc(1 , sizeof(NODE));
      newnode -> data = insertVal;
    if(*addofstart == 0)
    {
          *addofstart = *addofend = newnode;
          return;
    }
      // find the insert point
    for(tptr=*addofstart ; tptr && tptr->data < insertVal;tptr=tptr->next);

if( tptr == *addofstart)
{
// begin
newnode -> next = *addofstart;
*addofstart = (*addofstart) -> prev = newnode;
}
else if( tptr == 0)
{
    // end
newnode -> prev = *addofend;
*addofend = (*addofend) -> next = newnode;
}
else
{
// mid
//printf("%d %d" , tptr->data , tptr->prev->data);
newnode -> prev =  tptr ->prev;
newnode -> next = tptr;
tptr -> prev -> next = newnode;
tptr -> prev = newnode;

//getch();
}









}











