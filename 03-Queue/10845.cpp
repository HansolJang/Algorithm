//https://www.acmicpc.net/problem/10845
#include <cstdio>
#include <cstring>
using namespace std;
#define SIZE 10001
int q[SIZE];

int main() {
	int n;
	scanf("%d", &n);
	int front = 0;
	int rear = 0;
	char command[10];
	int num;
	for(int i = 0; i < n; i++) {
		scanf("%s", command);
		if(strncmp(command, "push", 4) == 0) {
			scanf("%d", &num);
			q[rear++] = num;
		} else if(strncmp(command, "pop", 3) == 0) {
			printf("%d\n", front == rear ? -1 : q[front++]);
		} else if(strncmp(command, "size", 4) == 0) {
			printf("%d\n", rear - front);
		} else if(strncmp(command, "empty", 5) == 0) {
			printf("%d\n", front == rear ? 1 : 0);
		} else if(strncmp(command, "front", 5) == 0) {
			printf("%d\n", front == rear ? -1 : q[front]);
		} else if(strncmp(command, "back", 4) == 0) {
			printf("%d\n", front == rear ? -1 : q[rear-1]);
		}
	}
	return 0;
}