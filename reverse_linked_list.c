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
void rev(list *t)
{
	if(head==NULL)
	{
		return;
	}
	else
	{
		if(t!=NULL)
		{
			rev(t->next);
			printf("%d\t", t->data);
		}
	}
}

void reverse() {
    struct node *prev = NULL;
    struct node *current = head;
    struct node *nextNode = NULL;

    while (current != NULL) {
        nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }

    head = prev;
}
void main()
{
	insert(10);
	
	insert(20);
	
	insert(30);
	rev(head);
	reverse();
	
}
