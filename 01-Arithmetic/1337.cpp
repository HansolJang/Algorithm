//https://www.acmicpc.net/problem/1337
#include <cstdio>
#include <algorithm>
using namespace std;
int input[10001];
int tmp, maxcnt, idx;
int main() {
	int n;
	scanf("%d", &n);
	for(int i=0; i<n; i++)
		scanf("%d", &input[i]);
	//정렬
	sort(input, input + n);
	//input[i]를 기준으로 하는 가장 긴 연속된 부분배열 찾기
	for(int i=0; i<n; i++) {
		tmp = 1;
		idx = i + 1; //범위 안에 있을 경우에만 다음 인덱스로
		for(int j=1; j<5; j++) { //input[i] ~ input[i]+4 범위 안에 있는지
			if(idx >= n) //인덱스 범위 검사
				break;
			if(input[idx] == input[i] + j) {
				idx += 1;
				tmp += 1;
			}
		}
		maxcnt = max(maxcnt, tmp);
	}
	printf("%d\n", 5 - maxcnt < 0 ? 0 : 5 - maxcnt); //연속된 배열이 5보다 길경우에도 답은 0
	return 0;
}