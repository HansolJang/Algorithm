/*
https://www.acmicpc.net/problem/5002
*/
#include <stdio.h>

#define ABS(a) (a) > 0 ? (a) : -(a)

int diff;
char input[111];
int person[111] = {};
int cnt;
int mcnt = 0;
int wcnt = 0;

void solve(int idx);

int main(){
	scanf("%d", &diff);
	scanf("%s", input);

	for(int i=0;; i++){
		if(input[i] == 0){
			cnt = i;
			break;
		}
		if(input[i] == 'W')
			person[i] = 1;
		else if(input[i] == 'M')
			person[i] = 2;
	}

	solve(0);
	printf("%d\n", mcnt + wcnt);

	return 0;
}

void solve(int idx){
	if(idx == cnt)
		return;

	//여자
	if(person[idx] == 1){
		//바로 입장
		if((ABS(wcnt + 1 - mcnt)) <= diff){
			wcnt++;
			// printf("woman idx: %d\n", idx);
			solve(idx + 1);
		}
		//바로 뒤 남자 입장후 자신 입장
		else{
			if(person[idx + 1] == 2 && (ABS(mcnt - wcnt)) <= diff){
				mcnt++;  //한칸 앞사람
				wcnt++;  //현재사람
				// printf("jump !!!! man and woman idx: %d\n", idx);
				solve(idx + 2);
			}
		}
		
	}

	if(person[idx] == 2){
		if((ABS(mcnt + 1 - wcnt)) <= diff){
			mcnt++;
			// printf("man idx: %d\n", idx);
			solve(idx + 1);
		}
		else{			
			if(person[idx + 1] == 1 && (ABS(wcnt - mcnt)) <= diff){
				mcnt++;  //한칸 앞사람
				wcnt++;  //현재사람
				// printf("jump !!!! man and woman idx: %d\n", idx);
				solve(idx + 2);
			}
		}
	}
}