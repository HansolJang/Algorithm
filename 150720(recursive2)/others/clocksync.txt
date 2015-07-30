HeeJoong-Dominic



드라이브
.
폴더 경로
내 드라이브
자소서
새로 만들기 
폴더 및 보기
내 드라이브
공유 문서함
Google 포토
최근
중요
휴지통
.

Word
2010920023_김희중_과학에세이_수정.hwp

PDF
2010920023_김희중_과학에세이_수정.pdf

Word
2010920023_김희중_과학에세이.hwp

PDF
2010920023_김희중_과학에세이.pdf

C++
clocksync.cpp

텍스트
clocksync.txt

C++
color.cpp

텍스트
color.txt

C++
door.cpp

텍스트
door.txt

C++
narrow_path.cpp

텍스트
narrow_path.txt

C++
nqueen.cpp

텍스트
nqueen.txt

C++
scales.cpp

텍스트
scales.txt

Google 문서
sk 자소서

C++
sudoku.cpp

텍스트
sudoku.txt
텍스트
clocksync.txt
세부정보
활동
clocksync.txt
공유 정보
공유되지 않음
일반 정보
유형
텍스트
크기
2KB (2,079바이트)
위치
자소서
소유자
나
수정한 날짜
오후 8:36, 나
열어본 날짜
오후 8:39, 나
만든 날짜
오후 8:36
설명
설명 추가
다운로드 권한
보기 권한만 있는 사용자는 다운로드 금지
5GB 사용함(30%)
저장용량 추가 구입
닫힘 
clocksync.txt열기
/*
 
 VC, GCC에서 사용
 
 */

#include <stdio.h>

/*
    두뇌폭발 시계
 */

bool is_end;
int ans;

int link_rules[10][10] = {
    {0, 1, 2, -1},
    {3, 7, 9, 11, -1},
    {4, 10, 14, 15, -1},
    {0, 4, 5, 6, 7, -1},
    {6, 7, 8, 10, 12, -1},
    {0, 2, 14, 15, -1},
    {3, 14, 15, -1},
    {4, 5, 7, 14, 15, -1},
    {1, 2, 3, 4, 5, -1},
    {3, 4, 5, 9, 13, -1}
};

int time_switch(int time){
    time += 3;
    if(time == 15){
        time = 3;
    }
    
    return time;
}

void click_switch(int switch_num, int* field){
    int i;
    for(i=0; link_rules[switch_num][i] != -1; i++){
        field[link_rules[switch_num][i]] = time_switch(field[link_rules[switch_num][i]]);
    }
}

bool is_all_set(int field[]){
    int i;
    for(i=0; i<16; i++){
        if(field[i] != 12){
            return false;
        }
    }
    return true;
}

void solve(int clocks[], int index, int count){
    
    if(is_all_set(clocks)){
        ans = count;
        return;
    }
    
    if(index > 9 || count > ans || count > 31){
        return;
    }
    
    for(int i=0; i<4; i++){
        
        solve(clocks, index+1, count+i);
        click_switch(index, clocks);
    }
}


int main()
{
    
    int itr;
    int nCount;		/* 문제의 테스트 케이스 */
    
    int clocks[16];
    
    scanf("%d", &nCount);	/* 테스트 케이스 입력 */
    
    for(itr=0; itr<nCount; itr++)
    {
        
        printf("#testcase%d\n",itr+1);
        
        /*
         2
         12 6 6 6 6 6 12 12 12 12 12 12 12 12 12 12
         12 9 3 12 6 6 9 3 12 9 12 9 12 12 6 6
         */
        
        for(int i=0; i<16; i++){
            scanf("%d", &clocks[i]);
        }
        
        is_end = false;
        ans = 1000;
        int counts[16] ={};
        
        solve(clocks, 0, 0);
        
        if(ans == 1000){
            ans = -1;
        }
        printf("%d\n", ans);
        /*
         
         알고리즘이 들어가는 부분
         
         */
        
    }
    
    return 0;	/* 반드시 return 0으로 해주셔야합니다. */
    
}