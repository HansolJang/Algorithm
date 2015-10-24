#include <stdio.h>

int N;

int solve(int N);  //return the minimum number that makes N a equal number

int main(void) {

	setbuf(stdout, NULL);

	int T;
	int test_case;

	scanf("%d", &T);
	for(test_case = 1; test_case <= T; test_case++) {
		//input
		scanf("%d", &N);

		printf("Case #%d\n", test_case);
		printf("%d\n", solve(N));

	}

	return 0;	// 정상종료 시 반드시 0을 리턴해야 합니다.
}

int solve(int N)
{
	int quo, rem;
	bool is_equal;

	for(int i=2;; i++)
	{
		quo = N;
		rem = quo % i;
		is_equal = true;
		
		while(quo > i)
		{
			quo = quo / i;
			if(rem != quo % i)
			{
				is_equal = false;
				break;
			}
		}

		if(is_equal && quo == rem)
			return i;
	}
}