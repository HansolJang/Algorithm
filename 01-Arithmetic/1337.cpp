//https://www.acmicpc.net/problem/1337
#include <cstdio>
#include <algorithm>
using namespace std;
int input[10001];
int diff[10001];
int inf = 1000000000;
int main() {
	int n;
	scanf("%d", &n);
	for(int i=0; i<n; i++)
		scanf("%d", &input[i]);
	//정렬
	sort(input, input + n);
	//diff 배열 설정
	for(int i=0; i<n; i++) {
		if(i == 0)
			diff[0] = 0;
		else
			diff[i] = input[i] - input[i - 1];
	}
	//구간의 합이 4보다 작은 부분 집합 중 원소의 개수가 가장 많은 것 찾기
	int minsum = inf;
	int mincnt = 0;
	int minidx = 0;
	int tsum, tcnt;
	for(int i=0; i<n; i++) {
		tcnt = 1;
		tsum = 0;
		for(int j=1; j<5; j++) {
			if(i + j < n) {
				tsum += diff[i + j];
				tcnt += 1;
				if(tsum <= 4) {
					if(mincnt < tcnt) {
						mincnt = tcnt;
						minidx = i;
						minsum = tsum;
					}
				}
			}
		}
	}
	int ans = 0;
	int anscnt = mincnt;
	//가운데가 비었을 경우 채워 넣기
	for(int i=1; i<mincnt; i++) {
		if(diff[minidx + i] > 1) {
			ans += diff[minidx + i] - 1;
			anscnt += diff[minidx + i] - 1;
		}
	}
	//다 채웠을 때도 5개가 안될 경우
	if(anscnt < 5)
		ans += 5 - anscnt;
	printf("%d\n", ans);
	return 0;
}