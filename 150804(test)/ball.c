
/*

VC, GCC에서 사용

*/

#include <stdio.h>

int M, N, K;//M 막대길이 N 구슬개수 K 오른쪽으로 K번째 
int ball[333333][2];

void swap(int (*arr)[2], int idx1, int idx2);
int partition(int (*arr)[2], int left, int right);
void quickSort(int (*arr)[2], int left, int right);

int main()
{

	int itr;
	int nCount;		/* 문제의 테스트 케이스 */
	int t;
	int idx;

	scanf("%d", &nCount);	/* 테스트 케이스 입력 */

	for(itr=0; itr<nCount; itr++)
	{

		printf("#testcase%d\n",itr+1);
		scanf("%d %d %d", &M, &N, &K);

		for(int i=0; i<N; i++)
		{
			scanf("%d %d", &ball[i][0], &ball[i][1]);
		}

		quickSort(ball, 0, N-1);

		// for(int i=0; i<N; i++)
		// {
		// 	printf("%d %d\n", ball[i][0], ball[i][1]);
		// }
		int time = 0;
		int f = 0;
		for(int i=N-1;i>=N-K;i--) {
			if(ball[i][1] != 1) {
				f = 1;
			}
		}

		int sum = 0;
		for(int i=N-1; i>=N - K; i--) {
			//K보다 큰 쪽의 왼쪽으로 향하는 공의 개수
			if(ball[i][1] == 0) {
				sum += 1;
			}
		}
		if(f == 0) 
		{
			//모두 오른쪽을 향하고 있을 경우
			time = M - ball[N - K][0];
			printf("%d %d\n", time, ball[N - K][0]);
		} 
		else 
		{
			for(int i=N-K-1; i>=0; i--) {
				if(ball[i][1] == 1) {
					time = M - ball[i][0];
					sum--;
					if(sum == 0) break;
				}
			}
			printf("%d %d\n", time, ball[N - K][0]);
		}

		printf("%d %d\n",t ,ball[N-K][0]);

	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */ 

}

void swap(int (*arr)[2], int idx1, int idx2)
{
	int t1 = arr[idx1][0];
	int t2 = arr[idx1][1];
	arr[idx1][0] = arr[idx2][0];
	arr[idx1][1] = arr[idx2][1];
	arr[idx2][0] = t1;
	arr[idx2][1] = t2;
}

int partition(int (*arr)[2], int left, int right)
{
	int pivot = arr[left][0];
	int low = left + 1;
	int high = right;

	while(low <= high)
	{
		while(pivot >= arr[low][0])
		{
			low++;
			if(low > high)
				break;
		}

		while(pivot < arr[high][0])
		{
			high--;
			if(low > high)
				break;
		}

		if(low <= high)
			swap(arr, low, high);
	}

	swap(arr, left, high);
	return high;
}

void quickSort(int (*arr)[2], int left, int right)
{
	if(left <= right)
	{
		int pivot = partition(arr, left, right);
		quickSort(arr, left, pivot - 1);
		quickSort(arr, pivot + 1, right);
	}
}

/*
손승하 운영자는 쇠구슬을 이용한 실험을 진행 중이다. 
완전 탄성 충돌에 대한 이해를 위해 컴퓨터를 이용하여 시뮬레이션 프로그램을 제작하고 있다.

완전 탄성충돌이란, 아래 그림처럼 운동에너지가 보존되는 탄성충돌로써, 
손승하 운영자의 실험에서 모든 쇠구슬의 속도는 v로 일정하므로 부딪혀도 모든 구슬은 v의 속도로 다시 튕겨나간다.

손승하 운영자는 매우 긴 막대기 위에 구슬들을 놓고 동시에 좌, 우 방향으로 동일한 속도로 굴렸을 때 
막대의 오른쪽 끝으로 K 번째 떨어지는 구슬에 대해서 그 구슬이 떨어지는 시간과 시작 위치를 알고싶다. 
(단, 구슬끼리 충돌한다면 서로 운동하던 반대방향으로 움직인다.)

손승하 운영자를 도와 시뮬레이션 프로그램을 완성하자.

[입력]
첫번째 줄 테스트 케이스 N입력
각 테스트케이스 첫 줄에는 막대의 길이 M (0<M<=100,000,000)과 막대 위 
총 구슬의 수 N(0<N<=300,000)과 K(0<K<=300,000)이 입력된다.
 그 후 N 줄 만큼 입력이 들어오며 해당 줄에는 각 구슬의 위치와 방향이 주어지는데, 
 첫 자연수가 위치이며 두 번째 수는 0(왼쪽으로 출발) 또는 1(오른쪽으로 출발)이 입력으로 들어온다. 
 (단, 오른쪽으로 떨어지는 구슬은 항상 K개 이상이다)


### 입력되는 구슬의 위치는 오름차순으로 입력되지 않을 수도 있다. ###

 [출력]
첫째 줄에 #testcaseN의 형태와 같이 번호를 출력한다
각 테스트케이스 별 첫 번째 수는 오른쪽으로 K 번째로 떨어지는 구슬의 시간이며, 
두 번째는 그 구슬이 시작한 위치이다.

-입출력 예-

입력
2
5 3 2                               
1 1
2 1
3 1
5 3 2                            
1 1
2 0
3 1

출력
#testcase1
3 2
#testcase2
4 2


*/