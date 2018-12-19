#include <iostream>
#include <cstring>
using namespace std;

int main() {
	char str[501];
	int length = 0;
	while(true) {
		cin.getline(str, sizeof(str));
		if(strcmp(str, "END") == 0) {
			break;
		}
		for(int i = 0; i < 501; i++) {
			if(str[i] == '\0') {
				length = i;
				break;
			}
		}
		for(int i = length - 1; i >= 0; i--) {
			printf("%c", str[i]);
		}
		printf("\n");
	}
	return 0;
}