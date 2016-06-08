//https://www.acmicpc.net/problem/11066
#include <iostream>
#include <algorithm>
#include <memory.h>
using namespace std;
#define SIZE 501
#define INF 987654321
int K;
int files[SIZE];
int d[SIZE][SIZE];
//index i부터 j까지의 최소 비용 반환
int solve(int i, int j) {
	if(i == j)
		return files[i];
	//합쳤을 경우 비용더하므로*2
	if(i + 1 == j)
		return (files[i] + files[j]) << 1;
	if(d[i][j] != -1)
		return d[i][j];
	int tmp, t1, t2;
	d[i][j] = INF;
	for(int k = i; k < j; k++) {
		tmp = 0;
		//2칸 이상 벌어져있을 경우 비용 더하므로 *2ㄴ
		tmp += (k - i > 1 ? solve(i, k) << 1 : solve(i, k));
		tmp += (j - (k + 1) > 1 ? solve(k + 1, j) << 1 : solve(k + 1, j));
		// cout << i << ' ' << j << ' ' << tmp << '\n';
		d[i][j] = min(d[i][j], tmp);
	}
	return d[i][j];
}
int main() {
	ios_base::sync_with_stdio(false);
	int test_case, fcnt;
	cin >> test_case;
	for(int i = 0; i < test_case; i++) {
		memset(d, -1, sizeof(d));
		memset(files, 0, sizeof(files));
		cin >> fcnt;
		for(int j = 0; j < fcnt; j++)
			cin >> files[j];
		cout << solve(0, fcnt -1) << '\n';
	}
	return 0;
}