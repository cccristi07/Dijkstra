#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

// vector implementation of a min-priority queu
typedef struct queue{

    int *vec_dist; // distance from source node,used for the order relationship
    int *vec_node; // vector of nodes
    int MAX_P; // maximum index of queue elements
    int MIN_P; // minimum index of queue elements
    int n;
}QUEUE;


// function to swap 2 integers
void swap(int *a,int *b){

    *a=*a ^ *b;
    *b=*a ^ *b;
    *a=*a ^ *b;
}

// returns a pointer to a newly created queue
QUEUE *newQueue(int n){

    QUEUE *q=(QUEUE*)malloc(sizeof(QUEUE));

    //allocate the vector inside the queue
    q->vec_dist=(int*)malloc(sizeof(int)*n);
    q->vec_node=(int*)malloc(sizeof(int)*n);
    q->n=n;

    // queue is empty
    q->MAX_P=-1;
    q->MIN_P=-1;

    return q;

}

// sorts the queue in ascending order using the dist as key
void asc_order(QUEUE *q){

    int i,j;
    if(q->MAX_P == q->MIN_P){
        return;// queue has either one element to order or none
    }

    for(i=q->MIN_P;i<q->MAX_P;i++)
        for(j=i+1;j<q->MAX_P+1;j++){

                if(q->vec_dist[i] > q->vec_dist[j]){

                    swap(&q->vec_dist[i],&q->vec_dist[j]);
                    swap(&q->vec_node[i],&q->vec_node[j]);

                }
    }

    return;
}

//updates an element of a queue with a new distance
void updateQueue(QUEUE *q,int node,int dist){

    int i;

        for(i=q->MIN_P ; i<=q->MAX_P ; i++){

            if(q->vec_node[i] == node)
                q->vec_dist[i]=dist;
        }
    asc_order(q);

}

//returns 1 if queue is empty , else 0
int isEmpty(QUEUE *q){

    if(q->MAX_P == -1 && q->MIN_P == -1)
        return 1;
    else
        return 0;

}


// enqueues an element, with  the min-priority rule
void enQueue(QUEUE *q, int dist,int node){

    if(q->MAX_P > q->n){

        printf("Queue size is exceeded");
        return;
    }

    // queue is empty
    if(q->MAX_P == -1 && q->MIN_P == -1){
        q->MAX_P=0;
        q->MIN_P=0;
        q->vec_dist[0]=dist;
        q->vec_node[0]=node;
        return;
    }
    // adds an element to the queue and checks if it is the minimum
    q->MAX_P++;
    q->vec_dist[q->MAX_P]=dist;
    q->vec_node[q->MAX_P]=node;

    asc_order(q);

    return;

}

// returns the first element from the priority queue then eliminates it
int deQueue(QUEUE *q){

    int v;
    if(q->MAX_P == -1 && q->MIN_P == -1){

        printf("Queue has no elements");
        exit(1);
    }

    // queue has one element
    if(q->MAX_P == q->MIN_P){
        v=q->vec_node[q->MAX_P];
        q->MAX_P = -1;
        q->MIN_P = -1;
        return v;

    }

    v=q->vec_node[q->MIN_P];
    q->MIN_P++;

    return v;
}

//returns the first element of the queue without dequeue
int Front(QUEUE *q){

    int v;

    if(q->MAX_P == -1 && q->MIN_P == -1){

        printf("Queue has no elements");
        exit(1);
    }

    // queue has one element
    if(q->MAX_P == q->MIN_P){
        v=q->vec_node[q->MAX_P];
        return v;
    }

    v=q->vec_node[q->MIN_P];

    return v;
}

// If node is in the queue returns 1 , else 0
int is_in_queue(QUEUE *q,int node){

    int i;

    for(i=q->MIN_P ; i<= q->MAX_P ; i++)
        if(q->vec_node[i]  == node)
            return 1;

    return 0;

}

// prints the elements of the queue
void printQueue(QUEUE *q){

    if(q->MIN_P == -1 && q->MAX_P == -1){
        printf("Queue is empty");
        return;
    }
    int i ;
    printf("DIST : ");
    for(i=q->MIN_P; i<=q->MAX_P ; i++)
        printf("%d ",q->vec_dist[i]);

    printf("\nNODES: ");


    for(i=q->MIN_P;i<=q->MAX_P ;i++)
        printf("%d ",q->vec_node[i]);

    printf("\n\n");
}

void freeQueue(QUEUE *q){

    free(q->vec_dist);
    free(q->vec_node);
    free(q);


}
#endif // QUEUE_H_INCLUDED
