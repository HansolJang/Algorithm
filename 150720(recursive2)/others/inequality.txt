#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define TRUE 1
#define FALSE 0

void is_Max(int max[10], int N, int output[10]) {
	int i, find_max = FALSE;
	for (i = 0; i <= N; i++) {
		if (max[i] < output[i]) {
			find_max = TRUE;
			break;
		}
		else if (max[i] > output[i]) break;
	}
	if (find_max)
		for (i = 0; i <= N; i++)
			max[i] = output[i];
}

void is_Min(int min[10], int N, int output[10]) {
	int i, j, find_min = FALSE;;
	for (i = 0; i <= N; i++) {
		if (min[i] > output[i]) {
			find_min = TRUE;
			break;
		}
		else if (min[i] < output[i]) break;
	}
	if (find_min)
		for (i = 0; i <= N; i++)
			min[i] = output[i];
}

void dfs(char inequality[10], int N, int visited[10], int output[10], int max[10], int min[10], int idx) {
	int i, j, x;
	if (idx == N + 1) {

		is_Max(max, N, output);
		is_Min(min, N, output);
		return;
	}

	for (i = 0; i <= 9; i++) {
		if (visited[i] == TRUE) continue;
		if (inequality[idx - 1] == '<' && output[idx - 1] >= i) continue;
		if (inequality[idx - 1] == '>' && output[idx - 1] <= i) continue;

		output[idx] = i;
		visited[i] = TRUE;


		dfs(inequality, N, visited, output, max, min, idx + 1);

		output[idx] = 0;
		visited[i] = FALSE;

	}
}

int main()
{

	int itr;
	int nCount;		/* 문제의 테스트 케이스 */

	scanf("%d", &nCount);	/* 테스트 케이스 입력 */

	for (itr = 0; itr<nCount; itr++)
	{
		int i, N, idx = 0;
		char inequality[16];
		int output[10];
		int visited[10];
		int max[10];
		int min[10];

		printf("#testcase%d\n", itr + 1);

		scanf("%d", &N);
		for (i = 0; i < N; i++)
			scanf(" %c", &inequality[i]);

		
		for (i = 0; i < 10; i++) {
			visited[i] = FALSE;
			max[i] = -1;
			min[i] = 10;
		}

		for (i = 0; i < 10; i++) {
			output[idx] = i;
			visited[i] = TRUE;

			dfs(inequality, N, visited, output, max, min, idx + 1);
			
			output[idx] = 0;
			visited[i] = FALSE;
		}

		for (i = 0; i <= N; i++)
			printf("%d", max[i]);
		printf("\n");

		for (i = 0; i <= N; i++)
			printf("%d", min[i]);
		printf("\n");

	}

	return 0;

}