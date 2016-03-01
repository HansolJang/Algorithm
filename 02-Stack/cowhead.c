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
		top = num;
		
		for(i=0; i<num; i++) {
			scanf("%lld", &height[i][0]);
			height[i][1] = 0; //초기화
			// printf("%lld\n", height[i]);
		}

		for(i=1; i<num; i++) {
			index = num - i;
			while(1) {
				/*
					if. 현재가 탑보다 크면
						반복 : 현재가 탑보다 작아질 때까지 {	
							1. pop
							2. 현재 가중치+1 만큼 카운트 증가
						}
					else. 현재가 탑보다 작거나 같으면
						1. push
				*/
				//empty
				if(top >= num) {
					//push
					top = index;
					break;
				}
				printf("index : %d, top : %d\n", index, top);
				printf("present : %lld, top: %lld\n", height[index][0], height[top][0]);
				if(height[index][0] > height[top][0]) {
					//while pop
					while(1) {
						if(height[index][0] < height[top][0]) {
							top--;  //push
							printf("push top2 : %lld\n", height[top][0]);
							break;
						} else {
							height[index][1]++;
							height[index][1] += height[top][1];
							top++;
							printf("pop top : %lld\n", height[top][0]);
							if(top > num-1) break; //empty
							//pop
						}
					}	
				} else {
					if(top == index) break; //자기 자신
					//push
					top--;
					printf("push3 top : %lld\n", height[top][0]);
					break;
				}
				
			} // while
		} //for

		for(i=0; i<num; i++) {
			sum += height[i][0];
		}
		printf("%d\n", sum);
	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */ 

}