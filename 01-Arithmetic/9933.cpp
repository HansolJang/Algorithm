//https://www.acmicpc.net/problem/9933
#include <iostream>
#include <string>
using namespace std;
int main() {
	int n, len1, len2, ansidx;
	bool is_same;
	string s[100];
	cin >> n;
	for(int i=0; i<n; i++)
		cin >> s[i];
	for(int i=0; i<n; i++) {
		len1 = s[i].length();
		for(int j=i; j<n; j++) {
			len2 = s[j].length();
			if(len1 != len2) continue;
			is_same = true;
			for(int k=0; k<len1; k++) {
				if(s[i][k] != s[j][len1-1-k]) {
					is_same = false;
					break;
				}
			}
			if(is_same) break;
		}
		if(is_same) {
			cout << len1 << ' ' << (char)s[i][len1 / 2] << '\n';
			break;
		}
	}
	return 0;
}