/*

VC, GCC에서 사용

*/

#include <stdio.h>

void make_binary(int* arr, int idx, int n, int k) {
	int i;
	if(idx == n) {
		int sum = 0;
		for(i=0; i<n; i++) {
			if(arr[i] == 1) sum++;
		}
		if(sum == k) {
			for(i=0; i<n; i++) {
				printf("%d", arr[i]);
			}
			printf("\n");
		}
		return;
	}
	arr[idx] = 1;
	make_binary(arr, idx+1, n, k);
	arr[idx] = 0;
	make_binary(arr, idx+1, n, k);
}

void print_binary(int n, int k) {
	int arr[n];
	make_binary(arr, 0, n, k);
}

int main()
{

	int itr;
	int nCount;		/* 문제의 테스트 케이스 */
	int n, k;
	int arr[33];

	scanf("%d", &nCount);	/* 테스트 케이스 입력 */

	for(itr=0; itr<nCount; itr++)
	{

		printf("#testcase%d\n",itr+1);

		scanf("%d %d", &n, &k);
		
		if(k == 1) {
			for(int i=0; i<n; i++) {
				for(int j=0; j<n; j++) {
					if(i == j) arr[i] = 1;
					else arr[j] = 0;
					printf("%d", arr[j]);
				}
				printf("\n");
			}
		} else {
			print_binary(n, k);
		}

	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */ 

}