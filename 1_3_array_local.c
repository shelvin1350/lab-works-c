#include <stdio.h>
int insert(int a[], int pos, int e)
{
	if(pos+1==10)
	{
		printf("\n\nArray is full");
	}
	else 
	{
		a[++pos]=e;
	}
	return pos;
}

int del(int a[], int pos)
{
	if(pos==-1)
	{
		printf("\n\nArray is empty");
	}
	else
	{
		printf("\n\nDeleted element is %d", a[pos--]);
	}
	return pos;
}
void traverse(int a[], int pos)
{
	if(pos==-1)
	{
		printf("\n\nArray is empty");
	}
	else 
	{
		printf("\n\na[%d] = %d", pos, a[pos]);
	}
}
void search(int a[], int pos, int e)
{
	if(pos==-1)
	{
		printf("\nArray is empty!!!");
		
	}
	else
	{
		int i;
		for(i=0; i<=pos+1; i++)
		{
			if(i==pos+1)
			{
				printf("\n\nElement not found!!!!");
				break;
			}
			if(a[i]==e)
			{
				printf("\n\n\nElement found!!\na[%d]=%d", i, e);
				break;
			}
		}
	}
}
void sel_sort(int a[], int pos)
{
	int i, j, temp;
	printf("Elements before sorting: \n");
	for(i=0; i<pos; i++)
	{
		printf("%d \t", a[i]);
	}
	for(i=0; i<=pos; i++)
	{
		for(j=i+1; j<pos; j++)
		{
			if(a[i]>a[j])
			{
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
	}
	printf("\nElements after sorting: \n");
	for(i=0; i<pos; i++)
	{
		printf("%d \t", a[i]);
	}
}
int menu()
{
	int ch;
	printf("\nInsert-1\nDelete-2\nTraverse-3\nSearch-4\nSort-5\nExit-6\nEnter your choice: \t");
	scanf("%d", &ch);
	return ch;
}  
void process()
{
	int ch, e;
	int a[10], pos=-1;
	for(ch=menu(); ch!=6; ch=menu())
	{
		switch(ch)
		{
			case 1:
				printf("\n\nEnter an element to push:\t");
				scanf("%d", &e);
				pos=insert(a, pos, e);
				break;
			case 2:
				pos=del(a, pos);
				break;
			case 3:
				traverse(a, pos);
				break;
			case 4:
				printf("\n\nEnter an element to search: ");
				scanf("%d", &e);
				search(a, pos, e);
				break;
			case 5:
				sel_sort(a, pos);
				break;
			default:
				printf("\n\nError: Invalid input.");
		}	
	}	
}
int main()
{
	process();
	return 0;	
}
  
