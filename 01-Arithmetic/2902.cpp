//https://www.acmicpc.net/problem/2902
#include <cstdio>
using namespace std;

int main() {
	char str[101];
	scanf("%s", str);
	for(int i = 0; i < 101; i++) {
		if(str[i] == '\0') break;
		if(str[i] >= 'A' && str[i] <= 'Z') printf("%c", str[i]);
	}
	printf("\n");
	return 0;
}