#include <stdio.h>
#include <malloc.h>
struct node 
{
	int data;
	struct node *next;
};

typedef struct node node;

node *head=NULL;
void insert(int e)
{
	if(head==NULL)
	{
		head=(node *)malloc(sizeof(node));
		head->data=e;
		head->next=NULL;
	}
	else
	{
		
		node *t=head;
		while(t->next!=NULL)
		{
			t=t->next;
		}
		t->next=(node *)malloc(sizeof(node));
		t->next->data=e;
		t->next->next=NULL;
	}
}
void sort()
{
	if(head==NULL)
	{
		printf("Empty list!!");
	}
	else
	{
		node *t=head, *t1;
		int temp;
		for(t=head; t->next!=NULL; t=t->next)
		{
			for(t1=t->next; t1!=NULL; t1=t1->next)
			{
				if(t->data > t1->data)
				{
					temp=t->data;
					t->data=t1->data;
					t1->data=temp;
				}
			}
		}
	}
}
void reverse()
{
	if(head==NULL)
	{
		printf("List is empty");
		return;
	}
	node *prev, *curr, *next;
	prev=NULL;
	curr=head;
	while(curr!=NULL)
	{
		next=curr->next;
		curr->next=prev;
		prev=curr;
		curr=next;
	}
	head=prev;

}
void disp()
{
	if(head==NULL)
	{
		printf("List empty");
	}
	else
	{
		node *t=head;
		while(t!=NULL)
		{
			printf("%d\t",t->data);
			t=t->next;
		}
		printf("\n");
	}
}
void main()
{
	insert(10);
	insert(60);
	insert(30);
	insert(40);
	disp();
	sort();
	disp();
	reverse();
	disp();
}

