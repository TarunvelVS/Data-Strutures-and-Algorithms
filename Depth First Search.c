#include<stdio.h>
#include<malloc.h>
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
int visited[NODES];

void DFS(char);
void BFS(char vertex);
void enqueue(char * ,  char ,  int* , int*);
char dequeue(char*  , int* , int*);
int main()
{
int ctr , ind , size , pos1 , pos2 , row , col  , startctr;
size = sizeof(edges) / sizeof(EDGE);

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

    //DFS( 'C');
    BFS('I' ) ;













return 0;
}





void enqueue(char *Q ,  char  vertex,  int* front , int* rear)
{
    if( *front == -1)
    {
        *front = *rear = 0;
        Q[*rear] = vertex;
    }
    else
         Q[++(*rear)] = vertex;
}
char dequeue(char * Q ,  int* front , int* rear)
{
    char temp;
        temp = Q[(*front)++];
        if( *front > *rear)
              *front = *rear = -1;

   return temp;
}














void BFS(char vertex)
{
         char Queue[NODES*NODES + 1]  , deqvertex;
         int front , rear ;
         NODEPTR tptr;
         front = rear = -1;

            enqueue( Queue , vertex , &front , &rear);
            deqvertex = dequeue(Queue , &front , &rear) ;
            do
            {
                if( visited[deqvertex -65] == 0)
                {
                      printf("%c " , deqvertex);
                     visited[deqvertex - 65] = 1;
                }

                 for(tptr = start[deqvertex-65] -> next ; tptr ; tptr=  tptr -> next )
                      if( visited[tptr->vertex - 65] == 0)
                         enqueue( Queue , tptr->vertex, &front , &rear);
                deqvertex = dequeue(Queue , &front , &rear) ;
            }while( front != -1);


}





void DFS(char vertex)
{
      NODEPTR tptr;
        if( visited[vertex - 65] == 1) return ;
        visited[vertex - 65] = 1;
        printf("%c " , vertex);
        for(tptr = start[vertex-65] ; tptr ; tptr = tptr -> next)
              DFS( tptr -> vertex);



}








