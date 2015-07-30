/*
	https://algospot.com/judge/problem/read/LIS
*/
#include <stdio.h>
#include <memory.h>

#define MAX(a, b) (a) > (b) ? (a) : (b) 

int N;
int input[555];
int cache[555][555];
int length;
int max = 0;
int solve(int idx, int preidx);

int main() {
	int itr;
	int nCount;
	scanf("%d", &nCount);

	for(itr = 0; itr<nCount; itr++) {
		max = 0;
		memset(cache, -1, sizeof(cache));
		scanf("%d", &N);

		for(int i=0; i<N; i++) {
			scanf("%d", &input[i]);
		}

		for(int i=0; i<N-1; i++) {
			length = 0;  //초기화
			length = solve(i, i);
			if(max < length) max = length;
		}
		printf("%d\n", max);
	}
	
	return 0;
}


int solve(int idx, int preidx) {
	// printf("%d %d\n", idx, preidx);
	if(idx == N) {
		return length;
	}

	int& ret = cache[idx][preidx];
	if(ret != -1) {
		// printf("---------caching\n");
		return ret;
	}

	//순증가 할 경우 길이++ 한 후 다음 인덱스를 확인하는 재귀 호출
	//처음 실행할땐 이전인덱스도 자기자신, 자기자신을 길이에 추가한후 다음 인덱스 재귀호출
	if(input[idx] > input[preidx] || idx == preidx) {
		// printf("--------length++\n");
		length++;
		ret = (MAX(length, solve(idx + 1, idx)));
	} else {
		// 순증가하지 않을 경우 다음 인덱스와 새로 비교
		// printf("-----------next\n");
		ret = (MAX(length, solve(idx + 1, preidx)));
	}
}

/*
시작 위치를 인자로 받아 끝까지 다 보면서 가장 긴 부분 순증가 수열의 길이를 반환
solve(int idx){
	length = 0;
	if(idx == N-1) {
		length++;
		return length;
	}

	if

}
*/