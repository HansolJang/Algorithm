//https://www.acmicpc.net/problem/9935
#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	int i, j, alen, blen, idx = 0;
	string a, b;
	bool isprinted = false;
	cin >> a >> b;
	alen = a.length();
	blen = b.length();
	bool unused[alen];
	if(blen == 1) {
		for(int i=0; i<alen; i++) {
			if(a[i] == b[0])
				unused[i] = true;
		}
	} else {
		stack<pair<int, int> > s;
		for(int i=0; i<alen; i++) {
			if(a[i] == b[0])
				s.push(make_pair(i, 0));
			else {
				if(!s.empty()) {
					if(a[i] == b[s.top().second + 1]) {
						s.push(make_pair(i, s.top().second + 1));
						if(s.top().second == blen - 1) {
							for(int j=0; j<blen; j++) {
								unused[s.top().first] = true;
								s.pop();
							}
						}
					} else {
						while(!s.empty())
							s.pop();
					}
				}
			}
		}
	}
	for(int i=0; i<alen; i++) {
		if(!unused[i]) {
			isprinted = true;
			cout << (char)a[i];
		}
	}
	if(!isprinted)
		cout << "FRULA\n";
	return 0;
}