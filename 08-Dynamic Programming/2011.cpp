//https://www.acmicpc.net/problem/2011
#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
using namespace std;
string input;
int d[5001];
int len;
//문자열의 idx번째에서의 가능한 경우의 수 리턴
int solve(int idx) {
	if(idx == len)
		return 1;
	if(idx > len)
		return 0;
	if(d[idx] != -1)
		return d[idx];
	d[idx] = 0;
	int t = (input[idx] - '0') * 10 + (input[idx + 1] - '0');
	if(t >= 10 && t <= 26)
		d[idx] += (solve(idx + 2) % 1000000);
	if(input[idx] - '0' > 0)
		d[idx] += (solve(idx + 1) % 1000000);
	return d[idx] %= 1000000;
}
int main() {
	memset(d, -1, sizeof(d));
	cin >> input;
	len = input.length();
	printf("%d\n", solve(0));
	return 0;
}