#include <stdio.h>
#include <stdlib.h>
struct node
{
	int data;
	struct node *next;
	struct node *prev;
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
		head->prev=NULL;
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
		t->next->prev=t;
	}
}
void display()
{
	if(head==NULL)
	{
		printf("Empty");
	}
	else
	{
		node *t=head;
		while(t!=NULL)
		{
			printf("%d\t", t->data);
			t=t->next;
		}
		printf("\n");
	}
}
//void delete(int e)
//{
//	if(head==NULL)
//	{
//		printf("Empty");
//	}
//	else
//	{
//		if(head->data==e && head->next==head)
//		{
//			
//			head=NULL;
//		}
//		else if(head->data==e)
//		{
//			node *t=head;
//			while(t->next!=head)
//			{
//				t=t->next;
//			}
//			t->next=head->next;
//			head=head->next;
//		}
//		else
//		{
//			node *t=head;
//			while(t->next!=head && t->next->data==e)
//			{
//				t=t->next;
//			}
//			if(t->next==head)
//			{
//				printf("Element not found");
//			}
//			else
//			{
//				t->next=t->next->next;
//			}
//		}
//	}
//}
void main()
{
	insert(20);
	insert(30);
	insert(40);
	display();
//	delete(20);
//	display();
//	delete(30);
//	display();
//	delete(40);
//	display();
}
