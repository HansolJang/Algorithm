/*
https://www.acmicpc.net/problem/2565
*/
#include <stdio.h>
#include <memory.h>

#define MAX(a,b) (a) > (b) ? (a) : (b)

int wire[555];
int cache[555];
int N;  //전기줄 갯수
int max = 0;  //왼쪽 전깃줄 번호중 가장 큰 수
int lis(int idx);

int main() {
	memset(wire, -1, sizeof(wire));
	memset(cache, -1, sizeof(cache));
	scanf("%d", &N);
	int a, b;
	for(int i=1; i<=N; i++)	{
		scanf("%d %d", &a, &b);
		wire[a] = b;
		if(a > max)	{
			//인덱스로 사용할 전깃줄의 번호중 가장 큰 수 
			max = a;
		}
	}
	int maxLis = -1;
	for(int i=1; i<=max; i++) {
		if(wire[i] != -1) {
			maxLis = (MAX(maxLis, lis(i)));
		}
	}
	printf("%d\n", N - maxLis);
	return 0;
}

//idx에서 시작하는 최대부분증가수열의 길이 반환
int lis(int idx) {
	// printf("%d\n", idx);
	if(idx > max)
		return 0;
	int& ret = cache[idx];
	if(ret != -1)
		return ret;
	ret = 1;
	for(int i=idx+1; i<=max; i++) {
		// -1은 사용하지않는 전깃줄
		if(wire[i] != -1) {
			if(wire[i] > wire[idx])
				ret = (MAX(ret, 1 + lis(i)));
		}
	}
	return ret;
}