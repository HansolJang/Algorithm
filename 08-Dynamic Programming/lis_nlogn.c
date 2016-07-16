/*
lis 시간복잡도 nlogn 풀이

기존의 lis(start)는 시작지점에서 시작하는 가장긴 lis 길이를 반환했던 함수를
lis[length]로 변경
길이가 length인 부분 증가수열중 마지막항이 가장 작을 경우의 마지막 항 저장

마지막 항이 작으면 작을수록 이후에 부분 증가수열이 길어질 가능성이 높아진다

*/
#include <stdio.h>
#include <memory.h>

#define SIZE 111111

int lis[SIZE];  //해당 길이의 부분증가수열의 가장 작은 마지막항을 저장
int input[SIZE];
int num, idx;

int bsearch(int key, int len);  //lis배열에 들어갈 위치를 찾을 이진검색 함수
void solve();

int main() {
	int itr;
	int nCount;
	scanf("%d", &nCount);
	for(itr=0; itr<nCount; itr++) {
		memset(lis, 0, sizeof(lis));
		scanf("%d %d", &num, &idx);
		for(int i=0; i<num; i++) {
			scanf("%d", &input[i]);
		}
		solve();
		printf("Case #%d\n", itr +1);
		if(lis[idx] != 0)
			printf("1\n");
		else
			printf("0\n");
	}
	return 0;
}

int bsearch(int key, int len) {
	int low = 0;
	int high = len;
	int mid;

	while(low <= high) {
		mid = (low + high) / 2;
		if(key > lis[mid])
			low = mid + 1;
		else if(key < lis[mid])
			high = mid - 1;
		else
			return mid;
	}
	return low;
}

void solve() {
	//첫번째 원소 넣기
	int pos;
	int len = 0;
	lis[++len] = input[0];  //len = 1
	for(int i=1; i<num; i++) {
		// printf("%d : ", i);
		//마지막 원소보다 크면 뒤에 추가
		if(lis[len] < input[i])
			lis[++len] = input[i];
		//작을 경우 들어갈 위치 찾아 갱신
		else if(lis[len] > input[i]) {
			pos = bsearch(input[i], len);
			lis[pos] = input[i];
			// printf("bsearch lis[%d] : %d\n", pos, input[i]);
		}
	}	
}


/*
N과 K, 주가가 주어졌을 때 주어진 조건을 만족하게 주식을 구입할 수 있는지 여부를 
알려주는 프로그램을 작성하시오. 

[입력] 
입력 파일에는 여러 테스트 케이스가 포함될 수 있다. 
파일의 첫째 줄에 케이스의 개수 T (2 ≤ T ≤ 100)가 주어지고, 
이후 차례로 T개 테스트 케이스가 주어진다. 각 테스트 케이스의 첫 줄에 두 정수 N과 K이 주어진다. 
N은 앞으로 주가를 알 수 있는 날 수이며,  (1 ≤ N ≤ 10,000) K는 거래의 회수이다. 
(1 ≤ K ≤ N) 다음 줄에는 앞으로 N날의 주가가 사이에 공백을 두고 주어진다. 
주가는 1부터 10,000 사이의 정수이다. 

[출력] 
각 테스트 케이스에 대해서 출력은 한 줄로 구성된다. 
T번째 테스트 케이스에 대해서는 첫째 줄에는 “Case #T”를 출력한다. 
두번째 줄에는 주어진 조건을 만족하게 주식을 살 수 있으면 1, 아니면 0을 출력한다. 

입력
3
10 6
100 50 70 90 75 87 105 78 110 60
6 3
100 90 80 70 60 50
10 4
8 11 9 7 4 6 12 13 5 10

출력
Case #1
1
Case #2
0
Case #3
1

*/