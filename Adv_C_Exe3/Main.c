#include <stdio.h>
#include "Stack.h"
#include "Queue.h"
#include <stdlib.h>

int main()
{
    Stack *s;
    s = (Stack*) calloc(1, sizeof(Stack));
    initStack(s);
    push(s,'O');
    push(s,'r');
    push(s,'e');
    push(s,'r');
    push(s,'O');
    
    // check the palindrome function
    (isPalindrome(s)) ? printf("Palindrome\n") : printf("not Palindrome\n");
    // check the flipBetweenHashes function
    char* str = "hello##ym#na#em#isoren";
    
    flipBetweenHashes(str);
    printf("\n");
    // check the rotateStack function
    
    push(s,'k');
    push(s,'e');
    push(s,'s');
    push(s,'s');
    push(s,'e');
    push(s,'m');
    
    rotateStack(s,3);
    PrintTheStack(s);
    printf("\n");
    
    // Queue check
    
    Queue *q = (Queue*) calloc(1,sizeof(Queue));
    if(!q){
        printf("Allocation failed...\n");
        exit(0);
    }
    enqueue(q,14);
    enqueue(q,6);
    enqueue(q,5);
    enqueue(q,4);
    enqueue(q,3);
    enqueue(q,2);
    enqueue(q,1);
    
//    rotateQueue(q);
    PrintQueue(q);
    cutAndReplace(q);
    PrintQueue(q);
    
    return 0;
}
