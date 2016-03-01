#include <stdio.h>

#define SIZE 11111

int day, a, b;
int price[SIZE];

int min(int a, int b)
{
	if(a > b)
		return b;
	else 
		return a;
}

int solve(int idx);

int main()
{
	int itr;
	int nCount;

	// freopen("large.in", "r", stdin);

	scanf("%d", &nCount);
	for(itr=0; itr<nCount; itr++)
	{
		scanf("%d %d %d", &day, &a, &b);
		for(int i=1; i<=day; i++)
			scanf("%d", &price[i]);

		printf("%d\n", solve(1));
	}
	return 0;
}

int solve(int idx)
{
	if(idx > day)
		return 0;

	return min(a * price[idx] + solve(idx + 1), b + solve(idx + 5));
}