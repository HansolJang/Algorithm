#include <stdio.h>
#include <math.h>

int main(){
	int second;
	int root;
	int diff;
	int i;
	int row, col;
	printf("입력\n");
	scanf("%d", &second);
	root = (int)sqrt(second);
	diff = second - (root*root);
	// printf("%d", root);
	/*
		홀수 : 행+1 ->(열+1) * 제곱근 -> (행-1) * 제곱근
		짝수 : 열+1 ->(행+1) * 제곱근 -> (열-1) * 제곱근
	*/
	if(root % 2 == 0) {
		row = root;
		col = 1;
		for(i=0; i<diff; i++) {
			if(i == 0) {
				row++;
			} else {
				if(i <= root) {
					col++;
				} else {
					row--;
				}
			}
			// printf("%d %d\n", row, col);
		}
	} else {
		row = 1;
		col = root;
		for(i=0; i<diff; i++) {
			if(i == 0) {
				col++;
			} else {
				if(i <= root) {
					row++;
				} else {
					col--;
				}
			}
			// printf("%d %d\n", row, col);
		}	
	}
	printf("%d %d\n", row, col);
	return 0;
}