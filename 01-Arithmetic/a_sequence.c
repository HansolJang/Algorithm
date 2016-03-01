#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#define SIZE 111111
#define TRUE 1
#define FALSE 0
#define INF 987654321

typedef int BOOL;

long long int seq[SIZE];
long long int diff[SIZE];
int M;
int ans;
long long int min_diff;
BOOL is_all_same;
BOOL is_each_same;

long long int min(long long int a, long long int b){
	if(a > b)
		return b;
	return a;
}

long long int gcd(long long int a, long long int b){
	if(b == 0)
		return a;
	return gcd(b, b % a);
}

int solve(long long int smallest_diff);

int main(void) {

	setbuf(stdout, NULL);

	int T;
	int test_case;

	scanf("%d", &T);
	for(test_case = 1; test_case <= T; test_case++) {
		// init
		memset(seq, 0, sizeof(seq));
		memset(diff, 0, sizeof(diff));
		is_each_same = FALSE;
		is_all_same = TRUE;
		min_diff = INF;

		// input
		scanf("%d", &M);
		for(int i=0; i<M; i++){
			scanf("%lld", &seq[i]);
			if(i > 0){
				// save & check diff
				diff[i-1] = seq[i] - seq[i-1];
				min_diff = min(diff[i-1], min_diff);
				// check same
				if(seq[i-1] == seq[i])
					is_each_same = TRUE;
				else
					is_all_same = FALSE;
			}
		}

		printf("Case #%d\n", test_case);
		// 모두 같은 수면 공차는 0 하나
		if(is_all_same)
			printf("1\n");
		else{	
			// 일부만 같은 수일 경우 등차 수열 X
			if(is_each_same)
				printf("0\n");
			else{
				// solve
				printf("%d\n", solve(min_diff));
			}
		}

	}

	return 0;
}

int solve(long long int smallest_diff){
	ans = 0;
	for(int divisor=1; divisor <= smallest_diff; divisor++){	
		// 약수이면
		if(smallest_diff % divisor == 0){
			BOOL is_common = TRUE;
			// 모두의 약수인지 검사
			for(int idx=0; idx<M-1; idx++){
				if(diff[idx] % divisor != 0){
					is_common = FALSE;
					break;
				}
			}
			if(is_common == TRUE)
				ans++;
		}
	}
	return ans;
}