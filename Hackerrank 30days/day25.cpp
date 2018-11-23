#include <cstdio>
#include <math.h>
using namespace std;

int main() {
    int testcase = 0;
    scanf("%d", &testcase);
    for (int i = 0; i < testcase; i++) {
        int num = 0;
        scanf("%d", &num);
        if(num == 1) {
            printf("Not prime\n");
            continue;
        }
        int maxnum = sqrt(num);
        bool result = true;
        for(int i = 2; i <= maxnum; i++) {
            if(num % i == 0) {
                result = false;
                break;
            }
        }
        if(result) printf("Prime\n");
        else printf("Not prime\n");
    }
}