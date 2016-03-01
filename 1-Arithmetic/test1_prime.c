/*

VC, GCC에서 사용

*/

#include <stdio.h>

char input[11111];
int acnt[111];  //65~90
bool isPrime[11111] = {};

void make_prime();

int main()
{

	int itr;
	int nCount;		/* 문제의 테스트 케이스 */

	scanf("%d", &nCount);	/* 테스트 케이스 입력 */
	make_prime(); //소수 세팅

	for(itr=0; itr<nCount; itr++)
	{

		printf("#testcase%d\n",itr+1);
		//초기화
		for(int i=0; i<111; i++)
		{
			acnt[i] = 0;
		}
		int cnt = 0;
		scanf("%s", &input);

		for(int i=0; i<11111; i++)
		{
			if(input[i] == 0)
				break;
			else
				acnt[input[i]] += 1;  //cnt 증가
		}

		for(int i=1; i<111; i++)
		{
			if(acnt[i] != 0 && isPrime[acnt[i]] == true)
			{
				printf("%c", i);
				cnt++;
			}
		}
		if(cnt == 0) printf("NONE");
		printf("\n");

	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */ 

}

void make_prime() {
	bool is_prime;
	for(int i=2; i<10001; i++)
	{
		is_prime = true;
		for(int j=2; j<i; j++)
		{
			if(j*j > i) {
				break;
			}
			if(i % j == 0) {
				is_prime = false;
				break;
			}
		}

		if(is_prime) {
			// printf("%d\n", i);
			isPrime[i] = true;
		}
	}
}