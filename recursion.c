#include <stdio.h>

void insert(int n)
{
	
	if(n!=11)
	{
		insert(n+1);
		printf("%d\t", n);
	}
}
int main()
{
	int i=0;
	insert(i);
}
