#include <iostream>
#include <cstring>
using namespace std;

int main() {
	char s[102];
	for(int i = 0; i < 100; i++) {
		cin.getline(s, 102);
		cout << s << '\n';
	}
	return 0;
}