#include <iostream>
#include <cstring>
#include <stack>
using namespace std;

int main() {
	char str[101];
	while(true) {
		cin.getline(str, sizeof(str));
		if(strcmp(str, ".") == 0) {
			break;
		}
		stack<char> s;
		for(int i = 0; i < 501; i++) {
			if(str[i] == '\0') break;
			if(str[i] == '(') s.push('(');
			else if(str[i] == '[') s.push('[');
			else if(str[i] == ')') {
				if(s.top() == '(') s.pop();
				else {
					s.push(')');
					break;
				}
			} else if (str[i] == ']') {
				if(s.top() == '[') s.pop();
				else {
					s.push(']');
					break;
				}
			}
		}
		if(s.empty()) 
			cout << "yes\n";
		else
			cout << "no\n";
	}
	return 0;
}