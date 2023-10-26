#include <stdio.h>
int i, j;
int coefsum[15], expsum[15];
void display(int n, coef[], exp[])
{
	for(i=0; i<n; i++)
	{
		if(exo[i]==0)
		{
			printf("%d", coef[i]);
		}
		else
		{
			printf("%d^%d", coef[i], exp[i]);
		}
		if(i!=n-1)
		{
			printf("+");
		}
	}
	printf("\n");
}
void add(int coef1[], int exp1[], int coef2[], int exp2[], int n1, int n2)
{
	int k=0;
	i=j=0;
	while(i<n1 && i<n2)
	{
		if(exp1[i]==exp2[i])
		{
			expsum[k]=exp1[i];
			coefsum[k]=coef1[i]+coef2[j];
			i++;j++;k++			
		}
		else if(exp1[i]<exp2[j])
		{
			expsum[k]=exp2[j];
			coefsum[k]=coef2[j];
			j++;k++;
		}
		else
		{
			expsum[k]=exp1[i];
			coefsum[k]=coef1[i];
			i++;k++;
		}
	}
	if(i<n1)
	{
		expsum[k]=exp1[i];
		coefsum[k]=coef1[i];
		i++; k++;
	}
	else
	{
		expsum[k]=exp2[j];
		coefsum[k]=coef2[j];
		j++; k++;
	}
	n3=k;
	disp(n, coef1)
}
