#ifndef DIJKSTRA_H_INCLUDED
#define DIJKSTRA_H_INCLUDED
#include "graph.h"


// relaxes all the edges of the graph in case there is a shorter path between nodes u and v
void Relax(GRAPH *g,QUEUE *q,int u,int v){

    if(g->source_dist[v] > g->source_dist[u] + g->w[u][v]){
            g->source_dist[v]=g->source_dist[u] + g->w[u][v];
            g->parent[v]=u;
    }
    updateQueue(q,v,g->source_dist[v]);
}

// initializes source distances for all nodes
void initNode(GRAPH *g,int node){


    int i;
    for(i=0 ; i<=g->V ; i++)
        g->source_dist[i]=INF;

    g->source_dist[node]=0;

}

// the search algorithm that takes start as the initial node
void dijkstra(GRAPH *g,QUEUE *q,int start){

    int i , counter=0 , u ,v;


    // initializing start node
    initNode(g,start);

    //inserting all vertices into the queue
    for(i=1 ; i<=g->V ; i++){
        enQueue(q,g->source_dist[i],i);
    }


    while(!isEmpty(q)){


        u=deQueue(q);
        g->S[counter]=u;

        for(v=1 ; v<=g->V ; v++)
            if(v != u && is_in_queue(q,v))
                    Relax(g,q,u,v);

        counter ++;
    }

}

#endif // DIJKSTRA_H_INCLUDED
