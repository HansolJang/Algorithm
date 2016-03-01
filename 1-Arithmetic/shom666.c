/*
https://www.acmicpc.net/problem/1436
*/
#include <stdio.h>

int shom[11111];
int cnt = 1;
int scnt;

void make_shom();
bool is_available(int num);

int main()
{
	int n;
	make_shom();
	scanf("%d", &n);
	printf("%d\n", shom[n]);
	return 0;
}

void make_shom(){
	for(int i=666;;i++){
		if(cnt > 10000){
			break;
		}

		if(is_available(i)){
			shom[cnt++] = i;
		}
	}
}

bool is_available(int num){
	scnt = 0;
	while(1){
		if(num % 10 == 6){
			scnt++;
			if(scnt == 3){
				return true;
			}
		}
		else{
			scnt = 0;
		}

		if(num / 10 == 0){
			break;
		}
		num /= 10;
	}
	return false;
}