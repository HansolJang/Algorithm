//https://www.acmicpc.net/problem/1700
#include <cstdio>
#include <cstring>
using namespace std;
int n, k, max, maxe, ans = 0;
int ename[100]; //input
int plugged[100];
int main() {
	scanf("%d %d", &n, &k);
	for(int i=0; i<k; i++)
		scanf("%d", &ename[i]);
	int plug_cnt = 1;
	plugged[0] = ename[0];
	for(int i=1; i<k; i++) {
		bool already_plugged = false;
		for(int j=0; j<n; j++) {
			if(plugged[j] == ename[i])
				already_plugged = true;
		}
		if(!already_plugged) {
			max = 0; maxe = 0;
			for(int j=0; j<n; j++) {
				bool check = false;
				for(int m=i+1; m<k; m++) {
					if(plugged[j] == ename[m]) {
						if(max < m) {
							max = m;
							maxe = j;
						}
						check = true;
						break;
					}
				}
				if(!check) {
					maxe = j;
					break;
				}
			}
			plugged[maxe] = ename[i];
			if(++plug_cnt > n) ans += 1;
		}
	}
	printf("%d\n", ans);
	return 0;
}