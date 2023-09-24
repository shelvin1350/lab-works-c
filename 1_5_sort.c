#include <stdio.h>
int a[15];
void read(int n)
{
    int i;
    printf("Enter %d elements: ", n);
    for(i=0; i<n; i++)
    {
     scanf("%d", &a[i]);
    }
}
void display(int n)
{
    int i;
    printf("\nElements in the array are: ");
    for (i=0; i<n; i++)
    {
        printf("\t%d", a[i]);
    }
}
void sort(int n)
{
    int i, j, temp;
    for(i=0; i<n; i++)
    {
        for(j=0; j<n-i-1; j++)
        {
            if(a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
    printf("\nSorting complete....\n");
}
int main()
{
    int n;
    printf("\nEnter the limit: ");
    scanf("%d", &n);
    read(n);
    printf("\nBefore sorting......");
    display(n);
    sort(n);
    printf("\nAfter sorting......");
    display(n);
    return(0);
}
