//https://www.acmicpc.net/problem/1874
#include <iostream>
#include <stack>

using namespace std;

#define SIZE      111111
#define ANS_SIZE   222222

int input[SIZE];
char ans[ANS_SIZE];
int ip_idx = 0;
int ans_idx = 0;
int num = 1;
int n, i;
bool is_possible = true;

int main() {
	stack<int> stack;
	cin >> n;
	for (i = 0; i < n; i++)
		cin >> input[i];
    for (i = 1; i <= input[0]; i++) { // i=1번째는 무조건 PUSH
   		stack.push(i);
   		ans[ans_idx++] = '+';
   	}
   	num = input[0] + 1;
    while (ans_idx < 2*n) {
    	if(stack.empty() || input[ip_idx] > stack.top()) {
	   		stack.push(num++);
	   		ans[ans_idx++] = '+';
    	}
   		if (input[ip_idx] < stack.top()) {
   			is_possible = false;
   			break;
   		}
   		if(input[ip_idx] == stack.top()) {
   			stack.pop();
   			ans[ans_idx++] = '-';
   			ip_idx++;
   		}
    }
    if (!is_possible)
   		cout << "NO\n";
    else {
   		for(i = 0; i < ans_idx; i++)
   			cout << ans[i] << '\n';
    }
    return 0;
}