/*

VC, GCC에서 사용

*/

#include <stdio.h>

int main()
{

	int itr;
	int nCount;		/* 문제의 테스트 케이스 */
	long long height[88888][2];
	int num;
	int i;
	int top;
	int index;

	scanf("%d", &nCount);	/* 테스트 케이스 입력 */

	for(itr=0; itr<nCount; itr++)
	{	

		printf("#testcase%d\n",itr+1);
		scanf("%d", &num);
		int sum = 0;
		
		for(i=0; i<num; i++) {
			scanf("%lld", &height[i][0]);
			height[i][1] = 0; //초기화
		}

		for(i=0; i<num; i++) {
			index = num-i-1; //5,4,3,2,1,0
			//스택이 비었을 경우 현재것을 푸시 
			if(i == 0) {
				top = index;
				continue;
			}

			// 키가 더 커서 볼 수 있을 경우
			// printf("index:%d, top: %d, height[i]: %d, top_height:%d\n", index, top, height[index][0], height[top][0]);
			if(height[index] > height[top]) {
				while(1) {
					//볼수 있으면
					if(height[index] > height[top]) {
						height[top][0] = 0;  
						height[index][1] = height[top][1] + 1; //cnt 증가
						top++; //pop
						if(top > num-1) {
							top = index; //push
							break;
						}
					}	
					//못보면 
					else {
						top--; //push
						break;
					}
				}
			}
			//못 볼 경우
			else {	
				top--;
			}
			
		} //for

		for(i=0; i<num; i++) {
			sum += height[i][1];
		}
		printf("%d\n", sum);
	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */ 

}