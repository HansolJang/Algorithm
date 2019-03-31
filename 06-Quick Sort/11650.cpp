#include <cstdio>
#include <algorithm>
using namespace std;

bool compare(const pair<int, int>& a, const pair<int, int>& b) {
	if (a.first == b.first) return a.second < b.second;
	else return a.first < b.first;
}

pair<int, int> arr[100001];

int main(){
	int n, temp1, temp2;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d %d", &temp1, &temp2);
		arr[i] = make_pair(temp1, temp2);
	}
	sort(arr, arr + n, compare);
	for(int i = 0; i < n; i++) {
		printf("%d %d\n", arr[i].first, arr[i].second);
	}
	return 0;
}