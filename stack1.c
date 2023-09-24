#include <stdio.h>
int stack[10], top=-1;
void push(int e)
{
	if(top+1==10)
	{
		printf("Stack overflow");
	}
	else
	{
		stack[++top]=e;
	}
}
void pop()
{
	if(top==-1)
	{
		printf("Stack underflow");
	}
	else
	{
		printf("Poped element is %d", stack[top--]);
	}
}
void peak()
{
	if(top==-1)
	{
		printf("Stack underflow");
	}
	else
	{
		printf("Element at the top is %d", stack[top--]);
	}
}
int menu()
{
	int ch;
	printf("push-1\npop-2\npeek-3\nExit-4\nEnter your choice: \t");
	scanf("%d", &ch);
	return ch;
}
void process()
{
	int ch, e;
	int i;
	for(ch=menu(); ch!=4
	; ch=menu())
	{
		switch(ch)
		{
			case 1:
				printf("Enter the element to push: ");
				scanf("%d", &e);
				push(e);
				break;
			case 2: 
				pop();
				break;
			case 3:
				peak();
				break;
			default: 
				printf("Invalid input");
		}
	}
}
int main()
{
	process();
}
