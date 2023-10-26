#include <stdio.h>
int a[15], n=-1;
void heaptree(int e)
{
	int i, t;
	i=++n;
	a[i]=e;
	while(i!=0)
	{
		if(a[i] < a[(i-1)/2])
		{
			break;
		}
		else
		{
			t=a[i];
			a[i]=a[(i-1)/2];
			a[(i-1)/2]=t;
		}
		i=(i-1)/2;
	}
}
void disparr()
{
	int i;
	for(i=0; i<=n; i++)
	{
		printf("%d\t", a[i]);
	}
}

void heapsort()
{
	int i, j, t, lc, rc;
	j=n;
	while(j>0)
	{
	
		i=0;
		t=a[i];
		a[i]=a[j];
		a[j]=t;
		j--;
		while(i<=j)
		{
			lc=(2*i)+1;
			rc=(2*i)+2;
			if(lc<=j && rc<=j)
			{
				if(a[i]>a[lc] && a[i]>a[rc])
				{
					break;					
				}
				else if(a[lc]>a[rc])
				{
					t=a[i];
					a[i]=a[lc];
					a[lc]=t;
					i=lc;
				}
				else
				{
					t=a[i];
					a[i]=a[rc];
					a[rc]=t;
					i=rc;
				}
			}
			else if(lc<=j && a[i]<a[lc])
			{
				t=a[i];
				a[i]=a[lc];
				a[lc]=t;
				i=lc;		
			}
			else
			{
				break;
			}
		}
	}
		
}
int menu()
{
	int ch;
	printf("1-insert\n2-sort elements\n3-Display\nUR choice: ");
	scanf("%d", &ch);
	return ch;
}
void process()
{
	int i, e, j;
	for(i=menu(); i!=4; i=menu())
	{
		switch(i)
		{
			
		
			case 1:
				printf("Enter element to insert");
				scanf("%d", &e);
				heaptree(e);
				break;
			case 2:
				heapsort();
				printf("SORTED!!!!!!!");
				break;
			case 3:
				disparr();
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
