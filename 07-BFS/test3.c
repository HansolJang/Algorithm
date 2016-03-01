/*

1 1 3 2 0 0 0 0 0
3 2 5 2 0 0 0 0 0
2 3 3 1 0 0 0 0 0
0 0 0 0 4 5 5 3 1
1 2 5 0 3 6 4 2 1
2 3 6 0 2 1 1 4 2
0 0 0 0 4 2 3 1 1
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0

*/

#include <stdio.h>

#define SIZE 111
#define QSIZE 111111

int N;  //땅 전체 크기
int ground[SIZE][SIZE];
int queue[QSIZE][2];
int front, rear;
bool visited[SIZE][SIZE];
int psize[SIZE][2];  //[0]땅의 넓이 [1]땅의 위치 plant 배열에서의 인덱스
int plant[SIZE * 2][2];  //행 2개씩 식물이 심어져있는 땅의 좌표
int pcnt;  //식물 심어진 땅의 갯수

int dirR[4] = {0, 0, 1, -1};
int dirC[4] = {1, -1, 0, 0};

void bfs(int row, int col);
void mysort(int (*psize)[2]);
void swap(int (*arr)[2], int idx1, int idx2);
int partition(int (*arr)[2], int left, int right);
void quickSort(int (*arr)[2], int left, int right);

int main()
{

	int itr;
	int nCount;		/* 문제의 테스트 케이스 */

	scanf("%d", &nCount);	/* 테스트 케이스 입력 */

	for(itr=0; itr<nCount; itr++)
	{	
		//초기화
		for(int i=0; i<SIZE; i++)
		{
			for(int j=0; j<SIZE; j++)
			{
				visited[i][j] = false;
				ground[i][j] = false;
			}
			psize[i][0] = 0;
			psize[i][1] = 0;
		}
		for(int i=0; i<SIZE*2; i++) {
			plant[i][0] = 0;
			plant[i][1] = 0;
		}
		front = 1;
		rear = 1;
		pcnt = 0;

		printf("#testcase%d\n",itr+1);

		scanf("%d", &N);
		for(int i=1; i<=N; i++)
		{
			for(int j=1; j<=N; j++)
			{
				scanf("%d", &ground[i][j]);
			}
		}

		for(int i=1; i<=N; i++)
		{
			for(int j=1; j<=N; j++)
			{
				if(ground[i][j] != 0 && visited[i][j] == false) 
				{
					bfs(i, j);
					pcnt++;
				}
			}
		}

		//땅의 넓이 계산
		// printf("%d\n", pcnt);
		for(int i=0; i<pcnt*2; i++) {
			// printf("%d %d\n", plant[i][0], plant[i][1]);
			if(i % 2 == 1) 
			{
				psize[i/2][0] = (plant[i][0] - plant[i-1][0] + 1) * (plant[i][1] - plant[i-1][1] + 1);
				psize[i/2][1] = i - 1 ;
				// printf("size : %d idx : %d\n", psize[i/2][0], psize[i/2][1]);
			}
		}

		//넓이 순으로 정렬
		// mysort(psize);
		quickSort(psize, 0, pcnt - 1);

		printf("%d ", pcnt);
		for(int i=0; i<pcnt; i++)
		{
			int row = plant[psize[i][1] + 1][0] - plant[psize[i][1]][0] + 1;
			int col = plant[psize[i][1] + 1][1] - plant[psize[i][1]][1] + 1;
			printf("%d %d ", row, col);
		}
		printf("\n");

	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */ 

}

void bfs(int row, int col) {

	visited[row][col] = true;
	queue[rear][0] = row;
	queue[rear++][1] = col;
	rear %= QSIZE;
	plant[pcnt * 2][0] = row;
	plant[pcnt * 2][1] = col;
	plant[pcnt * 2 + 1][0] = row;
	plant[pcnt * 2 + 1][1] = col;

	while(!(front == rear)) {
		int frow = queue[front][0];
		int fcol = queue[front++][1];
		front %= QSIZE;

		for(int i=0; i<4; i++) {
			int nextR = frow + dirR[i];
			int nextC = fcol + dirC[i];

			if(ground[nextR][nextC] != 0 && visited[nextR][nextC] == false)
			{	
				visited[nextR][nextC] = true;
				queue[rear][0] = nextR;
				queue[rear++][1] = nextC;
				rear %= QSIZE;

				//끝나는 좌표 넣기
				if(nextR >= plant[pcnt * 2 + 1][0] && nextC >= plant[pcnt * 2 + 1][1]) {
					plant[pcnt * 2 + 1][0] = nextR;
					plant[pcnt * 2 	+ 1][1] = nextC;
				}
			}
		}
	}
}

void mysort(int (*psize)[2])
{
	for(int i=0; i<pcnt-1; i++)
	{
		for(int j=0; j<pcnt-1; j++)
		{
			if(psize[j][0] >= psize[j+1][0]) 
			{	
				if(psize[j][0] == psize[j+1][0])
				{
					//넓이가 같을 경우 행이 작은것 부터
					int row = plant[psize[j][1] + 1][0] - plant[psize[j][1]][0] + 1;
					int nrow = plant[psize[j + 1][1] + 1][0] - plant[psize[j + 1][1]][0] + 1;
					if(row < nrow)
					{
						//swap
						int tsize = psize[j][0];
						int tpoint = psize[j][1];
						psize[j][0] = psize[j+1][0];
						psize[j][1] = psize[j+1][1];
						psize[j+1][0] = tsize;
						psize[j+1][1] = tpoint;
					}
				}
				//swap
				int tsize = psize[j][0];
				int tpoint = psize[j][1];
				psize[j][0] = psize[j+1][0];
				psize[j][1] = psize[j+1][1];
				psize[j+1][0] = tsize;
				psize[j+1][1] = tpoint;
			}
		}
	}
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
	int pivot = arr[left][0];  //땅의 넓이
	int low = left + 1;
	int high = right;

	while(low <= high)
	{
		//pivot 보다 커지면 멈춤
		while(pivot > arr[low][0])
		{
			low++;
			if(low > high)
				break;
			if(pivot == arr[low][0])
			{
				int prow = plant[arr[left][1] + 1] - plant[arr[left][1]] + 1;
				int lrow = plant[arr[low][1] + 1] - plant[arr[low][1]] + 1;

				if(prow < lrow)
					break;
			}
		}

		{
		while(pivot < arr[high][0])
			high--;
			if(low > high)
				break;
			if(pivot == arr[high][0])
			{
				//pivot == arr[high][0]일 때
				//pivot이 더 작으면 피봇과 스위치
				int prow = plant[arr[left][1] + 1] - plant[arr[left][1]] + 1;
				int hrow = plant[arr[high][1] + 1] - plant[arr[high][1]] + 1;
				if(prow < hrow)
					break;
			}
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