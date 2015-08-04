/*
https://www.acmicpc.net/problem/4782
*/
#include <stdio.h>

int b, n;
int anscnt;
int ans[111][2];

int get_m(int a, int b, int n);
void swap(int (*arr)[2], int idx1, int idx2);
int partition(int (*arr)[2], int left, int right);
void quickSort(int (*arr)[2], int left, int right);

int main()
{
	int itr;
	for(itr=0;; itr++)
	{
		anscnt = 0;
		scanf("%d %d", &b, &n);
		if(b == 0 && n == 0)
			break;

		for(int a=0; a<30; a++)
		{
			int m = (int)get_m((int)a, b, n);
			if(m != -1)
			{
				ans[anscnt][0] = a;
				ans[anscnt++][1] = m;
			}
		}

		quickSort(ans, 0, anscnt-1);

		for(int i=0; i<anscnt; i++)
		{
			printf("%d/%d ", ans[i][0], ans[i][1]);
		}
		printf("\n");

	}
	return 0;
}

int get_m(int a, int b, int n)
{
	long long int t1, t2, t3;
	for(int m=1; m<100; m++)
	{
		t1 = m * m * b;
		t2 = 2 * b * n * m;
		t3 = a * n * n;

		if(t1 - t2 + t3 == 0)
		{
			return m;
		}
	}

	return -1;
}

void swap(int (*arr)[2], int idx1, int idx2)
{
	int ta = arr[idx1][0];
	int tm = arr[idx1][1];
	arr[idx1][0] = arr[idx2][0];
	arr[idx1][1] = arr[idx2][1];
	arr[idx2][0] = ta;
	arr[idx2][1] = tm;
}

int partition(int (*arr)[2], int left, int right)
{
	double pivot = (double)arr[left][0] / (double)arr[left][1];
	int low = left + 1;
	int high = right;

	while(low <= high)
	{
		while(pivot >= (double)arr[low][0] / (double)arr[low][1])
		{
			low++;
			if(low > high)
				break;
		}

		while(pivot < (double)arr[high][0] / (double)arr[high][1])
		{
			high--;
			if(low > high)
				break;
		}

		// printf("low %d high %d\n", low, high);
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