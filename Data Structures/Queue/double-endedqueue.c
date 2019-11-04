#include<stdio.h>
#include<stdlib.h>
typedef struct Queue{
	int front;
	int rear;
	int size;
	int* arr;
	//int arr[100];
}queue;
void main(){
	queue* ptr;	
	queue* innit();
	int key;
	void enqueue_front(queue*,int);
	void enqueue_rear(queue*,int);
	void dqueue_front(queue*);
	void dqueue_rear(queue*);
	void print(queue*);
	int isempty(queue*);
	int isfull(queue*);
	void destroy(queue*);
	ptr=innit();
	int ch;
	do{
		printf("Enter you choice: \n");
		scanf("%d",&ch);	
		switch(ch){
			case 1: printf("Enqueue_front \n");
				printf("Enter the value \n");
				scanf("%d",&key); 
				enqueue_front(ptr,key);
				break;
			case 2: printf("Enqueue_rear \n");
				printf("Enter the value \n");
				scanf("%d",&key); 
				enqueue_rear(ptr,key);
				break;
			case 3: printf("dequeue_front \n");
				dqueue_front(ptr);
				break;
			case 4: printf("Dequeue_rear \n");
				dqueue_rear(ptr);
				break; 
			case 5: printf("print \n");
				print(ptr);
				break;
			default:printf("Enter '0' for exit \n Enter valid choice: \n");
				break;
		}
	}
	while(ch!=0);	
	destroy(ptr);
}
queue* innit(){
	queue* ptr=(queue*)malloc(sizeof(queue));
	printf("Enter size \n");
	scanf("%d",&ptr->size);
	ptr->front=ptr->rear=-1;
	ptr->arr=(int*)calloc(sizeof(int),ptr->size);
	return(ptr);
}
int isempty(queue* ptr){
	if (ptr->front==-1){
		return(1);
	}	
	return(0);
}
int isfull(queue* ptr){
	if (ptr->rear+1==ptr->front || ptr->rear==ptr->size-1 && ptr->front==0){
		return(1);
	}
	return(0);
}
void enqueue_front(queue* ptr, int key){
	if(isempty(ptr)){
		ptr->front=ptr->rear=0;
		ptr->arr[ptr->front]=key;
	}
	else if(isfull(ptr)){
		printf("FULL Bro \n");
	}
	else{
		ptr->front=((ptr->front )+ (ptr->size-1)) % (ptr->size);
		ptr->arr[ptr->front]=key;
	}
}
void enqueue_rear(queue* ptr, int key){
	if(isempty(ptr)){
		ptr->front=ptr->rear=0;
		ptr->arr[ptr->rear]=key;
	}
	else if(isfull(ptr)){
		printf("FULL Bro \n");
	}
	else{
		ptr->rear=((ptr->rear)+1) % (ptr->size);
		ptr->arr[ptr->rear]=key;
	}
}
void dqueue_front(queue* ptr){
	if(isempty(ptr)){
		printf("Cant BRO \n");
	}
	else if(ptr->front==ptr->rear){
		ptr->front=ptr->rear=-1;
	}
	else{		
		ptr->front=((ptr->front)+1) % (ptr->size);
	}
}
void dqueue_rear(queue* ptr){
	if(isempty(ptr)){
		printf("Cant Bro \n");
	}
	else if(ptr->front==ptr->rear){
		ptr->front=ptr->rear=-1;	
	}
	else{
		ptr->rear=((ptr->rear)+(ptr->size)-1) % (ptr->size);
	}
}
void print(queue* ptr){
	int frt=ptr->front;
	if(isempty(ptr)){
		printf("Cant BRO \n");
	}
	else{
		while(frt!=ptr->rear){					
			printf("%d \n",ptr->arr[frt]);
			frt=(frt+1) % (ptr->size);
		}
		printf("%d \n",ptr->arr[frt]);
	}
}
void destroy(queue* ptr){
	free(ptr->arr);
	free(ptr);
}
	
	
