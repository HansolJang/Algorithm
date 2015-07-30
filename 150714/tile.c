#include <stdio.h>

long long get_gcd(long long n1, long long n2) {
	if(n2 == 0) {
		return n1;
	}
	return get_gcd(n2, n1 % n2);
}

int main() {
	int itr;
	int nCount;
	int w;
	long long h;
	long long tsize;
	scanf("%d", &nCount);

	for(itr=0; itr<nCount; itr++){
		printf("#testCase%d\n", itr+1);
		
		scanf("%lld %lld", &w, &h);

		tsize = get_gcd(w, h);
		printf("%lld\n", tsize);

		printf("%lld\n", w/tsize * h/tsize);
	}
}