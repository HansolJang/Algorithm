/*

VC, GCC에서 사용

*/

#include <stdio.h>

char input[11];
int length;
bool used[11];
char res[111111][11];
int res_cnt;

void make_string(int idx, char* arr);
void sort(char* input, int length);

int main()
{

	int itr;
	int nCount;		/* 문제의 테스트 케이스 */
	char str[11];

	scanf("%d", &nCount);	/* 테스트 케이스 입력 */

	for(itr=0; itr<nCount; itr++)
	{
		length = 0;
		res_cnt = 0;

		printf("#testcase%d\n",itr+1);
		scanf("%s", &input);
		for(int i=0; i<11; i++) 
		{
			used[i] = false;  //used 초기화
			if(input[i] == 0)
			{
				break;
			}
			length++;  //문자열 길이 설정
		}

		sort(input, length);   //문자열 정렬
		make_string(0, str);
		
	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */ 

}

void sort(char* input, int length)
{
	for(int i=0; i<length-1; i++)
	{
		for(int j=0; j<length-1; j++)
		{
			if(input[j] > input[j+1]) 
			{	
				//swap
				char temp = input[j];
				input[j] = input[j+1];
				input[j+1] = temp;
			}
		}
	}
}

/*
입력받은 배열은 미리 정렬
0부터 문자열 길이 만큼 idx증가
*/
void make_string(int idx, char* arr) 
{
	bool is_same = true;
	if(idx == length) {

		if(res_cnt == 0) is_same = false;
		else {
			//현재 결과가 이미 있는지 확인
			for(int i=0; i<res_cnt; i++) {
				is_same = true;
				for(int j=0; j<length; j++) {
					if(arr[j] != res[i][j]) {
						is_same = false;
						break;
					}
				}
				if(is_same) break;
			}
		}
		if(!is_same) {
			for(int i=0; i<length; i++) {
				res[res_cnt][i] = arr[i];  //저장
				printf("%c", arr[i]);
			}
			printf("\n");
			res_cnt++;
		}
		return;
	}

	for(int i=0; i<length; i++) {
		if(used[i] == false) {
			arr[idx] = input[i];
			used[i] = true;
			make_string(idx + 1, arr);
			used[i] = false;
		}
	}
}