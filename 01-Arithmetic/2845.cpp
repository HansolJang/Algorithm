//https://www.acmicpc.net/problem/2845
#include <cstdio>
using namespace std;

int main() {
	int nperson, area;
	int news1, news2, news3, news4, news5;
	scanf("%d %d", &nperson, &area);
	int total = nperson * area;
	scanf("%d %d %d %d %d", &news1, &news2, &news3, &news4, &news5);
	printf("%d %d %d %d %d\n", news1 - total, news2 - total, news3 - total, news4 - total, news5 - total);
	return 0;
}