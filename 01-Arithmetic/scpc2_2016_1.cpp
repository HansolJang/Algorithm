#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int n, m, k, ans;
struct Rectangle {
	int x1, y1, x2, y2;
	Rectangle(int x1, int y1, int x2, int y2) : x1(x1), y1(y1), x2(x2), y2(y2) { }
};
bool rectcmp(Rectangle r1, Rectangle r2) {
	return r1.x1 < r2.x1;
}
vector<Rectangle> rect;
vector<int> includes_rect[5001];
int cache[5001];
bool is_included(int r1, int r2) {
	return (rect[r1].x1 <= rect[r2].x1) && (rect[r2].x1 < rect[r2].x2) && (rect[r2].x2 <= rect[r1].x2) 
	&& (rect[r1].y1 <= rect[r2].y1) && (rect[r2].y1 < rect[r2].y2) && (rect[r2].y2 <= rect[r1].y2);
}
//idx번째 사각형이 포함하는 최대 사각형 개수 리턴
int solve(int idx) {
	int len = includes_rect[idx].size();
	if(len == 0)
		return 1;
	if(cache[idx] != -1)
		return cache[idx];
	cache[idx] = 0;
	for(int i=0; i<len; i++)
		cache[idx] = max(cache[idx], 1 + solve(includes_rect[idx][i]));
	return cache[idx];
}
int main(int argc, char** argv) {
	setbuf(stdout, NULL);
	int T, test_case, i, j;
	int x1, y1, x2, y2;
	scanf("%d", &T);
	for(test_case = 1; test_case <= T; test_case++) {
		rect.clear();
		for(i=0; i<5001; i++) {
			includes_rect[i].clear();
			cache[i] = -1;
		}
		ans = 1;
		scanf("%d %d %d", &n, &m, &k);
		for(i=0; i<k; i++) {
			scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
			rect.push_back(Rectangle(x1, y1, x2, y2));
		}
		sort(rect.begin(), rect.end(), rectcmp);
		for(i=0; i<k; i++) {
			for(j = i+1; j<k; j++) {
				if(rect[j].x1 >= rect[i].x2)
					break;
				if(is_included(i, j))
					includes_rect[i].push_back(j);
			}
		}
		for(i=0; i<k; i++) 
			ans = max(ans, solve(i));
		printf("Case #%d\n", test_case);
		printf("%d\n", ans);
	}
	return 0;
}