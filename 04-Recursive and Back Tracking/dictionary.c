/*

	순열과 조합 (재귀)

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int compare(const void *a , const void *b) {
    return strcmp( (char*)a , (char*)b );
}

void get_pc(int idx, int n, int r, char* str, int* p_pcnt, int* p_qcnt, int p, int q, char* parr, char (*qarr)[1111]) {	
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

			/*
				다음 인덱스의 숫자가 무조건 더 커야함!
				비교문 하나로 바꿀 것
			*/
			//조합 결과 이미 있으면 출력
			if(*p_qcnt >= q) {
				for(i=0; i<r; i++) {
					printf("%c", parr[i]);				
				}
				printf("\n");
				for(i=0; i<r; i++) {
					printf("%c", qarr[q-1][i]);				
				}
				printf("\n");
			}
			// printf("\n");
		}

		//복원할 복사값
		strcpy(cpystr, str);
		//오름차순 정렬
		qsort(cpystr, r, sizeof(cpystr[0]) , compare);

		// 조합
		// 정렬 후 중복검사
		bool is_same;
		for(i=0; i<(*p_qcnt); i++) {
			samecnt = 0;
			is_same = false;
			for(int j=0; j<r; j++) {
				if(qarr[i][j] == cpystr[j]) {
					samecnt++;
				}
			}
			//정렬한 것이 이미 있으면 
			if(samecnt == r) {
				is_same = true;
				break;
			}
		}

		// 이미 있지 않으면
		if(!is_same) {
			for(i=0; i<r; i++) {
				qarr[(*p_qcnt)][i] = str[i];
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
						printf("%c", qarr[q-1][i]);				
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
	char qarr[1111][1111];
	char parr[15] = {};

	// scanf("%d", &nCount);	/* 테스트 케이스 입력 */

	// for(itr=0; itr<nCount; itr++)
	// {
		p_pcnt = 0;
		p_qcnt = 0;
		for(int i=0; i<111; i++) {
			for(int j=0; j<111; j++) {
				qarr[i][j] = -1;
			}
		}
		// printf("#testcase%d\n",itr+1);

		scanf("%d %d", &n, &r);
		scanf("%d %d", &p, &q);
		get_pc(0, n, r, str, &p_pcnt, &p_qcnt, p, q, parr, qarr);

	// }

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */ 

}