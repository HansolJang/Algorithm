#include <stdio.h>

int main() {
    int n = 0;
    scanf("%d", &n);
    for (int testcase = 0; testcase < n; testcase++) {
        char str[10001];
        scanf("%s", str);
        for (int i = 0; i < 10001; i++) {
            if (str[i] == '\0') break;
            if (i % 2 == 0) printf("%c", str[i]);
        }
        printf(" ");
        for (int i = 0; i < 10001; i++) {
            if (str[i] == '\0') break;
            if (i % 2 == 1) printf("%c", str[i]);
        }
        printf("\n");
    }
    return 0;
}

