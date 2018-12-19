#include <cstdio>
using namespace std;
int main() {
	int e, s, m;
	scanf("%d %d %d", &e, &s, &m);
	for(int i = s;;i+= 28) {
		if((i % 15 == 0 ? 15 : i % 15) == e 
			&& (i % 28 == 0 ? 28 : i % 28) == s 
			&& (i % 19 == 0 ? 19 : i % 19) == m) {
			printf("%d\n", i);
			break;
		}
	}
	return 0;
}