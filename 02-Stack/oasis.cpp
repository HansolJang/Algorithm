//https://www.acmicpc.net/problem/3015
#include <cstdio>
#include <vector>
#include <stack>
using namespace std;
vector<long long int> h(500000);

int main() {
	int N, i;
	scanf("%d", &N);
	for(i = 0; i<N; i++)
		scanf("%lld", &h[i]);
	return 0;
}