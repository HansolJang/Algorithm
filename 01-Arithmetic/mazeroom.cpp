//https://www.codeground.org/practice/practiceProbView.do?probId=6
#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char** argv) {
	//setbuf(stdout, NULL);
	int TC, test_case, N, K, i, row, col, t, sr, sc;
	bool minus;
	long long ans;
	string input;
	scanf("%d", &TC);
	for (test_case = 1; test_case <= TC; test_case++) {
		ans = 1;
		row = 0;
		col = 0;
		scanf("%d %d", &N, &K);
		cin >> input;
		for (i = 0; i < K; i++) {
			minus = false;
			if (input[i] == 'U')
				row--;
			else if (input[i] == 'D')
				row++;
			else if (input[i] == 'L')
				col--;
			else if (input[i] == 'R')
				col++;
			if ((row + col) >= N) {  //삼각형보다 밑쪽이면 대칭자리로 뒤집기
				row = N - 1 - row;
				col = N - 1 - col;
				minus = true;
			}
			t = ((row + col) * (row + col + 1)) / 2 + 1;  //시작하는 위치 값
			(row + col) % 2 ? t += row : t += col;  // 대각선으로 올라가거나 내려가는 대로 더해 최종값 구하기
			if (minus) {  //대칭된 값을 구했을 경우 실제 값 구한 후 row, col 값 되돌리기
				t = N * N + 1 - t;
				row = N - 1 - row;
				col = N - 1 - col;
			}
			ans += t;
		}
		printf("Case #%d\n", test_case);
		printf("%lld\n", ans);
	}

	return 0;
}