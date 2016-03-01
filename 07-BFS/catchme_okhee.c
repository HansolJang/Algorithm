#include<stdio.h>
#define SIZE 1111111
int N, K;
bool visited[SIZE]={0};

int q[SIZE][2];
int front,rear;
int bfs(int s_point,int time){
   
   q[rear][0] = s_point;
   q[rear][1] = time;
   rear = (rear+1)%SIZE;

   while(!(front==rear)){
      int x = q[front][0];
      int t = q[front][1];
      front = (front+1)%SIZE;
      //-1일때
      if(visited[x-1]==0 && x-1>=0 && x-1<=100000){
         visited[x-1]=1;
         q[rear][0] = x-1;
         q[rear][1] = t+1;
         rear= (rear+1)%SIZE;
         if(x-1 == K) return t+1;
      }
      //지금위치가 친구보다 크면 연산필요x
      if(x<K){
         if(visited[x+1]==0 && x+1>=0 && x+1<=100000){
            visited[x+1]=1;
            q[rear][0] = x+1;
            q[rear][1] = t+1;
            rear= (rear+1)%SIZE;
            if(x+1 == K) return t+1;
         }
         if(visited[x*2]==0 && (x*2)>=0 && (x*2)<=100000){
            visited[x*2]=1;
            q[rear][0] = (x*2);
            q[rear][1] = t+1;
            rear= (rear+1)%SIZE;
            if((x*2)== K) return t+1;
         }

      }
   }
   
}

int main(){

   scanf("%d %d",&N,&K);
   front=0;
   rear=0;
   if(N==K){
      printf("0\n");
   }else if(N>K){
      printf("%d\n",N-K);
   }
   else
      printf("%d\n",bfs(N,0));

   return 0;
}