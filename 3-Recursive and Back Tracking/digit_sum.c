/*
https://www.acmicpc.net/problem/5425
*/
#include <stdio.h>

int start, end;

int solve(int start, int end);


int main(){
	int itr;
	int nCount;

	scanf("%d",&nCount);

	for(itr=0; itr<nCount; itr++){
		scanf("%d %d", &start, &end);

		printf("%d\n", solve(start, end));
	}
	return 0;
}

int solve(int start, int end){
	int cpy = start;
	int cpye = end;
	int ds = 0;
	int de = 0;
	if(start/10 == end/10){
		while(1){
			ds += cpy % 10;
			if(cpy / 10 > 0){
				cpy /= 10;
			}
			else
				break;
		}
		while(1){
			de += cpye % 10;
			if(cpye / 10 > 0){
				cpye /= 10;
			}
			else
				break;
		}
		return ((end - start + 1) * (ds + de)) / 2;
	}

	int e = (start / 10) * 10 + 9;
	cpye = e;
	while(1){
		ds += cpy % 10;
		if(cpy / 10 > 0){
			cpy /= 10;
		}
		else
			break;
	}

	while(1){
		de += cpye % 10;
		if(cpye / 10 > 0){
			cpye /= 10;
		}
		else
			break;
	}
	int s = ((e - start + 1) * (ds + de)) / 2;

	return s + solve(((start / 10) + 1) * 10, end);
}