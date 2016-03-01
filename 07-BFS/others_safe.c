
#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)


#define BOARD_SIZE 111
#define Q_SIZE 11111
#define MAX_DIRECT_NUM 4

int maxHeight = 0;
int N;
int board[BOARD_SIZE][BOARD_SIZE] = { 0 };
int tmpBoard[BOARD_SIZE][BOARD_SIZE] = { 0 };
int visited[BOARD_SIZE][BOARD_SIZE] = { 0 };
int maxSafetyArea = 0;

int X[MAX_DIRECT_NUM] = { 0, 0, 1, -1 };
int Y[MAX_DIRECT_NUM] = { -1, 1, 0, 0 };

typedef struct queue{
   int x[Q_SIZE];
   int y[Q_SIZE];
   int front;
   int rear;
};

void q_init(queue* q){
   q->front = 0;
   q->rear = 0;
}

void push(queue* q, int xVal, int yVal){
   if (q->front == (q->rear + 1) % Q_SIZE){
      printf("queue is full.\n");
      return;
   }

   q->x[q->rear] = xVal;
   q->y[q->rear] = yVal;
   q->rear = (q->rear + 1) % Q_SIZE;
}

void pop(queue* q){
   q->front = (q->front + 1) % Q_SIZE;
}

bool empty(queue * q){
   if (q->front == q->rear)
      return true;
   return false;
}

int frontX(queue* q){
   return q->x[q->front];
}

int frontY(queue *q){
   return q->y[q->front];
}

void bfs(int rootX, int rootY){
   queue myQ;
   q_init(&myQ);
   push(&myQ, rootX, rootY);
   visited[rootY][rootX] = 1;

   while (!empty(&myQ)){
      int popX = frontX(&myQ);
      int popY = frontY(&myQ);
      pop(&myQ);

      for (int i = 0; i < MAX_DIRECT_NUM; i++)
      {
         int nextX = popX + X[i];
         int nextY = popY + Y[i];
         if (nextX >= 0 && nextX < N &&
            nextY >= 0 && nextY < N &&
            visited[nextY][nextX] == 0 &&
            tmpBoard[nextY][nextX] == 1){

               visited[nextY][nextX] = 1;
               push(&myQ, nextX, nextY);
         }
      }
   }
}

int main(){

   scanf("%d", &N);
   for (int i = 0; i < N; i++)
   {
      for (int j = 0; j < N; j++)
      {
         int val;
         scanf("%d", &val);
         if (maxHeight < val) maxHeight = val;
         board[i][j] = val;
      }
   }

   for (int rainHeight = 0; rainHeight <= 100; rainHeight++)
   {
      memset(tmpBoard, 0, sizeof(tmpBoard));
      memset(visited, 0, sizeof(visited));
      for (int i = 0; i < N; i++)
      {
         for (int j = 0; j < N; j++)
         {
            if (board[i][j] <= rainHeight){
               tmpBoard[i][j] = 0;
            }
            else{//안전영역
               tmpBoard[i][j] = 1;
            }
         }
      }
      

      int cnt = 0;
      for (int y = 0; y < N; y++)
      {
         for (int x = 0; x < N; x++)
         {
            if (tmpBoard[y][x] == 1 && visited[y][x] == 0){
               bfs(x, y);
               cnt++;
               //("%d번째 cnt :  %d\n", rainHeight, cnt);
            }
         }
      }
      //맥스값과 비교
      if (maxSafetyArea < cnt) maxSafetyArea = cnt;
      //만약 max값이 0이 아니지만 count가 0이 나오면 break;
      if (maxSafetyArea != 0 && cnt == 0) break;

   }
   printf("%d\n", maxSafetyArea);
   return 0;
}



//맥스값과 비