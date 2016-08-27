//https://www.acmicpc.net/problem/2816
#include <cstdio>
#include <cstring>
using namespace std;
int n, kbs1, kbs2, i;
char channel[101][11];
int main() {
	scanf("%d", &n);
	for(i=1; i<=n; i++) {
		scanf("%s", &channel[i]);
		if(!strcmp(channel[i], "KBS1")) kbs1 = i;
		if(!strcmp(channel[i], "KBS2")) kbs2 = i;
	}
	if(kbs2 < kbs1) kbs2++;
	for(i=1; i<kbs1; i++) printf("1");
	for(i=1; i<kbs1; i++) printf("4");
	for(i=1; i<kbs2; i++) printf("1");
	for(i=2; i<kbs2; i++) printf("4");
	printf("\n");
	return 0;
}