#include <stdio.h>
#include <memory.h>

int cache[111][111];
int board[111][111];
int N;
int sol(int row, int col);

int main() {
   int itr;
   int nCount;

   scanf("%d", &nCount);
   for(itr = 0; itr<nCount; itr++) {
      memset(cache, -1, sizeof(cache));
      memset(board, -1, sizeof(board));

      scanf("%d", &N);
      for(int i=1; i<=N; i++) {
         for(int j=1; j<=i; j++) {
            scanf("%d", &board[i][j]);
         }
      }

      printf("%d\n", sol(1, 1));

   }
   return 0;
}

/*
   가장 밑까지 갔을 경우 자기 자신을 리턴
   시작위치를 정해주면
   뻗어나가는 두 지점과 더해본 후 더 큰 값을 리턴 
*/
int sol(int row, int col) {
   if(row == N) {
      return board[row][col];
   }

   int& ret = cache[row][col];
   if(ret != -1) {
      return ret;
   }

   ret = 0;
   ret = board[row][col] + sol(row + 1, col);
   int temp = board[row][col] + sol(row + 1, col + 1);
   if(ret < temp) {
      ret = temp;
   }
   return ret;
}


/*
int n;
int borad[111][111];

// 캐시는 -1로 초기화
int cache[111][111];
// 현재 board[x][y]에 위치해 있을때
// [x][y]에서 시작하는 경로의 최대합 반환
int sol(int x, int y)
{
   if (x == n)
      return board[x][y];

   int& ret = cache[x][y];
   if (ret != -1)
   {
      return ret;
   }
   ret = 0;

   ret = max(ret, board[x][y] + sol(x + 1, y));
   ret = max(ret, board[x][y] + sol(x + 1, y + 1));
   return ret;   
}
*/