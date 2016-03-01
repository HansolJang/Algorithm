/*

VC, GCC에서 사용

*/

#include <stdio.h>

#define SIZE 333333

int N;
int score[SIZE];
int cpy[SIZE];
int rank[111];

void swap(int* arr, int idx1, int idx2);
int partition(int* arr, int left, int right);
void quickSort(int* arr, int left, int right);

int main(){

	int itr;
	int nCount;		/* 문제의 테스트 케이스 */

	scanf("%d", &nCount);	/* 테스트 케이스 입력 */

	for(itr=0; itr<nCount; itr++){
		for(int i=0; i<SIZE; i++){
			score[i] = -1;  //점수
			cpy[i] = -1;
			if(i<111){
				rank[i] = -1;
			}
		}
		printf("#testcase%d\n",itr+1);
		scanf("%d", &N);
		for(int i=1; i<=N; i++){
			scanf("%d", &score[i]);
			cpy[i] = score[i];
		}

		quickSort(cpy, 1, N);
		
		for(int i=1; i<=N; i++){
			if(cpy[i] != cpy[i - 1]){
				rank[cpy[i]] = i;
			}
		}

		for(int i=1; i<=N; i++){
			printf("%d\n", rank[score[i]]);
		}
		printf("\n");

	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */ 

}

void swap(int* arr, int idx1, int idx2){
	int temp = arr[idx1];
	arr[idx1] = arr[idx2];
	arr[idx2] = temp;
}

int partition(int* arr, int left, int right){
	int pivot = arr[left];
	int low = left + 1;
	int high = right;

	while(!(low > high)){
		//low값이 피봇보다 작을때까지
		while(pivot <= arr[low]){
			low++;
		}

		while(pivot > arr[high]){
			high--;
		}

		if(low <= high){
			swap(arr, low, high);
		}
	}

	swap(arr, left, high);
	return high;
}

void quickSort(int* arr, int left, int right){
	if(left <= right){
		int pivot = partition(arr, left, right);
		quickSort(arr, left, pivot - 1);
		quickSort(arr, pivot + 1, right);
	}
}