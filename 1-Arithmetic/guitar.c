/*
https://www.acmicpc.net/problem/1049
*/
#include <stdio.h>

#define INF 987654321

int N, M;
int minPack, minEach = INF;
int pack, each;
int ans = 0;

int main()
{
	scanf("%d %d", &N, &M);
	for(int i = 0; i < M; i++) {
		scanf("%d %d", &pack, &each);
		if(pack < minPack)
			minPack = pack;
		if(each < minEach)
			minEach = each;
	}

	if(minPack < minEach * 6) {
		ans = minPack * (int)(N / 6) + minEach * (N % 6);
	} else {
		ans = minEach * N;
	}
	printf("%d\n", ans);
}