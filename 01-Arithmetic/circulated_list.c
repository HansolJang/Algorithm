#include <stdio.h>

int N, P;
int next;
int arr[1111111];
bool is_end;

int get_next(int num);  //다음 원소 반환

int main(){

	int itr;
	int nCount;		/* 문제의 테스트 케이스 */

	scanf("%d", &nCount);	/* 테스트 케이스 입력 */

	for(itr=0; itr<nCount; itr++){

		is_end = false;
		printf("#testcase%d\n",itr+1);

		scanf("%d %d", &N, &P);
		arr[0] = N;

		for(int i=1;; i++){
			next = get_next(arr[i-1]);
			for(int j=0; j<i; j++){
				if(arr[j] == next){
					printf("%d\n", j);
					is_end = true;
					break;
				}
			}
			if(is_end){
				break;
			}
			// printf("%d\n", next);
			arr[i] = next;
		}

	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */ 

}

int get_next(int num)
{
	// printf("---------start : %d\n", num);
	int digit;
	int temp;
	int ret = 0;
	while(1){
		digit = num % 10;
		temp = digit;
		// printf("d : %d\n", digit);
		for(int i=0; i<P-1; i++){
			temp *= digit;
		}

		// printf("%d\n", temp);
		ret += temp;

		if(num / 10 > 0){
			num /= 10;
		}
		else{
			break;
		}
	}
	return ret;
}



/*
[사용가능 Header / Import File]
C/C++ - stdio.h , iostream 
Java - Scanner

제한시간 : 1초



소프트웨어 멤버십의 김삼성 회원은 정수론에 대해 공부를 하다 새로운 수열을 만들어 냈다.

이 수열을 만들기 위해서는 시작 숫자 N과 제곱수 P가 필요하다. N과 P가 정해지면, 수열의 첫 원소는 N이 되고, 
두 번째 원소는 첫 원소의 각 자릿수에 P제곱을 한 숫자들의 합이 됩니다. 
세 번째 원소도 두 번째 원소의 각 자릿수에 P제곱을 한 숫자들의 합으로 구할 수 있습니다.
예를 들어, N=57, P=2인 경우를 생각해봅시다. 수열의 첫 원소는 57이고, 두 번째 원소는 5×5+7×7=74가 됩니다. 
세 번째 원소는 7×7+4×4=65, 네 번째 원소는 6×6+5×5=61이 되는 식입니다. 
이런 방식으로 수열을 구해보면 57, 74, 65, 61, 37, 58, 89, 145, 42, 20, 4, 16, 37, 58, 89, … 가 됩니다. 

그런데, 김삼성 회원은 수열의 원소들이 순환하고 있음을 발견하였고, 
순환이 이루어지지 않은 앞쪽 부분 수열의 길이를 알고 싶어졌습니다. 김삼성 회원들 도와줍시다.

[입력]
첫번째 줄 테스트 케이스 입력
각 테스트 케이스의 첫 줄에 수열의 시작 숫자 N과 제곱수 P가 공백으로 분리되어 주어진다. (2 ≤ N ≤ 9999, 2 ≤ P ≤ 5)
 [출력]
첫째 줄에 #testcaseN의 형태와 같이 번호를 출력한다.
각 테스트 케이스의 첫 줄에 주어진 수열에서 순환되지 않은 앞쪽 부분 수열의 길이를 출력한다.

-입출력 예-
<입력 예>
1
57 2

<출력 예>
#testcase1
4
*/