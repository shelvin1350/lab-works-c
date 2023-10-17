#include <stdio.h>
#include <malloc.h>

struct node{
	int data;
	struct node *next;
};
typedef struct node stack;
stack *top;
void push(int e)
{
	stack *t=(stack *)malloc(sizeof(stack));
	t->data=e;
	t->next=top;
	top=t;
}

void pop()
{
	if(top==NULL)
	{
		printf("Stack Underflow");
	}
	else
	{
		printf("Deleted element is %d", top->data);
		top=top->next;
	}
}

int main()
{
	push(30);
	push(40);
	push(50);
	pop();
	pop();
	pop();
	pop();
	return 0;	
}
