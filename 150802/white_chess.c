/*
https://www.acmicpc.net/problem/1100
*/
#include <stdio.h>

int board[8][8];
char input[11];
int ans = 0;

int main()
{
	for(int i=0; i<8; i++)
	{
		scanf("%s", input);
		for(int j=0;; j++)
		{
			if(input[j] == 0)
				break;
			if(input[j] == '.')
				board[i][j] = 0;
			else if(input[j] == 'F')
				board[i][j] = 1;
		}
	}

	for(int i=0; i<8; i++)
	{
		for(int j=0; j<8; j++)
		{
			if(i % 2 == 0)
			{
				if(j % 2 == 0 && board[i][j] == 1)
					ans++;
			}
			else
			{
				if(j % 2 == 1 && board[i][j] == 1)
					ans++;
			}
		}
	}

	printf("%d\n", ans);

	return 0;
}