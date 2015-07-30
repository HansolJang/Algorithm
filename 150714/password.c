#include <stdio.h>

int main() {
	int itr;
	int nCount;
	char input[111];
	int len;
	scanf("%d", &nCount);

	for(itr=0; itr<nCount; itr++){
		printf("#testcase%d\n", itr+1);
		
		scanf("%d %s", &len, input);

		for(int i=1; i<len; i++) {
			if(input[i] == input[i-1]) {
				if(input[i] == ' ') continue;
				input[i] = ' ';
				input[i-1] = ' ';

				int con = 1; // 연속확인
				for(int j=1; j<len; j++) {
					if(con == 0) break;

					int templ = 1;
					int tempr = 0;
					// 왼쪽으로 숫자나올때까지
					while(1) {
						if(i-j-templ < 0) break;
						if(input[i-j-templ] != ' ') break;
						else templ++;
					}
					//오른쪽으로 숫자 나올때까지
					while(1) {
						if(i+j+templ > len) break;
						if(input[i+j+tempr] != ' ') break;
						else tempr++;
					}

					if(input[i-j-templ] == input[i+j+tempr]) {
						input[i-j-templ] = ' ';
						input[i+j+tempr] = ' ';
					} else con = 0;
				}
			}
		}

		for(int i=0; i<len; i++) {
			if(input[i] != ' ') {
				printf("%c", input[i]);
			}
		}
		printf("\n");
	}
}