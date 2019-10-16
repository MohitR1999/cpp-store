#include<iostream>
#include<stdlib.h>
using namespace std;

class Node{
public:
Node* next;
int data;
};

class llist{
public:
Node* head=new Node;
llist(){
head=NULL;
}
Node* createnode(int value);
void push(int val);
void pop();
void display();
};



int main(){
int i,value;
llist obj;
while(1){
cout<<"\n\n1.PUSH ELEMENT TO STACK\n2.POP ELEMENT FROM STACK\n3.DISPLAY STACK(DEMO PURPOSE)\n4.EXIT\n\nCHOOSE YOUR OPTION : ";
cin>>i;
switch(i){
case 1: 
cout<<"\nEnter Value you want to insert : ";
cin>>value;
obj.push(value);
break;
case 2:
obj.pop();

break;
case 3:
obj.display();
break;
case 4:
exit(0);
break;
}
}
}
//creating the node
Node* llist::createnode(int value){
Node* temp = new Node;
temp->data = value;
return temp;
}

//push operation
void llist::push(int val){
Node* temp = createnode(val);
temp->next = head;
head = temp;
cout<<"\n\nELEMENT ADDED\n\n";
}
//pop operation
void llist::pop(){
if(head==NULL){
cout<<"\n\nUNDERFLOW\n\n";
return;
}
Node*ptr;
ptr = head;
head = ptr->next;
cout<<"\n\nElement "<<ptr->data<<" popped out\n\n";
delete ptr;
}
//PRINTING THE STACK FOR DEMONSTRATION PURPOSE ONLY !
void llist::display(){
Node* ptr = head;
if(head==NULL){
cout<<"\n\nSTACK EMPTY\n\n";
return;
}
while(ptr!=NULL){
cout<<ptr->data<<" ";
ptr = ptr->next;
}
cout<<"\n\n";
}
