//https://www.acmicpc.net/problem/1456
#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;
int main() {
	long long a, b;
	int sqrtb, ans = 0;
	scanf("%lld %lld", &a, &b);
	sqrtb = sqrt(b);
	vector<bool> is_prime(sqrtb + 1, true);
	//에라토스테네스의 체로 소수 구하기
	for(int i=2; i<=sqrtb; i++) {
		if(is_prime[i]) {
			for(int j = i + i; j <= sqrtb; j+=i)
				is_prime[j] = false;
		}
	}
	//거의 소수 구하기
	for(int i=2; i<=sqrtb; i++) {
		if(is_prime[i]) {
			for(int j=2;; j++) {
				if(pow(i, j) > b) break;
				if(pow(i, j) >= a && pow(i, j) <= b)
					ans += 1;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}