/*

> < < < > > > < <
와 같은 괄호를 만족하는 최대, 최소 문자 출력하기

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void check_bracket(int idx, char* bracket, int num, char* cnum, char* max, char* min) {
	int i, j;
	int cnt;
	bool is_same;

	if(idx == num+1) {
		printf("max : %s\n", max);
		printf("min : %s\n", min);
		
		if(max[0] == -1 || min[0] == -1) {
			strcpy(max, cnum);
			strcpy(min, cnum);
		} else {
			if(atoi(max) < atoi(cnum)) strcpy(max, cnum);
			if(atoi(min) > atoi(cnum)) strcpy(min, cnum);
		}
		return;
	}

	//ascii 48~57 (0~9)
	for(i=0; i<10; i++) {
		cnum[idx] = i+48;

		if(idx == 0) {
			check_bracket(idx+1, bracket, num, cnum, max, min);
			continue;
		}
		
		if(bracket[idx-1] == '<') {
			if(cnum[idx-1] < cnum[idx]) {

				is_same = false;
				for(j=0; j<idx; j++) {
					if(cnum[j] == 48+i) {
						is_same = true;
						break;
					}
				}
				// for(j=0; j<num+1; j++) {
				// 	printf("%c", cnum[j]);
				// }
				// printf(" is same : %d\n", is_same);

				if(!is_same) check_bracket(idx+1, bracket, num, cnum, max, min);
			}
		} else if(bracket[idx-1] == '>') {
			if(cnum[idx-1] > cnum[idx]) {
				// printf("%s,  %c, used %d : %d\n", cnum, bracket[idx-1], i, used[i]);
				is_same = false;
				for(j=0; j<idx; j++) {
					if(cnum[j] == 48+i) {
						is_same = true;
						break;
					}
				}
				if(!is_same) check_bracket(idx+1, bracket, num, cnum, max, min);
			}
		}
	}

}

int main()
{

	int itr;
	int nCount;		/* 문제의 테스트 케이스 */
	int num;
	char bracket[10];  // 괄호 문자 저장
	int i, j;
	// int used[10] = {};
	char cnum[11] = {};
	char max[15];
	char min[15];

	scanf("%d", &nCount);	/* 테스트 케이스 입력 */

	for(itr=0; itr<nCount; itr++)
	{	
		for(i=0; i<11; i++) {
			min[i] = -1;
			max[i] = -1;
		}

		printf("#testcase%d\n",itr+1);
		scanf("%d", &num);
		for(i=0; i<num; i++) {
			scanf("%s", &bracket[i]);
		}

		check_bracket(0, bracket, num, cnum, max, min);
		for(i=0; i<num+1; i++) {
			printf("%c", max[i]);
		}
		printf("\n");
		for(i=0; i<num+1; i++) {
			printf("%c", min[i]);
		}
		printf("\n");
	}	

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */ 

}




/*

부등호

두 종류의 부등호 기호 ‘<’와 ‘>’가 k 개 나열된 순서열 A가 있다. 
우리는 이 부등호 기호 앞뒤에 서로 다른 한 자릿수 숫자를 넣어서 모든 부등호 관계를 만족시키려고 한다.

예를 들어, 제시된 부등호 순서열 A가 다음과 같다고 하자.

A ⇒ < < < > < < > < >

부등호 기호 앞뒤에 넣을 수 있는 숫자는 0부터 9까지의 정수이며 선택된 숫자는 모두 달라야 한다. 
아래는 부등호 순서열 A를 만족시키는 한 예이다.

3 < 4 < 5 < 6 > 1 < 2 < 8 > 7 < 9 > 0

이 상황에서 부등호 기호를 제거한 뒤, 
숫자를 모두 붙이면 하나의 수를 만들 수 있는데 이 수를 주어진 부등호 관계를 만족시키는 정수라고 한다.
그런데 주어진 부등호 관계를 만족하는 정수는 하나 이상 존재한다. 
예를 들어 3456128790 뿐만 아니라 5689023174도 아래와 같이 부등호 관계 A를 만족시킨다.

5 < 6 < 8 < 9 > 0 < 2 < 3 > 1 < 7 > 4

여러분은 제시된 k 개의 부등호 순서를 만족하는 (k+1) 자리의 정수 중에서 최대값과 최소값을 찾아야 한다. 
앞서 설명한 대로 각 부등호의 앞뒤에 들어가는 숫자는  0, 1, 2, 3, 4, 5, 6, 7, 8, 9 중에서 선택해야 하며 
선택된 숫자는 모두 달라야 한다.
프로그램의 실행시간은 1초를 넘을 수 없다.

입력
첫 줄에 테스트케이스 개수 T가 주어진다. 
다음 줄부터 각 테스트케이스에 대하여, 첫 줄에는 부등호 문자의 개수를 나타내는 정수가 주어진다. 
그 다음 줄에는 k 개의 부등호 기호가 하나의 공백을 두고 한 줄에 모두 제시된다. k 의 범위는 2 <= k <= 9이다.

출력
답을 출력하기 전에 각 테스트케이스의 순서에 따라 “#testcase1”“#testcase2”... 을 출력한다. 
각 테스트케이스에 대하여 제시된 부등호 관계를 만족하는 자리의 최대, 최소 정수를 첫째 줄과 둘째 줄에 각각 출력한다. 
단 아래 예 (1)과 같이 첫 자리가 0인 경우도 정수에 포함되어야 한다. 
모든 입력에 답은 항상 존재하며 출력 정수는 하나의 문자열이 되도록 해야 한다.

입출력 예

입력
2
2
< > 
9
> < < < > > > < <

출력 
#testcase1
897
021
#testcase2
9567843012
1023765489

*/