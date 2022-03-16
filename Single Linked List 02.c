#include<stdio.h>


typedef struct sllnode
{
    int num;
    struct sllnode * next;

} SLLNODE;
typedef SLLNODE * SLLNODEPTR;


SLLNODEPTR addNode( SLLNODEPTR start, int data)
{
SLLNODEPTR nn= NULL, tptr = NULL, prev = NULL;
    nn = (SLLNODEPTR) malloc(sizeof(SLLNODE));
    nn->num = data;
    nn->next = NULL;
    for(tptr = start; tptr && nn->num > tptr->num; prev = tptr,tptr =tptr->next);
    if(tptr== start) // insertion inth beginning or LL creation
    {
        nn->next =start;
        start = nn;
    }
    else
    {
       nn->next = tptr;
       prev->next = nn;
    }
    return start;
}


void displaySLL(SLLNODEPTR start)
{
SLLNODEPTR tptr;
for(tptr = start,printf("\n"); tptr; printf("%d->", tptr->num), tptr=tptr->next);
printf("NULL");
}
SLLNODEPTR reverseSLLItr(SLLNODEPTR start)
{
    SLLNODEPTR before, here, after;
    before = after = NULL;
    here = start;
    while(here)
    {
        after = here->next;
        here->next = before;
        before = here;
        here = after;
    }
    return before;
}
void delNode(SLLNODEPTR start, int delnum)
{
    SLLNODEPTR tptr = NULL, prev = NULL;
    for(tptr = start; tptr && tptr->num != delnum; prev = tptr, tptr= tptr->next);
    if(tptr== NULL)
        printf("\nWhich world are you From :-)");
    else{
            if(tptr==start)
               start = start->next;
            else
                prev->next = tptr->next;
            free(tptr);

    }

}

SLLNODEPTR reverseSLL(SLLNODEPTR called, SLLNODEPTR hold)
{
    SLLNODEPTR temp;
    if(called == NULL)
    {
        return hold;
    }
    temp = reverseSLL(called->next, called);
    called->next = hold;
    return temp;
}

SLLNODEPTR findMidPointSLL(SLLNODEPTR start)
{
    SLLNODEPTR slow, fast;

    slow= fast = start;
    while(fast->next)
    {

      if(fast->next)
           fast = fast->next;
            if(fast->next)
    {
        fast = fast->next;
        slow= slow->next;
    }

    }
    return slow;
}

void makeloop(SLLNODEPTR start)
{

SLLNODEPTR tptr = NULL, prev  = NULL;
    SLLNODEPTR safe = NULL;
    for(tptr =start; tptr; prev=tptr, tptr=tptr->next)
        if(tptr->num == 5) safe = tptr;

    prev->next = safe;
}


int isloop(SLLNODEPTR start)
{
    SLLNODEPTR slow,fast;
    slow = fast =start;
    // TRIVIA
    if(start== NULL) return 0;
    if(start->next ==start) return 1;
    while(fast->next)
  {
      if(fast->next)
         fast = fast->next;
         if(slow==fast) break;
         if(fast->next)
         {
             slow = slow->next;
             fast = fast->next;
         }
         if(slow==fast) break;
}
    if(slow==fast) return 1;


}


void removeLoop(SLLNODEPTR start)
{

    SLLNODEPTR slow,fast;
    slow = fast =start;
    // TRIVIA
    if(start== NULL) return 0;
    if(start->next ==start) return 1;
    while(fast->next)
  {
      if(fast->next)
         fast = fast->next;
         if(slow==fast) break;
         if(fast->next)
         {
             slow = slow->next;
             fast = fast->next;
         }
         if(slow==fast) break;
}
    if(slow==fast){
        SLLNODEPTR ptr1, ptr2, prev;

        ptr2 = slow;
        ptr1 = start;

        while(1)
        {
            prev= ptr2;
            ptr2 = ptr2->next;
            if(ptr2!=ptr1)
            ptr1=ptr1->next;
               else{

                prev->next = NULL;
                break;
               }
        }



    }

}

int main()
{
    int values[] = {1,2,3,4,5,6,7,8,9,10,11,15,16,17,12,13,14}, size, index;
SLLNODEPTR mid, start= NULL;
    size = sizeof(values) / sizeof(int);

    for(index = 0; index < size; index++)
        start = addNode(start, values[index]);
        displaySLL(start);
for(index = 0; index < size; index++)
        delNode(start, values[index]);
        displaySLL(start);


start = reverseSLL(start, NULL);
displaySLL(start);
start = reverseSLLItr(start);
displaySLL(start);
mid = findMidPointSLL(start);
printf("\n\n\n%d ", mid->num);
makeloop(start);
if(isloop(start) == 1) printf("\n\nYes");
else printf("No");
removeLoop(start);
displaySLL(start);


return 0;
}
