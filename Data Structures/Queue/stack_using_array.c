#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int A[MAX];
int top = -1;

void push()
{
	if (top == MAX - 1)
	{
		printf("Can't Insert! FULL\n");
		return;
	}

	printf("Enter data: ");
	scanf("%d", &A[++top]);
}

void pop()
{
	if (top == -1)
	{
		printf("Empty!\n");
		return;
	}

	printf("data: %d\n", A[top--]);
}

void atTop()
{
	if (top == -1)
	{
		printf("Empty!\n");
		return;
	}
	printf("At the top: %d\n", A[top]);
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