/*
	멤고리즘 
	우표 N개중 최대 K개를 선택할 수 있으며 우표의 데이터를 조합해
	1,2,3,4...의 수를 만듦
	만들수 있는 수중 가장 큰 수 출력
*/
#include <stdio.h>


#define SIZE 11111111

bool possible[SIZE];
int N, K;  //우표수, 선택할수 있는 원소 수 
int input[222] = {};

void make_possible(int* arr, int idx, int n);

int main() {
	int itr;
	int nCount;

	scanf("%d", &nCount);

	for(itr=0; itr<nCount; itr++) {
		scanf("%d %d", &N, &K);
		for(int i=0; i<N; i++) {

		}

		for(int i=1; i<=K; i++) {
			make_possible()
		}
	}
}