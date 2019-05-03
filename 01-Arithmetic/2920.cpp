// https://www.acmicpc.net/problem/2920
#include <cstdio>
using namespace std;
int main() {
	int isAscending = 1;
	int pre = 0;
	int temp = 0;
	for (int i = 0; i < 8; i++) {
		pre = temp;
		scanf("%d", &temp);
		if (i == 0) continue;
		if (i == 1) {
			isAscending = temp > pre ? 1 : 0;
		} else {
			if (isAscending == 1 && temp < pre) {
				isAscending = -1;
			} else if (isAscending == 0 && temp > pre) {
				isAscending = -1;
			}
		}
	}
	printf("%s\n", isAscending == 1 ? "ascending" : isAscending == 0 ? "descending" : "mixed");
	return 0;
}