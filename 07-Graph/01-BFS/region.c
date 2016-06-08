/*
https://www.acmicpc.net/problem/2583
*/
#include <stdio.h>
#include <memory.h>

#define SIZE 111
#define QSIZE 111111

int paper[SIZE][SIZE];
bool visited[SIZE][SIZE] = {};
int queue[QSIZE][2];
int row, col, num;
int sr, sc, er, ec; //start row, col, end row, col
int cnt;  //region num
int a; //one area
int area[SIZE]; //areas
int front, rear;

int dirR[4] = {0, 0, 1, -1};
int dirC[4] = {1, -1, 0, 0};

void swap(int* arr, int idx1, int idx2);
int partition(int* arr, int left, int right);
void quickSort(int* arr, int left, int right);
void bfs(int row, int col);

int main()
{
	memset(paper, -1, sizeof(paper));
	front = 1;
	rear = 1;
	cnt = 0;
	scanf("%d %d %d", &row, &col, &num);

	for(int r=1; r<=row; r++)
	{
		for(int c=1; c<=col; c++)
		{
			paper[r][c] = 1;
		}
	}

	for(int i=0; i<num; i++)
	{
		scanf("%d %d %d %d", &sc, &sr, &ec, &er);

		for(int r=sr + 1; r<=er; r++)
		{
			for(int c=sc + 1; c<=ec; c++)
			{
				paper[r][c] = 0;
			}
		}
	}

	for(int r=1; r<=row; r++)
	{
		for(int c=1; c<=col; c++)
		{
			if(visited[r][c] == false && paper[r][c] == 1)
			{
				cnt++;
				bfs(r, c);
				area[cnt] = a;
				// printf("%d : %d\n", cnt, a);
			}
		}
	}



	quickSort(area, 1, cnt);

	printf("%d\n", cnt);
	for(int i=1; i<=cnt; i++)
	{
		printf("%d ", area[i]);
	}
	printf("\n");

	return 0;
}

void bfs(int row, int col)
{
	a = 1; // 
	queue[rear][0] = row;
	queue[rear++][1] = col;
	rear %= QSIZE;
	visited[row][col] = true;

	while(!(front == rear))
	{
		int frow = queue[front][0];
		int fcol = queue[front++][1];
		front %= QSIZE;

		for(int i=0; i<4; i++)
		{
			int nextR = frow + dirR[i];
			int nextC = fcol + dirC[i];

			if(paper[nextR][nextC] == 1 && visited[nextR][nextC] == false)
			{
				a++;  //area plus
				visited[nextR][nextC] = true;
				queue[rear][0] = nextR;
				queue[rear++][1] = nextC;
				rear %= QSIZE;
			}
		}
	}
}

void swap(int* arr, int idx1, int idx2)
{
	int temp = arr[idx1];
	arr[idx1] = arr[idx2];
	arr[idx2] = temp;
}

int partition(int* arr, int left, int right)
{
	int pivot = arr[left];
	int low = left + 1;
	int high = right;

	while(low <= high)
	{
		while(arr[low] <= pivot)
		{
			low++;
			if(low > high)
			{
				break;
			}
		}

		while(arr[high] > pivot)
		{
			high--;
			if(low > high)
			{
				break;
			}
		}

		if(low <= high)
		{
			swap(arr, low, high);
		}
	}

	swap(arr, left, high);
	return high;
}

void quickSort(int* arr, int left, int right)
{
	if(left <= right)
	{
		int pivot = partition(arr, left, right);
		quickSort(arr, left, pivot - 1);
		quickSort(arr, pivot + 1, right);
	}
}