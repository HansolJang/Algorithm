//https://www.acmicpc.net/problem/1700
#include <cstdio>
#include <cstring>
using namespace std;
int n, k, max, maxe, ans = 0;
int ename[101]; //input
bool plugged[101] = {0, }; //is plugged
int check[101];
int main() {
	scanf("%d %d", &n, &k);
	for(int i=0; i<k; i++)
		scanf("%d", &ename[i]);
	for(int i=0; i<n; i++)
		plugged[ename[i]] = true;
	for(int i=n; i<k; i++) {
		if(plugged[ename[i]]) continue; //원래 꼽힌거면 건너뛰기
		memset(check, 0, sizeof(check));
		for(int j=i+1; j<k; j++) {
			if(!check[ename[j]])
				check[ename[j]] = j; //몇번째에 나왔었는지 체크
		}
		max = 0;
		bool unplugged = false;
		for(int j=1; j<=101; j++) {
			if(plugged[j]) {
				if(!check[j]) { //꽂혀있던 것 중 미래에 안나올 것 찾으면 뽑
					plugged[j] = false;
					unplugged = true;
					break;
				}
				if(check[j] > max) { //꽂혀있던 것 중 가장 나중에 나올거 찾기
					max = check[j];
					maxe = j;
				}
			}
		}
		if(!unplugged)
			plugged[maxe] = false;
		plugged[ename[i]] = true; //현재것 꽂기
		ans += 1;
	}
	printf("%d\n", ans);
	return 0;
}