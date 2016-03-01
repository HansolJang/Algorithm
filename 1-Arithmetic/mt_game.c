#include <stdio.h>

int a, b, c;
int N, K;
char winner[11];

char solve();

int main(void) {

	setbuf(stdout, NULL);

	int T;
	int test_case;

	scanf("%d", &T);
	for(test_case = 1; test_case <= T; test_case++) {

		scanf("%d %d %d", &a, &b, &c);
		for(int i=0; i<c; i++)
		{
			scanf("%d %d", &N, &K);
			winner[i] = solve();
		}

		winner[c] = '\0';
		printf("Case #%d\n", test_case);
		printf("%s\n", winner);        
	}

	return 0;
}

// char solve()
// {
// 	int rem = (N-1) % (K+1); //꼭 말해야하는 숫자
// 	int quo = (N-1) / (K+1); //몇바퀴 도는지
// 	int lost;  // 지는 차례
// 	if(rem == 0)
// 		lost = 1 + 2 * quo;
// 	else
// 		lost = 2 + 2 * quo;

// 	rem = lost % (a + b);
// 	printf("lost : %d, rem : %d, quo : %d\n", lost, rem, quo);
// 	if(rem <= a && rem > 0)
// 		return 'b';
// 	else
// 		return 'a';
// }

char solve()
{
	//a팀입장에서 N-1이 무조건 1*a ~ K*a 사이에 있어야함
	int cur = 0;
	while()
	{
		if(N-1 >= cur + a && N-1 <= cur + K*a)
			return a;
		cur += a; // go a

	}
}