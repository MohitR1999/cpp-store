#include<iostream>
using namespace std;
 class node{
  public:
    int data;
    node* next;
    node(int data){
    this->data=data;
    next=NULL;
   }
 };

 void insert_ll(node** bucket,int position,int element){
   node* newNode=new node(element);
   node*q;
   if(bucket[position]==NULL){
     bucket[position]=newNode;
     bucket[position]->next=NULL;
   }
   else{
   node* temp=bucket[position];
   node* q=NULL;
   if(bucket[position]->data>element){
   node* newNode=new node(element);
   newNode->next=bucket[position];
   bucket[position]=newNode;
    return;
 }
 while(temp!=NULL){
 if(temp->data>element){
 node* newNode=new node(element);
 q->next=newNode;
 newNode->next=temp;
 return;
 }
 q=temp;
 temp=temp->next;
 }
 node* newNode=new node(element);
 q->next=newNode;
 newNode->next=temp;
   }
}
int* Helper(int*arr,node** bucket,int n,int exp){
   for(int i=0;i<n;i++){
      insert_ll(bucket,((arr[i]/exp)%10),arr[i]);
   }
   int count=0;
   for(int i=0;i<10;i++){
     while(bucket[i]!=NULL){
       arr[count++]=bucket[i]->data;
       bucket[i]=bucket[i]->next;
   }
   }
   return arr;
}
int* RadixSort(int*arr,node**bucket,int n,int m){
    for(int e=1;m/e>0;e*=10){
       arr=Helper(arr,bucket,n,e);
    }
    return arr;
}
 int main(){
     int n;
     cout<<"Enter limit:";
     cin>>n;
     cout<<"\nEnter array elements:";
     int* arr=new int[n];
     for(int i=0;i<n;i++){
        cin>>arr[i];
     }
     node** bucket=new node*[n];
     for(int i=0;i<10;i++){
        bucket[i]=new node(0);
        bucket[i]=NULL;
    }
    int mx=arr[0];
    for(int i=1;i<n;i++){
       if(mx<arr[i]){
         mx=arr[i];
       }
    }
    arr=RadixSort(arr,bucket,n,mx);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
     }

 }

