/*

	순열과 조합 (재귀)

*/

#include <stdio.h>

void get_pc(int idx, int n, int r, char* str, int* p_pcnt, int* p_qcnt, int p, int q, char* parr, char* qarr) {	
	int i;
	char cpystr[15];
	int samecnt;

	if(idx == r) {
		//순열
		(*p_pcnt)++;
		if(*p_pcnt == p) {
			// printf("-------p match :");
			//순열 결과 저장
			for(i=0; i<r; i++) {
				// printf("%c", str[i]);
				parr[i] = str[i];
			}

			//조합 결과 이미 있으면 출력
			if(*p_qcnt >= q) {
				for(i=0; i<r; i++) {
					printf("%c", parr[i]);				
				}
				printf("\n");
				for(i=0; i<r; i++) {
					printf("%c", qarr[i]);				
				}
				printf("\n");
			}
		}

		// 조합
		// 문자가 뒤로갈수록 커짐
		bool is_combination = true;
		for(i=1; i<r; i++) {
			if(str[i] <= str[i-1]) {
				is_combination = false;
				break;
			}
		}
		
		if(is_combination) {
			for(i=0; i<r; i++) {
				qarr[i] = str[i];
			}
			(*p_qcnt)++;

			// 결과값 저장
			if((*p_qcnt) == q) {	
				// printf("-------q match :");
				//이미 순열 결과가 있으면 출력
				if(*p_pcnt >= p) {
					for(i=0; i<r; i++) {
						printf("%c", parr[i]);				
					}
					printf("\n");
					for(i=0; i<r; i++) {
						printf("%c", qarr[i]);				
					}
					printf("\n");
				}
			}
		} 
		return;
	}

	bool is_already;
	for(i=0; i<n; i++) {
		is_already = false;
		// 순열 중복검사
		/*
			0~24의 배열에 쓴 문자를 1로 바꿔도 됨
			visit 처럼 
		*/
		for(int j=0; j<idx; j++) {
			if(str[j] == 65+i) {
				is_already = true;
				break;
			}
		}

		if(!is_already) {
			if(*p_pcnt <= p || *p_qcnt <= q) {
				str[idx] = 65+i;
				// recursive
				get_pc(idx+1, n, r, str, p_pcnt, p_qcnt, p, q, parr, qarr);  
			}
		}
	}
	
}

int main()
{

	int itr;
	int nCount;		/* 문제의 테스트 케이스 */
	int n, r;
	int p, q;  //p순열 q조합
	int p_pcnt, p_qcnt;
	char str[15];
	char qarr[15] = {};
	char parr[15] = {};

	scanf("%d", &nCount);	/* 테스트 케이스 입력 */

	for(itr=0; itr<nCount; itr++)
	{
		p_pcnt = 0;
		p_qcnt = 0;

		printf("#testcase%d\n",itr+1);

		scanf("%d %d", &n, &r);
		scanf("%d %d", &p, &q);
		get_pc(0, n, r, str, &p_pcnt, &p_qcnt, p, q, parr, qarr);

	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */ 

}