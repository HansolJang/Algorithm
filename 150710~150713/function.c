#include <stdio.h>

int Large_Num(int a, int b);  //이름만 선언

int main(){
	printf("3과 4중에서 큰 수는 %d 이다 \n", Large_Num(3, 4));
	printf("7과 2중에서 큰 수는 %d 이다\n", Large_Num(2, 7));
	return 0;
}


//반환값 함수이름(인자) { 함수내용 }
int Large_Num(int a, int b) {
	if(a> b) 
		return a;
	else
		return b;
}