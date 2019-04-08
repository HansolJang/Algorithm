// https://www.acmicpc.net/problem/2444
#include <cstdio>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
        for(int j = n - i; j > 0; j--)
            printf(" ");
        for(int j = 1; j <= i * 2 - 1; j++)
            printf("*");
        printf("\n");
    }
    for(int i = n - 1; i > 0; i--){
        for(int j = n - i; j > 0; j--)
            printf(" ");
        for(int j= 1; j <= i * 2 - 1; j++)
            printf("*");
        printf("\n");
    }
	return 0;
}