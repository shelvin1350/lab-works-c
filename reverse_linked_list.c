#include <stdio.h>
#include <malloc.h>
struct node{
	int data;
	struct node *next;
};
typedef struct node list;
list *head=NULL;
void insert(int e)
{
	list *t;
	if(head==NULL)
	{
		head=(list *)malloc(sizeof(list));
		head->data=e;
		head->next=NULL;
	}
	else
	{
		t=head;
		while(t->next!=NULL)
		{
			t=t->next;
		}
		t->next=(list *)malloc(sizeof(list));
		t->next->data=e;
		t->next->next=NULL;
	}
}
void display()
{
	if(head==NULL)
	{
		printf("List Empty");
	}
	else
	{
		list *t;
		t=head;
		while(t!=NULL)
		{
			printf("%d\t", t->data);
			t=t->next;
		}
	}
}
void delete(int e)
{
	list *t;
	t=head;
	if(head==NULL)
	{
		printf("The list is empty");
	}
	else if(t->next==NULL)
	{
		if(t->data!
		head=NULL;
	}
	else
	{
		while(t->next!=NULL && t->next->data==e)
		{
			t=t->next;
		}
		t=t->next;
	}
}
void main()
{
	insert(10);
	display();
	insert(20);
	display();
	insert(30);
	display();
	delete(10);
	display();
	delete (20);
	display();
}
