#include<stdio.h>
#define NODES 9
typedef struct edge
{
     char v1 , v2;
     int weight;

}EDGE;
typedef struct node
{
     char vertex;
     int weight;
     struct node *next;
}NODE;
typedef NODE* NODEPTR ;

NODEPTR start [NODES]  , newnode , tptr;

EDGE edges[14] = { {'A' , 'C' ,3 } , {'A' , 'D' , 5} ,{'A' , 'B' ,9 } ,
 {'B' , 'G' , 1} ,{'B' , 'E' , 3} , {'C' , 'F' ,9 } ,{'C' , 'D' , 2} , {'F' , 'H' ,12 } ,
{'F' , 'G' , 4} , {'G' , 'E' ,15 } ,{'G' , 'I' ,10 } , {'H' , 'I' ,6 } ,{'E' , 'I' , 5} , {'D' , 'G' , 6} };
int main()
{
int ctr , ind , size , pos1 , pos2 , row , col  , startctr;
size = sizeof(edges) / sizeof(EDGE);

// init
for(ctr = 0 ; ctr < NODES ; ctr++)
{
         NODE *newnode = 0;
         newnode = (NODE*)calloc( 1 , sizeof(NODE));
         newnode -> vertex = ctr + 65;
         start[ctr ] = newnode;
}


    for(ind = 0 ; ind < size ; ind++)
    {
              startctr = edges[ind].v1 - 'A';
           newnode = (NODE*)calloc( 1 , sizeof(NODE));
           newnode -> vertex = edges[ind].v2;
           newnode -> weight = edges[ind].weight;
        for(tptr = start[startctr] ; tptr->next ; tptr = tptr ->next ) ;
        tptr -> next = newnode;

              startctr = edges[ind].v2 - 'A';
           newnode = (NODE*)calloc( 1 , sizeof(NODE));
           newnode -> vertex = edges[ind].v1;
           newnode -> weight = edges[ind].weight;
        for(tptr = start[startctr] ; tptr->next ; tptr = tptr ->next ) ;
        tptr -> next = newnode;

    }
for(ctr  = 0 ; ctr < NODES ; ctr++ , printf("\n"))
{
    printf("%c ->" , start[ctr] -> vertex);
      for(tptr = start[ctr]->next ;  tptr -> next ; tptr = tptr -> next)
          printf("(%d)%c ->" , tptr -> weight , tptr -> vertex);
printf("(%d)%c " , tptr->weight , tptr -> vertex);
}
















return 0;
}
