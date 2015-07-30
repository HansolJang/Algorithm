#include <stdio.h>

int N;
int acnt;
int board[12][12];

int abs(int a) {
	if(a > 0) return a;
	else return -a;
}

bool is_possible(int row, int col) {
	for(int i=0; i<N; i++) {
		if(board[row][i] == 1) return false;
	}

	for(int i=0; i<N; i++) {
		if(board[i][col] == 1) return false;
	}

	for(int i=0; i<N; i++) {
		for(int j=0; j<N; j++) {
			if(abs(row-i) == abs(col-j) && board[i][j] == 1) return false;
		}
	}
	return true;
}

void queen(int row) {
	if(row == N) {
		for(int j=0; j<N; j++) {
			for(int k=0; k<N; k++) {
				printf("%d ", board[j][k]);
			}
			printf("\n");
		}
		printf("\n");
		acnt += 1;
		return;
	}

	for(int i=0; i<N; i++) {
		// queen(row+1);
		if(is_possible(row, i)) {
			// printf("row %d col %d\n", row, i);
			board[row][i] = 1;
			queen(row + 1);
			board[row][i] = 0;
		}
	}
}


int main()
{
    
    int itr;
    int nCount;		/* 문제의 테스트 케이스 */
    
    scanf("%d", &nCount);	/* 테스트 케이스 입력 */
    
    for(itr=0; itr<nCount; itr++)
    {
     	acnt = 0;   
     	for(int i=0; i<12; i++) {
     		for(int j=0; j<12; j++) {
     			board[i][j] = 0;
     		}
     	}
        printf("#testcase%d\n",itr+1);
        scanf("%d", &N);

        queen(0);

        printf("%d\n", acnt);
        
    }
    
    return 0;	/* 반드시 return 0으로 해주셔야합니다. */ 
    
}