#include <stdio.h>
#include "Stack.h"
#include "Queue.h"
#include <stdlib.h>

int main()
{
    //** Stack Check **//
    printf("***Stack Check***\n");
    
    // check the palindrome function
    
    Stack *s;
    s = (Stack*) calloc(1, sizeof(Stack));
    
    push(s,'O');
    push(s,'r');
    push(s,'e');
    push(s,'r');
    push(s,'O');
    
    destroyStack(s);
    initStack(s);
    
    (isPalindrome(s)) ? printf("Palindrome\n") : printf("not Palindrome\n");
    
    // check the flipBetweenHashes function
    
    char* str = "hell#ymo#fr#ie#nd";
    
    printf("flipBetweenHashes function : \n");
    printf("before : %s\n",str);
    printf("after  : ");
    flipBetweenHashes(str);
    printf("\n\n");
    
    // check the rotateStack function
    
    printf("rotateStack function : \n");
    
    push(s,'k');
    push(s,'e');
    push(s,'s');
    push(s,'s');
    push(s,'e');
    push(s,'m');
    
    printf("before : ");
    PrintTheStack(s);
    rotateStack(s,3);
    printf("after  : ");
    PrintTheStack(s);
    printf("\n");
    
    //** Queue Check **//
    printf("***Queue Check***\n");
    
    Queue *q = (Queue*) calloc(1,sizeof(Queue));
    if(!q){
        printf("Allocation failed...\n");
        exit(0);
    }
    
    // check the rotateQueue function
    
    enqueue(q,1);
    enqueue(q,2);
    enqueue(q,3);
    enqueue(q,4);
    enqueue(q,5);
    enqueue(q,6);
    enqueue(q,7);
    
    printf("rotateQueue function : \n");
    
    printf("before : ");
    PrintQueue(q);
    rotateQueue(q);
    printf("after  : ");
    PrintQueue(q);
    printf("\n");
    destroyQueue(q);
    initQueue(q);
    
    // check the cutAndReplace function
    
    enqueue(q,6);
    enqueue(q,1);
    enqueue(q,5);
    enqueue(q,2);
    enqueue(q,3);
    enqueue(q,1);
    enqueue(q,9);
    
    printf("cutAndReplace function : \n");
    printf("before : ");
    PrintQueue(q);
    cutAndReplace(q);
    printf("after  : ");
    PrintQueue(q);
    printf("\n");
    
    // check the sortKidsFirst function
    
    printf("sortKidsFirst function : \n");
    printf("before : ");
    PrintQueue(q);
    sortKidsFirst(q);
    printf("after  : ");
    PrintQueue(q);
    printf("\n");
    destroyQueue(q);
    free(q);
    
    return 0;
}
