//https://www.acmicpc.net/problem/2352
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n;
int port[40001];
int lis[40001]; //길이가 n인 lis의 마지막 숫자 저장
int bsearch(int key, int len) {
	int low = 1;
	int high = len;
	int mid;
	while(low <= high) {
		mid = (low + high) / 2;
		if(key > lis[mid])
			low = mid + 1;
		else if(key < lis[mid])
			high = mid - 1;
		else
			return mid;
	}
	return low;
}
int main() {
	scanf("%d", &n);
	for(int i=1; i<=n; i++)
		scanf("%d", &port[i]);
	int pos, len = 0;
	lis[++len] = port[1];
	for(int i=2; i<=n; i++) {
		if(lis[len] < port[i])
			lis[++len] = port[i];
		else if(lis[len] > port[i]) {
			pos = bsearch(port[i], len);
			lis[pos] = port[i];
		}
	}
	printf("%d\n", len);
	return 0;
}