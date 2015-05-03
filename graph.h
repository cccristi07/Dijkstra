#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED
#include "queue.h"
#define INF 9999999



typedef struct graph{

    int V; // number of nodes
    int **w; // weight matrix for the graph , with non negative weights
    int *S; // all the nodes in the graph, after the dijkstra traverse
    int *source_dist;
    int *parent;

}GRAPH;

// returns a pointer to a newly created graph
GRAPH* newGraph(int V){

    GRAPH *g=(GRAPH*)malloc(sizeof(GRAPH));
    int i,j;
    g->V=V;

    //matrix allocation.
    g->w=(int**)calloc(V+1,sizeof(int*));

    for(i=0;i<=V;i++)
        g->w[i]=(int*)calloc(V+1,sizeof(int));

    for(i=0;i<=V;i++)
        for(j=0;j<=V;j++)
            g->w[i][j]=INF;

    //allocation for utility vectors inside the data structure
    g->S=(int*)calloc(V+1,sizeof(int));

    g->parent=(int*)calloc(V+1,sizeof(int));

    g->source_dist=(int*)calloc(V+1,sizeof(int));

    return g;

}


/* adds and edge between the two nodes
 * 1 for directed
 * 0 for undirected
 */
void addEdge(GRAPH *g,int v1,int v2,int cost, int directed){

    if(directed == 0){
        g->w[v1][v2]=cost;
        g->w[v2][v1]=cost;
    }

    if(directed == 1)
        g->w[v1][v2]=cost;
}

// free the memory allocated by the graph
void freeGraph(GRAPH *g){

    int i;

    for(i=0;i<=g->V;i++)
        free(g->w[i]);

    free(g->w);
    free(g->parent);
    free(g->S);
    free(g->source_dist);
}


#endif // GRAPH_H_INCLUDED
