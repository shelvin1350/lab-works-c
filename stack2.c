#include <stdio.h>
#define max 20
int stack[max], top=-1;
void push(int e)
{
	if(top+1==max)
	{
		printf("stack overflow");
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
		printf("Poped element %d", stack[top--]);
	}
}
int main()
{
	push(45);
	push(59);
	push(40);
	pop();
	pop();
	pop();
	pop();
	return 0;
}
