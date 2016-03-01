#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

int compare (const void *a, const void *b)
{
    // const int *ia = (const int *)a; // casting pointer types 
    // const int *ib = (const int *)b;
    return *(int*)a  - *(int*)b; 
}

int num1;
int num2;
int arr1[1111111];
int arr2[1111111];

bool search(int num);

int main() {
	int nCount;	
	int itr;
	scanf("%d", &nCount);

	for(itr=0; itr<nCount; itr++) {
		memset(arr1, 0, sizeof(arr1));
		memset(arr2, 0, sizeof(arr2));
		scanf("%d", &num1);
		for(int i=0; i<num1; i++) {
			scanf("%d", &arr1[i]);
		} 

		qsort(arr1, num1, sizeof(int), compare);
		for(int i=0; i<num1; i++)
		{
			printf("%d ", arr1[i]);
		}
		printf("\n");

		scanf("%d", &num2);
		for(int i=0; i<num2; i++) {
			scanf("%d", &arr2[i]);
		} 

		for(int i=0; i<num2; i++) {
			printf("%d\n", search(arr2[i]));
		}
	}
	return 0;
}

//이진탐색을 진행한다
bool search(int num) {
	int pivot = num1/2;
	int left = 0;
	int right = num1 - 1;

	if(num > arr1[right] || num < arr1[left]) {
		return false;
	}

	//왼쪽이 오른쪽보다 커질때까지 진행 
	while(left <= right) {
		if(arr1[left] == num || arr1[right] == num || arr1[pivot] == num) {
			return true;
		}
		//오른쪽선택
		if(num > arr1[pivot]) {
			left = pivot + 1;
			// if(num < arr1[left] && num > arr1[pivot]) {
			// 	return false;
			// }
			pivot = (left + right) / 2;
		} 
		//왼쪽 선택
		else
		{
			right = pivot - 1;
			// if(num > arr1[right] && num < arr1[pivot]) {
			// 	return false;
			// }
			pivot = (left + right) / 2;	
		}
	}	

	return false;

}