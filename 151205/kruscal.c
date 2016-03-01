#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#define V_SIZE	11111
#define E_SIZE 	111111
#define Q_SIZE	111111
#define TRUE	1
#define FALSE	0

typedef int BOOL;
typedef struct edge
{
	int weight;
	int v_from;
	int v_to;
} edge;

int graph[V_SIZE][V_SIZE];
edge arr_edge[E_SIZE];
int vcnt, ecnt;
int v1, v2, w;

// bfs
BOOL visited[V_SIZE];
edge queue[Q_SIZE];
int front, rear;

// quick sort
void swap(edge *arr, int idx1, int idx2);
int partition(edge *arr, int left, int right);
void quicksort(edge *arr, int left, int right);

// check path
BOOL check_path(BOOL *visited);

int main()
{
	memset(graph, 0, sizeof(graph));
	scanf("%d %d", &vcnt, &ecnt);
	edge e;
	for(int i=0; i<ecnt; i++)
	{
		scanf("%d %d %d", &v1, &v2, &w);
		// set graph
		graph[v1][v2] = w;
		graph[v2][v1] = w;
		// set edge
		e.weight = w;
		e.v_from = v1;
		e.v_to = v2;
		arr_edge[i] = e;
	}

	quicksort(arr_edge, 0, ecnt-1);

	// 간선 하나 지우기
	// bfs
	for(int i=0; i<ecnt; i++)
	{
		// remove edge
		graph[arr_edge[i].v_from][arr_edge[i].v_to] = 0;
		graph[arr_edge[i].v_to][arr_edge[i].v_from] = 0;

		// init
		memset(visited, FALSE, sizeof(visited));
		front = 1;
		rear = 1;
		// bfs


		if(!check_path(visited))
		{
			// recovery edge
			graph[arr_edge[i].v_from][arr_edge[i].v_to] = arr_edge[i].weight;
			graph[arr_edge[i].v_to][arr_edge[i].v_from] = arr_edge[i].weight;
		}
	}

	return 0;
}

void swap(edge *arr, int idx1, int idx2)
{
	edge e;
	e.weight = arr[idx1].weight;
	e.v_from = arr[idx1].v_from;
	e.v_to = arr[idx1].v_to;

	arr[idx1].weight = arr[idx2].weight;
	arr[idx1].v_from = arr[idx2].v_from;
	arr[idx1].v_to = arr[idx2].v_to;


}

int partition(edge *arr, int left, int right)
{
	int pivot = arr[left].weight;
	int low = left + 1;
	int high = right;

	while(low <= high)
	{
		while(pivot <= arr[low].weight)
		{
			low++;
			if(low > high)
				break;
		}

		while(pivot > arr[high].weight)
		{
			high--;
			if(low > high)
				break;
		}

		if(low <= high)
		{
			swap(arr, low, high);
		}
	}

	swap(arr, left, high);
	return high;
}

void quicksort(edge *arr, int left, int right)
{
	if(left <= right)
	{
		int pivot = partition(arr, left, right);
		quicksort(arr, left, pivot - 1);
		quicksort(arr, pivot + 1, right);
	}
}

BOOL check_path(BOOL *visited)
{
	BOOL res = TRUE;
	for(int i=0; i<vcnt; i++)
	{
		if(visited[i] == FALSE)
		{
			res = FALSE;
			break;
		}
	}
	return res;
}