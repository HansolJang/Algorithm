//https://www.acmicpc.net/problem/10942
#include <cstdio>
#include <memory.h>
using namespace std;
#define SIZE 2001
int seq[SIZE];
int d[SIZE][SIZE];
int N, M, s, e;
bool is_palindrome(int s, int e) {
    if(s == e)
        return true;
    if(s + 1 == e) {
        if(seq[s] == seq[e])
            return true;
        return false;
    }
    if(d[s][e] != -1)
        return d[s][e];
    if(seq[s] != seq[e])
        return d[s][e] = false;
    return d[s][e] = is_palindrome(s + 1, e - 1);
}
int main() {
    memset(d, -1, sizeof(d));
    scanf("%d", &N);
    for(int i = 1; i <= N; i++)
        scanf("%d", &seq[i]);
    scanf("%d", &M);
    for(int i = 0; i < M; i++) {
        scanf("%d %d", &s, &e);
        printf("%d\n", is_palindrome(s, e));
    }
    return 0;
}