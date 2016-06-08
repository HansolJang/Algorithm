#include <stdio.h>
#include <memory.h>

#define INF 987654321
#define SIZE 1111

int N;  //number of vertex
int M;  //number of edge
int map[SIZE][SIZE];
int earned_cnt;

int idx[SIZE];  //save path
int value[SIZE];  //save min value
bool visited[SIZE];
bool is_earned[SIZE];
void solve();
void dikstra(int start);

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
		earned_cnt = 0;
		//input
		scanf("%d %d", &N, &M);
		for(int i=0; i<M; i++) {
			scanf("%d %d %d", &start, &end, &length);
			map[start][end] = length;
			map[end][start] = length;  //양방향
		}
		solve();
		printf("Case #%d\n", test_case);		
		if(earned_cnt == N)
			printf("%d\n", N-earned_cnt);
		else {
			printf("%d ", N-earned_cnt);
			for(int i=1; i<=N; i++) {
				if(!is_earned[i])
					printf("%d ", i);
			}
			printf("\n");
		}
	}
	return 0;	// 정상종료 시 반드시 0을 리턴해야 합니다.
}

void solve() {
	//모든 시작, 끝점에 대한 경로 찾기
	for(int i=1; i<N; i++) {
		//reset
		for(int j=0; j<SIZE; j++) {
			value[j] = INF;
			visited[j] = false;
			idx[j] = 0;
		}
		dikstra(i);
	}
}

void dikstra(int start) {
	int min, p;
	value[start] = 0;
	for(int i=1; i<=N; i++) {
		min = INF;
		// find min value
		for(int j=1; j<=N; j++)	{
			if(value[j] < min && visited[j] == false) {
				// printf("min : %d\n", j);
				min = value[j];
				p = j;
			}
		}
		//visit from min value
		visited[p] = true;
		for(int k=1; k<=N; k++) {
			if(value[p] + map[p][k] < value[k] && map[p][k] != 0) {
				value[k] = value[p] + map[p][k];
				idx[k] = p;  // save path
			}
		}
	}
	//set is_earned
	for(int i=1; i<=N; i++)	{
		p = i;
		do {
			p = idx[p];
			if(p != start && p > 0
				&& is_earned[p] == false) {
				earned_cnt++;
				is_earned[p] = true;
			}
		} while(idx[p] != 0);
	}
}