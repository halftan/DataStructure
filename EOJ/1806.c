#include <stdio.h>
#include <stdlib.h>

void select_sort(int *arr,int n);
int main(void){
	int i,n;
	int *arr;
	scanf("%d",&n);
	arr = (int*)calloc(sizeof(int),n);
	for(i = 0;i < n;++i)
		scanf("%d",arr + i);
	select_sort(arr,n);
	for(i = 0;i < n;++i)
		printf("%d ",*(arr + i));
	return 0;
}

void select_sort(int *arr,int n){
	int i,j,min,t;
	for(i = 0;i < n - 1;++i){
		min = i;
		for(j = i + 1;j < n;++j)
			if(arr[min] > arr[j])
				min = j;
		if(min != i){
			t = arr[min];
			arr[min] = arr[i];
			arr[i] = t;
		}
	}
}
