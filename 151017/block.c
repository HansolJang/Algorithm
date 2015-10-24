#include <stdio.h>
#include <memory.h>

int block_num;
int block[111111];
int newarr[111111];
bool flag;
int count;


void cheak(){

	for(int i=1;i<block_num-1;i++){

	if(block[i]>0){
		
		if(block[i-1]==0 || block[i+1]==0){
			newarr[i]=0;
		}
		else if(block[i-1]>block[i] && block[i+1]>block[i])
		{
			newarr[i]=block[i]-1;

		}else if(block[i-1]<block[i] && block[i+1]<block[i])
		{
			if(block[i-1]<block[i+1]){
				newarr[i]=block[i+1]-block[i];
			}	else{
				newarr[i]=block[i-1]-block[i];
			}
		}else{

			if(block[i-1]<block[i+1]){
				newarr[i]=block[i-1]-block[i];
			}else if(block[i-1]>block[i+1]){
				newarr[i]=block[i+1]-block[i];
			}else{

				newarr[i]=block[i]-1;
			}
		}
	}
		for(int i =0; i<block_num;i++){
			printf("%d, ", newarr[i]);
		}
		printf("\n");

	}

	for(int i =0; i<block_num;i++){

		if(newarr[i]!=0){
			for(int j =0; j<block_num;j++){
				block[j]=newarr[j];
				flag=false;
			}
			break;
		}

		flag=true;
	}
}
int main(void) {

	int T;
	int test_case;

	setbuf(stdout, NULL);

	scanf("%d", &T);
	for(test_case = 1; test_case <= T; test_case++) {
		//	이 부분에서 알고리즘 프로그램을 작성하십시오.
		memset(block, 0, sizeof(block));
		memset(newarr, 0, sizeof(newarr));
		flag=true;
		count=0;
		scanf("%d",&block_num);

		for(int i=0;i<block_num;i++){
			scanf("%d",&block[i]);
		}
		
		newarr[0]=0;
		newarr[block_num-1]=0;
	
		cheak();

		if(flag==true){
			printf("Case #%d\n", test_case);
			printf("%d\n", count);

		}else{
			count++;
			cheak();
		}

	}

	return 0;	//	정상종료 시 반드시 0을 리턴해야 합니다.
}