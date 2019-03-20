//https://www.acmicpc.net/problem/14490
#include <string>
#include <iostream>
using namespace std;

int gcd(int a, int b) {
	if(b == 0) return a;
	return gcd(b, a % b);
}

int main() {
	string input;
	cin >> input;
	int sub_index = 0;
	for(int i = 0;; i++) {
		if(input[i] == ':'){
			sub_index = i;
			break;
		}
	}
	int num1 = stoi(input.substr(0, sub_index));
	int num2 = stoi(input.substr(sub_index + 1, input.size()));
	int gcdnum = gcd(num1, num2);
	cout << num1 / gcdnum << ':' << num2 / gcdnum << '\n';
}