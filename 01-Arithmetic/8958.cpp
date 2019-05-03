// https://www.acmicpc.net/problem/8958
#include <cstdio>
using namespace std;

int main() {
	int tc = 0;
	scanf("%d", &tc);
	char input[81];
	for (int i = 0; i < tc; i++) {
		scanf("%s", input);
		int score = 0;
		int tempScore = 0;
		for(int i = 0; i < 80; i++) {
			if(input[i] == '\0') break;
			if (input[i] == 'O') score += ++tempScore;
			else tempScore = 0;
		}
		printf("%d\n", score);
	}
	return 0;
}