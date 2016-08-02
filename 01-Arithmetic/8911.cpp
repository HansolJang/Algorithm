//https://www.acmicpc.net/problem/8911
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int main() {
	int left, right, up, down, dir, x, y; // 0-북, 1-동, 2-남, 3-서
	int tc;
	cin >> tc;
	while(tc--) {
		left = 0, right = 0, up = 0, down = 0, dir = 0, x = 0, y =0;
		string input;
		cin >> input;
		int len = input.length();
		for(int i=0; i<len; i++) {
			if(input[i] == 'L') 
				dir = (dir + 3) % 4;
			if(input[i] == 'R')
				dir = (dir + 1) % 4;
			if(input[i] == 'F' || input[i] == 'B') {
				if(dir % 2 == 0) {
					if((dir == 0 && input[i] == 'F') || (dir == 2 && input[i] == 'B'))
						y += 1;
					else
						y -= 1;
				} else {
					if((dir == 1 && input[i] == 'F') || (dir == 3 && input[i] == 'B'))
						x += 1;
					else
						x -= 1;
				}
			}
			left = min(left, x); right = max(right, x);
			up = max(up, y); down = min(down, y);
		}
		cout << (up - down) * (right - left) << '\n';
	}
	return 0;
}