#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node* next;
};

struct node* head = NULL;

void push()
{
	struct node* temp = (struct node* )malloc(sizeof(struct node));
	printf("Enter data: ");
	scanf("%d", &temp->data);
	if (head == NULL)
	{
		head = temp;
		return;
	}
	temp->next = head;
	head = temp;
}

void pop()
{
	if (head == NULL)
	{
		printf("Empty!\n");
		return;
	}
	printf("data: %d\n", head->data);
	struct node* temp = head;
	head = head->next;
	free(temp);
}

void atTop()
{
	if (head == NULL)
	{
		printf("Empty!\n");
		return;
	}
	printf("At the top: %d\n", head->data);
}

int main()
{
	int choice;
	
	while(1)
	{
		printf("1. Push\n2. Pop\n3. At top\n4. Exit\n\nEnter Choice: ");
	scanf("%d", &choice);
		switch(choice)
		{
			case 1: 
				push();
				break;
			case 2:
				pop();
				break;
			case 3:
				atTop();
				break;
			default:
				exit(0);
		}
	}

}