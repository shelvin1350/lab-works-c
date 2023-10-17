#include <stdio.h>
#include <malloc.h>
struct node{
	int data;
	struct node *next;
};

typedef struct node queue;
queue *f=NULL, *r=NULL;

void enqueue(int e)
{
	queue *t=NULL;
	t=(queue *)malloc(sizeof(queue));
	t->data=e;
	t->next=NULL;
	if(f=NULL)
	{
		f=t;
		r=t;
	}
	else
	{
		t->next=r;
		r=t;
	}	
}
void dequeue()
{
	if(f==NULL)
	{
		printf("Empty list !!");
	}
	else 
	{
		printf("Enqueued element is %d", r->data);
		r=r->next;
	}
}
void main()
{
	
}
