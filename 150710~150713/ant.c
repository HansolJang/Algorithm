#include <stdio.h>
/*
	몫과 나머지를 이용해 풀기
	(가상 좌표계가 더 붙어있다고 생각하고 그려보기)
	몫이 짝수:(시작위치+시간)을 가로나 세로로 나눈 나머지
	몫이 홀수:가로나 세로길이 - 짝수일때와 같은 계산값
			한번 튕겼다 나오는 것이므로 빼야함!
*/
int main(void){
	int w;
	int h;
	int startX;
	int startY;
	int t;
	int x, y, restX, restY, valX, valY;
	scanf("%d %d", &w, &h);
	scanf("%d %d", &startX, &startY);
	scanf("%d\n", &t);
	// printf("w:%d h:%d sw: %d sh:%d t:%d\n", w, h, startW, startH, t);
	x = startX + t;
	y = startY + t;
	valX = (int)x / w;
	valY = (int)y / h;
	restX = x % w;
	restY = y % h;

	if(valX % 2 == 0) {
		x = restX;
	} else {
		x = w - restX;
	}

	if(valY % 2 == 0) {
		y = restY;
	} else {
		y = h - restY;
	}
	printf("%d %d\n", x, y);
	return 0;
}