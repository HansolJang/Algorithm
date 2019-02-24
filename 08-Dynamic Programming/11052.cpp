//https://www.acmicpc.net/problem/11052
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n;
int card_pack[1001] = {0, };
int cache[1001] = {-1, };

int solve(int card_count) {
	if(card_count >= n) {
		if(card_count == n) return 0;
		else return -987654321;
	}
	if(cache[card_count] != -1) 
		return cache[card_count];
	cache[card_count] = 0;
	for(int i = 1; i <= n; i++)
		cache[card_count] = max(cache[card_count], card_pack[i] + solve(card_count + i));
	return cache[card_count];
}

int main() {
	memset(cache, -1, sizeof(cache));
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) 
		scanf("%d", &card_pack[i]);
	printf("%d\n", solve(0));
}