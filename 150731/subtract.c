/*
https://www.acmicpc.net/problem/4782
*/
#include <stdio.h>

int b, n;
int anscnt;
int ans[111][2];

int gcd(int a, int b);
int get_m(int a, int b, int n);

int main()
{
	int itr;
	for(itr=0;; itr++)
	{
		anscnt = 0;
		scanf("%d %d", &b, &n);
		if(b == 0 && n == 0)
			break;

		for(int a=0; a<20; a++)
		{
			int m = (int)get_m((int)a, b, n);
			if(m != -1)
			{
				ans[anscnt][0] = a;
				ans[anscnt++][1] = m;
			}
		}

		for(int i=0; i<anscnt; i++)
		{
			printf("%d/%d ", ans[i][0], ans[i][1]);
		}
		printf("\n");

	}
	return 0;
}

int gcd(int a, int b)
{
	if(b == 0) return a;
	gcd(b, a % b);
}

int get_m(int a, int b, int n)
{
	long long int t1, t2, t3;
	for(int m=1;m<100; m++)
	{
		t1 = m * m * b;
		t2 = 2 * b * n * m;
		t3 = a * n * n;

		if(t1 - t2 == -(t3))
		{
			return m;
		}
	}

	return -1;
}