#include <stdio.h>
int i, j;
int a[3][3], b[3][3], c[3][3];
void disp()
{
    for(i=0; i<3; i++)
    {
        for(j=0; j<3; j++)
        {
            printf("\t%d", c[i][j]);
        }
        printf("\n");
    }
}
void ins()
{
    
    printf("Enter elements in first matrix: ");
    for(i=0; i<3; i++)
    {
        for(j=0; j<3; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    printf("Enter elements in the second matrix: ");
    for(i=0; i<3; i++)
    {
        for(j=0; j<3; j++)
        {
            scanf("%d", &b[i][j]);
        }
    }
}
void add()
{
    printf("Addition!!!!!!!!!!!!!\n");
    for(i=0; i<3; i++)
    {
        for(j=0; j<3; j++)
        {
            c[i][j]=a[i][j]+b[i][j];
        }
    }
    printf("Sum of matrix is: \n");
    disp();
}
void sub()
{
    printf("Subraction!!!!!!!!!!!!!\n");

    for(i=0; i<3; i++)
    {
        for(j=0; j<3; j++)
        {
            c[i][j]=a[i][j]-b[i][j];
        }
    }
    printf("Difference of matrix is: \n");
    disp();
}
void mul()
{
    printf("Multiplication!!!!!!!!!!!!!\n");
    int i, j;
    for(i=0; i<3; i++)
    {
        for(j=0; j<3; j++)
        {
            c[i][j]=0;
            c[i][j]=c[i][j]+(a[i][j]*b[j][i]);
        }
    }
    printf("{roduct of matrix is: \n");
    disp();
}
int main()
{
    ins();
    add();
    sub();
    mul();
    return 0;
}