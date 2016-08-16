//https://www.acmicpc.net/problem/2618
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define X 0
#define Y 1
int path[1001][1001];
int event[1001][2];
int dp[1001][1001];
int dist[1001][1001];
int n, w, x, y, inf = 1000000000;
int get_dist(int x1, int y1, int x2, int y2) {
	return abs(x1 - x2) + abs(y1 - y2);
}
//경찰차1, 2가 해당 사건 번호에 위치할 때의 최소 거리 리턴
int solve(int car1, int car2) {
	int next_event = max(car1, car2) + 1;
	if(next_event == w + 1)
		return 0;
	if(dp[car1][car2] != -1)
		return dp[car1][car2];
	//1번차 선택
	int temp1 = dist[car1][next_event] + solve(next_event, car2);
	//2번차 선택
	int temp2 = dist[next_event][car2] + solve(car1, next_event);
	//차번호 저장
	path[car1][car2] = (temp1 > temp2 ? 2 : 1);
	return dp[car1][car2] = min(temp1, temp2);
}
int main() {
	memset(dp, -1, sizeof(dp));
	scanf("%d", &n);
	scanf("%d", &w);
	for(int i=1; i<=w; i++) {
		scanf("%d %d", &x, &y);
		event[i][X] = x; event[i][Y] = y;
	}
	//dist배열 세팅
	for(int i=1; i<=w; i++) {
		dist[0][i] = get_dist(1, 1, event[i][X], event[i][Y]);
		dist[i][0] = get_dist(n, n, event[i][X], event[i][Y]);
		for(int j=1; j<=w; j++)
			dist[i][j] = get_dist(event[i][X], event[i][Y], event[j][X], event[j][Y]);
	}
	printf("%d\n", solve(0, 0));
	int car1 = 0, car2 = 0;
	for(int i=1; i<=w; i++){
		printf("%d\n", path[car1][car2]);
		if(path[car1][car2] == 1) car1++;
		else car2++;
	}
	return 0;
}