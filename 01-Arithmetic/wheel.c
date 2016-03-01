/*

VC, GCC에서 사용

*/

#include <stdio.h>

#define MIN(a,b) (a) > (b) ? (b) : (a)
#define INF 987654321

char inputFrom[11];
char inputTo[11];

int rfront;  //오른쪽으로 돌때 처음과 끝  --
int lfront;  //왼쪽으로 돌때 처음과 끝  ++
int fromfront;  //입력값의 처음
int tofront;  //입력값의 처음

int wheelFrom[32];
int wheelTo[32];

char digit16[16] = {'0','1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
int digit2[16][4] = {{0, 0, 0, 0}, {0, 0, 0, 1}, {0, 0, 1, 0}, {0, 0, 1, 1}, {0, 1, 0, 0}, {0, 1, 0, 1}, 
					{0, 1, 1, 0}, {0, 1, 1, 1}, {1, 0, 0, 0}, {1, 0, 0, 1}, {1, 0, 1, 0},
					{1, 0, 1, 1}, {1, 1, 0, 0}, {1, 1, 0, 1}, {1, 1, 1, 0}, {1, 1, 1, 1}};

int main()
{

	int itr;
	int nCount;		/* 문제의 테스트 케이스 */

	scanf("%d", &nCount);	/* 테스트 케이스 입력 */

	for(itr=0; itr<nCount; itr++)
	{
		for(int i=0; i<32; i++)
		{
			wheelFrom[i] = 0;
			wheelTo[i] = 0;
		}
		printf("#testcase%d\n",itr+1);

		scanf("%s", &inputFrom);
		scanf("%s", &inputTo);

		int length = 0;
		int rear;
		fromfront = 0;
		tofront = 0;

		//from 2진수로 바꾸기
		for(int i=0; i<11; i++)
		{
			if(inputFrom[i] == 0)
				break;

			length++;
			for(int j=0; j<16; j++)
			{
				//1~F
				if(inputFrom[i] == digit16[j])
				{
					//이진수로 바꾸기
					for(int k=0; k<4; k++)
					{
						wheelFrom[i*4 + k] = digit2[j][k];
						if(k == 3)
							rear = i*4 + k;
					}
				}
			}
		}
		//길이가 작으면 0부터 읽도록 
		if(length != 8)
		{
			fromfront = rear + 1;
		}

		length = 0;
		//to 2진수로 바꾸기
		for(int i=0; i<11; i++)
		{
			if(inputTo[i] == 0)
				break;

			length++;
			for(int j=0; j<16; j++)
			{
				//1~F
				if(inputTo[i] == digit16[j])
				{
					//이진수로 바꾸기
					for(int k=0; k<4; k++)
					{
						wheelTo[i*4 + k] = digit2[j][k];
						if(k == 3)
							rear = i*4 + k;
					}
				}
			}
		}

		if(length != 8)
		{
			tofront = rear + 1;
		}

		bool right;
		bool left;
		int minRight = INF;
		int minLeft = INF;

		lfront = fromfront;
		rfront = fromfront;

		//전체회전
		for(int i=0; i<33; i++)
		{
			//오른쪽으로 돌림
			if(minRight == INF)
			{
				right = true;
				for(int r=0; r<32; r++)
				{
					if(wheelFrom[(r + rfront) % 32] != wheelTo[(tofront + r) % 32])
					{
						right = false;
						break;
					}
				}

				if(right)
					minRight = (MIN(minRight, i));
			}
			
			if(minLeft == INF)
			{
				left = true;
				//왼쪽으로 돌림
				for(int l=0; l<32; l++)
				{
					if(wheelFrom[(l + lfront) % 32] != wheelTo[(tofront + l) % 32])
					{
						left = false;
						break;
					}
				}
				if(left)
					minLeft = (MIN(minLeft, i));
			} 

			lfront = (lfront + 1) % 32;
			rfront--;
			if(rfront < 0)
				rfront = 31;	
		} //회전 32번


		if(minRight == minLeft)
		{
			if(minRight == INF)
			{
				printf("Not possible\n");
			}
			else
			{
				printf("%d Any\n", minRight);
			}	
		}
		else if(minRight > minLeft)
		{
			printf("%d Left\n", minLeft);
		}
		else if(minRight < minLeft)
		{
			printf("%d Right\n", minRight);
		}
	}
	return 0;	/* 반드시 return 0으로 해주셔야합니다. */ 

}