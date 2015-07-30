
/*
 
 VC, GCC에서 사용
 
 */

#include <stdio.h>

/*
    nqueen
 */

#define ABS(a) (a) > 0 ? (a) : -(a)

int N;
int ans;

int field[15][15];

bool is_available(int x, int y){
    //가로 검사
    for(int i=0; i<N; i++){
        if(field[x][i] == 1){
            return false;
        }
    }
    
    //세로 검사
    for(int i=0; i<N; i++){
        if(field[i][y] == 1){
            return false;
        }
    }
    
    //대각선 검사
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if((ABS(x-i)) == (ABS(y-j)) && field[i][j] == 1){
                return false;
            }
        }
    }
    return true;
}

void solve(int count){
    
    if(count == N){
        ans += 1;
        return;
    }
    
    for(int i=0; i<N; i++){
        if(is_available(count, i)){
            field[count][i] = 1;
            solve(count + 1);
            field[count][i] = 0;
        }
    }
}

int main()
{
    
    int itr;
    int nCount;		/* 문제의 테스트 케이스 */
    
    scanf("%d", &nCount);	/* 테스트 케이스 입력 */
    
    for(itr=0; itr<nCount; itr++)
    {
        
        printf("#testcase%d\n",itr+1);
        
        scanf("%d", &N);
        
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                field[i][j] = 0;
            }
        }
        ans = 0;
        solve(0);
        
        printf("%d\n", ans);
        
        /*
         
         알고리즘이 들어가는 부분
         
         */
        
    }
    
    return 0;	/* 반드시 return 0으로 해주셔야합니다. */ 
    
}