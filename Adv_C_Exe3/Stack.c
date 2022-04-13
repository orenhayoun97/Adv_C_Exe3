#include "Stack.h"
#include "stdlib.h"
#include <stdio.h>

/***************** Stack ADT Implementation *****************/

void initStack(Stack* s)
{
    s->head = NULL;
}

void destroyStack(Stack* s)
{
    // deal with empty list
    if(!s->head) return;
    // have a list
    charNode* temp1 = s->head;
    charNode* temp2 = s->head;
    while(!temp1){
        temp1 = temp1->next;
        free(temp2);
        temp2 = temp1;
    }
    return;
}

void push(Stack* s, char data)
{
    charNode* newhead = (charNode*) calloc(1,sizeof(charNode));
    newhead->data = data;
	// deal with empty list
    if(!s->head){
        s->head = newhead;
        return;
    }
    // deal with not empty list
    newhead->next = s->head;
    s->head = newhead;
    return;
    
}

char pop(Stack* s)
{
    // deal with empty list
    if(isEmptyStack(s)) exit(0);
    // deal with list
    char data;
    charNode* temp = s->head;
    s->head = s->head->next;
    data = temp->data;
    free(temp);
    return data;
}


int isEmptyStack(const Stack* s)
{
    // empty list
    if(!s->head) return 1;
    // not empty
    else return 0;
}

void flipBetweenHashes(const char* sentence){
    
    Stack *s = (Stack*) calloc(1,sizeof(Stack));
    initStack(s);
    char *temp = sentence;
    // deal with empty sentence
    if(!sentence){
        printf("there is no sentence...");
        return;
    }
    // deal with sentence
    while(*temp != '\0'){
        if(*temp == '#'){ //"hello##ym#na#em#isoren"
            temp++;
            while(*temp != '#'){
                push(s,*temp);
                temp++;
            }
            while(!isEmptyStack(s)){
                printf("%c",pop(s));
            }
            temp++;
        }
            printf("%c",*temp);
            temp++;
    }
    destroyStack(s);
}
int checkHowMuchInStack(charNode *head){
    charNode *temp = head;
    int counter = 0;
    while(temp != NULL){
        counter++;
        temp = temp->next;
    }
    return counter;
}

int isPalindrome(Stack* s)
{
	// check if the s is null
    if(!s) return 0;
    // check if empty list
    if(isEmptyStack(s)) return 1;
    
    int i = 0;
    // need to allocate a place int memory for this stack
    Stack *s_help = (Stack*) calloc(1,sizeof(Stack));
    if(!s_help){
        printf("allocation faield...\n");
        exit(1);
    }
    initStack(s_help);
    int size = checkHowMuchInStack(s->head);
    if(!size%2){ //  Zogi = True
        for(i = 0;i < size/2 ;i++){
            push(s_help,pop(s));
        }
    }
    else{ // E Zogi
        for(i = 0;i < size/2 ;i++){
            push(s_help,pop(s));
        }
        pop(s);
    }
    for(i=0;i < size/2 ; i++){
        if(pop(s) != pop(s_help)){
            return 0;
        }
    }
    return 1;
}
void rotateStack(Stack* s, int n)
{
	// add your code here
}
