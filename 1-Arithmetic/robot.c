#include <stdio.h>

#define ABS(a) (a) > 0 ? (a) : -(a)

int N, M;  //신호설비수와 명령수
int pos[111111][2];
char order[333333];
long long int dissum;

char direction[4] = {'E', 'W', 'S', 'N'};
int dirX[4] = {1, -1, 0, 0};
int dirY[4] = {0, 0, -1, 1};

int main()
{

	int itr;
	int nCount;		/* 문제의 테스트 케이스 */

	scanf("%d", &nCount);	/* 테스트 케이스 입력 */

	for(itr=0; itr<nCount; itr++)
	{
		dissum = 0;
		printf("#testcase%d\n",itr+1);

		scanf("%d %d", &N, &M);
		for(int i=0; i<N; i++)
		{
			scanf("%d %d", &pos[i][0], &pos[i][1]);
			dissum += (ABS(pos[i][0])) + (ABS(pos[i][1]));
		}
		scanf("%s", &order);

		int x = 0;
		int y = 0;
		int cnt;
		for(int i=0; i<M; i++)
		{
			for(int d=0; d<4; d++)
			{
				if(order[i] == direction[d])
				{
					x += dirX[d];
					y += dirY[d];
					cnt = 0;
					for(int j=0; j<N; j++)
					{
						//이전보다 가까워진 신호설비 좌표의 개수 구하기
						switch(d)
						{
							case 0:
							//동:x좌표가 x보다 크면
								if(pos[j][0] >= x)
									cnt++;
								break;
							case 1:
							//서: x좌표가 x보다 작으면
								if(pos[j][0] <= x)
									cnt++;
								break;
							case 2:
							//남: y좌표가 y보다 작으면
								if(pos[j][1] <= y)
									cnt++;
								break;
							case 3:
							//북: y좌표가 y보다 크면
								if(pos[j][1] >= y)
									cnt++;
								break;
						}
					}

					dissum = dissum + N - (2 * cnt);
					printf("%lld ", dissum);

					break;  //동서남북 for문 탈출
				} //if
			} //for 방향
		} //for 명령
		printf("\n");
	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */ 

}