/*
https://www.acmicpc.net/problem/1182
*/
#include <stdio.h>
#include <memory.h>

int N;  //원소 개수
int input[22];
int target;
int ans = 0;
int sum = 0;

void solve(int cnt, int idx);

int main() {
	scanf("%d %d", &N, &target);
	for(int i=0; i<N; i++) {
		scanf("%d", &input[i]);
	}

	solve(0, 0);

	printf("%d\n", ans);
	return 0;
}

//다음에 선택할 인덱스와 현재까지 선택한 원소들의 합
void solve(int cnt, int idx) {
	// printf("cnt: %d idx : %d sum : %d\n", cnt, idx, sum);
	if(idx == N)
	{
		if(target == sum && cnt != 0)
		{
			ans++;
		}
		return;	
	}

	sum += input[idx];
	solve(cnt + 1, idx + 1); //현재 인덱스 선택
	sum -= input[idx];
	solve(cnt, idx + 1);  //현재 인덱스 선택안함
}