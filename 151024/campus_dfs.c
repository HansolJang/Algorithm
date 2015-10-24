#include <stdio.h>
#include <memory.h>

#define INF 987654321
#define SIZE 1111

int N;  //number of vertex
int M;  //number of edge
int map[SIZE][SIZE];
int ans_cnt;
bool is_earned[SIZE];  //answer
bool each_is_earned[SIZE];
int each_min_length;
int visited[SIZE];


void solve();
void dfs(int start, int end, int cur, int length, int* visited);

int main(void) {

	setbuf(stdout, NULL);

	int T;
	int test_case;
	int start, end, length;

	scanf("%d", &T);
	for(test_case = 1; test_case <= T; test_case++) {
		//reset
		memset(map, 0, sizeof(map));
		memset(is_earned, 0, sizeof(is_earned));

		//input
		scanf("%d %d", &N, &M);
		for(int i=0; i<M; i++)
		{
			scanf("%d %d %d", &start, &end, &length);
			map[start][end] = length;
			map[end][start] = length;  //양방향
		}

		solve();

		printf("Case #%d\n", test_case);

		ans_cnt = 0;
		for(int i=1; i<=N; i++)
		{
			if(!is_earned[i]){
				ans_cnt++;
			}
		}

		printf("%d ", ans_cnt);
		if(ans_cnt != 0)
		{
			for(int i=1; i<=N; i++)
			{
				if(!is_earned[i]){
					printf("%d ", i);
				}
			}
		}

		printf("\n");

	}

	return 0;	// 정상종료 시 반드시 0을 리턴해야 합니다.
}

void solve()
{
	//모든 시작, 끝점에 대한 경로 찾기
	for(int i=1; i<=N; i++)
	{
		for(int j=i+1; j<=N; j++)
		{
			if(map[i][j] != 0)
				continue;
			//reset
			// printf("---------------------reset start :%d end:%d\n", i, j);
			each_min_length = INF;
			memset(each_is_earned, 0, sizeof(each_is_earned));
			for (int k = 0; k < SIZE; k++)
			{
				visited[k] = INF;
			}
			//visit start
			visited[i] = 0;
			dfs(i, j, i, 0, visited);

			for(int h=1; h<=N; h++)
			{
				if(each_is_earned[h])
					is_earned[h] = true;
			}
		}

		// printf("start : %d\n", i);
		// for(int h=1; h<=N; h++)
		// {
		// 	printf("arrive : %d value : %d\n", h, is_earned[h]);
		// }
	}
}


void dfs(int start, int end, int cur, int length, int* visited)
{
	//end : find min_path
	if(cur == end)
	{
		if(length <= each_min_length)
		{
			// printf("each_min_length : %d cur len : %d\n", each_min_length, length);
			if(length < each_min_length) {
				each_min_length = length;
				memset(each_is_earned, 0, sizeof(each_is_earned));
			}

			for(int i=1; i<=N; i++)
			{
				if(visited[i] > 0 && visited[i] < INF 
					&& i != start && i != end) {
					// printf("[is_earned] : %d\n", i);
					each_is_earned[i] = true;
				}
			}
		}
		return;
	}

	//next step
	for(int i=1; i<=N; i++)
	{
		if(map[cur][i] != 0 
			&& (visited[i] == INF || length + map[cur][i] <= visited[i]))
		{
			length += map[cur][i];
			visited[i] = length;
			// printf("[visited] cur : %d visited : %d length : %d\n", cur, i, length);
			dfs(start, end, i, length, visited);
			visited[i] = INF;
			length -= map[cur][i];
		}
	}
}
