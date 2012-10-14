#include <stdio.h>
#include <stdlib.h>

void insertion_sort(int*,int);
int main(void){
	int arr[] = {52,45,1,5,8,1,5,43,1,5,57,8,5212,5,46548,84,15};
	int len = 17;
	int i;
	insertion_sort(arr,len);
	for(i = 0;i < len;++i)
		printf("%d ",arr[i]);
	return 0;
}

void insertion_sort(int* arr, int len){
	int i,j;
	int temp;
	for(i = 1;i < len;++i){
		temp = arr[i];
		j = i - 1;
		while((j >= 0) && (arr[j] > temp)){
			arr[j + 1] = arr[j];
			--j;
		}
		arr[j + 1] = temp;
	}
}
