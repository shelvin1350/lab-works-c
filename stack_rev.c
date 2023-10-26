#include <stdio.h>
#define size 20
char stack[size];
int top=-1;
void push(char item)
{
	if(top+1==size)
	{
		printf("Error!! Stack is full");
		return;
	}
	stack[++top]=item;
}
char pop()
{
	if(top==-1)
	{
		printf("Error!! Stack underflow");
		return '\0';
	}
	return stack[top--];
}
int main()
{
	char ch, n=0;
	printf("Enter a string: ");
	do{
		scanf("%c", &ch);
		push(ch);
		n++;
	}while(ch!='\n');
	
	
	printf("Reverse is  ");
	for(n; n>0; n--)
	{
		printf("%c", pop());
	}
	return 0;
}
