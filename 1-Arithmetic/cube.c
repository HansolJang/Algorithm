#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/*
1. 약수를 구한다 (약수의 개수 카운트)
2-1. 약수 개수 == 2이면 소수, 1*n*1만
2-2. 소수가 아닐경우 (가로, 세로, 높이)의 쌍을 찾는다
3. 대각선이 정수이면 ans++ (l^2 = a^2 + b^2 + c^2) 
*/

int N;
int d_cnt;
int ans_cnt;
int divisor[111];
int iroot;
int sum;
double dsum;
int isum;

void get_divisor(int N);
int check_line(int w, int h, int d); //if line is integer, return 1 else return 0

int main(){
	int itr;
	int nCount;

	scanf("%d", &nCount);
	for(itr=0; itr<nCount; itr++){
		ans_cnt = 0;
		scanf("%d", &N);
		iroot = sqrt(N);

		get_divisor(N);

		if(d_cnt == 2)
			check_line(1, 1, N);
		else{
			for(int i=0; i<d_cnt; i++){
				for(int j=0; j<d_cnt; j++){
					for(int k=0; k<d_cnt; k++){
						if(divisor[i] * divisor[j] * divisor[k] == N){
							// printf("%d %d %d\n", divisor[i], divisor[j], divisor[k]);
							ans_cnt += check_line(divisor[i], divisor[j], divisor[k]);
						}
					}
				}
			}
		}

		//todo : 중복검사
		printf("%d\n", ans_cnt);
	}

	return 0;
}

void get_divisor(int N){
	int quo;
	d_cnt = 0;
	for(int i=1; i<=iroot; i++)	{
		quo = N / i;
		if(N % i == 0){
			divisor[d_cnt++] = i;
			if(i != quo){
				divisor[d_cnt++] = quo;
			}
		}
	}
}

int check_line(int w, int h, int d){
	sum = w*w + h*h + d*d;
	dsum = sqrt(sum);
	isum = sqrt(sum);
	// printf(" [sum] %d %f %d\n", sum, dsum, isum);
	if(dsum - isum == 0){
		return 1;
	}
	return 0; 
}