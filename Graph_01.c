#include<stdio.h>
#include<string.h>
typedef struct edge
{
     char v1;
     char v2;
     int wt;
} EDGE;

typedef struct node{

char nvert;
struct node * nnext;

} NODE;
typedef NODE * NODEPTR;

typedef struct list{
char lvert;
struct list * lnext;
NODEPTR start;
} LIST;
typedef LIST * LISTPTR;

#define NOE 17
EDGE edges[NOE] ={
{'E','V',96},
{'E','S',18},
{'X','B',3},
{'K','Y',10},
{'B','T',6},
{'B','O',5},
{'K','B',16},
{'N','C',100},
{'S','N',16},
{'S','X',8},
{'T','C',55},
{'T','Y',24},
{'O','C',70},
{'Y','C',50},
{'V','K',42},
{'X', 'T', 23},
{'O', 'K', 10}
};

int main()
{
    LISTPTR startG = NULL, lprev= NULL, ltptr= NULL, nnL;
    NODEPTR nnN, nprev = NULL, ntptr;
    int ctr;
    for(ctr = 0; ctr < NOE; ctr++)
    {
        // search for v1 in list
        for(ltptr = startG; ltptr && ltptr->lvert!= edges[ctr].v1; lprev = ltptr, ltptr=ltptr->lnext);
        if(startG== NULL)
        {

            nnL = (LISTPTR) malloc(sizeof(LIST));
            nnL->lvert = edges[ctr].v1;
            nnL->start= NULL;
            nnL->lnext = NULL;
            ltptr = startG= nnL;
        }
        else if(ltptr==NULL)
        {

            nnL = (LISTPTR) malloc(sizeof(LIST));
            nnL->lvert = edges[ctr].v1;
            nnL->start= NULL;
            nnL->lnext = NULL;
           ltptr = lprev->lnext= nnL;
        }

        for(ntptr =  ltptr->start; ntptr; nprev = ntptr, ntptr= ntptr->nnext);
        if(ltptr->start==NULL)
        {

            nnN= (NODEPTR) malloc(sizeof(NODE));
            nnN->nvert = edges[ctr].v2;
            nnN->nnext = NULL;
            ltptr->start = nnN;
        //     printf("reached\n");
           // printf("%c %c\n", ltptr->lvert, nnN->nvert);
        }
        else
        {nnN= (NODEPTR) malloc(sizeof(NODE));
        nnN->nvert = edges[ctr].v2;
            nnN->nnext = NULL;
            nprev->nnext = nnN;
           //       printf("reached\n");
        }
        // search for v2 in list
        for(ltptr = startG; ltptr && ltptr->lvert!= edges[ctr].v2; lprev = ltptr, ltptr=ltptr->lnext);
        if(startG== NULL)
        {

            nnL = (LISTPTR) malloc(sizeof(LIST));
            nnL->lvert = edges[ctr].v2;
            nnL->start= NULL;
            nnL->lnext = NULL;
            ltptr = startG= nnL;
        }
        else if(ltptr==NULL)
        {

            nnL = (LISTPTR) malloc(sizeof(LIST));
            nnL->lvert = edges[ctr].v2;
            nnL->start= NULL;
            nnL->lnext = NULL;
           ltptr = lprev->lnext= nnL;
        }

        for(ntptr =  ltptr->start; ntptr; nprev = ntptr, ntptr= ntptr->nnext);
        if(ltptr->start==NULL)
        {

            nnN= (NODEPTR) malloc(sizeof(NODE));
            nnN->nvert = edges[ctr].v1;
            nnN->nnext = NULL;
            ltptr->start = nnN;
        //     printf("reached\n");
           // printf("%c %c\n", ltptr->lvert, nnN->nvert);
        }
        else
        {nnN= (NODEPTR) malloc(sizeof(NODE));
        nnN->nvert = edges[ctr].v1;
            nnN->nnext = NULL;
            nprev->nnext = nnN;
            }
    } // main for ctr
for(ltptr = startG; ltptr; ltptr= ltptr->lnext, printf("\n"))
{
    printf("%c : ", ltptr->lvert);
    for(ntptr= ltptr->start; ntptr; ntptr = ntptr->nnext)
        printf("->%c", ntptr->nvert);
}
return 0;
}
