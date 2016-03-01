#include <stdio.h>

/*
	인접행렬기반 dfs
	o(n^2) : 정점마다 dfs함수가 오직 한번 호출됨 -> n번
			 * 다음 정점을 찾는 반복문(모든 정점 탐색) -> n번
	
	인접리스트기반 dfs
	o(nE) : 정점마다 dfs함수가 오직 한번 호출됨 -> n번
			* 다음정점이 포인터로 연결되어있으므로 엣지의 개수 만큼 반복 -> E번
			최대 간선개수 : nC2 (n개중 2개를 선택할 경우의수) = n(n-1)/2 = E (최악의 E)
*/

int n; //정점의 개수
int mygraph[111][111];
bool visited[111]; //i번째의 정점을 들렀으면 visited[i] = 1;

int main(){



	return 0;
}

//mygraph[s][2] = 1 s에서 2번 정점으로 갈 수 있음

//s = 시작정점
void dfs(int s) {

	 //s번 정점 방문 체크
	visited[s] = true;

	for(int next = 1; next <= n; next++) {
		
		//mygraph에서 갈 수 있고 아직 방문하지 않음
		if(mygraph[s][next] == 1 && visited[next] == false) {
			
			dfs(next);
		}
	}
}