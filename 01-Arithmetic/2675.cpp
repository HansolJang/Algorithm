#include <cstdio>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		int r;
		char string[21];
		scanf("%d %s", &r, &string[0]);
		for(int j = 0; j < 21; j++) {
			if(string[j] == '\0') {
				printf("\n");
				break;
			}
			for(int k = 0; k < r; k++) {
				printf("%c", string[j]);
			}
		}
	}
	return 0;
}