#include<stdio.h>
#include<malloc.h>

int main() {
	
	int n, i;
	int *arr;
	
	printf("Enter array size : ");
	scanf("%d", &n);
	
	arr = (int *)malloc(sizeof(int) * n);
	printf("\n\n Using malloc \n\n");
	for(i = 0; i< n; i++) {
		
		printf("%d, ", arr[i]);
	}
	
	arr = (int *)calloc(n, sizeof(int));
	printf("\n\n Using calloc \n\n");
	for(i = 0; i< n; i++) {
		
		printf("%d, ", arr[i]);
	}
	
	printf("\n\n");
	for(i = 0; i< n; i++) {
		
		scanf("%d", &arr[i]);
	}
	
	printf("Enter new array size : ");
	scanf("%d", &n);
	
	arr = (int *)realloc(arr, sizeof(int) * n);
	
	for(i = 0; i< n; i++) {
		
		printf("%d, ", arr[i]);
	}
	
	
}
