//https://www.acmicpc.net/problem/6679
#include <cstdio>
using namespace std;

int getRestSum(int num, int dec) {
	int temp = num;
	int res = 0;
	while(temp > 0) {
		res += temp % dec;
		temp /= dec;
	}
	return res;
}

int main() {
	for(int i = 1000; i < 10000; i++) {
		int sum10 = getRestSum(i, 10);
		if(sum10 == getRestSum(i, 12) 
			&& sum10 == getRestSum(i, 16)) {
			printf("%d\n", i);
		}
	}
	return 0;
}