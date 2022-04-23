#include "Queue.h"
#include <stdlib.h>
#include <stdio.h>

/***************** Queue ADT Implementation *****************/

void initQueue(Queue* q)
{
    q->head = q->tail = NULL;
    return;
}

void destroyQueue(Queue* q)
{
    // empty queue
    if(q == NULL) return;
    intNode *temp,*clear;
    temp = clear = q->head;
    while(temp != NULL){
        temp = temp->next;
        free(clear);
        clear = temp;
    }
    return;
}

void enqueue(Queue* q, unsigned int data)
{
    intNode* new = (intNode*) calloc(1,sizeof(intNode));
    new->data = data;
    if(isEmptyQueue(q)){
        q->head = q->tail = new;
        return;
    }
    q->tail->next = new;
    q->tail = new;
    return;
}

unsigned int dequeue(Queue* q)
{
    intNode* temp = q->head;
    int data = q->head->data;
    q->head = q->head->next;
    free(temp);
    if(isEmptyQueue(q)){
        initQueue(q);
        return data;
    }
    return data;
}

int isEmptyQueue(const Queue* q)
{
    if(q->head == NULL) return 1;
    return 0;
}

/***************** Functions using Queues - Implementation/definition **************************/

void rotateQueue(Queue* q)
{
	// case with empty queue
    if(q == NULL){
        printf("**the Queue is empty...\n");
        return;
    }
    // case with a queue
    Queue* helper = (Queue*) calloc(1,sizeof(Queue));
    if(helper == NULL){
        printf("***Allocation failed...\n");
        exit(1);
    }
    while(q->head->next != NULL){
        enqueue(helper,dequeue(q));
    }
    while(isEmptyQueue(helper) == 0){
        enqueue(q,dequeue(helper));
    }
    destroyQueue(helper);
    return;
}
int SizeCheck(Queue* q){
    intNode* temp = q->head;
    int size = 0;
    while(temp != NULL){
        size++;
        temp = temp->next;
    }
    return size;
}
int AverageNum(Queue* q, int size){
    intNode* temp = q->head;
    int aver = 0;
    while(temp != NULL){
        aver += temp->data;
        temp = temp->next;
    }
    return (aver / size);
}
void CombanitonOfQueue(Queue *q, Queue *helper,int size){
    for(int i = 0; i< size;i++){
        enqueue(q,dequeue(helper));
    }
    return;
}
void ChangeDirection(Queue* q,int size){
    Queue* helper = (Queue*) calloc(1,sizeof(Queue));
    if(helper == NULL){
        printf("***Allocation failed...\n");
        exit(1);
    }
    for(int i = 0 ; i < size ; i++){
        rotateQueue(q);
        enqueue(helper,dequeue(q));
    }
    CombanitonOfQueue(q,helper,size);
}
void cutAndReplace(Queue* q)
{
    // case with Nullptr Queue
    if(q == NULL){
        printf("**There is no Queue...\n");
        return;
    }
    Queue* helper = (Queue*) calloc(1,sizeof(Queue));
    if(helper == NULL){
        printf("***Allocation failed...\n");
        exit(1);
    }
    // case with empty Queue
    if(isEmptyQueue(q)){
        printf("**The Queue is empty...\n");
        return;
    }
    int size = SizeCheck(q);
    if(size % 2 != 0){ // E Zogi
        enqueue(q,AverageNum(q,size));
        size += 1;
    }
    // cut the Queue to half
    CombanitonOfQueue(helper,q,size/2);
    // Change the direction of the half of tail
    ChangeDirection(q, size/2);
    // put in the main queue, the rest queue
    CombanitonOfQueue(q,helper,size/2);
    free(helper);
    return;
}
void PrintQueue(Queue *q){
    intNode* temp = q->head;
    while(temp != NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
    return;
}

int CheckTheLowestNumber(Queue *q){
    intNode *lowest,*beflow,*prev,*temp;
    int data = 0;
    lowest = temp = q->head;
    beflow = prev = NULL;
    while(temp != NULL){
        if(lowest->data > temp->data){
            beflow = prev;
            lowest = temp;
        }
        prev = temp;
        temp = temp->next;
    }
    if(beflow != NULL){
        beflow->next = lowest->next;
    }
    else{
        q->head = lowest->next;
    }
    
    data = lowest->data;
    free(lowest);
    return data;
}
void sortKidsFirst(Queue* q)
{
    // Check if the Queue is nullptr
    if(q == NULL){
        printf("**There is no Queue...\n");
        return;
    }
	// Check if Queue is empty
    if(isEmptyQueue(q)){
        printf("**The Queue is empty...\n");
        return;
    }
    // deal with one node
    if(q->head == q->tail){
        printf("**There is only one node in this Queue");
        return;
    }
    Queue *helper = (Queue*) calloc(1,sizeof(Queue));
    initQueue(helper);
    if(helper == NULL){
        printf("***Allocation failed...\n");
        exit(1);
    }
    while(!isEmptyQueue(q)){
        enqueue(helper,CheckTheLowestNumber(q));
    }
    while(!isEmptyQueue(helper)){
        enqueue(q,dequeue(helper));
    }
    destroyQueue(helper);
    free(helper);
    return;
}
