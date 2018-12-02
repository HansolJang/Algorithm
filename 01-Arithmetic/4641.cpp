//https://www.acmicpc.net/problem/4641
#include <cstdio>
using namespace std;

int main() {
	int arr[20] = {0, };
	int size;
	while(true) {
		for(int i = 0; i < 15; i++) {
			scanf("%d", &arr[i]);
			if(arr[i] == -1) {
				return 0;
			}
			if(arr[i] == 0) {
				size = i;
				break;
			}
		}
		int ans = 0;
		for(int i = 0; i < size; i++) {
			for(int j = 0; j < size; j++) {
				if(arr[i] * 2 == arr[j]) {
					ans++;
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}