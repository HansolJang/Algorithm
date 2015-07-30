/*
	입력: 1111-222-33-444 N M
	-(하이픈)으로 나누어진 스트링을 받아 
	M번째 숫자열의 각자리에 N을 더하여 암호만들어 출력
		* 하나의 숫자열의 최대 길이는 4, 넘어가면 INPUT ERROR! 출력
		* 4자리보다 작을 경우 앞에 0을 채운 후 N 더하기
*/
#include <stdio.h>
#include <memory.h>		

char input[111];
int N;  // 더할 수
int M;  // 암호의 위치
char d_input[111][11];  // -(하이픈)경계로 자른 암호
bool is_err;  //ERROR! 출력할 플래그
int h_cnt; //하이픈 개수
int n_cnt; //하이픈 마다 숫자개수
int password[4]; // 결과

int main() {
	int itr;
	int nCount;

	scanf("%d", &nCount);

	for(itr=0; itr < nCount; itr++) {

		memset(d_input, -1, sizeof(d_input));
		memset(password, -1, sizeof(password));
		is_err = false;
		h_cnt = 1;
		n_cnt = 0;

		printf("#testcase%d\n", itr+1);
		scanf("%s %d %d", &input, &N, &M);

		for(int i=0; i<111; i++) {
			//문자열 끝
			if(input[i] == 0) break;

			if(input[i] == '-') {
				h_cnt++;
				n_cnt = 0;
			} 
			//하이픈이 나오기 전까지 배열에 저장
			else {

				d_input[h_cnt][n_cnt] = input[i];
				n_cnt++;

				if(n_cnt > 4) {
					is_err = true;
					break;
				}
			}
		}

		if(is_err) {
			printf("INPUT ERROR!\n");
			continue;
		} 

		n_cnt = 0; // 숫자의 갯수 확인
		for(int i=0; i<11; i++) {
			if(d_input[M][i] == -1) {
				break;
			} 
			n_cnt++;
		}	

		int idx = 3;
		for(int i=n_cnt-1; i>=0; i--) {
			//뒤부터 넣기
			// char -> int
			password[idx] = d_input[M][i]-'0';
			// +N
			password[idx] = (password[idx] + N) % 10;
			idx--;
		}

		//빈자리 0으로 채운뒤 출력
		for(int i=0; i<4; i++) {
			if(password[i] == -1) {
				password[i] = N;
			}
			printf("%d", password[i]);
		}
		printf("\n");
	}

	return 0;
}