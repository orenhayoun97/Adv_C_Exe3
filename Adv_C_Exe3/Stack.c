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
    if(isEmptyStack(s)) return NULL;
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

//void sendToAnotherStack(Stack *s,Stack *s1){
//    charNode *temp = s1->head;
//    // if empty list
//    if(!s || !s1) return;
//    // not empty
//    while(temp == NULL){
//        push(s,temp->data);
//        temp = temp->next;
//    }
//}
//void printStack(Stack *s){ // print from the buttom to the top
//    Stack *helper;
//    while(s->head == NULL){
//        push(helper,s->head->data);
//    }
//    destroyStack(s);
//    while(helper->head == NULL){
//        printf("%c",pop(helper));// free inside the function
//    }
//    return;
//}

/*************** Functions using stacks - Implementation/definition **************************/

//void flipBetweenHashes(const char* sentence)
//{
//    Stack *s, *s_help;
//    char *temp = sentence;
//    int check = 0;
//	// deal with empty sentence
//    if(!sentence){
//        printf("there is no sentece...");
//        return;
//    }
//    // deal with a sentence
//    while(*temp != '\0'){
//        // deal with no '#'
//        if(*temp == '#'){
//            check = 0;
//            temp++;
//            initStack(s_help);
//            // deal with 2 '#' one after one ##
//            while(temp != '#'){
//                check = 1;
//                push(s_help,*temp);
//                temp++;
//            }
//            if(check) sendToAnotherStack(s,s_help); // put in header stack the helper stack
//        }
//        push(s,*temp);
//        temp++;
//    }
//    destroyStack(s_help);
//    printStack(s);
//    return;
//}
void flipBetweenHashes(const char* sentence){
    
    Stack *s = NULL;
    initStack(s);
    char *temp = sentence;
    // deal with empty sentence
    if(!sentence){
        printf("there is no sentece...");
        return;
    }
    // deal with sentence
    while(*temp != '\0'){
        if(*temp == '#'){
            temp++;
            while(*temp != '#'){
                push(s,*temp);
                printf("%c",pop(s));
                temp++;
            }
            temp++;
        }
        printf("%c",*temp);
        temp++;
    }
    destroyStack(s);
}
int checkHowMuchInStack(Stack *s){
    charNode *temp = s->head;
    int counter = 0;
    while(!temp){
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
    Stack *s_help = NULL;
    initStack(s_help);
    int size = checkHowMuchInStack(s);
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
