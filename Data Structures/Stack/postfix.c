#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
// Stack structure using an array
typedef struct Stack {
	int* arr;
	int top;
} Stack;
int size;
// Initialise a Stack of given size
Stack* stack_initialize(int);

// Push an element onto the Stack
void stack_push(Stack*, int);

// Pop an element from the Stack. Do not return the element
void stack_pop(Stack*);

// Check if the Stack is empty
int stack_is_empty(Stack*);

// Return the top element of the Stack
int stack_peek(Stack*);

// Free the resources held by the Stack
void stack_destroy(Stack*);

// Convert an infix expression to postfix expression
void convert_infix_to_postfix(const char*, char*);

int main() {
	char source_infix[2000];
	char target_postfix[2000];
	int number_of_inputs = 0;
	scanf("%d", &number_of_inputs);
	for(int counter = 0; counter < number_of_inputs; ++ counter) {
		scanf("%s", source_infix);
		convert_infix_to_postfix(source_infix, target_postfix);
		printf("%s\n", target_postfix);
	}
	return 0;
}

Stack* stack_initialize(int size)
{
    Stack* ptr_stack=(Stack*)malloc(sizeof(Stack));
    ptr_stack->top=-1;
    ptr_stack->arr=(int*)calloc(size,sizeof(int));
    return(ptr_stack);
}

void stack_push(Stack *ptr_stack, int key) 
{
    if((ptr_stack->top) >= size-1){
    }
    else{
        ptr_stack->arr[++(ptr_stack->top)]=key;
    }
    
}

void stack_pop(Stack* ptr_stack)
{
    if(stack_is_empty(ptr_stack)){
    }
    else{
        (ptr_stack->top)--;
    }
}

int stack_is_empty(Stack *ptr_stack)
{
    if(ptr_stack->top==-1){
        return(1);
    }
    return(0);
}

int stack_peek(Stack *ptr_stack) 
{
    if(stack_is_empty(ptr_stack)){
        return;
    }
    else{
        return(ptr_stack->arr[ptr_stack->top]);
    }
}

void stack_destroy(Stack *ptr_stack) 
{
    free(ptr_stack);
}

void convert_infix_to_postfix(const char *source_infix, char *target_postfix)
{

    int pre(char);
    size=strlen(source_infix);
    Stack* ptr_stack=stack_initialize(size);
    int i=0;
    while(source_infix[i]!='\0'){
        if(isalnum(source_infix[i])){
            *(target_postfix)=source_infix[i];
            target_postfix++;
        }
        else if(source_infix[i]=='{'||source_infix[i]=='('||source_infix[i]=='['){
            stack_push(ptr_stack,source_infix[i]);
        } 
        else if(source_infix[i]=='}'||source_infix[i]==')'||source_infix[i]==']'){
            char p=source_infix[i];
            char ch;
            if(p=='}'){
                ch='{';
            }
            else if(p==')'){
                ch='(';
            }
            else if(p==']'){
                ch='[';
            }
            while(!stack_is_empty(ptr_stack) && ptr_stack->arr[ptr_stack->top]!=ch){
                *(target_postfix)=ptr_stack->arr[ptr_stack->top];
                stack_pop(ptr_stack);
                target_postfix++;
            }
            if(stack_is_empty(ptr_stack)){
            }
            else{
            stack_pop(ptr_stack);
            }
        }
        else{
            if(pre(source_infix[i])>pre(ptr_stack->arr[ptr_stack->top])){
            }
            else{
                while(!stack_is_empty(ptr_stack) && pre(ptr_stack->arr[ptr_stack->top])>pre(source_infix[i])){
                    *(target_postfix)=ptr_stack->arr[ptr_stack->top];
                    target_postfix++;
                    stack_pop(ptr_stack);
                }
            }
            stack_push(ptr_stack,source_infix[i]);
        }
        i++;
    }
    while(!stack_is_empty(ptr_stack)){
        *(target_postfix)=ptr_stack->arr[ptr_stack->top];
        stack_pop(ptr_stack);
        target_postfix++;
    }

    *(target_postfix)='\0';
    stack_destroy(ptr_stack);
}
int pre(char ch){
    if(ch=='{'||ch=='['||ch=='('){
        return(0);
    }
    if(ch=='+'||ch=='-'){
        return(1);
    }
    if(ch=='*'||ch=='/'||ch=='%'){
        return(2);
    }
}   
