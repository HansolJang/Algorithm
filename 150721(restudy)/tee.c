// #include <stdio.h>


// 	input - integer array ex) 1 25 -3 -4 7 6 -6 -7
// 	받은 input에서 합이 0인 subset의 개수를 찾아라
// 	위 예제에서 -3 -4 7 / 6 -6 / 7 6 -6 -7 subset은 총 3개이다
// 	시간복잡도는 최소 nlogn

// int main() {

// }


// 확장자는 .cpp으로 한 경우이다.
// 확장자를 .c로 할려면 몇가지를 고쳐야 한다.
//
// subset sum problem에 대한 동적계획법
#include <stdio.h>
// 동적계획법을 위한 2차원 배열
bool subset[10000][101];
// 해를 담을 배열
int solution[101]={0,};
// subset배열로 부터 solution를 구해내는 함수
void extract(int set[], int n, int sum) {
    int i;
    if(sum==0) {
        return;
    }
    for(i=0;i<n;i+=1) {
        if(subset[sum][i+1]) {
            break;
        }
    }
    solution[i]=1;
    extract(set, n, sum-set[i]);
}
// n개의 원소를 가지는 set의 부분집합의 합이 sum과 같아지면 참을 반환한다.
bool isSubsetSum(int set[], int n, int sum) {
    // 집합은 앞에서 부터 연속된 부분을 크기로 본다.
    // 크기 j 인 집합 중에서 합이 i가 되는 부분집합이 존재하면 
    // subset[i][j]는 참이 된다.
    // 구해야하는 합 sum보다 1줄이 많다. (0부터 sum까지)
    // 원소번호는 1부터 n까지를 가진다. 따라서 n+1칸을 가지게 된다.
    // bool subset[sum+1][n+1];

    // 만약 sum이 0일 경우에는 모두가 true가 된다.
    for (int i = 0; i <= n; i+=1) {
        subset[0][i] = true;
    }
 
    // 만약 sum 이 0 이 아니고 집합의 크기가 0이라면, 모두 false이다.
    for (int i = 1; i <= sum; i+=1) {
        subset[i][0] = false;
    }
 
    // subset 테이블을 무게 1부터 sum까지 가면서 채워나간다. 
    for (int i = 1; i <= sum; i+=1) {
        // 집합의 크기가 1부터 n까지 가면서
        for (int j = 1; j <= n; j+=1) {
            // 만약 크기가 1작은 집합에서 i를 만들수 있다면, 현재 크기의 집합에서도 만들 수 있다.
            subset[i][j] = subset[i][j-1];
            // 만약 i가 원소 x=set[j-1]보다 클 경우이고 subset[i][j]가 여전히 false라면
            // subset[i-x][j-1] 이 true라면 subset[i][j]가 true가 된다.
            // 즉 i에서 x를 뺀 합을 j-1크기의 set에서 만들 수 있고 
            // j번째 원소인 x=set[j-1] (0부터 시작하므로 j번째라고 할 수 있다)
            // 를 같이 고려하면 subset[i][j]는 true가 된다.
            if (i >= set[j-1]) {
                subset[i][j] = subset[i][j] || subset[i - set[j-1]][j-1];
            }
        }
    }
 
    // 아래 표로부터 부분집합을 추출해 낸다.
    for (int i = 0; i <= sum; i+=1) {
        for (int j = 0; j <= n; j+=1) {
            printf ("%4d", subset[i][j]);
        }
        printf("\n");
    } 
    if(subset[sum][n]) {
        extract(set, n, sum);
    }    

    return subset[sum][n];
}
 
// 메인함수
// 처음에는 n의 값을 읽고, set에 n개의 정수를 읽어 들인다.
// 전체 합을 구한다음 2로 나눈 값을 sum에 넣는다.
// 그 후에 isSubsetSum함수를 호출해서 true가 반환되면
// 해가 존재하고,  그 해는 solution 배열에 들어 있다.
int main() {
    int set[100] = {1, 25, -3, -4, 7, 6, -6, -7};
    int sum = 0;
    int n = 7, x;
    if (isSubsetSum(set, n, sum) == true) {
        printf("주어진 합에 대한 해를 발견함\n");
        x=0;
        for(int i=0;i<n;i+=1) {
            if(solution[i]!=0) {
                //printf("%d ", set[i]);
                x+=1;
            }
        }
        printf("\n%d\n", x);
        for(int i=0;i<n;i+=1) {
            if(solution[i]!=0) {
                printf("%d ", set[i]);
            }
        }
        printf("\n");
    } else {
        printf("0\n");
    }

    return 0;
}