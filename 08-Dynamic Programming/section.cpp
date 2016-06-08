//https://www.acmicpc.net/problem/2228
#include <iostream>
#include <algorithm>
#include <memory.h>
using namespace std;
#define INF 987654321
int arr[102];
int d[102][50];
int N, M;
//n개의 수를 m개의 구간으로 나눌 때의 최대 합 반환
int solve(int n, int m) {
	//base condition
	//구간나누기 성공
	if(m == 0)
		return 0;
	//구간나누기 실패
	if(n < 1 || (n == 0 && m != 0))
		return -INF;
	//메모이제이션
	if(d[n][m] != -1)
		return d[n][m];
	//1.구간 포함x
	d[n][m] = 0;
	d[n][m] += solve(n-1, m);
	//2.구간 포함o
	int tmp;
	for(int i = n; i >= 1; i--) {
		tmp = 0;
		for(int j = i; j <= n; j++)
			tmp += arr[j];
		tmp += solve(i - 2, m - 1);		
		d[n][m] = max(d[n][m], tmp)
	}
	return d[n][m];
}
int main() {
	ios_base::sync_with_stdio(false);
	memset(d, -1, sizeof(d));
	cin >> N >> M;
	for(int i = 1; i <= N; i++)
		cin >> arr[i];
	cout << solve(N, M) << '\n';
	return 0;
}