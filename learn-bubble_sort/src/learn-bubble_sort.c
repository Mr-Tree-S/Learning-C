#include <stdio.h>

#define ARR_LEN 256
#define elemType int

void bubble_sort(elemType arr[], int len){
	elemType temp;
	int i, j;
	for(i=0; i<len-1; i++){
		for(j=0; j<len-1-i; j++){
			if(arr[j]>arr[j+1]){
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
}


int main(void)
{
	elemType arr[ARR_LEN]={6,5,4,7,8,9,3,2,1,0};
	int len=10;
	int i;

	bubble_sort(arr, len);
	for(i=0; i<len; i++){
		printf("%d\n", arr[i]);
	}

	return 0;
}
