#include <stdio.h>

int main(void){
	int i;
	char str[100];
	gets(str);
	char c;
	int wCount = 0;
	int len = sizeof(str)/sizeof(char);
	// printf("%s\n", str);
	// 스페이스가 두번 연속 들어올 경우 예외처리
	for(i=0; i<len; i++) {
		if(str[i] == NULL) {
			// printf("null\n");
			if(c == 32) {
				// printf("double space\n");
				break;
			} else {
				wCount++;
				break;
			}
		} else if (str[i] == 32) {
			if(c == 32) {
				// printf("double space\n");
			} else {
				// printf("word++ \n");
				wCount++;
			}
			c = str[i];
		} else {
			c = str[i];
		}
	}
	// printf("%d\n", len);
	printf("%d\n", wCount);
	return 0;
}