// https://www.acmicpc.net/problem/10039
#include <cstdio>
using namespace std;

int main() {
	int sum = 0;
	int temp = 0;
	for(int i = 0; i < 5; i++) {
		scanf("%d", &temp);
		sum += temp < 40 ? 40 : temp;
	}
	printf("%d\n", sum / 5);
	return 0;
}