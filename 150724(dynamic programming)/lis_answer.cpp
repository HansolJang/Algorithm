/*
https://algospot.com/judge/problem/read/LIS

*/
#include <stdio.h>
#include <memory.h>

#define SIZE 555
#define MAX(a,b) (a) > (b) ? (a) : (b)

int N;
int input[SIZE];
int cache[SIZE];

int lis(int start);

int main() {
	int itr;
	int nCount;

	scanf("%d", &nCount);

	for(itr=0; itr<nCount; itr++) {
		memset(cache, -1, sizeof(cache));
		scanf("%d", &N);
		for(int i=0; i<N; i++) {	
			scanf("%d", &input[i]);
		}

		int maxV = -1;
		for(int start=0; start<N; start++) {
			maxV = (MAX(maxV, lis(start)));
		}

		printf("%d\n", maxV);
	}

	return 0;
}

//start 인덱스에서 시작하는 가장 긴 부분증가수열 길이 리턴
int lis(int start) {

	//인덱스를 벗어나면
	if(start < 0 || start >= N) {
		return 0;
	}

	int& ret = cache[start];

	if(ret != -1) {
		return ret;
	}

	//자기자신을 무조건 포함하므로 최소길이 1
	ret = 1;

	for(int next=start+1; next<N; next++) {
		//현재 시작 값보다 크면 부분증가수열의 다음 인자로 선택될 수 있음
		if(input[next] > input[start]) {
			//하나를 선택 -> 자기자신 더하기 + 1
			//선택했을 때의 길이들중 가장 긴 길이 리턴
			ret = (MAX(ret, 1 + lis(next)));
		}
	}

	return ret;
}