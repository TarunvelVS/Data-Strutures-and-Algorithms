#include<stdio.h>


typedef struct sllnode
{
    int num;
    struct sllnode * next;

} SLLNODE;
typedef SLLNODE * SLLNODEPTR;
SLLNODEPTR start, nn, tptr, prev;

void addNode(int data)
{

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
}


void displaySLL()
{

for(tptr = start,printf("\n"); tptr; printf("%d->", tptr->num), tptr=tptr->next);
printf("NULL");
}
SLLNODEPTR reverseSLLItr()
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
void delNode(int delnum)
{
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

SLLNODEPTR findMidPointSLL()
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

void makeloop()
{

    SLLNODEPTR safe = NULL;
    for(tptr =start; tptr; prev=tptr, tptr=tptr->next)
        if(tptr->num == 5) safe = tptr;

    prev->next = safe;
}


isloop()
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


removeLoop()
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
SLLNODEPTR mid;
    size = sizeof(values) / sizeof(int);

    for(index = 0; index < size; index++)
        addNode(values[index]);
        displaySLL();
/*for(index = 0; index < size; index++)
        delNode(values[index]);
        displaySLL();


start = reverseSLL(start, NULL);
displaySLL();
start = reverseSLLItr();
displaySLL();
mid = findMidPointSLL();
printf("\n\n\n%d ", mid->num);*/
makeloop();
if(isloop() == 1) printf("\n\nYes");
else printf("No");
removeLoop();
displaySLL();


return 0;
}
