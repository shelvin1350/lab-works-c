#include <stdio.h>
#include <malloc.h>
struct node{
	int data;
	struct node *next;
};
typedef struct node queue;
queue *f, *r;
void enqueue(int e)
{
	queue *t;
	t=(queue *)malloc(sizeof(queue));
	t->data=e;
	t->next=NULL;
	if(f==NULL)
	{
		f=t;
		r=t;	
	}
	else
	{
		r->next=t;
		r=t;
	}
}
 
void dequeue()
{
	if(f==NULL)
	{
		printf("Queue is empty\n\n");
	}
	else
	{
		printf("%d\n", f->data);
		f=f->next;
		if(f==NULL)
		{
			r==NULL;
		}
	}
}

int main()
{
	enqueue(50);
	enqueue(40);
	enqueue(45);
	enqueue(25);
	dequeue();
	dequeue();
	dequeue();
	dequeue();
	dequeue();
	return 0;
}
