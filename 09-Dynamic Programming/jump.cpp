//https://www.acmicpc.net/problem/1890
#include <iostream>
#include <memory.h>
using namespace std;
#define SIZE 111
int N;
int board[SIZE][SIZE];
long long d[SIZE][SIZE] = {-1, };
long long solve(int i, int j) {
	if(i == N-1 && j == N-1)	
		return 1;
	if(i >= N || j >= N)
		return 0;
	if(d[i][j] != -1)
		return d[i][j];
	d[i][j] = 0;
	return d[i][j] += (solve(i + board[i][j], j) + solve(i, j + board[i][j]));
}
int main() {
	ios_base::sync_with_stdio(false);
	memset(d, -1, sizeof(d));
	cin >> N;
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++)
			cin >> board[i][j];
	}
	cout << solve(0, 0) << '\n';
	return 0;
}