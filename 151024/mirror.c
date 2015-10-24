#include <stdio.h>
#include <memory.h>

#define SIZE 1111

int N;
int room[SIZE][SIZE];
bool visited[SIZE][SIZE];
int dir; //direction of light
int mir; //mirror number
int cnt; //answer, rendezvous count

//light from 
//0:east, 1:west, 2:south, 3:north
int dir_row[4] = {0, 0, -1, 1};
int dir_col[4] = {-1, 1, 0, 0};

int one_row[4] = {1, -1, 0, 0};
int one_col[4] = {0, 0, 1, -1};
int one_dir[4] = {3, 2, 1, 0};

int two_row[4] = {-1, 1, 0, 0};
int two_col[4] = {0, 0, -1, 1};
int two_dir[4] = {2, 3, 0, 1};

void reflection();

int main(void) {

	setbuf(stdout, NULL);

	int T;
	int test_case;

	scanf("%d", &T);
	for(test_case = 1; test_case <= T; test_case++) {
		//reset
		memset(room, -1, sizeof(room));
		memset(visited, 0, sizeof(visited));

		//input
		scanf("%d", &N);
		for(int i=1; i<=N; i++)
		{
			for(int j=1; j<=N; j++)
			{
				scanf("%1d", &room[i][j]);
			}
		}

		reflection();
		
		printf("Case #%d\n", test_case);
		printf("%d\n", cnt);
        
	}

	return 0;
}

void reflection()
{
	//start
	int row = 1;
	int col = 1;
	cnt = 0;
	dir = 1; //light from west

	while(room[row][col] != -1)
	{
		if(room[row][col] == 0)
		{
			//keep going
			row += dir_row[dir];
			col += dir_col[dir];
		}
		else if(room[row][col] == 1)
		{
			if(visited[row][col] == false)
			{
				cnt++;
				visited[row][col] = true;
			}
			//move
			row += one_row[dir];
			col += one_col[dir];
			dir = one_dir[dir];
		}
		else if(room[row][col] == 2)
		{
			if(visited[row][col] == false)
			{
				cnt++;
				visited[row][col] = true;
			}
			//move
			row += two_row[dir];
			col += two_col[dir];
			dir = two_dir[dir];
		}
	}
}