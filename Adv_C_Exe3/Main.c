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
    char* str = "hello##ym#na#em#isoren";
    // check the flipBetweenHashes function
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
    
    return 0;
}
