#include <stdio.h>
#include "Stack.h"
#include "Queue.h"

int main()
{
    Stack *s = NULL;
    initStack(s);
    push(s,'A');
    push(s,'B');
    push(s,'B');
    push(s,'A');
    (isPalindrome(s)) ? printf("Palindrome\n") : printf(" not Palindrome\n");
    return 0;
}
