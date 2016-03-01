#include <stdio.h>

int cnt_zero, cnt_one;

int fibonacci(int n) {
    if (n == 0) {
        cnt_zero += 1;
        return 0;
    } else if (n == 1) {
        cnt_one += 1;
        return 1;
    } else {
    	return fibonacci(n-1) + fibonacci(n-2);
    }
}

int main() {
	int itr, nCount, n;
	scanf("%d", &nCount);
	for(itr = 0; itr < nCount; itr++) {
		cnt_zero = 0;
		cnt_one = 0;
		scanf("%d", &n);
		fibonacci(n);
		printf("%d %d\n", cnt_zero, cnt_one);
	}
	return 0;
}