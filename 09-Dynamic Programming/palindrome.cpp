//https://www.acmicpc.net/problem/10942
#include <iostream>
#include <memory.h>
using namespace std;
#define SIZE 2001
int seq[SIZE];
int d[SIZE][SIZE];
int N, M, s, e;
bool is_palindrome(int s, int e) {
	if(s == e)
		return true;
	if(s + 1 == e) {
		if(seq[s] == seq[e])
			return true;
		return false;
	}
	if(d[s][e] != -1)
		return d[s][e];
	if(seq[s] != seq[e])
		return d[s][e] = false;
	d[s][e] = 1;
	return d[s][e] &= is_palindrome(s + 1, e - 1);
}
int main() {
	ios_base::sync_with_stdio(false);
	memset(d, -1, sizeof(d));
	cin >> N;
	for(int i = 1; i <= N; i++)
		cin >> seq[i];
	cin >> M;
	for(int i = 0; i < M; i++) {
		cin >> s >> e;
		cout << is_palindrome(s, e) << '\n';
	}
	return 0;
}