/*
	https://www.acmicpc.net/problem/1527
*/
#include <stdio.h>

int shom[333] = {};
int arr[10] = {};
int s_cnt = 0; //254
int ans = 0;
void make_shom(int* arr, int idx, int n);

int main() {
	//shom 수 세팅
	for(int i=1; i<8; i++) {
		make_shom(arr, 0, i);
	}

	int N;

	scanf("%d", &N);

	for(int i=0; i<s_cnt; i++) {
		if(shom[i] > N) {
			printf("%d\n", shom[i-1]);
			break;
		}
	}

	return 0;
}

void make_shom(int* arr, int idx, int n) {
	int mul = 1;
	if(idx == n) {
		for(int i=1; i<=n; i++) {
			if(i==1) {
				shom[s_cnt] = arr[n-i];
			} else {
				mul *= 10;
				shom[s_cnt] += arr[n-i] * mul; 
			}
			
		}
		// printf("%lld\n", shom[s_cnt]);
		s_cnt++;
		return;
	}

	arr[idx] = 4;
	make_shom(arr, idx+1, n);
	arr[idx] = 7;
	make_shom(arr, idx+1, n);
}