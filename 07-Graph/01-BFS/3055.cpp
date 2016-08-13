//https://www.acmicpc.net/problem/3055
#include <iostream>
#include <cstring>
#include <string>
using namespace std;
#define SIZE  55
#define QSIZE 10000000
enum Type {stone, road, water};
int row, col, front, rear, srow, scol, erow, ecol;
pair<int, int> q[QSIZE];
int map[SIZE][SIZE];
int mapcpy[SIZE][SIZE];
int visited[SIZE][SIZE];
int rdir[4] = {0, 0, 1, -1};
int cdir[4] = {1, -1, 0, 0};
void waterfall();
int main() {
	string input;
	front = 1; rear = 1;
	cin >> row >> col ;
	for(int i=0; i<row; i++) {
		cin >> input;
		for(int j=0; j<col; j++) {
			switch(input[j]) {
				case 'D' : erow = i; ecol = j; break;
				case 'S' : {
					pair<int, int> p = make_pair(i, j);
					q[front++] = p;
					front %= QSIZE;
					break;
				}
				case '.' : map[i][j] = road; break;
				case '*' : map[i][j] = water; break;
				case 'X' : map[i][j] = stone; break;
			}
		}
	}
	int frow, fcol, nrow, ncol, second = 0;
	while(!(front == rear)) {
		frow = q[rear].first;
		fcol = q[rear++].second;
		rear %= QSIZE;
		if(second == visited[frow][fcol]) {
			second++;
			waterfall();
		}
		for(int i=0; i<4; i++) {
			nrow = frow + rdir[i];
			ncol = fcol + cdir[i];
			if(nrow > row || nrow < 0 || ncol > col || ncol < 0) continue;
			if(nrow == erow && ncol == ecol) {
				cout << visited[frow][fcol] + 1 << '\n';
				return 0;
			}
			if(map[nrow][ncol] == road) {
				visited[nrow][ncol] = visited[frow][fcol] + 1;
				pair<int, int> p = make_pair(nrow, ncol);
				q[front++] = p;
				front %= QSIZE;
			}
		}
	}
	cout << "KAKTUS\n";
	return 0;
}
void waterfall() {
	int nrow, ncol;
	memcpy(mapcpy, map, sizeof(map));
	for(int i=0; i<row; i++) {
		for(int j=0; j<col; j++) {
			if(map[i][j] == water) {
				for(int k=0; k<4; k++) {
					nrow = i + rdir[k];
					ncol = j + cdir[k];
					if(nrow > row || nrow < 0 || ncol > col || ncol < 0) continue;
					if(map[nrow][ncol] == stone || map[nrow][ncol] == 0) continue;
					mapcpy[nrow][ncol] = water;
				}
			}
		}
	}
	memcpy(map, mapcpy, sizeof(map));
}