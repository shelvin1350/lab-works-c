#include <stdio.h>

int a[5]={5,4,3,2,1};
void sort()
{
	int i, j, t;
	for(i=0; i<5; i++)
	{
		printf("%d\t", a[i]);
	}
	
	for(i=0; i<5-1; i++)
	{
		for(j=i+1; j<5; j++)
		{
			if(a[j]<a[i])
			{
				t=a[i];
				a[i]=a[j];
				a[j]=t;
			}
		}
	}
	for(i=0; i<5; i++)
	{
		printf("%d\t", a[i]);
	}
	printf("\n");
}
int main()
{
	sort();
}
