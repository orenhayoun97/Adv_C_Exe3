#include <stdio.h>
#include "Stack.h"
#include "Queue.h"
#include <stdlib.h>

int main()
{
    Stack *s =(Stack*)calloc(1,sizeof(Stack));
    initStack(s);
    push(s,'O');
    push(s,'r');
    push(s,'e');
    push(s,'O');
    push(s,'r');

//    (isPalindrome(s)) ? printf("Palindrome\n") : printf("not Palindrome\n");
    char* str = "hello#ym#na#em#isoren";
    flipBetweenHashes(str);
    printf("\n");
    return 0;
}
