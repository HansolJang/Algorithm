//https://www.acmicpc.net/problem/10866
#include <cstdio>
#include <cstring>
#include <deque>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	char command[15];
	int num;
	deque<int> deq;
	for(int i = 0; i < n; i++) {
		scanf("%s", command);
		if(strncmp(command, "push_front", 10) == 0) {
			scanf("%d", &num);
			deq.push_front(num);
		} else if(strncmp(command, "push_back", 9) == 0) {
			scanf("%d", &num);
			deq.push_back(num);
		} else if(strncmp(command, "pop_front", 9) == 0) {
			printf("%d\n", deq.empty() ? -1 : deq.front());
			if (!deq.empty())
				deq.pop_front();
		} else if(strncmp(command, "pop_back", 8) == 0) {
			printf("%d\n", deq.empty() ? -1 : deq.back());
			if (!deq.empty())
				deq.pop_back();
		} else if(strncmp(command, "size", 4) == 0) {
			printf("%lu\n", deq.size());
		} else if(strncmp(command, "empty", 5) == 0) {
			printf("%d\n", deq.empty() ? 1 : 0);
		} else if(strncmp(command, "front", 5) == 0) {
			printf("%d\n", deq.empty() ? -1 : deq.front());
		} else if(strncmp(command, "back", 4) == 0) {
			printf("%d\n", deq.empty() ? -1 : deq.back());
		}
	}
	return 0;
}