#include <cstdio>
#define QSIZE 10000001
using namespace std;

int n, d, k, l;
int queue[QSIZE];
int front = 0;
int rear = 0;

void push(int num) {
	queue[rear++] = num;
	rear %= QSIZE;
}

int pop() {
	int num = queue[front++];
	front %= QSIZE;
	return num;
}

int size() {
	if(front == rear) return 0;
	else return rear - front < 0 ? front - rear : rear - front;
}

int main() {
	scanf("%d %d %d %d",&n, &d, &k, &l);
	for(int i = 0; i < n; i++) {
		if(i == 0) push(1);
		else {
			if(d == 1) push(i + 1);
			else push(n - i + 1);	
		}
	}
	
	int start = front;
	push(pop());
	for(int i = 0; i < n - 1; i++) {
		int step = k % size() == 0 ? size() : k % size();
		for(int j = 0; j < step - 1; j++) {
			push(pop());
		}
		k += l;	
		pop();
	}
	printf("%d\n", pop());
	return 0;
}