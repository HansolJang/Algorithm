#include <stdio.h>
#include <string.h>

int main() {
	int itr;
	int nCount;
	int row, col;
	int f, a, c, e, face_cnt;
	int i, j;
	char board[55][55];
	char line[55];

	scanf("%d", &nCount);

	for(itr=0; itr<nCount; itr++){
		printf("#testCase%d\n", itr+1);
		scanf("%d %d", &row, &col);

		for(i=0; i<row; i++){
			scanf("%s", line);
			strcpy(board[i], line);
		}

		f = 0;
		a = 0;
		c = 0;
		e = 0;
		face_cnt = 0;
		for(i=0; i<row-1; i++) {
			for(j=0; j<col-1; j++) {
				switch(board[i][j]) {
					case 'f': 
					f++;
					break;
					case 'a':
					a++;
					break;
					case 'c':
					c++;
					break;
					case 'e':
					e++;
					break;
				}
				switch(board[i+1][j]) {
					case 'f': 
					f++;
					break;
					case 'a':
					a++;
					break;
					case 'c':
					c++;
					break;
					case 'e':
					e++;
					break;
				}
				switch(board[i][j+1]) {
					case 'f': 
					f++;
					break;
					case 'a':
					a++;
					break;
					case 'c':
					c++;
					break;
					case 'e':
					e++;
					break;
				}
				switch(board[i+1][j+1]) {
					case 'f': 
					f++;
					break;
					case 'a':
					a++;
					break;
					case 'c':
					c++;
					break;
					case 'e':
					e++;
					break;
				}

				if(f == 1 && a == 1 && c == 1 && e == 1) {
					face_cnt++;
				}
				f = 0;
				a = 0;
				c = 0;
				e = 0;
			}
		}
		printf("%d\n", face_cnt);
	}
}