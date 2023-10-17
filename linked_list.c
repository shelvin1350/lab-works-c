#include <stdio.h>
#include <malloc.h>
struct node{
	int data;
	struct node *next;
};

typedef struct node stack;
stack *top=NULL;
void push(int e){
	stack *t=(stack *)malloc(sizeof(stack));
	t->data=e;
	t->next=top;
	top=t;
}

void pop()
{
	if(top==NULL)
	{
		printf("Empty!!\n");
	}
	else
	{
		printf("Poped element is %d\n", top->data);
		top=top->next;
	}
}
void peek()
{
	if(top==NULL)
	{
		printf("Empty!!\n");
	}
	else
	{
		printf("%d\n", top->data);
	}
}
void main()
{
	push(20);
	push(30);
	peek();
	push(40);
	peek();
	pop();
	peek();
	pop();
	pop();
	peek();
}
