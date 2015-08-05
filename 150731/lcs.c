/*
https://www.acmicpc.net/problem/5582
*/
#include <stdio.h>
#include <memory.h>

#define MAX(a,b) (a) > (b) ? (a) : (b)
#define SIZE 4444

char input1[SIZE] ={};
char input2[SIZE] = {};
int cache[33];
int len1 = -1;
int len2 = -1;
int maxlen = -1;

int lcs(char al;);

int main()
{
	memset(cache, -1, sizeof(cache));
	scanf("%s", &input1);
	scanf("%s", &input2);

	for(int i=0; i<SIZE; i++)
	{
		if(input1[i] == 0)
		{
			len1 = i;
			if(len2 != -1)
				break;
		}

		if(input2[i] == 0)
		{
			len2 = i;
			if(len1 != -1)
				break;
		}
	}

	for(int i=0; i<len1; i++)
	{
		for(int j=0; j<len2; j++)
		{
			maxlen = (MAX(maxlen, lcs(i, j)));
		}
	}

	printf("%d\n", maxlen);

	return 0;
}

//해당 인덱스에서 시작하는 공통부분수열의 길이 반환
int lcs(int idx1, int idx2)
{
	if((input1[idx1] == 0 && input2[idx2] == 0) || 
		input1[idx1] != input2[idx2])
	{
		return 0; 
	}

	int& ret = cache[idx1][idx2];
	if(ret != -1)
	{
		return ret;
	}

	ret = 0;

	ret = 1 + lcs(idx1 + 1, idx2 + 1);

	return ret;
}