#include<stdio.h>
#include<string.h>
typedef struct edge
{
     char v1;
     char v2;
     int wt;
} EDGE;

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
 int **graph=NULL;
 int ctr, nodectr=0, pos1, pos2, outer, inner;
 char *nodes=NULL;
// find uniq nodes

nodes  = (char *) calloc(NOE, sizeof(char));

for(ctr = 0; ctr < NOE; ctr++)
{
            if(strchr(nodes, edges[ctr].v1) == NULL)
                nodes[nodectr++] = edges[ctr].v1;
            if(strchr(nodes, edges[ctr].v2) == NULL)
                nodes[nodectr++] = edges[ctr].v2;
}
// make space for the graph
//printf("%d", nodectr);
graph = (int **) calloc(nodectr, sizeof(int *));
for(ctr = 0; ctr < nodectr; ctr++)
       graph[ctr] = (int *) calloc(nodectr, sizeof(int));
       ctr = 0;
// fill graph data
for(ctr = 0; ctr < NOE; ctr++)
{

       pos1 = strchr(nodes,edges[ctr].v1)  -  nodes ;
         pos2 =  strchr(nodes,edges[ctr].v2) -  nodes ;
            graph[pos1][pos2] = 1;
            graph[pos2][pos1]=1;
            graph[pos1][pos1] = 1;
            graph[pos2][pos2]=1;

}
// print graph
for(outer = 0, printf("  "); outer < nodectr; outer++)
    printf("%c ", nodes[outer]);

for(outer = 0, printf("\n"); outer < nodectr; outer++, printf("\n"))
{
printf("%c ", nodes[outer]);
    for(inner = 0; inner < nodectr; inner++)
           printf("%d ", graph[outer][inner]);
}
return 0;
}
