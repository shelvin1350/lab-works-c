#include <stdio.h>
void read(int a[], int n)
{
	int i;
	printf("Enter the values of the array: ");
	for(i=0; i<n; i++)
		scanf("%d", &a[i]);	
}
void disp(int a[], int n, int i)
{
	if(i==n)
	{
		return; 
	}

	i++;
	disp(a, n, i);	
	
	printf("%d\t", a[i-1]);
}
int main()
{
	int a[15], i=0, n;
	printf("Enter the limit: ");
	scanf("%d", &n);
	read(a, n);
	
	disp(a, n, i);	
	return 0;	
}
