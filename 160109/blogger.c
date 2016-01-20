#include <stdio.h>
#include <memory.h>

#define SIZE 1111

int ans;
int post_cnt; // 맨처음에 입력 몇개 받을지
int blogger[SIZE]; // 포스트 갯수 세는 배열
int max_post;  //현재 최고 포스트 개수
int max_blogger;  //현재 최고 포스트를 쓴 블로거


int main() {
	int itr, testCase;
	scanf("%d", &testCase);
	int tmp;

	/*
	post_cnt를 입력받고, 
	그 수만큼 반복하면서 blogger 배열의 카운트 증가
	+ max 카운트 발견할 때 마다 첫번째로 찾은 맥스값에 해당하는 블로거를 맥스_블로거에 저장
	*/
	for(itr = 0; itr < testCase; itr++) {
		//solve
		memset(blogger, 0, sizeof(blogger));
		max_post = 0;
		scanf("%d", &post_cnt);
		for(int i=0; i<post_cnt; i++) {
			scanf("%d", &tmp);
			blogger[tmp] += 1;  // 글 하나 증가

			if(blogger[tmp] > max_post) {
				max_post = blogger[tmp];
				max_blogger = tmp;
			}

		}

		printf("#testCase%d\n", itr+1);
		printf("%d\n", max_blogger);
	}
	return 0;
}