#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "graph.h"
#include "dijkstra.h"


int main()
{
    FILE *f=fopen("graph.in","rt");

    if(f == NULL){
        perror("");
        exit(1);
    }

    int V,v1,v2,cost;

    fscanf(f,"%d",&V);
    GRAPH *g=newGraph(V);

    while(!feof(f)){
        fscanf(f,"%d %d %d",&v1,&v2,&cost);
        addEdge(g,v1,v2,cost,0); // 0 because the graph is undirected
    }


    QUEUE *q=newQueue(V);

    int i;
    dijkstra(g,q,1);

    for(i=0 ; i<V ; i++)
        printf("%d ",g->S[i]);

    fclose(f);
    freeGraph(g);
    freeQueue(q);
    return 0;
}
