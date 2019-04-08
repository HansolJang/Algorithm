// https://www.acmicpc.net/problem/11286
#include <cstdio>
#include <queue>
using namespace std;

struct cmp{
    bool operator()(long long t, long long u){
        long long abst = t < 0 ? t * (-1) : t;
        long long absu = u < 0 ? u * (-1) : u;
        if (abst == absu) 
        	return t > u;
        else return abst > absu;
    }
};

int main() {
	int n;
	long long temp;
	scanf("%d", &n);
	priority_queue<long long, vector<long long>, cmp> pq;
	for(int i = 0; i < n; i++) {
		scanf("%lld", &temp);
		if (temp == 0) {
			if (pq.empty())
				printf("0\n");
			else {
				printf("%lld\n", pq.top());
				pq.pop();
			}
		} else pq.push(temp);
	}
	return 0;
}