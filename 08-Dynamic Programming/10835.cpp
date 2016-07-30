//https://www.acmicpc.net/problem/10835
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n;
int left[2000];
int right[2000];
int d[2000][2000];
int solve(int l, int r) {
	if(l == n || r == n)
		return 0;
	if(d[l][r] != -1)
		return d[l][r];
	d[l][r] = 0;
	if(left[l] > right[r])
		d[l][r] = right[r] + solve(l, r + 1);
	d[l][r] = max(d[l][r], solve(l + 1, r));
	d[l][r] = max(d[l][r], solve(l + 1, r + 1));
	return d[l][r];
}
int main() {
	memset(d, -1, sizeof(d));
	scanf("%d", &n);
	for(int i=0; i<n; i++) scanf("%d", &left[i]);
	for(int i=0; i<n; i++) scanf("%d", &right[i]);
	printf("%d\n", solve(0, 0));
	return 0;
}	