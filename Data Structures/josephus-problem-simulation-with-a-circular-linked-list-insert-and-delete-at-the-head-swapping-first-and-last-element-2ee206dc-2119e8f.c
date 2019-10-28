#include <stdio.h>
#include <stdlib.h>

// Node of the circular linked list.
typedef struct Node
{
    int data;
    struct Node *next;
} Node;

// Handle of the list.
// Head points to the first node in the list.
// Tail points to the last node in the list.
typedef struct List
{
    Node *head;
    Node *tail;
    int length;
} List;

// Initializes a cirucular linked list.
List* initialize_list();

// Creates a node and stores the data in it.
Node* create_node(int data);

// Inserts data at the head of the list.
void insert_head(List* cll, int data);

// Deletes the node at the head position. No operation if list is empty.
void delete_head(List* cll);

// Swaps the first(Head) and last(Tail) element.
void swap_first_and_last(List* cll);

// Prints the data present in the safe node according to the josephus problem.
int josephus(List* cll, int k);

// Prints the entire list. Prints "EMPTY" if the list is empty.
void display(List* cll);

// Deallocates resources held by the list.
void destroy_list(List* cll);


int main()
{

    List* cll = initialize_list();
    int ele, choice, pos, k;
    
    do
    {
        scanf("%d",&choice);

        switch(choice)
        {
            // Insert at Head.
            case 1:
                scanf("%d",&ele);
                insert_head(cll,ele);
                break;

            // Delete at Head.
            case 2:
                delete_head(cll);
                break;

            // Josephus problem.
            case 3:
                scanf("%d",&k);
                ele = josephus(cll,k);
                printf("%d\n",ele);
                break;

            // Swap first and last element.
            case 4:
                swap_first_and_last(cll);
                break;

            // Print entire list.
            case 5:
                display(cll);
                break;  
      
        }
    }
    while (choice != 0);

    destroy_list(cll);
    return 0;
}

List* initialize_list()
{
    List* cll=(List*)malloc(sizeof(List*));
    cll->head=NULL;
    cll->tail=NULL;
    cll->length=0;
    return(cll);
}

Node* create_node(int data)
{
    Node* nw=(Node*)malloc(sizeof(Node));
    nw->data=data;
    return(nw);
}

void insert_head(List* cll, int data)
{
    Node* temp=create_node(data);
    if(cll->head==NULL){
        cll->head=temp;
        cll->tail=temp;
        temp->next=temp;
    }
    else{
        temp->next=cll->head;
        Node* var=cll->head;
        while(var->next!=cll->head){
            var=var->next;
        }
        var->next=temp;
        cll->head=temp;
    }
    cll->length++;
}

void delete_head(List* cll)
{
    if(cll->head==NULL){
    }
    else{
        if(cll->head==cll->tail){
            free(cll->head);
            cll->head=NULL;
            cll->tail=NULL;
        }
        else{
            Node* var=cll->head;
            while(var->next!=cll->head){
                var=var->next;
            }
            var->next=cll->head->next;
            Node* del=cll->head;
            cll->head=var->next;
            free(del);
        }
        cll->length--;
    }
}

void swap_first_and_last(List* cll)
{
    if(cll->head==NULL || cll->head==cll->tail){
    }
    else{
        int a;
        a=cll->head->data;
        cll->head->data=cll->tail->data;
        cll->tail->data=a;
    }
}

int josephus(List* cll, int k)
{
    Node* temp=cll->head;
    if(cll->head==NULL || cll->length<k){
        return;
    }
    else{
        for(int i=0;i<k;i++){
            temp=temp->next;
        }
        while(cll->length>1){
            if(temp->next==cll->head){
                cll->head=temp->next->next;
            }
            if(temp->next==cll->tail){
                cll->tail=temp;
            }
            Node* del=temp->next;
            temp->next=temp->next->next;
            temp=temp->next;
            free(del);
            cll->length--;
        }
        return(temp->data);
    }    
}

void display(List* cll)
{
    if(cll->head==NULL){
        printf("EMPTY");
    }
    else{
        Node* var=cll->head;
        if(cll->head==cll->tail){
            printf("%d ",cll->head->data);
        }
        else{
            while(var->next!=cll->head){
                printf("%d ",var->data);
                var=var->next;
            }
            printf("%d ",var->data);
        }
    }
    printf("\n");
}

void destroy_list(List* cll)
{
    free(cll);
}