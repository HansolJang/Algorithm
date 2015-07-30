/*
	https://algospot.com/judge/problem/read/TILING2
*/
#include <stdio.h>
#include <memory.h>

long long int cache[111];

long long int tiling(int num);

int main() {
	int itr;
	int nCount;
	int N;

	scanf("%d", &nCount);

	for(itr=0; itr<nCount; itr++) {
		memset(cache, -1, sizeof(cache));
		scanf("%d", &N);
		printf("%d\n", tiling(N));
	}
	
	return 0;
}

long long int tiling(int num) {
	if(num == 1) {
		return 1;
	}

	if(num == 2) {
		return 2; 
	}

	long long int& ret = cache[num];

	if(ret != -1) {
		return ret;
	}

	ret = (tiling(num-1) % 1000000007 )+ (tiling(num-2) % 1000000007);
	return ret;
	
}