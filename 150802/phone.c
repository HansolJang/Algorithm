/*
https://www.acmicpc.net/problem/5052
*/
#include <stdio.h>
#include <memory.h>
#include <stdlib.h>
#include <string.h>

int N;
char phone[11111][11];
bool is_same;

int compare(const void *a, const void *b) {
  return( strcmp( (char *)a, (char *)b) );
}

int main()
{
	int itr;
	int nCount;
	scanf("%d", &nCount);
	for(itr=0; itr<nCount; itr++)
	{
		scanf("%d", &N);
		for(int i=0; i<N; i++)
		{
			scanf("%s",&phone[i]);
		}	

		qsort((void *)phone, N, sizeof(phone[0]), compare);

		for(int i=0; i<N-1; i++)
		{
			is_same = true;
			for(int j=0; j<11; j++)
			{
				if(phone[i][j] == 0)
					break;
				if(phone[i][j] != phone[i+1][j])
				{
					is_same = false;
					break;
				}
			}
			if(is_same)
				break;
		}

		if(is_same)
			printf("NO\n");
		else
			printf("YES\n");

	}
	return 0;
}